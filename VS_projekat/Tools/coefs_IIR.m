
Fs = 48000;        % Sampling frequency
Fc = 1000;         % Cutoff frequency
N = 4;             % Filter order


[b, a] = butter(N, Fc/(Fs/2), 'low');

% Konverzija u sekcije drugog reda (biquad cascade form)
[sos, g] = tf2sos(b, a);


disp('Biquad sekcije (sos):');
disp(sos);

disp('Gain (g):');
disp(g);
