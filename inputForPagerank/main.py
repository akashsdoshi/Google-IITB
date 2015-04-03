from Links import number_links
from Links import linksOnPage

f = open("outputFinal.txt","r")
#fwrite = open("ranks.txt","w")
content = f.read()
links = content.split()
listLinks = []
for i in range(len(links)):
	if links[i].find("pdf")<0 and links[i].find("jpg") and links[i].find("png")<0 and links[i].find('jpeg')<0 and links[i].find('JPG')<0 and links[i].find('login')<0 and links[i]!='http://placements.iitb.ac.in/blog' and links[i].find('casde')<0 and links[i].find('http://www.csre.iitb.ac.in/')<0 and links[i].find('www.met.iitb.ac.in')<0:	
		try:
			n = number_links(links[i],links)		
			#fwrite.write(str(n) + '\n')
			#print n
			linksOnPage(links[i],listLinks,links)
		except:
			#fwrite.write('Error' + '\n')
			#print "Error"
			n ='0' 
	else:
		#print "0"
		n = 0
	print n	
	for j in listLinks:
		print str(j) + ' ',	
	print '\n'	
	listLinks = []
f.close()
#fwrite.close()

