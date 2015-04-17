import math

def printMatrix(matrix):
	for i in range(len(matrix[0])):
		for j in range(len(matrix[0])):
			print matrix[i][j],
		print '\n'
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
	return matrix

def MultiplyByScalar(matrix, scalar):
	for i in range(len(matrix[0])):
		for j in range(len(matrix[0])):
			matrix[i][j] = matrix[i][j]*scalar
	return matrix

def MultiplyByScalarCol(matrix, scalar):
	for i in range(len(matrix)):
		matrix[i] = matrix[i]*scalar
	return matrix

def magnitude(matrix):
	mag = 0
	for i in range(len(matrix)):
		mag = mag + matrix[i]*matrix[i]
	return math.sqrt(mag)

def MultiplyByMatrix(matrix, rank):
	output = [0 for x in range(1962)]	
	for i in range(len(matrix[0])):
		for j in range(len(matrix[0])):
			output[i] = output[i] + matrix[i][j]*rank[j]
	return output
		

def addMatrix(matrix_1, matrix_2):
	for i in range(len(matrix_1[0])):
		for j in range(len(matrix_1[0])):
			matrix_1[i][j] = matrix_1[i][j] + matrix_2[i][j]
	return matrix_1

def ConvergeCheck(matrix_1, matrix_2):
	Count = 0
	for i in range(len(matrix_1)):
		if matrix_1[i] == matrix_2[i]:
			Count = Count + 1
	if Count != 0:
		return True
	return False


def transMatrix(file_Name):
	matrix = [[0 for x in range(1962)] for x in range(1962)]

	f = open(file_Name,'r')
	lines = f.readlines()
	numberOfLinks = []
	Links = []
	f.close()

	#lines[i] for i from 0 to 6003 is no. of links on page no. i/3
	#lines[i+1] for i from 0 to 6003 is links on page no. (i-1)/3

	for i in range(5886):
		if i%3==0:	
			numberOfLinks.append(lines[i])
		if i%3==1:
			Links.append(lines[i])

	#numberOfLinks[i] is number of links on page i
	#Links[i] is links on page i
	for i in range(1962):
		for j in range(1962):
			if Links[i].find(str(j))>=0:		
				matrix[i][j] = matrix[i][j] + 1./int(numberOfLinks[i])
			else:
				matrix[i][j] = 0

	for i in range(1962):
		matrix[i][i]=0	

	matrix = transpose(matrix)
	return matrix

#matrix = transMatrix('outputNEW.txt')
#printMatrix(matrix)
