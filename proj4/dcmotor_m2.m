function [dx, y] = dcmotor_m2(t, x, u, b, j, l, k,r, varargin)
%DCMOTOR_M  ODE file representing the dynamics of a motor.
% The same DC-motor that was modeled by IDGREY; see IDDEMO7.

%   Copyright 2005-2014 The MathWorks, Inc.

% Output equations.
y = [x(1);                         ... % Angular position.
     x(2);                         ...% Angular velocity. 
     x(3);                         ... % Current.
    ];

% State equations.
A = [0,1,0;0,(-b/j),k/j;0,(-k/l),(-r/l)];
B = [0;0;1/l];
dx=A*x+B*u;