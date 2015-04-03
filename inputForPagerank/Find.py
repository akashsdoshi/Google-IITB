#find in listLinks

def Find(listLinks, url):
	for i in range(len(listLinks)):
		if url==listLinks[i]:
			return True
	return False

#returns index of url in the list of links
#def findInList(links,url):
#	for i in range(len(links)):
#		if url == links[i]:
#			return i
#	return -1
