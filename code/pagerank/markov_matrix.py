from matrix import transMatrix
from matrix import transpose

def markovMat(file_Name):
	matrix = transMatrix(file_Name)
	#matrix = transpose(matrix)
	Count = 0 	
	for i in range(len(matrix[0])):
		for j in range(len(matrix[0])):
			if matrix[j][i]==0:
				Count = Count + 1
		if Count == len(matrix[i]):
			matrix[j][i] = 1./len(matrix[0])	
		Count = 0
	#matrix = transpose(matrix)
	return matrix
