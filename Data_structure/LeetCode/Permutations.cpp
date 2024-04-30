#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
/*class Solution {
public:
int h=0;
vector<string> per(string p,string u,int k,int m)
    {
    vector<string> list;
    if(u.length()==0)
       {
        if(h==k)
            {
        return list;
            }
        h++;
        list.push_back(p);
        return list;
        }
    for(int i=m;i<u.length();i++)
        {
        string temp1,temp2;
        temp1.insert(temp1.begin(),u.begin()+i,u.begin()+i+1);
        temp2=u;
        temp2.erase(temp2.begin()+i);
        temp1=p+temp1;
        vector<string>l2=per(temp1,temp2,k,0);
        list.insert(list.end(),l2.begin(),l2.end());
        }
    return list;
    }
string getPermutation(int n, int k) 
    {
    string s;
    long m=1,x=1;
    for(int i=1;i<=n;i++)
        {
        x*=i;
        s.push_back('0'+i);
        }
    x/=n;
    while((m*x)<=k)
        {
        m++;
        }
    m--;
    int l=m*x;
    h=l;   
    vector<string> list=per("",s,k,m);
    return list[list.size()-1];
    }
};
int main()
    {
    system("cls");   
    Solution obj;
    string s;
    s=obj.getPermutation(3,3);
    for(int i=0;i<list.size();i++)
        {
        cout<<list[i]<<" ";
        }
    cout<<s;
    return 0;
    }*/
//ANOTHER APPROACH
 string per(vector<int> &fact,vector<int> &digits,int n,int k,string s)
    {
    if(k==0)
        {
        for(int i=0;i<digits.size();i++)
            {
            s.push_back('0'+digits[i]);
            }
        return s;
        }
    int i=k/(fact[n]);
    s.push_back('0'+digits[i]);
    digits.erase(digits.begin()+i);
    k-=i*fact[n];
    return per(fact,digits,n-1,k,s);
    }
string generate(int n,int k)
    {
    vector<int> fact,digits;
    int f=1;
    string s;
    for(int i=1;i<=n;i++)
        {
        f*=i;
        digits.push_back(i);
        fact.push_back(f);
        }
    return per(fact,digits,n-2,k-1,s);
    }
int main()
    {
    system("cls");
    string s=generate(3,3);
    cout<<s;
    return 0;
    }