function [dx, y] = dcmotor_m(t, x, u, tau, k, varargin)
%DCMOTOR_M  ODE file representing the dynamics of a motor.
% The same DC-motor that was modeled by IDGREY; see IDDEMO7.

%   Copyright 2005-2014 The MathWorks, Inc.

% Output equations.
y = [x(1);                         ... % Angular position.
     x(2)                          ... % Angular velocity.
    ];

% State equations.
dx = [x(2);                        ... % Angular velocity.
      -(1/tau)*x(2)+(k/tau)*u(1)   ... % Angular acceleration.
 ];
