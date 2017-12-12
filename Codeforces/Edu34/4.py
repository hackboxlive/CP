from collections import OrderedDict
n = int(input())
str_arr = raw_input().split(' ')
arr = [int(num) for num in str_arr]
for i in range(n):
	m[arr[i]].append(i)
