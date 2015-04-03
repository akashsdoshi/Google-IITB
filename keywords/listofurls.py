#input = output of keywords.py

import re

f = open("truncFinal.txt","r")
url = []
lines = f.readlines()
for i in range(len(lines)):
	x = lines[i].find(" ")
	url.append(lines[i][ : x])
for i in range(len(lines)):
	lines[i] = lines[i].replace(url[i], "")
for i in range(len(lines)):
	lines[i] = list(re.findall('[a-z]+', lines[i].lower()))
#for i in range(len(lines)):	
#	lines[i].remove(" ")
for i in range(len(lines)):
	print url[i],
	for j in range(len(lines[i])):
		print lines[i][j],
	print ''
		
			
	
