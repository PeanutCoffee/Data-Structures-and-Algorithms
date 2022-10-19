%take 50 X,Y points
n_x_point=50; 
n_y_point=50; 

%assume infinity at 200
assume_infinity=200;

%creating a 50*50 matrix initialising with 0s to store voltages at points
Vol=zeros(n_y_point,n_x_point);

%scaling our plots between 0 and 1 on x-y axes
x_min=0; x_max=1; y_min=0; y_max=1;

%stepsize in x & y direction
step_x=(x_max-x_min)/(n_x_point-1);
step_y=(y_max-y_min)/(n_y_point-1);

%calculating Voltage at x,y
for i=1:n_x_point 
    for j=1:n_y_point 
        xplot=x_min+(j-1)*step_x;
        yplot=y_min+(i-1)*step_y;
        for n=1:assume_infinity
            Vol(i,j)=Vol(i,j)+(2-2*(-1)^n)*sinh(n*pi*yplot)*sin(n*pi*xplot)/(n*pi*sinh(n*pi));
        end
    end
end

[xmesh,ymesh] = meshgrid(x_min:step_x:x_max , y_min:step_y:y_max);

%plotting the surface
surf(xmesh,ymesh,Vol);
xlabel('x(m)');
ylabel('y(m)');
zlabel('Vol(Vol)')
figure;

%plotting the contour
[C,h] = contour(xmesh,ymesh,Vol);
set(h,'ShowText','on','TextStep',get(h,'LevelStep'));
xlabel('x(m)');
ylabel('y(m)');
figure;

%plotting lines of Electric field
contour(xmesh,ymesh,Vol); [px,py] = gradient(Vol);
hold on,quiver(xmesh,ymesh,-px,-py,5),hold off,
xlabel('x(m)');
ylabel('y(m)');
