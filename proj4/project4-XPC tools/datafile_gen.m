%generates binary matlab files for post processing
clc
clear all

tg=slrt;
sc1=tg.getscope(1);
sc2=tg.getscope(2);
sc3=tg.getscope(3);
sc4=tg.getscope(4);
sc5=tg.getscope(5);

currentData=sc1.Data; %unscaled
voltageData=sc2.Data; %V
inputPWM=sc3.Data; %0-5V
position=sc4.Data; %counts
velocity=sc5.Data; %counts/s
time=sc1.Time;

%save('prbs','time','currentData','voltageData','inputPWM','position','velocity');

%save('square2Hz','time','currentData','voltageData','inputPWM','position','velocity');

save('triangle3Hz','time','currentData','voltageData','inputPWM','position','velocity');