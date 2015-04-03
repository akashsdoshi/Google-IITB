import os

os.system("wget 'https://bootstrap.pypa.io/get-pip.py'")
#uid = os.getlogin()
#os.system("cd /home/" + uid + "/Downloads")
os.system("sudo python get-pip.py")
os.system("sudo pip install dropbox")
os.system("echo 'Use \"python main.py\" for running the search engine'")
