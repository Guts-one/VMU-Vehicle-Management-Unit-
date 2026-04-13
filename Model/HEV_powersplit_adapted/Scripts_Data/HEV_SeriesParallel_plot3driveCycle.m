% Code to plot simulation results from HEV_powersplit_adapted.slx

% Copyright 2017-2025 The MathWorks, Inc.

% Reuse figure if it exists, else create new figure
if ~exist('h3_HEV_powersplit_adapted', 'var') || ...
        ~isgraphics(h3_HEV_powersplit_adapted, 'figure')
    h3_HEV_powersplit_adapted = figure('Name', 'HEV_powersplit_adapted');
end
figure(h3_HEV_powersplit_adapted)
clf(h3_HEV_powersplit_adapted)

plot(DriveCycles(Drive_Cycle_Num).time, DriveCycles(Drive_Cycle_Num).SpdKph, 'LineWidth', 1)
grid on
title(['Vehicle Speed for Drive Cycle ' num2str(Drive_Cycle_Num)]);
ylabel('Speed (kph)')

xlabel('Time (s)')
