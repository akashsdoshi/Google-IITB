
#include "google.h"


void LoadMyImage(void);

HANDLE hBitmap;
HWND hsti;

// The Window Procedure function
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    // Reading the event messages
    switch(msg)
    {

        case WM_CTLCOLOREDIT:                //for setting textbox input color

        SetBkMode((HDC)wParam, TRANSPARENT);
        SetTextColor((HDC)wParam, RGB(255,0,0)); //setting color
        break;

        case WM_CREATE:

        {
            // for loading background
            LoadMyImage();
            hsti = CreateWindowW(L"static",L"",WS_CHILD | WS_VISIBLE | SS_BITMAP,0, 0, 1080, 720,hwnd, (HMENU) 1, NULL, NULL);
            SendMessage(hsti, STM_SETIMAGE,(WPARAM) IMAGE_BITMAP, (LPARAM) hBitmap);
            // creating title box
            Title = CreateWindowEx(NULL,"STATIC","Google @ IITB At Your Service",WS_CHILD | WS_VISIBLE,440,10,200,30,hwnd,NULL,NULL,NULL);
            // creating text input field
            TextInput = CreateWindowEx(NULL,"EDIT","",WS_BORDER | WS_CHILD |WS_VISIBLE , 340 ,50,400,30,hwnd,NULL,NULL,NULL);
            // creating search button
            Search   = CreateWindowEx(NULL,"BUTTON","Search", WS_BORDER | WS_CHILD |WS_VISIBLE , 490 ,90,100,30,hwnd,(HMENU)SEARCH,NULL,NULL);
        }

        break;

        case WM_COMMAND:

        {

            switch(wParam) // values of buttons are passed in wParam through messages
            {

                case SEARCH:  // defined as 1000
                {
                    SpellChecker ob;
                    if(cnt != 0 || non_ex == 1)
                    {
                        cleaning(hwnd,non_ex);
                        hsti = CreateWindowW(L"static",L"",WS_CHILD | WS_VISIBLE | SS_BITMAP,0, 0, 1080, 720,hwnd, (HMENU) 1, NULL, NULL);
                        SendMessage(hsti, STM_SETIMAGE,(WPARAM) IMAGE_BITMAP, (LPARAM) hBitmap);
                    }
                    else
                    {
                        ob.load(DICTIONARY);
                        ifstream infile("test.txt");
                        ifstream infile1("page_ranks.txt");
                        if(infile == NULL)
                        {
                            cout << "Could not open file";
                            return 1;
                        }
                        for(int i = 0; i < 100; i++)
                        {
                            hash_t[i] = new node();
                            hash_title[i] = new node();
                        }
                        for(int i = 0; i < 1962; i++)
                        {
                            infile1 >> page_rank[i];
                            title[i] = "";
                        }
                        for(int i = 0;i <1961;)
                        {
                            string tmp;
                            infile >> tmp;
                            if((tmp.substr(0,4).compare("http")==0)||(tmp.substr(0,6).compare("mailto")==0))
                            {
                                arr[i] = tmp;
                                i++;
                            }
                            else
                            title[i-1].append(tmp.append(" "));
                        }
                        for(int i = 0; i < 1962;i++)
                        {
                            if((title[i].compare("") != 0))
                            helpinsert(title[i],i,hash_title);
                            string tmp = " ";
                            string ar[10] = {"https:","http:","www1.","www.","iitb.ac.in",".com","/en/","www2.",".php",".jsp"};
                            for(int k = 0; k < 10; k++)
                            {
                                if(tmp.compare(" ") == 0)
                                tmp = arr[i];
                                int a = tmp.length();
                                int b = ar[k].length();
                                for(int j = 0;j <= a-b;j++)
                                {
                                    if(tmp.substr(j,ar[k].length()).compare(ar[k])==0)
                                    {
                                        tmp = tmp.replace(j,ar[k].length()," ");
                                        break;
                                    }
                                }
                            }
                            for(int i = 0; i < tmp.length();i++)
                            {
                                if(!isalpha(tmp[i]) && !(tmp[i]>=48 && tmp[i]<=57))
                                tmp.replace(i,1," ");
                            }
                            helpinsert(tmp,i,hash_t);
                        }

                    }
                    int gwtstat =0;
                    gwtstat = GetWindowText(TextInput,&Searchinput[0],90);
                    string search;
                    search = Searchinput;
                    tmp_search = search;
                    for(int i = 0;i < search.length();)
                    {
                        search[i] = tolower(search[i]);
                        if(search[i] >= 48 && search[i] <= 57)
                        search.replace(i,1,"");
                        else if(!isalpha(search[i]) && search[i] != ' ')
                        {
                            search.replace(i,1,"");
                            tmp_search.replace(i,1,"");
                        }
                        else
                        i++;
                    }
                    string buf;
                    stringstream ss(search);
                    bool ck1 = true;
                    while (ss >> buf)
                    {
                        if(buf.length() > 0)
                        {
                            tokens.push_back(buf);
                            string ck = ob.checker(buf);
                            node* f1 = finding(buf,hash_t);
                            node* f2 = finding(buf,hash_title);
                            if((ck.compare(buf) == 0 || (f1 != 0||f2 != 0)))
                            t_check.push_back(buf);
                            else if(ck.compare("")!= 0)
                            {
                                t_check.push_back(ck);
                                ck1 = false;
                            }
                        }
                    }
                    if(!ck1)
                    {
                        string changedWord;
                        for(int i=0; i<t_check.size(); i++)
                        {
                            changedWord = changedWord.append(t_check[i].append(" "));
                        }
                        QueryAlt = CreateWindowEx(NULL,"STATIC"," Do you want to search for ",WS_CHILD | WS_VISIBLE,350,130,180,30,hwnd,NULL,NULL,NULL);
                        QueryWord = CreateWindowEx(NULL,"STATIC",changedWord.c_str(),WS_CHILD | WS_VISIBLE,530,130,200,30,hwnd,(HMENU) alter,NULL,NULL);
                        QueryAnsY = CreateWindowEx(NULL,"BUTTON","Yes",BS_DEFPUSHBUTTON | WS_CHILD | WS_BORDER | WS_VISIBLE,500,170,35,30,hwnd,(HMENU) AY,NULL,NULL);
                        QueryAnsN = CreateWindowEx(NULL,"BUTTON","No",BS_DEFPUSHBUTTON | WS_CHILD | WS_BORDER | WS_VISIBLE,545,170,35,30,hwnd,(HMENU) AN,NULL,NULL);
                    }
                    else
                    {
                        SendMessage(hwnd,msg,AD,lParam);
                    }
                }

                break;

                // checking whether to search for alternate keyword
                case AY:
                tokens = t_check;
                // pseudo default case for a keyword
                case AD:
                // checking whether to search for alternate keyword
                case AN:
                {
                    // removing unnecessary buttons and statics
                    DestroyWindow(QueryAlt);
                    DestroyWindow(QueryWord);
                    DestroyWindow(QueryAnsY);
                    DestroyWindow(QueryAnsN);
                    //Updating the window
                    UpdateWindow(hwnd);
                    string changedWord;
                    for(int i=0; i<tokens.size(); i++)
                    {
                        changedWord = changedWord.append(tokens[i]);
                    }
                    for(int i = 0,j = 0;i < changedWord.length();i++,j++)
                    {
                        if(tmp_search[j] >= 48 && tmp_search[j] <= 57)
                        i--;
                        else if(tmp_search[j] != changedWord[i])
                        {
                            if(tmp_search[i] != ' ')
                            {
                                stringstream tm;
                                tm << changedWord[i];
                                string tm1;
                                tm >> tm1;
                                tmp_search.replace(j,1,tm1);
                            }
                            else
                            i--;
                        }
                    }
                    changedWord = tmp_search;
                    // Displaying the current search
                    QueryAlt = CreateWindowEx(NULL,"STATIC","  Searching for ",WS_CHILD | WS_VISIBLE,400,130,100,30,hwnd,NULL,NULL,NULL);
                    QueryWord = CreateWindowEx(NULL,"STATIC",changedWord.c_str(),WS_CHILD | WS_VISIBLE,500,130,200,30,hwnd,(HMENU) alter,NULL,NULL);
                    tokens.erase(tokens.begin(),tokens.end());
                    stringstream tm(changedWord);
                    string tm1;
                    while(tm >> tm1)
                    tokens.push_back(tm1);
                    for(int i = 0; i < tokens.size();i++)
                    {
                        string ins = tokens.at(i);
                        v2.push_back(ins);
                        count++;
                        for(int j = i+1; j < tokens.size();j++)
                        {
                            ins.append(tokens.at(j));
                            v2.push_back(ins);
                            count++;
                        }
                    }
                    bool chk = false;
                    int chk_count = 0;
                    bool offload1 = false;
                    for(int i = 0; i < count;i++)
                    {
                        chk = helpfind(v2.at(i),offload1);
                        if(chk)chk_count++;
                        if(chk_count >= 1)
                        chk = true;
                    }
                    bool chk2 = false;
                    chk_count = 0;
                    for(int i = 0; i < count; i++)
                    {
                        string tmp = v2[i];
                        for(int j = 2; j < tmp.length();j++)
                        {
                            if(i == count-1 && j == tmp.length()-1)
                            offload1 = true;
                            chk2 = helpfind(tmp.substr(0,j+1),offload1);
                            if(chk2)chk_count++;
                            if(chk_count >= 1)
                            chk2 = true;
                        }
                    }

                    // Redirecting to google if not found
                    if((!chk2 && !chk) || (cnt == 0))
                    {
                        non_ex = 1;
                        Redirect = CreateWindowEx(NULL,"STATIC","Sorry!!Not in Google@IITB Domain!Redirecting to Google...",WS_CHILD | WS_VISIBLE,380,130,390,30,hwnd,NULL,NULL,NULL);
                        string web = "https://www.google.co.in/search?q=iitb+";
                        string changedWord1;
                        for(int i=0; i<tokens.size(); i++)
                        {
                            changedWord1 = changedWord1.append(tokens[i]);
                        }
                        web.append(changedWord1);
                        for(int i = 0; i < 1000000; i++);
                        ShellExecute(NULL,"open",web.c_str(),NULL,NULL,SW_SHOWNORMAL);
                    }
                    // Displaying the first 10 results
                    else{
                    stringstream ccnt;
                    ccnt << cnt;
                    string str;
                    ccnt >> str;
                    No_of_searches = CreateWindowEx(NULL,"STATIC"," No of results found : ",WS_CHILD | WS_VISIBLE,400,165,150,30,hwnd,NULL,NULL,NULL);
                    TheNum = CreateWindowEx(NULL,"STATIC",str.c_str(),WS_CHILD | WS_VISIBLE,550,165,100,30,hwnd,NULL,NULL,NULL);
                    int d = (cnt < 10)?cnt:10;
                    for(int i = page; i < d; i++)
                    Button[i] = CreateWindowEx(NULL,"BUTTON",arr[v1.at(i)].c_str(),BS_DEFPUSHBUTTON | WS_VISIBLE | WS_BORDER | WS_CHILD,100,210 + (40*i),880,30,hwnd,(HMENU) (i),NULL,NULL);
                    if(cnt >= 10){
                    Next01 = CreateWindowEx(NULL,"BUTTON","NEXT",BS_DEFPUSHBUTTON | WS_VISIBLE | WS_BORDER | WS_CHILD,690,610,80,30,hwnd,(HMENU) Next,NULL,NULL);
                    Prev01 = CreateWindowEx(NULL,"BUTTON","PREV",BS_DEFPUSHBUTTON | WS_VISIBLE | WS_BORDER | WS_CHILD,600,610,80,30,hwnd,(HMENU) Prev,NULL,NULL);}
                    stringstream ccn;
                    string st;
                    ccn << ((page/10) + 1);
                    ccn >> st;
                    PageNo = CreateWindowEx(NULL,"STATIC",st.c_str(),WS_CHILD | WS_VISIBLE,1000,640,80,80,hwnd,NULL,NULL,NULL);
                }
                }
                break;

            }

            // opening the page that user has selected
            for(int m = 0; m < cnt ;m++)
            {
                if(wParam == m)
                openwebpage(m);
            }
            // for showing the next 10 results
            if (wParam == Next)
            {
                // Destroying prev results
                if(PrevEnd != NULL)
                DestroyWindow(PrevEnd);
                for(int i =page ; i < (((page + 10)<cnt)?page+10:cnt); i++)
                {
                    DestroyWindow(Button[i]);
                }
                DestroyWindow(PageNo);
                UpdateWindow(hwnd);
                // displaying next 10 results
                page = page + 10;
                stringstream cc;
                string s;
                cc << ((int)(page/10) + 1);
                cc >> s;
                PageNo = CreateWindowEx(NULL,"STATIC",s.c_str(),WS_CHILD | WS_VISIBLE,1000,640,80,80,hwnd,NULL,NULL,NULL);
                for(int i = page; i < (((page + 10)<cnt)?page+10:cnt); i++)
                Button[i] = CreateWindowEx(NULL,"BUTTON",arr[v1.at(i)].c_str(),BS_DEFPUSHBUTTON | WS_VISIBLE | WS_BORDER | WS_CHILD,100,210 + (40*(i-page) ),880,30,hwnd,(HMENU) ((i)),NULL,NULL);
                UpdateWindow(hwnd);
            }
            if (wParam == Prev)
            {
                // Destroying prev results
                for(int i =page; i <page + 10; i++)
                {
                    DestroyWindow(Button[i]);
                }
                DestroyWindow(PageNo);
                UpdateWindow(hwnd);
                // displaying next 10 results
                if (page != 0) // checking if the user does go beyond 0
                {
                    page = page - 10;
                    stringstream ccn;
                    string st;
                    ccn << ((int)(page/10) + 1);
                    ccn >> st;
                    PageNo = CreateWindowEx(NULL,"STATIC",st.c_str(),WS_CHILD | WS_VISIBLE,1000,640,80,80,hwnd,NULL,NULL,NULL);
                    for(int i = page; i < page + 10; i++)
                    Button[i] = CreateWindowEx(NULL,"BUTTON",arr[v1.at(i)].c_str(),BS_DEFPUSHBUTTON | WS_VISIBLE | WS_BORDER | WS_CHILD,100,210 + (40*(i-page) ),880,30,hwnd,(HMENU) (i),NULL,NULL);
                }
                else
                PrevEnd = CreateWindowEx(NULL,"STATIC","Please press next for results ",WS_CHILD | WS_VISIBLE,390,360,300,30,hwnd,NULL,NULL,NULL);
                UpdateWindow(hwnd);
            }
        }
        break;

        case WM_CLOSE:
        // deleting objects creating before closing
        cleaning(hwnd,non_ex);
        DestroyWindow(hwnd);
        break;

        case WM_DESTROY:
            PostQuitMessage(0);
        break;

        default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEX wc; //creating a window class
    HWND hwnd; // creating handle to our main(parent) window
    MSG Msg; // messages generated are stored in Msg

    //Registering the Window Class

    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL,IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

    // Checking if window class is registered or not
    if(!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "Window Registration Failed!", "Error!",MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // Creating the Main Window
    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,                               // extended window style
        g_szClassName,                                  // class name
        "Google @ IITB",                                // window title
        WS_OVERLAPPEDWINDOW,  // window styles
        0,0, 1080, 720,         // position and dimensions of window
        NULL, NULL, hInstance, NULL);                   // other parameters

    // Checking if window is created or not
    if(hwnd == NULL)
    {
        MessageBox(NULL, "Window Creation Failed!", "Error!",MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // displaying the window
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // The Message Loop
    while(GetMessage(&Msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }

    return Msg.wParam;

}

// opens the web page
void openwebpage(int a)
{
     ShellExecute(NULL,"OPEN",arr[v1.at(a)].c_str(),NULL,NULL,SW_SHOWNORMAL);
}


void helpinsert(string t,int index,node** hash_t)
{
    insert(t,index,hash_t);
    string buf;
    stringstream ss(t);
    while (ss >> buf)
    insert(buf,index,hash_t);
}
int ret_ascii(string tmp)
{
    int val = 0;
    for(int j = 0;j < tmp.length();j++)
    {
        if(isalpha(tmp[j]))
        val += (int)tmp[j];
    }
    val %= 100;
    return val;
}

node* finding(string search,node** hash_t)
{
    for(int i = 0; i < search.length();)
    {
        if(search[i] == ' ')
        {
            search.replace(i,1,"");
            continue;
        }
        i++;
    }
    int value = ret_ascii(search);
    node* counter;
    counter = hash_t[value];
    if(counter != 0)
    {
        while(counter != 0)
        {
            if(counter->key.compare(search) == 0)
            break;
            else
            counter = counter->next;
        }
    }
    return counter;
}

void openpage(int website,bool offload)
{
    if(website != 1963)
    {
        bool wchk = true;
        for(int i = 0; i < cnt; i++)
        {
            if(website == v1[i])
            {
                wchk = false;
                break;
            }
        }
        if(wchk)
        {
            v1.push_back(website);
            cnt++;
        }
    }
    if(offload && website == 1963 && v1.size()>0)
    {
        vector <string> v2;
        quickSort(v1,0,v1.size()-1);
    }
}

bool helpfind(string search,bool offload1)
{
    node* t1 = finding(search,hash_t);
    node* t2 = finding(search,hash_title);
    bool offload;
    if(t1 != 0)
    {
        for(int i = 1;i < (t1->vn).size();i++)
        {
            offload = false;
            openpage((t1->vn).at(i),offload);
        }
    }
    if(t2 != 0)
    {
        for(int i = 0;i < (t2->vn).size();i++)
        {
            offload = false;
            openpage((t2->vn).at(i),offload);
        }
    }
    if(offload1)
    openpage(1963,offload1);
    if(t1 == 0 && t2 == 0)
    return false;
    return true;
}

void quickSort(vector <int> &v1, int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = v1[(left + right) / 2];

      /* partition */
      while (i <= j) {
            while (page_rank[v1[i]] > page_rank[pivot])
                  i++;
            while (page_rank[v1[j]] < page_rank[pivot])
                  j--;
            if (i <= j) {
                  tmp = v1[i];
                  v1[i] = v1[j];
                  v1[j] = tmp;
                  i++;
                  j--;
            }
      };

      /* recursion */
      if (left < j)
            quickSort(v1, left, j);
      if (i < right)
            quickSort(v1, i, right);
}

void insert(string t,int index,node** hash_t)
{
    int b = t.length();
    for(int j = b-1; (j >= 2);j--)
    {
        string tmp = t.substr(0,j+1);
        for(int i = 0; i < tmp.length();i++)
        tmp[i] = tolower(tmp[i]);
        node* find = finding(tmp,hash_t);
        if(find != 0)
        (find->vn).push_back(index);
        else{
        for(int i = 0; i < tmp.length();i++)
        tmp[i] = tolower(tmp[i]);
        int value = ret_ascii(tmp);
        node* counter;
        counter = hash_t[value];
        if(hash_t[value]->key == " ")
        {
            hash_t[value]->key = tmp;
            (hash_t[value]->vn).push_back(index);
        }
        else
        {
            if(counter != 0)
            {
                while(counter->next != 0)
                counter = counter->next;
            }
            counter->next = new node;
            counter = counter->next;
            counter->next = 0;
            counter->key = tmp;
            (counter->vn).push_back(index);
        }}
    }
}

void deleting(node** hash_t)
{
    node* counter = hash_t[0];
    for(int i = 0;i < 1962;i++)
    {
        counter = hash_t[i];
        while(counter != 0)
        {
            node* prev = counter;
            counter = counter->next;
            delete(prev);
        }
    }
}

void cleaning(HWND hwnd,int non_e)
{
    if(non_e == 0){
    for(int i = 0; i < cnt;i++)
    DestroyWindow(Button[i]);
    if(cnt >= 10){
    DestroyWindow(QueryAlt);
    DestroyWindow(QueryWord);
    DestroyWindow(QueryAnsY);
    DestroyWindow(QueryAnsN);
    DestroyWindow(Prev01);
    DestroyWindow(Next01);
    DestroyWindow(No_of_searches);
    DestroyWindow(TheNum);}
    }
    else
    DestroyWindow(Redirect);
    DestroyWindow(hsti);
    UpdateWindow(hwnd);
    v2.erase(v2.begin(),v2.end());
    v1.erase(v1.begin(),v1.end());
    tokens.erase(tokens.begin(),tokens.end());
    t_check.erase(t_check.begin(),t_check.end());
    count = 0;
    cnt = 0;
    page = 0;
    non_ex = 0;
    tmp_search = "";

}

void LoadMyImage(void) {

    hBitmap = LoadImage(NULL,g_szFilename , IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}
