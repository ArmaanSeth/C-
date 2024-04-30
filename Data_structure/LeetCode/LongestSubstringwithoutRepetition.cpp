#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    void update(vector<char> &k,char n,map<char,int> &m)
        {
        while(k[0]!=n)
            {
            m[k[0]]=0;
            k.erase(k.begin());
            }
        k.erase(k.begin());
        }
    int lengthOfLongestSubstring(string s) 
    {
    if(s.length()==0)
        {
        return 0;
        }
    map<char,int> m;
    vector<char> k;
    int b=0,e,max=0;
    for(int i=0;i<s.length();i++)
        {
        if(m[s[i]]==0)
            {
            m[s[i]]=1;
            k.push_back(s[i]);
            }
        else
            {
            if(max<k.size())
                {
                max=k.size();
                }
            update(k,s[i],m);
            k.push_back(s[i]);
            }
        }
    if(max<k.size())
        {
        max=k.size();
        }
    return max;
    }
};
int main()
    {
    system("cls");
    Solution obj;
    int i=obj.lengthOfLongestSubstring("abba");
    cout<<i;
    return 0;
    }