%load(fullfile(matlabroot, 'toolbox', 'ident', 'iddemos', 'data', 'dcmotordata'));
z = iddata(y2, u2, 0.01, 'Name', 'DC-motor');
z.InputName = 'Voltage';
z.InputUnit =  'V';
z.OutputName = {'Angular position', 'Angular velocity','Current'};
z.OutputUnit = {'rad', 'rad/s','Amps'};
z.Tstart = 0;
z.TimeUnit = 's';   
% 
% figure('Name', [z.Name ': Voltage input -> Angular position output']);
% plot(z(:, 1, 1));   % Plot first input-output pair (Voltage -> Angular position).
% figure('Name', [z.Name ': Voltage input -> Angular velocity output']);
% plot(z(:, 2, 1));   % Plot second input-output pair (Voltage -> Angular velocity).
% figure('Name', [z.Name ': Voltage input -> Current']);
% plot(z(:, 3, 1));   

figure(1);
subplot(3,1,1);
%figure('Name', [z.Name ': Voltage input -> Angular position output']);
plot(z(:, 1, 1));   % Plot first input-output pair (Voltage -> Angular position).
%figure('Name', [z.Name ': Voltage input -> Angular velocity output']);
subplot(3,1,2);
plot(z(:, 2, 1));  
subplot(3,1,3);
plot(z(:, 3, 1));  



FileName      = 'dcmotor_m2';       % File describing the model structure.
Order         = [3 1 3];           % Model orders [ny nu nx].
                % b, j, l, k,r
Parameters    = [0.000001; 0.000001; 0.001; 0.01;7.5];         % Initial parameters. Np = 2.
InitialStates = [0; 0; 0];            % Initial initial states.
Ts            = 0;                 % Time-continuous system.
nlgr = idnlgrey(FileName, Order, Parameters, InitialStates, Ts, ...
                'Name', 'DC-motor');
set(nlgr, 'InputName', 'Voltage', 'InputUnit', 'V',               ...
          'OutputName', {'Angular position', 'Angular velocity','Current'}, ...
          'OutputUnit', {'rad', 'rad/s','Amps'},                         ...
          'TimeUnit', 's');
nlgr = setinit(nlgr, 'Name', {'Angular position' 'Angular velocity' 'Current'});
nlgr = setinit(nlgr, 'Unit', {'rad' 'rad/s' 'Amps'});
nlgr = setpar(nlgr, 'Name', { 'Damping' 'Load Inertia' 'Inductance' 'Gear Ratio' 'Motor Resisdance'});
nlgr = setpar(nlgr, 'Unit', { 'B' 'rad/(V*s)' 'Henry' 'ratio' 'Ohm'});
size(nlgr)


%compare(z, nlgr);


% nlgr.SimulationOptions.AbsTol = 1e-6;
% nlgr.SimulationOptions.RelTol = 1e-5;
% 
% 
% nlgr = setinit(nlgr, 'Fixed', {false false false}); % Estimate the initial states.
% opt = nlgreyestOptions('Display', 'on');
% opt.SearchOption.MaxIter = 20;
% 
% %opt.SearchMethod='grad';
% nlgr = nlgreyest(z, nlgr, opt);
% compare(z, nlgr);
