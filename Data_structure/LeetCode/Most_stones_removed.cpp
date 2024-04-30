#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        if(stones.size()<2)
            return 0;
        int a=0;
        vector<int> list;
        list.push_back(0);
        for(int i=1;i<stones.size();i++){
            if(stones[i][0]==stones[0][0] || stones[i][1]==stones[0][1])
                list.push_back(i);
        }
        if(list.size()==1){
            vector<int> temp;
            temp.push_back(stones[0][0]);
            temp.push_back(stones[0][1]);
            stones.erase(stones.begin());
            a=removeStones(stones);
            stones.insert(stones.begin(),temp);
        }    
        else{
            int max=0;
            for(int i=0;i<list.size();i++){
                vector<int> temp;
                int pos=list[i];
                /*if(pos<0)
                    pos=0;*/
                temp.push_back(stones[list[i]][0]);
                temp.push_back(stones[list[i]][1]);
                stones.erase(stones.begin()+list[i]);
                a=removeStones(stones);
                if(max<a)
                    max=a;
                stones.insert(stones.begin()+pos,temp);
            }
            a=max+1;
        }
    return a;
    }
};
int main(){
    system("cls");
    Solution obj;
    vector<vector<int>> stones={{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    int a=obj.removeStones(stones);
    cout<<a<<endl;
    return 0;
}