#from matrix import transMatrix
from markov_matrix import markovMat
from matrix import printMatrix
from matrix import MultiplyByScalar
from matrix import addMatrix

def googleMat(p, file_Name):
	#googleMatrix = (1-p)*matrix + (1/2002)*p*T
	#T[i][j] = 1
	T = [[1 for x in range(1962)] for x in range(1962)]
	matrix = markovMat(file_Name)
	temp1 = MultiplyByScalar(matrix, (1-p))
	temp2 = MultiplyByScalar(T, p/1962)
	googleMatrix = addMatrix(temp1,temp2)
	return googleMatrix
