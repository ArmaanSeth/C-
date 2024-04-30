#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int recursion(vector<int> prices,vector<int>& dp, int pos){
        if(pos>=prices.size()-1){
            return 0;
        }
        else if(dp[pos]!=-1){
            if(dp[pos]<0)
                return 0;
            return dp[pos];
        }
        else{
            int max=-1;
            for(int i=pos;i<prices.size();i++){
                int p,temp;
                p=prices[i]-prices[pos];
                temp=recursion(prices,dp,i+1);
                if(temp>0)
                    p+=temp;
                if(p>max)
                    max=p;
            }
            dp[pos]=max;
            return max;
        }
        
    }
    int maxProfit(vector<int>& prices) {
        /*vector<vector<int>> matrix;
        for(int i=0;i<prices.size();i++){
            vector<int> temp;
            for(int j=0;j<prices.size(),j++){
                temp.push_back(prices[i]-prices[j])
            }
            matrix.push_back(temp);
        }*/
       /* vector<int> dp(prices.size(),-1);
        return recursion(prices,dp,0);*/
        int buy = prices[0], max_profit = 0;
        for (int i = 1; i < prices.size(); i++) {
    
            // Checking for lower buy value
            if (buy > prices[i])
                buy = prices[i];
    
            // Checking for higher profit
            else if (prices[i] - buy > max_profit)
                max_profit = prices[i] - buy;
        }
        return max_profit;  
    }
};
int main(){
    system("cls");
    vector<int> prices={7,1,5,3,6,4};
    Solution obj;
    int ans=obj.maxProfit(prices);
    cout<<"\nAns="<<ans;
    return 0;
}