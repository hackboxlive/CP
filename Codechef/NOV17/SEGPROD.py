import sys, math

def build(n, p):
	for i in range(n-1, 0, -1):
		tree[i] = (tree[i << 1] * tree[i << 1 | 1]) % p

def query(l, r, n, p):
	res = 1
	l = l + n
	r = r + n
	while l < r:
		if l & 1 == True:
			res *= tree[l]
			l += 1
			res %= p
		if r & 1 == True:
			r -= 1
			res *= tree[r]
			res %= p
		l >>= 1
		r >>= 1
	return res

def precompute():
	temp = p
	if temp % 2 == 0:
		ctr = 0
		while temp % 2 == 0:
			temp /= 2
			ctr += 1
		factors.append((2, ctr))
	sq = int(math.sqrt(temp))
	for i in range(int(3), sq + 1, 2):
		if temp % i == 0:
			ctr = 0
			while temp % i == 0:
				temp /= i
				ctr += 1
			factors.append((i, ctr))
	if temp > 2:
		factors.append((int(temp), 1))

def build_dp():
	for i in range(n):
		for j in range(len(factors)):
			if arr[i] % factors[j][0] == 0:
				ctr = 0
				v = arr[i]
				while v % factors[j][0] == 0:
					v /= factors[j][0]
					ctr += 1
				dp[i][j] = ctr
		if arr[i] == 0:
			zero[i] = 1
	for i in range(len(factors)):
		for j in range(1, n):
			dp[j][i] += dp[j-1][i]
	for i in range(1, n):
		zero[i] += zero[i-1]

t = int(input())
for tt in range(t):
	n, p, q = map(int, sys.stdin.readline().split())
	factors = []
	precompute()
	tree = [0] * n
	arr = list(map(int, sys.stdin.readline().split()))	
	dp = [[0 for x in range(len(factors))] for y in range(n)]
	zero = [0] * n
	build_dp()
	tree.extend(arr)
	build(n, p)
	bs = int(q / 64)
	b = list(map(int, sys.stdin.readline().split()))
	x = 0
	l = 0
	r = 0
	v = 0
	for i in range(q):
		if i % 64 == 0:
			l = (b[int(i / 64)] + x) % n
			r = (b[int(i / 64) + 1] + x) % n
		else:
			l = (l + x) % n
			r = (r + x) % n
		if l > r:
			l, r = r, l
		if l == 0:
			v = 0
			if zero[r] > 0:
				break
			for j in range(len(factors)):
				if dp[r][j] >= factors[j][1]:
					v += 1
		else:
			v = 0
			if zero[r] - zero[l - 1] > 0:
				break
			for j in range(len(factors)):
				if dp[r][j] - dp[l-1][j] >= factors[j][1]:
					v += 1
		if v < len(factors):
			x = query(l, r + 1, n, p)
		else:
			x = 0
		x += 1
		x %= p
	print(x)
