# Catalan number
C = [0 for _ in range(100 + 1)]
C[0] = 1
for i in range(1,101):
	for k in range(i):
		C[i] += C[i - k - 1]*C[k]
		
# Input
while 1:
	n = int(input())
	if n == -1:
		break
	print(C[n])