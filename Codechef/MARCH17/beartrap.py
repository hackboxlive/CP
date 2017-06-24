# The example usage is shown at the bottom of the program.

SLEEP_TIME = 0.3 # time waited after draw()
ALWAYS_DRAW = True # "True" if you want to run draw() automatically after each cat() and block()
N = 20 # the size of the grid
where_cat = (0, 0)
blocked = []

def clear():
	global where_cat
	global blocked
	where_cat = (0, 0)
	blocked = []

def inside(row, col):
	if abs(row) >= N:
		return False
	if row <= 0:
		return -N - row + 1 <= col and col < N
	return -N + 1 <= col and col < N - row

def areAdjacent(A, B):
	if A[0] == B[0]:
		return abs(A[1] - B[1]) == 1
	if A[1] == B[1]:
		return abs(A[0] - B[0]) == 1
	return A == (B[0]+1, B[1]-1) or B == (A[0]+1, A[1]-1)

def draw():
	def char(row, col):
		assert(inside(row, col))
		if (row, col) == where_cat:
			return "c"
		if blocked.count((row, col)) == 1:
			return "#"
		return "." if col % 2 == 0 else ","
	for row in range(-N+1, N):
		for repeat in range(abs(row)):
			print(" ", end = "")
		if row <= 0:
			for col in range(-N - row + 1, N):
				print(char(row,col) + " ", end = "")
		else:
			for col in range(-N + 1, N - row):
				print(char(row,col) + " ", end = "")
		print("")
	print("")
	import time
	time.sleep(SLEEP_TIME)

def my_error(command, message):
	print("error in " + command + ": " + message)
	exit(1)

def my_warning(command, message):
	print("warning in " + command + ": " + message)

def cat(row, col):
	global where_cat
	command = "cat(" + str(row) + "," + str(col) + ")"
	if not inside(row, col):
		my_error(command, "cat can't move to a cell outside the grid.")
	if blocked.count((row, col)):
		my_error(command, "cat can't move to a blocked cell.")
	if not areAdjacent(where_cat, (row, col)):
		my_warning(command, "cat moved between two cells that aren't adjacent.")
	where_cat = (row, col)
	if ALWAYS_DRAW:
		draw()

def block(row, col):
	global blocked
	command = "block(" + str(row) + "," + str(col) + ")"
	if not inside(row, col):
		my_error(command, "you can't block a cell outside the grid.")
	if blocked.count((row, col)):
		my_error(command, "you can't block a cell that is already blocked.")
	if where_cat == (row, col):
		my_error(command, "command ignored - you can't block a cell that contains the cat.")
	blocked.append((row, col))
	if ALWAYS_DRAW:
		draw()

"""
README

You can save this file as visualizer.py and run it in a terminal with a command:
	python3 visualizer.py

You can use functions:

1) cat(r,c) - Move the cat to (r,c). Prints warning if (r,c) isn't adjacent
		to the previous cell where the cat was. Terminates with error if
		the cell (r,c) is blocked or is outside the grid.

2) block(r,c) - block the cell (r,c). Terminates with error if the cell (r,c)
		is already blocked, is outside the grid or it contains the cat.

3) clear() - Clears the grid. The cat will be in the cell (0,0).

4) draw() - Draws the grid and waits for SLEEP_TIME seconds (0.3 by default).

By default functions cat() and block() run the function draw() automatically.
To turn it off, use a command "ALWAYS_DRAW = False". You can turn it on
again with "ALWAYS_DRAW = True" if you want.

If you want to change the time waited after each draw(), use "SLEEP_TIME = X"
where X denotes the new time in seconds.

You can change the grid size with e.g. "N = 15".

You can modify this file in any way you want, but you can't share
any modifications with other participants.

See the example usage below.
"""
cat(0,1); block(0,2); cat(1,1); block(5,7); cat(1,2); block(1,8); cat(1,3); block(1,6); cat(2,3); block(6,1); cat(2,4); block(8,1); cat(2,5); block(7,5); cat(3,5); block(3,8); cat(3,6); block(8,3); cat(4,6); block(2,5); cat(5,6); block(6,6); cat(4,7); block(4,8); cat(5,6); block(5,2); cat(6,5); block(2,8); cat(7,4); block(8,4); cat(7,3); block(8,2); cat(7,2); block(7,1); cat(6,2); block(1,7); cat(5,3); block(4,3); cat(4,4); block(3,4);