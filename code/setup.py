import sys
import os

X = raw_input("This will install pip and beautiful soup 4. Do you want to continue (Y/N): ")
if X.lower() == "y":
    os.system("wget https://bootstrap.pypa.io/get-pip.py")
    os.system("python get-pip.py")
    os.system("pip install beautifulsoup4")
