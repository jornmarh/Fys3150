import matplotlib.pyplot as plt
import numpy as np

filename = "data.txt"

x = []
u = []
v = []
for line in open(filename, 'r'):
    x_value = (float(line.split()[0]))
    y_value = (float(line.split()[1]))
    x.append(x_value)
    u.append(y_value)
    v.append(1 -(1-np.exp(-10))*x_value-np.exp(-10*x_value))

plt.plot(x,u)
plt.plot(x,v)
plt.xlabel("x")
plt.ylabel("u,v")

plt.title("comparisson of U/x and v/x")
plt.show();
