def printMatrix(matrix):
	for i in range(len(matrix[0])):
		for j in range(len(matrix[0])):
			print matrix[i][j],
	return

def Swap(matrix, i, j):
	temp = matrix[i][j]
	matrix[i][j] = matrix[j][i]
	matrix[j][i] = temp
	return

def transpose(matrix):
	for i in range(len(matrix[0])):
		for j in range(i):
			Swap(matrix,i,j)
	return


def transMatrix(file_Name):
	matrix = [[0 for x in range(2002)] for x in range(2002)]

	f = open(file_Name,'r')
	lines = f.readlines()
	numberOfLinks = []
	Links = []
	f.close()

	#lines[i] for i from 0 to 6003 is no. of links on page no. i/3
	#lines[i+1] for i from 0 to 6003 is links on page no. (i-1)/3

	for i in range(6006):
		if i%3==0:	
			numberOfLinks.append(lines[i])
		if i%3==1:
			Links.append(lines[i])

	#numberOfLinks[i] is number of links on page i
	#Links[i] is links on page i
	for i in range(2002):
		for j in range(2002):
			if Links[i].find(str(j))>=0:		
				matrix[i][j] = matrix[i][j] + 1./int(numberOfLinks[i])
			else:
				matrix[i][j] = 0

	for i in range(2002):
		matrix[i][i]=0	

	transpose(matrix)
	return matrix

matrix = transMatrix('outputNEW.txt')
printMatrix(matrix)
