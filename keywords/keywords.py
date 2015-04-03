#first input

page = open("final_list.txt","r")
lines = page.readlines()
url = []
#f = open("title.txt"."r")
#content = f.read()
#url = content.split()
f = open("truncFinal.txt","w")
#for i in range(len(lines)):
#	url_start = lines[i].find("http")
#	url_end = lines[i].find(" ",url_start+1)
#	url.append(lines[i][url_start : url_end])
#	start = lines[i].find(" ")	
#	lines[i] = lines[i].replace("<title>"," ")
#	lines[i] = lines[i].replace("</title>","")
#	lines[i] = lines[i].replace("\n","")
#	lines[i] = lines[i].replace("|","")
#	lines[i] = lines[i].replace("-","")
#	lines[i] = lines[i].replace("::","")
#	lines[i] = lines[i].replace(",","")
	#lines[i] = lines[i].replace("?","")
#	f.write(lines[i] + '\n')
	
page.close()

for i in range(len(lines)):
	url_start = lines[i].find("http")
	url_end = lines[i].find(" ",url_start+1)
	url.append(lines[i][url_start : url_end])
	lines[i] = lines[i].replace("http://","")
	lines[i] = lines[i].replace("www.","")
	lines[i] = lines[i].replace("www1.","")
	lines[i] = lines[i].replace("www2.","")
	lines[i] = lines[i].replace(".ac.in"," ")
	lines[i] = lines[i].replace("/"," ")
	lines[i] = lines[i].replace(".jsp"," ")
	lines[i] = lines[i].replace(".jpg"," ")
	lines[i] = lines[i].replace(".jpeg"," ")
	lines[i] = lines[i].replace(".png"," ")
	lines[i] = lines[i].replace(".JPG"," ")
	lines[i] = lines[i].replace("."," ")
	lines[i] = lines[i].replace("~"," ")
	lines[i] = lines[i].replace("_"," ")
	lines[i] = lines[i].replace("https:","")
	f.write(url[i] +' ' +  lines[i].lower() )

f.close()



