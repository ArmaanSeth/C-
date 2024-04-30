#include<iostream>
#include<vector>
#include<conio.h>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool row(vector<vector<char>>& board,int r, int c, map<int,int> m)
        {

        if(r>=9 || c>=9 || r<0 || c<0)
            {
            return true;
            }
        if(board[r][c]=='.')
            {
            return row(board,r+1,c,m);
            }
        if(m[(int)(board[r][c]-'0')]==0 && (int)(board[r][c]-'0')<10 && (int)(board[r][c]-'0')>0)
            {
            m[(int)(board[r][c]-'0')]++;
            return row(board,r+1,c,m);
            }
        else
            {
                return false;
            }
        return false;
        }
    bool col(vector<vector<char>>& board,int r, int c, map<int,int> m)
        {
        if(r>=9 || c>=9 || r<0 || c<0)
            {
            return true;
            }
        if(board[r][c]=='.')
            {
            return col(board,r,c+1,m);
            }
        if(m[(int)(board[r][c]-'0')]==0 && (int)(board[r][c]-'0')<10 && (int)(board[r][c]-'0')>0)
            {
            m[(int)(board[r][c]-'0')]++;
            return col(board,r,c+1,m);
            }
        return false;
        }

    bool box(vector<vector<char>>& board,int r,int c, map<int,int> m)
        {
        if(r>=9 || c>=9 || r<0 || c<0)
            {
            return true;
            }
        if(c%3==0 && r%3==0)
            {
            map<int,int> l;
            m=l;
            }
        if(board[r][c]=='.')
            {
            if(c%3==2)
                {
                return box(board,r+1,c-2,m);
                }
            else
                {
                return box(board,r,c+1,m);
                }
            }
        if(m[(int)(board[r][c]-'0')]==0 && (int)(board[r][c]-'0')<10 && (int)(board[r][c]-'0')>0)
            {
            m[(int)(board[r][c]-'0')]++;
            if(c%3==2)
                {
                return box(board,r+1,c-2,m);
                }
            else
                {
                return box(board,r,c+1,m);
                }
            }
        return false;
        }
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        bool t=true;
        int c=0,r=0;
        while(t==true && c<9 && r<9)
            {
            map<int,int> m,l;
            t=row(board,0,c,m);
            if(t==true)
                {
                t=col(board,r,0,l);
                }
            c++;
            r++;
            if(c%3==0 && t==true)
                {
                map<int,int> k;
                t=box(board,0,c-3,k);
                }
            }
        return t;
    }
};
int main()
    {
        system("cls");
        Solution obj;
        vector<vector<char>> g
            {
            {'.','.','.', '9','.','.', '.','.','.'},
            {'.','.','.', '.','.','.', '.','.','.'},
            {'.','.','3', '.','.','.', '.','.','1'},
            
            {'.','.','.', '.','.','.', '.','.','.'},
            {'1','.','.', '.','.','.', '3','.','.'},
            {'.','.','.', '.','2','.', '6','.','.'},
            
            {'.','9','.', '.','.','.', '.','7','.'},
            {'.','.','.', '.','.','.', '.','.','.'},
            {'8','.','.', '8','.','.', '.','.','.'}
            };
        bool l=obj.isValidSudoku(g);
        /*for(int i=0;i<g.size();i++)
            {
                for(int j=0;j<g[i].size();j++)
                    {
                        cout<<g[i][j]<<' ';
                    }
                cout<<endl;
            }*/
        cout<<endl<<l;
        getch();
        return 2;
    }