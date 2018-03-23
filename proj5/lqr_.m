A=[0,1;0,-1/0.1440];
B=[0;111.3292/0.1440];
Q=[1,0;0,10]; % first entry relates to x & and index[2,2] relates to velocity
R=[1];
K=lqr(A,B,Q,R);