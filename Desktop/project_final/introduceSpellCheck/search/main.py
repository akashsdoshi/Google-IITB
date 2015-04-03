from functions import SearchFinal
from functions import getData
#from functions import getCode
from functions import getRanks
from functions import spellCheck
from functions import getKeyWeights
import datetime
#from functions import *

#code = getCode()
hash_table = getData()
getRanks()
getKeyWeights()
change = False

#print hash_table
entry = raw_input("Enter search: ")
time_obj = datetime.datetime.now()
time_start = time_obj.microsecond
#result = SearchFinal(entry, hash_table)
query = entry.split()
for i in range(len(query)):
	bestword = spellCheck(query[i])
	if bestword != True:
		query[i] = bestword
		change = True

changedEntry = ""
for i in range(len(query)):
	changedEntry = changedEntry + " " + query[i]
if change == True:
	#print changedEntry search
	result = SearchFinal(changedEntry, hash_table)
	#end time
	time_end_obj = datetime.datetime.now()
	time_end = time_end_obj.microsecond
	time_sec = (time_end - time_start)/1000000.0
	if result != -1:
		for i in result:
			print i
	print "Your search took " + str(time_sec) + " seconds to execute"
	print "Showing result for '" + changedEntry + "'"
	X = raw_input("Search instead for '" + entry + "' (Y/N): ")
	if X == "Y" or X == "y":
		result = SearchFinal(entry, hash_table)
	else:
		print ""
		#end the program
		#if result != -1:
		#	for i in result:
		#		print i

else:
	result = SearchFinal(entry, hash_table)
	if result != -1:
		for i in result:
			print i
	time_end_obj = datetime.datetime.now()
	time_end = time_end_obj.microsecond
	time_sec = (time_end - time_start)/1000000.0
	print "Your search took " + str(time_sec) + " seconds to execute"
	
