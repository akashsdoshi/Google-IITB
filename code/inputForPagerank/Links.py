import re
import sys
import urllib
import urlparse
from bs4 import BeautifulSoup
from Find import Find
#from Find import findInList

def number_links(url,links): 
	page = urllib.urlopen(url)
	text = page.read()
 	soup = BeautifulSoup(text)
	number = 0
 
	for tag in soup.findAll('a', href=True):
		if tag['href'].find('http')<0:				
			tag['href'] = urlparse.urljoin(url, tag['href'])
		if tag['href'].find('#')<0 and tag['href'].find('iitb.ac.in')>=0 and tag['href']!=url and tag['href'].find('mailto')<0 and tag['href'].find('javascript:')<0:
			if tag['href'] in links:
				number = number + 1

	page.close()
	return number


#returns list of links on a page
def linksOnPage(url,listLinks,links):
	page = urllib.urlopen(url)
	text = page.read()
 	soup = BeautifulSoup(text)
 
	for tag in soup.findAll('a', href=True):
		if tag['href'].find('http')<0:				
			tag['href'] = urlparse.urljoin(url, tag['href'])
		if tag['href'].find('#')<0 and tag['href'].find('iitb.ac.in')>=0 and tag['href']!=url and tag['href'].find('mailto')<0 and tag['href'].find('javascript:')<0:
			for x in range(len(links)):
				if tag['href'] == links[x]:
					listLinks.append(x)

	page.close()
	return listLinks
