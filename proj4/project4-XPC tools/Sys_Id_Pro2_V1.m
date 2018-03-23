
clear all
close all
clc

% Load all data
PostProcess_new2


%write inital guesses for big motor
% R=3; %resistance
% L=5E-3; %inductance
% kb=.063; %backemf constant
% ktau=0.12; %torque constant 
% J=.00005; %inertia
% c=.00025; %friction constant

%final guesses for big motor:
R=1; %resistance
L=5E-3; %inductance
kb=.01; %backemf constant
ktau=0.1; %torque constant 
J=.00005; %inertia
c=.00025; %friction constant

%for small geared motor:
% R=3.5; %resistance
% L=5E-4; %inductance
% kb=.01; %backemf constant
% ktau=0.01; %torque constant 
% J=5e-7; %inertia
% c=.005; %friction constant

a = [(-R/L) 0 (-kb/L);0 0 1;(ktau/(J)) 0 (-c/(J))];
b  = [1/L;0;0];
c  = [1 0 0; 0 1 0;0 0 1];
d  = [0; 0; 0];
K  = [0 0 0;0 0 0;0 0 0]; %disturbance element
x0 = [0; 0; 0]; %initial state



Tss=0;
m3 = idss(a,b,c,d,K,x0,Tss); %last entry Ts=0 -> continous time model



%{
% Define state-space model with user-defined free parameters
% Initialize model (initial guess for parameter values)
% states are:  x(1) = position,  x(2) = velocity
% A  = [0 1; -1 -1];
% B  = [0 0;0.1 0.1];
% C  = [1 0; 0 1];
% D  = [0 0];
% m3 = idss(A,B,C,D,K,x0,'T',0);
%}

m3.Structure.a.Free = ((a~=0) & (a~=1));
m3.Structure.b.Free = (b~=0);
m3.Structure.c.Free = false;
m3.Structure.d.Free = false;
m3.Structure.k.Free = false;
%m3.Structure.x0.Fixed = false;


% calculate model parameters
opt = ssestOptions('Focus','simulation','Display','on','Searchmethod','gn');
opt.SearchOption.MaxIter=1000;
opt.SearchOption.Tolerance=0.001;
m4   = pem(mdata,m3,opt);

m4.a
m4.b
m4.c
m4.d

m3.a
m3.b


figure
opt1=compareOptions('InitialCondition',[moutput(1,1);moutput(1,2);moutput(1,3)]);
compare(mdata,m4,opt1);
figure
opt2=compareOptions('InitialCondition',[voutput(1,1);voutput(1,2);voutput(1,3)]);
compare(vdata,m4,opt2);


figure
opt3=compareOptions('InitialCondition',[vSoutput(1,1);vSoutput(1,2);vSoutput(1,3)]);
compare(vSdata,m4,opt3);
figure
opt4=compareOptions('InitialCondition',[vToutput(1,1);vToutput(1,2);vToutput(1,3)]);
compare(vTdata,m4,opt4);


wv = logspace(-2,3,10000);
tfm4=tf(m4,'measured');
figure
bode(tfm4,wv);
hold on
Gprbs=spafdr(vdata,[],wv);
% Fvdata=fft(vdata,10000);
% G2prbs=tfest(Fvdata,[2;3;2],[1;0;0]);
bode(Gprbs)
%bode(G2prbs)

