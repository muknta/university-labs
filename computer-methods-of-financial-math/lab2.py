# Методи Ейлера-Маруями та Мільштейна
# для апроксимації вінерівського процесу

import numpy as np
import plotly.express as px
import matplotlib.pyplot as plt

S0 = 100
mu = 0.1
sigma = 0.05
t0 = 0
T = 1

def wiener_process(N = 100):
    dt = (T - t0)/N
    t = np.arange(t0, T, dt)
    dW = np.sqrt(dt) * np.random.randn(N)
    W = np.cumsum(dW)
    return t, dt, W, dW

def analytic_solution_St(t, dt, W, dW):
    S = S0 * np.exp((mu - (1/2)*sigma**2)*t + sigma*W)
    return S


def euler_maruyama_approximation(dt, t, S, dW):
    a = mu*S
    b = sigma*S

    dS_approx = a*dt + b*dW
    S_approx = np.cumsum(dS_approx) + S0

    return S_approx


def milstein_approximation(dt, t, S, dW):
    a = mu*S
    b = sigma*S # b' = sigma

    dS_approx = a*dt + b*dW + (1/2)*b*sigma*np.abs(dW**2 - dt)
    S_approx = np.cumsum(dS_approx) + S0

    return S_approx


def first_task():
    t, dt, W, dW = wiener_process()
    _, _, S, _ = analytic_solution_St(t, dt, W, dW)

    plt.plot(t, S)
    plt.legend(['Analytic solution'], loc='upper left')
    plt.show()

def second_task():
    t, dt, W, dW = wiener_process()
    S = analytic_solution_St(t, dt, W, dW)

    S_approx_euler = euler_maruyama_approximation(dt, t, S, dW)
    S_approx_milstein = milstein_approximation(dt, t, S, dW)

    plt.plot(t, S)
    plt.plot(t, S_approx_euler)
    plt.plot(t, S_approx_milstein)
    plt.legend(['Analytic solution', 'Euler-Maruyama approximation', 'Milstein approximation'], loc='upper left')
    plt.show()

def third_task(N_experiments = 50, N_steps = 100):
    overall_milstein_approximation_error = 0
    overall_euler_approximation_error = 0

    for _ in range(N_experiments):
        t, dt, W, dW = wiener_process(N_steps)
        S = analytic_solution_St(t, dt, W, dW)

        S_approx_euler = euler_maruyama_approximation(dt, t, S, dW)
        S_approx_milstein = milstein_approximation(dt, t, S, dW)

        for i in range(len(S)):
            overall_milstein_approximation_error += np.abs(S_approx_milstein[i] - S[i])
            overall_euler_approximation_error += np.abs(S_approx_euler[i] - S[i])

    mean_milstein_approximation_error = overall_milstein_approximation_error / (N_experiments * len(S))
    mean_euler_approximation_error = overall_euler_approximation_error / (N_experiments * len(S))

    print(mean_milstein_approximation_error)
    print(mean_euler_approximation_error)

# first_task()

# second_task()

third_task(50, 100)
third_task(50, 200)
third_task(50, 400)
