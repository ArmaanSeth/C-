#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution 
    {
    public:
    vector<int> recursion(string expression)
        {
        vector<int> ans;
        int n=0,i=0,len=expression.length();
        for(i=0;i<len;i++)
            {
            if(int(expression[i])<48)
                {
                vector<int> left,right;
                string l="",r="";
                l=expression.substr(0,i);
                r=expression.substr(i+1);
                left=recursion(l);
                right=recursion(r);
                for(int a:left)
                    {
               //     cout<<a<<" ";
                    for(int b:right)
                        {
                      //  cout<<b<<endl;
                        if(expression[i]=='+')
                            {
                            ans.push_back(a+b);
                            }
                        else if(expression[i]=='-')
                            {
                            ans.push_back(a-b);
                            }
                        else
                            {
                            ans.push_back(a*b);
                            }
                        }
                    }
                }
            }
        if(ans.empty())
            {
         //   cout<<expression<<"  ";
            ans.push_back(stoi(expression));
            }
        return ans;
        }
    vector<int> diffWaysToCompute(string expression) 
        {
        vector<int> ans=recursion(expression);
        return ans;
        }
    };
int main()
    {
    system("cls");
    Solution obj;
    string str="11";
    vector<int> ans=obj.diffWaysToCompute(str);
    cout<<endl;
    for(int i=0;i<ans.size();i++)
        {
           cout<<ans[i]<<" ";
        }
    return 0;
    }