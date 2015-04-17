import re
import sys
import urllib
import urlparse
from bs4 import BeautifulSoup

#returns all the links on url page

def Find(links, url):
	for i in range(len(links)):
		if url==links[i]:
			return True
	return False

def spider_links(url, links):  #links initialized in main program
	page = urllib.urlopen(url)
	text = page.read()
 	soup = BeautifulSoup(text)
 
	for tag in soup.findAll('a', href=True):
		if tag['href'].find('http')<0:				
			tag['href'] = urlparse.urljoin(url, tag['href'])
		if Find(links,tag['href'])==False and tag['href'].find('#')<0 and tag['href'].find('iitb.ac.in')>=0 and tag['href']!=url and tag['href'].find('mailto')<0 and tag['href'].find('javascript:')<0:
			links.append(tag['href'])

	page.close()
	return links
