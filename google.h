#ifndef GOOGLE_H
#define GOOGLE_H
#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string.h>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <cctype>
#include "Dictionary.h"
#include <stdlib.h>
#include <tchar.h>
#include <simplecpp>
#define DICTIONARY "large.txt"

#define SEARCH 2000
#define Prev 2001
#define Next 2002
#define AY 2003
#define AN 2004
#define AD 2005
#define alter 2006

using namespace std;
struct node
{
    string key;
    node* next;
    vector<int> vn;
    node()
    {
       key = " ";
       next = 0;
    }
};

int non_ex = 0;

const char g_szFilename[] = "Background.bmp";

const char g_szClassName[] = "Google @IITB";

char Searchinput[90] ;

HWND Title;

HWND Search;

HWND Prev01;

HWND Next01;

HWND PrevEnd;

HWND TextInput;

HWND QueryAlt;

HWND QueryWord;

HWND QueryAnsN;

HWND QueryAnsY;

HWND No_of_searches;

HWND TheNum;

HWND Redirect;

HWND PageNo;

HWND* Button = new HWND[10];

int page = 0;

int count = 0;

vector<string> tokens;

vector<string> t_check;

vector<string> v2;

vector<int> vct1;

vector <int> vct2;

string tmp_search;

string arr[1962];

string title[1962];

double page_rank[1962];

static node* hash_t[100];

static node* hash_title[100];

static int cnt = 0;

vector<int> v1;

void helpinsert(string tmp,int index,node** hash_t);//breaks up the string to be inserted into words and then sends it to insert

void insert(string tmp,int index,node** hash_t);//inserts the string along with its corresponding website index into the hash table

node* finding(string search,node** hash_t);//Performs a typical hash search on the string passed in the passed hash table

int ret_ascii(string tmp);//Computes the sum % 100 of the ASCII values of the characters of the string passed to it

void openpage(string website,bool offload);//pushes website onto stack only if not present and at the end sorts them calling QuickSort

void openwebpage(int a);//Opens the webpage cooresponding to the clicked button

bool helpfind(string search,bool offload1);//Performs preliminary vhecks on a string before it is searched for

void quickSort(vector <int> &v1, int left, int right); //To sort large number of page ranks

void deleting(node** hash_t);

void cleaning(HWND hwnd,int non_ex);

#endif // GOOGLE_H
