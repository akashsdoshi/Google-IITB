#input = output of listofurls.py

f = open("finalListToUse.txt","r")
keys = f.readlines()
f.close()
url = []
newkeys = [[] for w in range(len(keys))]
for i in range(len(keys)):
	url_start = keys[i].find("http")
	url_end = keys[i].find(" ",url_start+1)
	url.append(keys[i][url_start : url_end])
for i in range(len(keys)):
	keys[i] = keys[i].split()
for i in range(len(keys)):
	for j in range(1,len(keys[i])):
		for k in range(3, len(keys[i][j])+1):
			newkeys[i].append(keys[i][j][ : k])
for i in range(len(newkeys)):
	print url[i],
	for j in range(len(newkeys[i])):
		print newkeys[i][j],
	print ""
