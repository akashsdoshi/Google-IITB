import cPickle as pickle
from functions import hashFunc

def getUrls(url_file_name):
	url = []
	keys = open(url_file_name, "r").readlines()
	for i in range(len(keys)):
		url_start = keys[i].find("http")
		url_end = keys[i].find(" ",url_start+1)
		url.append(keys[i][url_start : url_end])
	return url

def ranksTable(ranks_file_name, url_file_name):
	table = {}
	f = open(ranks_file_name, "r")
	ranks = f.readlines()
	urlList = getUrls(url_file_name)
	for i in range(len(urlList)):
		hashkey = hashFunc(urlList[i])
		if hashkey in table:
			table[hashkey].append([urlList[i], ranks[i]])
		else:
			table[hashkey] = [[urlList[i], ranks[i]]]
	return table
	
def writeTofile(table):
	with open("pageranks.p","wb") as fp:
		pickle.dump(table, fp)
		 
		
#main_program

table = ranksTable("ranks.txt", "finalListToUse.txt")
writeTofile(table)
	
