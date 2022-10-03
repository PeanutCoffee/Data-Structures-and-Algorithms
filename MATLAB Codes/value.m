d=0.30; %the width of the sheet in the x direction
L=20; %length of sheet in the y direction
J=5; %value of surface current density
Js=J*[0 1 0]; %the vector of surface current density

Xmin=-0.15; %coordinate of lowest x value on sheet
Xmax=0.15; %coordinate of maximum x value on sheet
Ymin=-10; %coordinate of lowest y value on sheet
Ymax=10; %coordinate of maximum y value on sheet
NumberOfXDivisions=20; %number of cells in the x direction
NumberOfYDivisions=100; %number of cells in the y direction
dx=(Xmax-Xmin)/NumberOfXDivisions; %step in the x direction
dy=(Ymax-Ymin)/NumberOfYDivisions; %step in the y direction
ds=dx*dy; %area of one subsection of sheet

ZCellCenter=0; %all points on sheet has a coordinate z=0
NumberOfXPlottingPoints=10; %number of plotting points along the x axis
NumberOfZPlottingPoints=10; %number of plotting points along the z axis
PlotXmin=-0.5; %lowest x value on the plot plane
PlotXmax=0.5; %maximum x value on the plot plane
PlotZmin=-0.5; %lowest z value on the plot plane
PlotZmax=0.5; %maximum z value on the plot plane
PlotStepX= (PlotXmax-PlotXmin)/(NumberOfXPlottingPoints-1);%plotting step in the x direction
PlotStepZ=(PlotZmax-PlotZmin)/(NumberOfZPlottingPoints-1); %plotting step in the z direction

[XData,ZData]=meshgrid(PlotXmin:PlotStepX:PlotXmax, PlotZmin:PlotStepZ:PlotZmax); %build arrays of plot plane
PlotY=0; %all points on observation plane have zero y coordinate
Bx=zeros(NumberOfXPlottingPoints,NumberOfZPlottingPoints); %x component of field
Bz=zeros(NumberOfXPlottingPoints, NumberOfZPlottingPoints);%z component of field
for m=1:NumberOfXPlottingPoints %repeat for all plot points in the x direction
    for n=1:NumberOfZPlottingPoints %repeat for all plot points in the y direction
        PlotX=XData(m,n); %x coordinate of current plot point
        PlotZ=ZData(m,n); %z coordinate of current plot point
        if ((PlotZ==0)&(PlotX>=Xmin)&(PlotX<=Xmax)) % if the plotting point is on the current sheet
            Bx(m,n)=0.5*J; % we use the model of infinite current sheet
            Bz(m,n)=0;
            continue;
        end
        Rp=[PlotX PlotY PlotZ]; %poistion vector of observation points
        for i=1:NumberOfXDivisions %repeat for all divisions in the x direction
            for j=1:NumberOfYDivisions %repeat for all cells in the y direction
                XCellCenter=Xmin+(i-1)*dx+0.5*dx; %X center of current subsection
                YCellCenter=Ymin+(j-1)*dy+0.5*dy; %Y center current subsection
                Rc=[XCellCenter YCellCenter ZCellCenter]; %position vector of center of current subsection
                R=Rp-Rc; %vector pointing from current subsection to the current observation point
                norm_R=norm(R); %get the distance between the current surface element and the observation point
                R_Hat=R/norm_R; %unit vector in the direction of R
                dH=(ds/(4*pi*norm_R*norm_R))*cross(Js,R_Hat); %this is the contribution from current element
                Bx(m,n)=Bx(m,n)+dH(1,1); %increment the x component at the current observation point
                Bz(m,n)=Bz(m,n)+dH(1,3); %increment the z component at the current observation point
            end %end of j loop
        end %end of i loop
    end %end of n loop
end % end of m loop

quiver(XData, ZData, Bx, Bz);
xlabel('x(m)');%label x axis
ylabel('z(m)');%label y axis
%The following routing caculates the magnetic field at point P
P=[0 0 0.25];%position of point P
Hp=[0 0 0];%the magnetic field at point P
for i=1:NumberOfXDivisions %repeat for all divisions in the x direction
    for j=1:NumberOfYDivisions %repeat for all cells in the y direction
        XCellCenter=Xmin+(i-1)*dx+0.5*dx; %X center of current subsection
        YCellCenter=Ymin+(j-1)*dy+0.5*dy; %Y center current subsection
        Rc=[XCellCenter YCellCenter ZCellCenter]; %position vector of center of current subsection
        R=P-Rc; %vector pointing from current subsection to the current observation point
        norm_R=norm(R); %get the distance between the current surface element and the observation point
        R_Hat=R/norm_R; %unit vector in the direction of R
        dH=(ds/(4*pi*norm_R*norm_R))*cross(Js,R_Hat); %this is the contribution from current element
        Hp=Hp+dH;
    end %end of j loop
end %end of i loop