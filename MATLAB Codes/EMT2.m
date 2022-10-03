clc
clear all
close all

d=0.30; %width of the sheet in x
L=20; %length of sheet in y
J=5; %surface current density
Js=J*[0 1 0]; %vector of surface current density

x_min=-0.15; 
x_max=0.15; 
y_min=-10; 
y_max=10; 
x_div=20; %divisions in x direction
y_div=100; %divisions in y direction
dx=(x_max-x_min)/x_div; 
dy=(y_max-y_min)/y_div; 
ds=dx*dy; %area of 1 small [art

ZCellCenter=0; 
x_point=10; 
z_point=10; 
Plotx_min=-0.5;
Plotx_max=0.5;
PlotZmin=-0.5; 
PlotZmax=0.5; 
x_step= (Plotx_max-Plotx_min)/(x_point-1);
z_step=(PlotZmax-PlotZmin)/(z_point-1);

[XData,ZData]=meshgrid(Plotx_min:x_step:Plotx_max, PlotZmin:z_step:PlotZmax); 
PlotY=0;
Bx=zeros(x_point,z_point); 
Bz=zeros(x_point, z_point);
for m=1:x_point
    for n=1:z_point 
        PlotX=XData(m,n); 
        PlotZ=ZData(m,n);
        if ((PlotZ==0)&&(PlotX>=x_min)&&(PlotX<=x_max))
            Bx(m,n)=0.5*J;
            Bz(m,n)=0;
            continue;
        end
        Rp=[PlotX PlotY PlotZ];
        for i=1:x_div 
            for j=1:y_div 
                XCellCenter=x_min+(i-1)*dx+0.5*dx; 
                YCellCenter=y_min+(j-1)*dy+0.5*dy; 
                Rc=[XCellCenter YCellCenter ZCellCenter];
                R=Rp-Rc;
                norm_R=norm(R); 
                R_Hat=R/norm_R; 
                dH=(ds/(4*pi*norm_R*norm_R))*cross(Js,R_Hat);
                Bx(m,n)=Bx(m,n)+dH(1,1); 
                Bz(m,n)=Bz(m,n)+dH(1,3); 
            end 
        end 
    end 
end 

%plottting the figure
quiver(XData, ZData, Bx, Bz);
xlabel('x(m)');
ylabel('z(m)');


%The following routing caculates the magnetic field at point P
P=[0 0 0.25];
Hp=[0 0 0];
for i=1:x_div 
    for j=1:y_div 
        XCellCenter=x_min+(i-1)*dx+0.5*dx; 
        YCellCenter=y_min+(j-1)*dy+0.5*dy; 
        Rc=[XCellCenter YCellCenter ZCellCenter]; 
        R=P-Rc; 
        norm_R=norm(R); 
        R_Hat=R/norm_R; 
        dH=(ds/(4*pi*norm_R*norm_R))*cross(Js,R_Hat); 
        Hp=Hp+dH;
    end 
end 