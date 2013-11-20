import numpy as np
import matplotlib.pyplot as plt
import sys

x,y = np.loadtxt(sys.argv[1], unpack = True)

plt.plot(x,y)
plt.xlabel('x')
plt.ylabel('f(x)')
plt.title('f(x) vs x')
plt.text(60, .025, r'$\mu=100,\ \sigma=15$')
#plt.axis([40, 160, 0, 0.03])
plt.grid(True)
plt.show()
