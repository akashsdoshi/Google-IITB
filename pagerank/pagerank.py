from google_matrix import googleMat
from matrix import MultiplyByMatrix
from matrix import ConvergeCheck
from matrix import magnitude
from matrix import MultiplyByScalarCol

def page_Rank(file_Name):
	rank = [1./1962 for x in range(1962)]
	matrix = googleMat(0.85, file_Name)
	while True:
	#for i in range(50):
		temp = rank	
		rank = MultiplyByMatrix(matrix, rank)
		rank = MultiplyByScalarCol(rank,1./magnitude(rank))
		if ConvergeCheck(rank, temp) == True:
			break
	return rank

def printRanks(ranks):
	for i in range(len(ranks)):
		print ranks[i]
	return
	
