#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
    vector<int> ans;
    map<char,int> m,c;
    int counter1=0;
    for(int i=0;i<p.length();i++)
        {
        c[p[i]]+=1;
        m[p[i]]=int(p[i]);
        counter1+=int(p[i]);
        }
    bool flag=false;
    char str[1];
    for(int i=0;i<s.length();i++)
        {
        int j=i;
        int k=0;
        int counter2=0;
        if(flag==true)
            {
            if(m[s[i+p.length()-1]]==0)
                {
                i=i+p.length()-1;
                flag=false;
                }
            else if(s[i+p.length()-1]==str[0])
                {
                ans.push_back(i);
                str[0]=s[i];
                }
            else
                {
                flag=false;
                }
            continue;
            }
        map<char,int> c_track;
        while(k<p.length() && j<s.length())
            {
            if(m[s[j]]==0 || c_track[s[j]]>c[s[j]])
                {
                break;
                }
            c_track[s[j]]+=1;
            counter2+=m[s[j]];
            j++;
            k++;
            }
        if(counter1==counter2)
            {
            ans.push_back(i);
            str[0]=s[i];
            flag=true;
            }
        else
            {
            flag=false;
            }
        }
    return ans;
    }
};
int main()
    {
    system("cls");
    Solution obj;
    string s="bbb",p="abc";//s="cbaebabacd",p="abc";
    vector<int> ans=obj.findAnagrams(s,p);
    cout<<endl;
    for(int i=0;i<ans.size();i++)
        {
        cout<<ans[i]<<" ";
        }
    return 0;
    }