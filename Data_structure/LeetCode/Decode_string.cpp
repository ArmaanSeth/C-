#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;    
class Solution {
public:
string rec(string s)
    {
    if(s.length()==0)
        {
        return s;
        }
    string str,temp=s;
    if(s[0]>='a')
        {
        str+=s[0];
        temp.erase(temp.begin());
        str+=rec(temp);
        }
    else if(s[0]=='[')
        {
        temp.erase(temp.begin());
        str=rec(temp);
        }
    else if(s[0]<='9')
        {
        int i=0,n=0;
        while(s[i]<='9')
            {
            n=(int)s[i]-48+n*10;
            temp.erase(temp.begin());
            i++;
            }
        str=rec(temp);
        string t=str;
        i=1;
        while(i<n)
            {
            str+=t;
            i++;
            }
        i=0;
        temp.erase(temp.begin());
        while(i>=0)
            {
            if(temp[0]=='[')
                {
                i++;
                }
            if(temp[0]==']')
                {
                i--;
                }
            temp.erase(temp.begin());
            }
        str+=rec(temp);
        }
    return str;
    }
string decodeString(string s) 
    {
    return rec(s);    
    }
};
int main()
    {
    system("cls");
    Solution obj;
    string s=obj.decodeString("3[z]2[2[y]pq4[2[jk]e1[f]]]ef");
    cout<<s;
    return 0;
    }