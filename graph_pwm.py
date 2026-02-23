import matplotlib.pyplot as plt
import numpy as np
from scipy import signal

clock_speed = 84000000  
prescaler = 839
period = 1999
pulse = 1000

# okay so pwm_freq = clock_speed / prescaler * period
# duty cycle = pulse / period

timer_tick_freq = clock_speed / (prescaler + 1)
pwm_freq = timer_tick_freq / (period + 1)
duty_cycle = (pulse / (period + 1)) * 100

time = np.linspace(0, 0.06, 1000) 
wave = signal.square(2 * np.pi * pwm_freq * time, duty=duty_cycle/100)

plt.figure(figsize=(10, 4))
plt.plot(time * 1000, wave, color='green', linewidth=2)
plt.title(f'PWM Output ({pwm_freq}Hz, {duty_cycle}% Duty Cycle)')
plt.xlabel('Time (ms)')
plt.ylabel('On/Off')
plt.ylim(-1.5, 1.5)
plt.grid(True)
plt.show()