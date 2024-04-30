#include<iostream>
#include<string>
using namespace std;
class Solution 
    {
    public:
    string longestPalindrome(string s) 
        {
        string str;
        int max=0,len=s.length();
        for(int i=0;i<len;i++)
            {
            //cout<<i<<endl;
            int l=0,n=i,m=i+1;
            string temp="";
            bool flag=false;
            while(m<len && n>=0 && s[m]==s[n])
                {
                n--;
                m++;
                flag=true;
                }
            n++;
            m--;
            if(flag==true)
                {
                l=m-n+1;
                if(max<l)
                    {
                    max=l;
                    for(int k=n;k<=m;k++)
                        {
                        temp+=s[k];
                        }
                    str=temp;
                    }
                flag=false;
                }
            n=i-1;
            m=i+1;
            while(m<len && n>=0 && s[m]==s[n])
                {
                n--;
                m++;
                flag=true;
                }
            n++;
            m--;
            if(flag==true)
                {
                l=m-n+1;
                if(max<l)
                    {
                    max=l;
                    for(int k=n;k<=m;k++)
                        {
                        temp+=s[k];
                        }
                    str=temp;
                    }
                cout<<l<<endl;
                }
            }
        if(str=="")
            str=s[0];
        return str;
        }
    };
int main()
    {
    system("cls");
    Solution obj;
    string str="babad",ans;
    ans=obj.longestPalindrome(str);
    cout<<"Main=";
    cout<<ans;
    return 0;
    }