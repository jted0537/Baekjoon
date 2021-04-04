import numpy as np
import time as ti
# a = np.random.rand(1000000)

# tic = ti.time()
# c = np.dot(a,a)
# toc = ti.time()
# print((toc-tic)*1000)

# tic = ti.time()
# for i in range(1000000) :
#     c += a[i] * a[i]
# toc = ti.time()

# print((toc-tic)*1000)

# a = 1/a
# print(a)
h = np.zeros(6)
print(h)
i = np.zeros((4,3))
print(i)
print(i.dtype)

j = np.array(['믿음', '소망', '사랑'])
print(j.dtype)

k = np.ones((4,3), dtype = 'int32')
print(k)
l = np.ones((4,3,2), dtype = 'int32')
print(l)
m = np.empty((4,3))
print(m)
n = np.full(4,3)
print(n)
# print(n.ndim)
# o = np.full((4,3), fill_value = 9)
ll = np.eye(4, 3, -1)
print(ll)