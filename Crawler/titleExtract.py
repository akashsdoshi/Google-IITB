import urllib
from bs4 import BeautifulSoup

page = open("useForTitle.txt","r")
lines = page.read()
links = lines.split()
f = open("title.txt","w")
#j=0

#notWorking = ['http://csist.hss.iitb.ac.in','http://www1.ir.iitb.ac.in/','http://drona.iitb.ac.in','http://www2.iitb.ac.in:8080/placement/']

for i in range(len(links)):
	try:	
		if links[i].find('pdf')<0 and links[i].find('jpg')<0 and links[i].find('jpeg')<0 and links[i].find('JPG')<0 and links[i].find('png')<0 and links[i].find('login')<0 and links[i]!='http://placements.iitb.ac.in/blog' and links[i].find('casde')<0 and links[i].find('http://www.csre.iitb.ac.in/')<0 and links[i].find('www.met.iitb.ac.in')<0:		
			page = urllib.urlopen(links[i]).read()
			obj = BeautifulSoup(page)
			for j in obj.findAll('title'):
				f.write(links[i] + ' ' + str(j) + '\n')
		else:
			f.write(links[i] + '\n')
	except:
		f.write(links[i] + '\n')		
		continue
f.close()

