import sys
import math
from decimal import Decimal

n = int(input())
point = []
neg = False
pos = False
for i in range(n):
	x, y = sys.stdin.readline().split()
	x = int(x)
	y = int(y)
	if y < 0:
		neg = True
		y = y * -1
	else:
		pos = True
	point.append((x, y))
if neg is True and pos is True:
	print('-1')
	sys.exit(0)
lo = Decimal(0)
hi = Decimal(1e16)
ans = True
ctr = 0
while hi - lo >= 1e-8 and ctr < 200:
	mid = Decimal(lo + hi)/Decimal(2.0)
	#mid = Decimal.from_float(mid)
	#print(mid)
	x1 = -1e16
	x2 = 1e16
	iter_ans = True
	# print(ctr, mid, lo, hi)
	for i in range(n):
		vvv = Decimal(Decimal(2 * mid) - Decimal(point[i][1]))
		vvv = Decimal(vvv * Decimal(point[i][1]))
		if(vvv < 0):
			iter_ans = False
			break
		v2 = Decimal(vvv).sqrt()
		v1 = Decimal(v2 * -1)
		v1 = Decimal(v1 + point[i][0])
		v2 = Decimal(v2 + point[i][0])
		if v2 < x1 or v1 > x2:
			iter_ans = False
			break
		x1 = max(x1, v1)
		x2 = min(x2, v2)
	# print(iter_ans)
	if iter_ans == True:
		hi = mid
	else:
		lo = mid + Decimal(1e-8)
	ans = iter_ans
	ctr += 1

if lo != 1e16:
	print(Decimal(lo))
else:
	print('-1')
