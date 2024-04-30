#include<iostream>
#include<vector>
using namespace std;
class Solution 
    {
    public:
    vector<vector<string>> recursion(string s,vector<vector<int>> &dp,int pos) 
        {
        vector<vector<string>> list;
        if(s.length()<=1)
            {
            vector<string> str;
            str.push_back(s);
            list.push_back(str);
            }
        else
            {
            string temp="";
            for(int i=pos;i<s.length();i++)
                {
                temp+=s[i];
                if(dp[pos][i]==0)
                    {
                    int f=0,l=i,flag=0;
                    while(f<=l)
                        {
                        if(s[f]==s[l])
                            {
                            f++;
                            l--;
                            flag=1;
                            }
                        else
                            {
                            flag=-1;
                            break;
                            }
                        }
                    dp[pos][i]=flag;
                    }
                else if(dp[pos][i]==-1)
                    continue;
                if(dp[pos][i]==1)
                    {
                    if(i==s.length()-1)
                        {
                        vector<string> str;
                        str.push_back(temp);
                        list.push_back(str);
                        break;
                        }
                    vector<vector<string>> temp_list=recursion(s,dp,i+1);
                 /*   if(temp_list.size()>=2 && temp_list[temp_list.size()-1][0]=="")
                        {
                        temp_list.erase(temp_list.begin()+temp_list.size()-1);
                        }*/
                    for(int j=0;j<temp_list.size();j++)
                        {
                        temp_list[j].insert(temp_list[j].begin(),temp);//.begin(),temp.end());
                        }
                    list.insert(list.end(),temp_list.begin(),temp_list.end());
                    }
                }
            }
        return list;
        }
    vector<vector<string>> partition(string s) 
        {
        vector<vector<int>> dp(s.length(),vector<int>(s.length(),0));
        return recursion(s,dp,0);
        }
    };
int main()
    {
        system("cls");
        vector<vector<string>> ans;
        Solution obj;
        ans=obj.partition("aab");
        for(int i=0;i<ans.size();i++)
            {
            for(int j=0;j<ans[i].size();j++)
                {
                cout<<ans[i][j]<<" ";
                }
            cout<<endl;
            }
        return 0;
    
    }