from functions import SearchFinal
from functions import getData
from functions import getCode
from functions import getRanks
from functions import spellCheck
#from functions import *

code = getCode()
hash_table = getData(code)
getRanks(code)

#print hash_table
entry = raw_input("Enter search: ")
#result = SearchFinal(entry, hash_table)
query = entry.split()
for i in range(len(query)):
	bestword = spellCheck(query[i])
	if bestword != True:
		query[i] = bestword
		change = True

changedEntry = ""
for i in range(len(query)):
	changedEntry = changedEntry + query[i]
if change == True:
	print "Showing result for '" + changedEntry + "'"
	X = raw_input("Search instead for '" + entry + "'? (Y/N): ")
	if X == "Y" or X == "y":
		result = SearchFinal(entry, hash_table)
	else:
		result = SearchFinal(changedEntry, hash_table)
	if result != -1:
		for i in result:
			print i

else:
	result = SearchFinal(entry, hash_table)
	if result != -1:
		for i in result:
			print i
