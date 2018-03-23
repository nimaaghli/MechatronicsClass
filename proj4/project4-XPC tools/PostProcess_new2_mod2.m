
clc
clear all
close all

%All: 1.Current(V)  2.Voltage(V)  3.Theta(counts)    4.Thetadot(counts/s)
load('prbs')
PRBS=[currentData voltageData position velocity];
clear('time','currentData','voltageData','inputPWM','position','velocity');

load('square2Hz')
SQUARE = [currentData voltageData position velocity];
clear('time','currentData','voltageData','inputPWM','position','velocity');

load('triangle3Hz')
TRIANGLE = [currentData voltageData position velocity];
clear('time','currentData','voltageData','inputPWM','position','velocity');


Ts = 5E-5; %sample period/interval

clear a b c d


SQUARE(:,1) = idfilt(SQUARE(:,1),[0,.015],'FilterOrder',1,'noncasual'); %filter for current
SQUARE(:,2) = idfilt(SQUARE(:,2),[0,.025],'FilterOrder',1,'noncasual'); %filter for voltage
%theta does not need filter
SQUARE(:,4) = idfilt(SQUARE(:,4),[0,.03],'FilterOrder',2,'noncasual'); %filter for thetadot

TRIANGLE(:,1) = idfilt(TRIANGLE(:,1),[0,.01],'FilterOrder',4,'noncasual'); %filter for current
TRIANGLE(:,2) = idfilt(TRIANGLE(:,2),[0,.04],'FilterOrder',4,'noncasual'); %filter for voltage
%theta does not need filter
TRIANGLE(:,4) = idfilt(TRIANGLE(:,4),[0,.04],'FilterOrder',3,'noncasual'); %filter for thetad

PRBS(:,1) = idfilt(PRBS(:,1),[0,.01],'FilterOrder',1,'noncasual'); %filter for current
PRBS(:,2) = idfilt(PRBS(:,2),[0,.02],'FilterOrder',1,'noncasual'); %filter for voltage
%theta does not need filter
PRBS(:,4) = idfilt(PRBS(:,4),[0,.025],'FilterOrder',2,'noncasual'); %filter for thetad

% n=6E5;
% a=1;
% b = (1/250)*ones(1,250);
% y=filter(b,a,TRIANGLE(1:n,1));
% plot((1:n),y)

n=6E5;
%n=20000;
%plot([1:n],TRIANGLE(1:n,1),[1:n],a(1:n));




%current and voltage offset and scaling

SQUARE(:,1) = SQUARE(:,1)-2.526; %offset for 0
SQUARE(:,1) = SQUARE(:,1)*6.122;
SQUARE(:,2) = (SQUARE(:,2)*-1)+4.9E-3; %offset for 0 and flip

TRIANGLE(:,1) = TRIANGLE(:,1)-2.526; %offset for 0
TRIANGLE(:,1) = TRIANGLE(:,1)*6.122;
TRIANGLE(:,2) = (TRIANGLE(:,2)*-1)+4.9E-3; %offset for 0

PRBS(:,1) = PRBS(:,1)-2.526; %offset for 0
PRBS(:,1) = PRBS(:,1)*6.122;
PRBS(:,2) = (PRBS(:,2)*-1)+4.9E-3; %offset for 0


%Position scaling to rad
SQUARE(:,3)=SQUARE(:,3)*(2*3.14159)/2000;
TRIANGLE(:,3)=TRIANGLE(:,3)*(2*3.14159)/2000;
PRBS(:,3)=PRBS(:,3)*(2*3.14159)/2000;

%Velocity scaling to rad/s
SQUARE(:,4)=SQUARE(:,4)*(2*3.14159)/2000;
TRIANGLE(:,4)=TRIANGLE(:,4)*(2*3.14159)/2000;
PRBS(:,4)=PRBS(:,4)*(2*3.14159)/2000;




yS = [ SQUARE(:,3) SQUARE(:,4)]; %outputs
uS = [SQUARE(:,2)]; %inputs

yT = [ TRIANGLE(:,3) TRIANGLE(:,4)]; %outputs
uT = [TRIANGLE(:,2)]; %inputs

y = [ PRBS(:,3) PRBS(:,4)]; %outputs
u = [PRBS(:,2)]; %inputs



mdata  = iddata(y(250:floor(end*(2/3)),:),u(250:floor(end*(2/3)),:),Ts);
vdata  = iddata(y(floor(end*(2/3)):end-250,:),u(floor(end*(2/3)):end-250,:),Ts);
vSdata = iddata(yS(250:end-250,:),uS(250:end-250,:),Ts);
vTdata = iddata(yT(250:end-250,:),uT(250:end-250,:),Ts);


set(mdata, 'InputName', 'Voltage', 'InputUnit', 'V');
set(mdata, 'OutputName', {'Angular position', 'Angular velocity'});
set(mdata, 'OutputUnit', {'rad', 'rad/s'});
set(mdata, 'Tstart', 0, 'TimeUnit', 's');

set(vdata, 'InputName', 'Voltage', 'InputUnit', 'V');
set(vdata, 'OutputName', {'Angular position', 'Angular velocity'});
set(vdata, 'OutputUnit', {'rad', 'rad/s'});
set(vdata, 'Tstart', 0, 'TimeUnit', 's');

set(vSdata, 'InputName', 'Voltage', 'InputUnit', 'V');
set(vSdata, 'OutputName', {'Angular position', 'Angular velocity'});
set(vSdata, 'OutputUnit', {'rad', 'rad/s'});
set(vSdata, 'Tstart', 0, 'TimeUnit', 's');

set(vTdata, 'InputName', 'Voltage', 'InputUnit', 'V');
set(vTdata, 'OutputName', {'Angular position', 'Angular velocity'});
set(vTdata, 'OutputUnit', {'rad', 'rad/s'});
set(vTdata, 'Tstart', 0, 'TimeUnit', 's');

moutput= mdata.y;
minput = mdata.u;
voutput= vdata.y;
vinput = vdata.u;
vSoutput =  vSdata.y;
vSinput = vSdata.u;
vToutput =  vTdata.y;
vTinput = vTdata.u;

%}

