import urllib
from bs4 import BeautifulSoup
from spiderLinks import spider_links
from spiderLinks import Find
#from findAllTitles import FindText

links = []

#notWorking = ['http://www.iitb.ac.in/en/education/academic-divisions','http://www.iitb.ac.in/en/students/information-current-students','http://www.iitb.ac.in/en/about-iit-bombay/student-affairs-office','http://www.iitb.ac.in/en/about-iit-bombay/student-hostels','http://www.iitb.ac.in/en/exchange-opportunities-iitb-students','http://www.iitb.ac.in/en/students/information-prospective-students','http://www.iitb.ac.in/en/students/information-prospective-students','http://www.iitb.ac.in/en/education/why-iitb']

spider_links('http://www.iitb.ac.in',links)
#f = open("links.txt","w")
#for i in range(len(links)):
#	f.write(links[i]+'\n')
#f.close()


#for links appearing later in the list
nextStart = 0

f = open("testLinks.txt","w")
j=1
while len(links)<10000:
	try:		
		spider_links(links[j],links)
		j=j+1	
		for i in range(nextStart,len(links)):	
			f.write(links[i]+'\n')
		nextStart = len(links)
	except:
		j=j+1
f.close()





#f = open("titles.txt","w")
#for i in range(len(links)):
#	f.write(links[i]+'\n')
#	if links[i]!='http://www1.ir.iitb.ac.in/' and links[i]!='http://drona.iitb.ac.in' and links[i].find('pdf')<0 and links[i].find('jpg')<0 #and links[i].find('jpeg')<0 and links[i].find('JPG')<0 and links[i].find('png')<0 and links[i]!='http://asc.iitb.ac.in':   #remove the asc #site later		
#		titles = FindText(links[i])
#		for j in range(len(titles)):
#			f.write(str(titles[j])+'\n')
#	f.write('\n\n\n\n')
#f.close()


