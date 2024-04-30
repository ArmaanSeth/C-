#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<string> recursion(vector<string> stringlist,string up,int pos)
        {
        vector<string> ans,temp;
        if(pos>=stringlist.size())
            {
            return ans;
            }
        string str=stringlist[pos];
        int l=str.length();
        for(int i=0;i<l;i++)
            {
            string k=up+stringlist[pos][i];
            temp=recursion(stringlist,k,pos+1);
            if(temp.size()==0)
                {
                temp.push_back(k);
                }
            ans.insert(ans.end(),temp.begin(),temp.end());
            }
        return ans;        
        }
    vector<string> letterCombinations(string digits) 
        {
        vector<string> map,possible_letters,ans;
        map.push_back("abc");
        map.push_back("def");
        map.push_back("ghi");
        map.push_back("jkl");
        map.push_back("mno");
        map.push_back("pqrs");
        map.push_back("tuv");
        map.push_back("wxyz");
        for(int i=0;i<digits.length();i++)
            {
            int pos=int(digits[i])-50;
            string str=map[int(digits[i])-50];
            possible_letters.push_back(str);
            }
        ans=recursion(possible_letters,"",0);
        return ans;
        }
};
int main()
    {
    system("cls");
    Solution obj;
    string str="23";
    vector<string> ans;
    ans=obj.letterCombinations(str);
    for(int i=0;i<ans.size();i++)
        {
        cout<<ans[i]<<",";
        }
    return 0;
    }