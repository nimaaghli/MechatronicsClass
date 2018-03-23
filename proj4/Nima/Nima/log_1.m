t=tg.TimeLog;
out=tg.OutputLog;
figure(1);
subplot(6,1,1)
plot(t,out(:,1));
subplot(6,1,2)
plot(t,out(:,2));
subplot(6,1,3)
plot(t,out(:,1));
subplot(6,1,4)
plot(t,out(:,3));

subplot(6,1,5)
plot(t,out(:,1));
subplot(6,1,6)
plot(t,out(:,5));
figure(2);
plot(t,out(:,5));