import numpy as np
import plotly.express as px

def wiener_process(N=1000, T=1):
    dt = T / N;
    dW = np.sqrt(dt) * np.random.randn(N)
    W = np.cumsum(dW)
    t = np.linspace(dt, T, N)
    return np.insert(t, 0, 0), np.insert(W, 0, 0)

simulation_data = {}

t, W = wiener_process()
yLabel = 'Wiener - W(t)'
xLabel = 'Time - t'
simulation_data[xLabel] = t
simulation_data[yLabel] = W

fig = px.line(simulation_data, x=xLabel, y=yLabel)
fig.show()
