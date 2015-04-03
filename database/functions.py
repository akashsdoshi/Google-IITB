from Find import Find
import cPickle as pickle
import dropbox

hash_table = {}
weightOfKeys = {}

def urlsAndKeys(file_name, listKeys):
	f = open(file_name,"r")	#file_name is the file that has the ngrams
	keys = f.readlines()
	f.close()
	#listKeys = []
	url = []
	urlForKey = {}
	for i in range(len(keys)):
		url_start = keys[i].find("http")
		url_end = keys[i].find(" ",url_start+1)
		url.append(keys[i][url_start : url_end])
	for i in range(len(keys)):
		keys[i] = keys[i].split()
	for i in range(len(keys)):
		for j in range(len(keys[i])):
			if Find(listKeys, keys[i][j]) == 0:
				listKeys.append(keys[i][j])
			if keys[i][j] in urlForKey:
				urlForKey[keys[i][j]].append(url[i])
			else:
				urlForKey[keys[i][j]] = [url[i]]
#	for key in listKeys:
#		print key
#		for j in range(len(urlForKey[key])):
#			print urlForKey[key][j],
#		print ""
	return urlForKey


def hashFunc(key):
	hashout = 0
	for i in range(len(key)):
		hashout = hashout + ord(key[i])
	return hashout


def hashTable(file_name):
	#hash_table = {}
	listKeys = []
	table = urlsAndKeys(file_name, listKeys)
	for key in listKeys:
		hashkey = hashFunc(key)
		if hashkey in hash_table:
			hash_table[hashkey].append([key] + table[key])
		else:
			hash_table[hashkey] = [[key] + table[key]]
	with open('data.p', 'wb') as fp:
		pickle.dump(hash_table, fp)
	return hash_table
	
	
def uploadhashTableToCloud(code):
	client = dropbox.client.DropboxClient(code)
	f = open('data.p', 'rb')
	response = client.put_file('data.p', f)
	print 'uploaded: ', response
	

