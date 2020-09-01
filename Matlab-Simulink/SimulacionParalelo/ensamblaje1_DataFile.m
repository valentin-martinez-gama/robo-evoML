% Simscape(TM) Multibody(TM) version: 7.1

% This is a model data file derived from a Simscape Multibody Import XML file using the smimport function.
% The data in this file sets the block parameter values in an imported Simscape Multibody model.
% For more information on this file, see the smimport function help page in the Simscape Multibody documentation.
% You can modify numerical values, but avoid any other changes to this file.
% Do not add code to this file. Do not edit the physical units shown in comments.

%%%VariableName:smiData


%============= RigidTransform =============%

%Initialize the RigidTransform structure array by filling in null values.
smiData.RigidTransform(11).translation = [0.0 0.0 0.0];
smiData.RigidTransform(11).angle = 0.0;
smiData.RigidTransform(11).axis = [0.0 0.0 0.0];
smiData.RigidTransform(11).ID = '';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(1).translation = [0 0 0];  % mm
smiData.RigidTransform(1).angle = 0;  % rad
smiData.RigidTransform(1).axis = [0 0 0];
smiData.RigidTransform(1).ID = 'B[Eslabon 3-1:-:Eslabon 4-1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(2).translation = [119.99999999997354 -1.9639401216409169e-11 10];  % mm
smiData.RigidTransform(2).angle = 0;  % rad
smiData.RigidTransform(2).axis = [0 0 0];
smiData.RigidTransform(2).ID = 'F[Eslabon 3-1:-:Eslabon 4-1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(3).translation = [0 0 0];  % mm
smiData.RigidTransform(3).angle = 0;  % rad
smiData.RigidTransform(3).axis = [0 0 0];
smiData.RigidTransform(3).ID = 'B[Eslabon 1y2-1:-:Eslabon 3-1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(4).translation = [120.00000000004601 3.4731328923953697e-11 10];  % mm
smiData.RigidTransform(4).angle = 0;  % rad
smiData.RigidTransform(4).axis = [0 0 0];
smiData.RigidTransform(4).ID = 'F[Eslabon 1y2-1:-:Eslabon 3-1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(5).translation = [0 0 0];  % mm
smiData.RigidTransform(5).angle = 0;  % rad
smiData.RigidTransform(5).axis = [0 0 0];
smiData.RigidTransform(5).ID = 'B[Eslabon 1y2-2:-:Eslabon 4-1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(6).translation = [-8.7817876504622661e-13 -7.1552927104075116e-13 20];  % mm
smiData.RigidTransform(6).angle = 0;  % rad
smiData.RigidTransform(6).axis = [0 0 0];
smiData.RigidTransform(6).ID = 'F[Eslabon 1y2-2:-:Eslabon 4-1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(7).translation = [0 0 0];  % mm
smiData.RigidTransform(7).angle = 0;  % rad
smiData.RigidTransform(7).axis = [0 0 0];
smiData.RigidTransform(7).ID = 'B[Eslabon 5-1:-:Eslabon 1y2-1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(8).translation = [119.99999999998886 2.2595258997171186e-12 10.000000000000028];  % mm
smiData.RigidTransform(8).angle = 0;  % rad
smiData.RigidTransform(8).axis = [0 0 0];
smiData.RigidTransform(8).ID = 'F[Eslabon 5-1:-:Eslabon 1y2-1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(9).translation = [157 0 10.000000000000009];  % mm
smiData.RigidTransform(9).angle = 0;  % rad
smiData.RigidTransform(9).axis = [0 0 0];
smiData.RigidTransform(9).ID = 'B[Eslabon 5-1:-:Eslabon 1y2-2]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(10).translation = [120.00000000000102 -5.6843418860808015e-14 20.000000000000028];  % mm
smiData.RigidTransform(10).angle = 0;  % rad
smiData.RigidTransform(10).axis = [0 0 0];
smiData.RigidTransform(10).ID = 'F[Eslabon 5-1:-:Eslabon 1y2-2]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(11).translation = [-115.00283348603621 -17.121721130678228 207.00000000000003];  % mm
smiData.RigidTransform(11).angle = 0;  % rad
smiData.RigidTransform(11).axis = [0 0 0];
smiData.RigidTransform(11).ID = 'RootGround[Eslabon 5-1]';


%============= Solid =============%
%Center of Mass (CoM) %Moments of Inertia (MoI) %Product of Inertia (PoI)

%Initialize the Solid structure array by filling in null values.
smiData.Solid(4).mass = 0.0;
smiData.Solid(4).CoM = [0.0 0.0 0.0];
smiData.Solid(4).MoI = [0.0 0.0 0.0];
smiData.Solid(4).PoI = [0.0 0.0 0.0];
smiData.Solid(4).color = [0.0 0.0 0.0];
smiData.Solid(4).opacity = 0.0;
smiData.Solid(4).ID = '';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(1).mass = 0.018853694547466635;  % kg
smiData.Solid(1).CoM = [58.344113567956171 0 4.9999999999999991];  % mm
smiData.Solid(1).MoI = [1.3228020909163987 28.974805387836007 29.983379236294624];  % kg*mm^2
smiData.Solid(1).PoI = [0 0 0];  % kg*mm^2
smiData.Solid(1).color = [0.69803921568627447 0.69803921568627447 0.69803921568627447];
smiData.Solid(1).opacity = 1;
smiData.Solid(1).ID = 'Eslabon 3*:*Predeterminado';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(2).mass = 0.020951650121533903;  % kg
smiData.Solid(2).CoM = [55.482085807088808 0 6.0013319055528758];  % mm
smiData.Solid(2).MoI = [1.6541637140166532 36.482847525690751 37.41024095325664];  % kg*mm^2
smiData.Solid(2).PoI = [0 1.1639895117986041 0];  % kg*mm^2
smiData.Solid(2).color = [0.69803921568627447 0.69803921568627447 0.69803921568627447];
smiData.Solid(2).opacity = 1;
smiData.Solid(2).ID = 'Eslabon 4*:*Predeterminado';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(3).mass = 0.019094085290328505;  % kg
smiData.Solid(3).CoM = [62.39042723821288 0 5];  % mm
smiData.Solid(3).MoI = [1.3269425710551699 29.786942294250252 30.795650110466614];  % kg*mm^2
smiData.Solid(3).PoI = [0 0 0];  % kg*mm^2
smiData.Solid(3).color = [0.69803921568627447 0.69803921568627447 0.69803921568627447];
smiData.Solid(3).opacity = 1;
smiData.Solid(3).ID = 'Eslabon 1y2*:*Predeterminado';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(4).mass = 0.0251495023164412;  % kg
smiData.Solid(4).CoM = [78.500000000000028 0 4.9999999999999991];  % mm
smiData.Solid(4).MoI = [1.7117637561828991 65.757188380672602 67.04979376491481];  % kg*mm^2
smiData.Solid(4).PoI = [0 0 0];  % kg*mm^2
smiData.Solid(4).color = [0.69803921568627447 0.69803921568627447 0.69803921568627447];
smiData.Solid(4).opacity = 1;
smiData.Solid(4).ID = 'Eslabon 5*:*Predeterminado';


%============= Joint =============%
%X Revolute Primitive (Rx) %Y Revolute Primitive (Ry) %Z Revolute Primitive (Rz)
%X Prismatic Primitive (Px) %Y Prismatic Primitive (Py) %Z Prismatic Primitive (Pz) %Spherical Primitive (S)
%Constant Velocity Primitive (CV) %Lead Screw Primitive (LS)
%Position Target (Pos)

%Initialize the RevoluteJoint structure array by filling in null values.
smiData.RevoluteJoint(5).Rz.Pos = 0.0;
smiData.RevoluteJoint(5).ID = '';

%This joint has been chosen as a cut joint. Simscape Multibody treats cut joints as algebraic constraints to solve closed kinematic loops. The imported model does not use the state target data for this joint.
smiData.RevoluteJoint(1).Rz.Pos = -40.536997242478172;  % deg
smiData.RevoluteJoint(1).ID = '[Eslabon 3-1:-:Eslabon 4-1]';

smiData.RevoluteJoint(2).Rz.Pos = -88.300938602455901;  % deg
smiData.RevoluteJoint(2).ID = '[Eslabon 1y2-1:-:Eslabon 3-1]';

smiData.RevoluteJoint(3).Rz.Pos = -95.818706151723717;  % deg
smiData.RevoluteJoint(3).ID = '[Eslabon 1y2-2:-:Eslabon 4-1]';

smiData.RevoluteJoint(4).Rz.Pos = -70.53591266647166;  % deg
smiData.RevoluteJoint(4).ID = '[Eslabon 5-1:-:Eslabon 1y2-1]';

smiData.RevoluteJoint(5).Rz.Pos = -103.55514235968201;  % deg
smiData.RevoluteJoint(5).ID = '[Eslabon 5-1:-:Eslabon 1y2-2]';

