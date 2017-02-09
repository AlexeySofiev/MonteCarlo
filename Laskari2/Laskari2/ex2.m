close all
clear all
cd data

lcg=load('ex2lcg.txt')
pm=load('ex2pm.txt')
lcgShuffle=load('ex2lcgShuffle.txt')

figure;
subplot(3,1,1)
plot(lcg,'*')
title('LCG')
xlabel('Enumeration of Ck value')
ylabel('Ck')

subplot(3,1,2)
plot(pm,'*')
title('PM')
xlabel('Enumeration of Ck value')
ylabel('Ck')

subplot(3,1,3)
plot(lcgShuffle,'*')
title('LCG with shuggle')
xlabel('Enumeration of Ck value')
ylabel('Ck')


figure;
f2ax1=subplot(3,1,1)
hist(lcg,20)
title('LCG')


f2ax2=subplot(3,1,2)
hist(pm,20)
title('PM')


f2ax3=subplot(3,1,3)
hist(lcgShuffle,20)
title('LCG with shuggle')
linkaxes([f2ax1,f2ax2,f2ax3])


figure;
f3ax1=subplot(3,1,1)
hist(abs(lcg),20)
title('LCG')


f3ax2=subplot(3,1,2)
hist(abs(pm),20)
title('PM')


f3ax3=subplot(3,1,3)
hist(abs(lcgShuffle),20)
title('LCG with shuggle')


linkaxes([f3ax1,f3ax2,f3ax3])


cd ..