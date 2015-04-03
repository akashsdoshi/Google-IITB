from functions import hashTable
from functions import uploadToCloud

code = raw_input("Authorization code: ")
hashTable("NGramkeys.txt")

uploadhashTableToCloud(code)	#also upload to dropbox

