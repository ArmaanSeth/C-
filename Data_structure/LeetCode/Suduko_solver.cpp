#include<iostream>
#include<conio.h>
#include<vector>
#include<string.h>
#include<map>
using namespace std;
vector<vector<int>> freq={{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0},{8,0},{9,0},{0,0}};
class Solution 
    {
    public:
    vector<int> row(vector<vector<char>>& board,int r,int c)
        {
        vector<int> rd;
        if(r>8 || c>8)
            {
            return rd;
            }
        else if(board[r][c]=='.')
            {
            vector<int> temp=row(board,r,c+1);
            if(temp.size()>0)
                rd.insert(rd.end(),temp.begin(),temp.end());            
            }
        else
            {
            rd.push_back((int)(board[r][c]-'0'));
            freq[9][1]++;
            freq[(int)(board[r][c]-'0')-1][1]++;
            vector<int> temp=row(board,r,c+1);
            if(temp.size()>0)
                rd.insert(rd.end(),temp.begin(),temp.end());
            }
        return rd;
        }
    vector<int> col(vector<vector<char>>& board,int r,int c)
        {
        vector<int> cd;
        if(r>8 || c>8)
            {
            return cd;
            }
        else if(board[r][c]=='.')
            {
            vector<int> temp=col(board,r+1,c);
            if(temp.size()>0)
                cd.insert(cd.end(),temp.begin(),temp.end());            
            }
        else
            {
            cd.push_back((int)(board[r][c]-'0'));
            vector<int> temp=col(board,r+1,c);
            if(temp.size()>0)
                cd.insert(cd.end(),temp.begin(),temp.end());
            }
        return cd;
        }
    vector<int> box(vector<vector<char>>& board,int r,int c,int k)
        {
        vector<int> bd;
        if(k>8)
            {
            return bd;
            }  
        if(board[r][c]=='.')
            {
            vector<int> temp;
            if(c%3==2)
                {
                temp=box(board,r+1,c-2,k+1);
                if(temp.size()>0)
                    {
                    bd.insert(bd.end(),temp.begin(),temp.end());
                    }
                }
            else
                {
                temp=(box(board,r,c+1,k+1));
                if(temp.size()>0)
                    {
                    bd.insert(bd.end(),temp.begin(),temp.end());
                    }
                }
            }
        else 
            {
            bd.push_back((int)(board[r][c]-'0'));
            vector<int> temp;
            if(c%3==2)
                {
                temp=box(board,r+1,c-2,k+1);
                if(temp.size()>0)
                    {
                    bd.insert(bd.end(),temp.begin(),temp.end());
                    }
                }
            else
                {
                temp=(box(board,r,c+1,k+1));
                if(temp.size()>0)
                    {
                    bd.insert(bd.end(),temp.begin(),temp.end());
                    }
                }
            }
        return bd;
        }  
    int check(int r,int c,int n,vector<vector<int>> &rd,vector<vector<int>> &cd,vector<vector<int>> &bd,vector<vector<char>> &board)
        {
        if(r>8 || c>8)
            {
            return false;
            }
        
        int k=0;
        for(int i=0;i<9;i++)
            {
            if(board[r][i]=='.' && find(cd,i,n)==-1 && find(bd,(r/3+3*(i/3)),n)==-1)
                {
                k++;
                }
            }
        if(k==1)
            {
            return 1;
            }
        return 0;
        }
    void update(vector<vector<char>>& board,vector<vector<int>>& rd,vector<vector<int>>& cd,vector<vector<int>>& bd,int r,int c,int n)
        {
        if(r>8 || c>8)
            {
            return;
            }
        freq[9][1]++;
        freq[n-1][1]++;
        board[r][c]=('0'+n);
        rd[r].push_back(n);
        cd[c].push_back(n);
        int i=r/3,j=c/3;
        bd[(i+3*j)].push_back(n);
        }
    int find(vector<vector<int>> &list,int i,int n)
        {
        for(int j=0;j<list[i].size();j++)
            {
            if(list[i][j]==n)
                {
                return j;
                }
            }
        return -1;
        }
    void solve(vector<vector<char>>& board,int c,int n,vector<vector<int>> &rd,vector<vector<int>> &cd,vector<vector<int>> &bd)
        {
        int k=-1,i=0;
        if(c>8)
            {
            return;
            }
        if(find(cd,c,n)!=-1)
            {
            solve(board,c+1,n,rd,cd,bd);
            return;
            }
        for(i=0;i<9;i++)
            {
            if(i%3==0 && find(bd,(i/3+3*(c/3)),n)==-1)
                {
                vector<int> pos=boxsolve(board,rd,cd,bd,n,(i/3+3*(c/3)));
                if(pos[0]!=-1)
                    {
                    update(board,rd,cd,bd,pos[0],pos[1],n);
                    if(pos[1]==c)
                        {
                        break;
                        }
                    }
                }
            if(board[i][c]=='.')
                {
                if(find(rd,i,n)==-1 && find(bd,(i/3+3*(c/3)),n)==-1)
                    {
                    if(check(i,c,n,rd,cd,bd,board)==1)
                        {
                        k=i;
                        break;
                        }
                    if(k==-1)
                        k=i;
                    else
                        k=-2;
                    }
                }    
            }
        if(k>=0)
            {
            update(board,rd,cd,bd,k,c,n);
            }
        solve(board,c+1,n,rd,cd,bd);
        return;
        }        
    void solve2(vector<vector<char>>& board,vector<vector<int>> &rd,vector<vector<int>> &cd,vector<vector<int>> &bd)
        {
        for(int i=0;i<9;i++)
            {
            if(rd[i].size()==8)
                {
                int temp=45;
                for(int k=0;k<8;k++)
                    {
                    temp-=rd[i][k];
                    }
                for(int j=0;j<9;j++)
                    {
                    if(board[i][j]=='.')
                        {
                        update(board,rd,cd,bd,i,j,temp);
                        break;
                        }
                    }
                }
            if(cd[i].size()==8)
                {
                int temp=45;
                for(int k=0;k<8;k++)
                    {
                    temp-=cd[i][k];
                    }
                for(int j=0;j<9;j++)
                    {
                    if(board[j][i]=='.')
                        {
                        update(board,rd,cd,bd,j,i,temp);
                        break;
                        }
                    }
                }
            if(bd[i].size()==8)
                {
                int l=3*(i%3),k=3*(i/3);
                int temp=45;
                for(int k=0;k<8;k++)
                    {
                    temp-=bd[i][k];
                    }
                for(int j=0;j<9;j++)
                    {
                    if(board[l][k]=='.')
                        {
                        update(board,rd,cd,bd,l,k,temp);
                        break;
                        }
                    if(k%3==2)
                        {
                        k=3*(i/3);
                        l++;
                        }
                    else
                        {
                        k++;
                        }
                    }
                }
            }
        }
    void solve3(vector<vector<char>>& board,vector<vector<int>> &rd,vector<vector<int>> &cd,vector<vector<int>> &bd)
        {
        vector<vector<vector<int>>> list=genlist(board,rd,cd,bd);
        for(int i=0;i<9;i++)
            {
            if(bd[i].size()==7)
                {
                int c=(i/3)*3,r=(i%3)*3;
                vector<vector<int>> pos;
                while(pos.size()!=2)
                    {
                    if(board[r][c]=='.')
                        {
                        pos.push_back({r,c});
                        }
                    if(c%3==2)
                        {
                        r++;
                        c-=2;
                        }
                    else
                        {
                        c++;
                        }
                    }
                int v=pos[0][0],l=pos[0][1];
                int n=list[v][l][0];
                int m=list[v][l][1];
                if(pos[0][0]==pos[1][0])
                    {
                    c=((3-(pos[0][1]%3+pos[1][1]%3))+3*((pos[0][1])/3));
                    r=(pos[0][0])%3;
                    int r1;
                    if(r==0)
                        {
                        r1=2;
                        }
                    else if(r==1)
                        {
                        r1=0;    
                        }
                    else
                        {
                        r1=1;
                        }
                    r=(3-r1-r);
                    r+=3*(pos[0][0]/3);
                    r1+=3*(pos[0][0]/3);
                    for(int j=0;j<9;j++)
                        {
                        if(list[j][c].size()==1)
                            {
                            update(board,rd,cd,bd,j,c,list[j][c][0]);
                            list=genlist(board,rd,cd,bd);
                            continue;
                            }
                        for(int k=0;k<list[j][c].size();k++)
                            {
                            if(list[j][c][k]==m || list[j][c][k]==n)
                                {
                                list[j][c].erase(list[j][c].begin()+k);
                                k--;
                                }
                            }
                        if(list[j][c].size()==1)
                            {
                            update(board,rd,cd,bd,j,c,list[j][c][0]);
                            list=genlist(board,rd,cd,bd);
                            }
                        }
                    for(int j=0;j<9;j++)
                        {
                        if(list[j][c].size()==1)
                            {
                            update(board,rd,cd,bd,j,c,list[j][c][0]);
                            list=genlist(board,rd,cd,bd);
                            continue;
                            }
                        for(int k=0;k<list[r][j].size();k++)
                            {
                            if(list[r][j][k]==m || list[r][j][k]==n)
                                {
                                list[r][j].erase(list[r][j].begin()+k);
                                k--;
                                }
                            }
                        if(list[r][j].size()==1)
                            {
                            update(board,rd,cd,bd,r,j,list[r][j][0]);
                            list=genlist(board,rd,cd,bd);
                            }
                        }
                    for(int j=0;j<9;j++)
                        {
                        if(list[j][c].size()==1)
                            {
                            update(board,rd,cd,bd,j,c,list[j][c][0]);
                            list=genlist(board,rd,cd,bd);
                            continue;
                            }
                        for(int k=0;k<list[r1][j].size();k++)
                            {
                            if(list[r1][j][k]==m || list[r1][j][k]==n)
                                {
                                list[r1][j].erase(list[r1][j].begin()+k);
                                k--;
                                }
                            }
                        if(list[r1][j].size()==1)
                            {
                            update(board,rd,cd,bd,r1,j,list[r1][j][0]);
                            list=genlist(board,rd,cd,bd);
                            }
                        }
                    }
                else if(pos[0][1]==pos[1][1])
                    {
                    r=((3-(pos[0][0]%3+pos[1][0]%3))+3*((pos[0][0])/3));
                    c=(pos[0][1])%3;
                    int c1;
                    if(c==0)
                        {
                        c1=2;
                        }
                    else if(c==1)
                        {
                        c1=0;    
                        }
                    else
                        {
                        c1=1;
                        }
                    c=(3-c1-c);
                    c+=3*(pos[0][1]/3);
                    c1+=3*(pos[0][1]/3);
                    for(int j=0;j<9;j++)
                        {
                        if(list[j][c].size()==1)
                            {
                            update(board,rd,cd,bd,j,c,list[j][c][0]);
                            list=genlist(board,rd,cd,bd);
                            continue;
                            }
                        for(int k=0;k<list[r][j].size();k++)
                            {
                            if(list[r][j][k]==m || list[r][j][k]==n)
                                {
                                list[r][j].erase(list[r][j].begin()+k);
                                k--;
                                }
                            }
                        if(list[r][j].size()==1)
                            {
                            update(board,rd,cd,bd,r,j,list[r][j][0]);
                            list=genlist(board,rd,cd,bd);
                            }
                        }
                    for(int j=0;j<9;j++)
                        {
                        if(list[j][c].size()==1)
                            {
                            update(board,rd,cd,bd,j,c,list[j][c][0]);
                            list=genlist(board,rd,cd,bd);
                            continue;
                            }
                        for(int k=0;k<list[j][c].size();k++)
                            {
                            if(list[j][c][k]==m || list[j][c][k]==n)
                                {
                                list[j][c].erase(list[j][c].begin()+k);
                                k--;
                                }
                            }
                        if(list[j][c].size()==1)
                            {
                            update(board,rd,cd,bd,j,c,list[j][c][0]);
                            list=genlist(board,rd,cd,bd);
                            }
                        }
                    for(int j=0;j<9;j++)
                        {
                        if(list[j][c].size()==1)
                            {
                            update(board,rd,cd,bd,j,c,list[j][c][0]);
                            list=genlist(board,rd,cd,bd);
                            continue;
                            }
                        for(int k=0;k<list[j][c1].size();k++)
                            {
                            if(list[j][c1][k]==m || list[j][c1][k]==n)
                                {
                                list[j][c1].erase(list[j][c1].begin()+k);
                                k--;
                                }
                            }
                        if(list[j][c1].size()==1)
                            {
                            update(board,rd,cd,bd,j,c1,list[j][c1][0]);
                            list=genlist(board,rd,cd,bd);
                            }
                        }
                    }
                else
                    {
                    r=((3-(pos[0][0]%3+pos[1][0]%3))+3*((pos[0][0])/3));
                    c=((3-(pos[0][1]%3+pos[1][1]%3))+3*((pos[0][1])/3));
                    for(int j=0;j<9;j++)
                        {
                        if(list[j][c].size()==1)
                            {
                            update(board,rd,cd,bd,j,c,list[j][c][0]);
                            list=genlist(board,rd,cd,bd);
                            continue;
                            }
                        for(int k=0;k<list[r][j].size();k++)
                            {
                            if(list[r][j][k]==m || list[r][j][k]==n)
                                {
                                list[r][j].erase(list[r][j].begin()+k);
                                k--;
                                }
                            }
                        if(list[r][j].size()==1)
                            {
                            update(board,rd,cd,bd,r,j,list[r][j][0]);
                            list=genlist(board,rd,cd,bd);
                            }
                        }
                    for(int j=0;j<9;j++)
                        {
                        if(list[j][c].size()==1)
                            {
                            update(board,rd,cd,bd,j,c,list[j][c][0]);
                            list=genlist(board,rd,cd,bd);
                            continue;
                            }
                        for(int k=0;k<list[j][c].size();k++)
                            {
                            if(list[j][c][k]==m || list[j][c][k]==n)
                                {
                                list[j][c].erase(list[j][c].begin()+k);
                                k--;
                                }
                            }
                        if(list[j][c].size()==1)
                            {
                            update(board,rd,cd,bd,j,c,list[j][c][0]);
                            list=genlist(board,rd,cd,bd);
                            }
                        }
                    }
                }
            }
        }
    vector<vector<vector<int>>> genlist(vector<vector<char>>& board,vector<vector<int>> &rd,vector<vector<int>> &cd,vector<vector<int>> &bd)
        {
        vector<vector<vector<int>>> list;
        int r=0,c=0;
        while(r<9)
            {
            vector<vector<int>> temp;
            c=0;
            while(c<9)
                {  
                vector<int> temp1;
                if(board[r][c]=='.')
                    { 
                    int a[9]={1,1,1,1,1,1,1,1,1},b[9]={1,1,1,1,1,1,1,1,1},d[9]={1,1,1,1,1,1,1,1,1};
                    int k=3*(c/3)+(r/3);    
                    int f=0;
                    while(f<9)
                        {
                        if(f<rd[r].size())
                            {
                            a[rd[r][f]-1]=0;
                            }
                        if(f<cd[c].size())
                            {
                            b[cd[c][f]-1]=0;
                            }
                        if(f<bd[k].size())
                            {
                            d[bd[k][f]-1]=0;
                            }
                        f++;
                        }
                    f=1;
                    for(f=1;f<=9;f++)
                        {
                        if(a[f-1]==1 && b[f-1]==1 && d[f-1]==1)
                            {
                            temp1.push_back(f);
                            }
                        }
                    }
                temp.push_back(temp1);
                c++;
                }
            list.push_back(temp);
            r++;       
            }
        return list;
        }
    vector<int> boxsolve(vector<vector<char>>& board,vector<vector<int>>& rd,vector<vector<int>>& cd,vector<vector<int>>& bd,int n,int i)
        {
        vector<vector<int>> pos;
        int count=0;
        int r=3*(i%3),c=3*(i/3);
        int temp[3][3];
        for(int j=0;j<3;j++)
            {
            for(int k=0;k<3;k++)
                {
                if(board[r][c]=='.')
                    {
                    temp[j][k]=1;
                    pos.push_back({r,c});
                    count++;
                    }
                else
                    {
                    temp[j][k]=0;
                    }
                if(find(cd,c,n)!=-1 || find(rd,r,n)!=-1)
                    {
                    if(temp[j][k]==1)
                        {
                        if(pos[pos.size()-1][0]==r && pos[pos.size()-1][1]==c)
                            {
                            pos.pop_back();
                            }
                        count--;
                        }
                    temp[j][k]=0;
                    }
                if(c%3==2)
                    {
                    c-=2;
                    r++;
                    }
                else
                    {
                    c++;
                    }
                }
            }
        if(count==1)
            {
            return pos[0];
            }
        pos.push_back({-1,-1});
        return pos[pos.size()-1];    
        }
    void solveSudoku(vector<vector<char>>& board) 
        {
        int c=0,r=0;
        vector<vector<int>> rd,cd,bd;
        while(c<9 && r<9)
            {
            rd.push_back(row(board,r,0));
            cd.push_back(col(board,0,c));
            if(c%3==2)
                {
                bd.push_back(box(board,0,c-2,0));
                bd.push_back(box(board,3,c-2,0));
                bd.push_back(box(board,6,c-2,0));
                }
            c++;
            r++;
            }
        cout<<endl;
        while(freq[9][1]!=81)   
            {
            vector<vector<int>> f=freq;
            for(int i=0;i<9;i++)
                {
                for(int j=i;j<8-i;j++)
                    {
                    if(f[j][1]>f[j+1][1])
                        {
                        vector<int> temp=f[j+1];
                        f[j+1]=f[j];
                        f[j]=temp;
                        }
                    }
                solve(board,0,f[8-i][0],rd,cd,bd);
                solve2(board,rd,cd,bd);
                solve3(board,rd,cd,bd);
             /*   for(int i=0;i<9;i++)
                    {
                    if(i%3==0)
                    cout<<endl;
                    for(int j=0;j<9;j++)
                        {
                        if(j%3==0)
                            cout<<"   ";
                        cout<<board[i][j]<<" ";
                        } 
                    cout<<endl;
                    }*/
                }
            }
        }
    };
int main()
    {
    system("cls");
    Solution obj;
    vector<vector<char>> g
        /*{
        {'5','3','.', '.','7','.', '.','.','.'},
        {'6','.','.', '1','9','5', '.','.','.'},
        {'.','9','8', '.','.','.', '.','6','.'},
            
        {'8','.','.', '.','6','.', '.','.','3'},
        {'4','.','.', '8','.','3', '.','.','1'},
        {'7','.','.', '.','2','.', '.','.','6'},
            
        {'.','6','.', '.','.','.', '2','8','.'},
        {'.','.','.', '4','1','9', '.','.','5'},
        {'.','.','.', '.','8','.', '.','7','9'}
        };
        {
        {'.','.','9', '7','4','8', '.','.','.'},
        {'7','.','.', '.','.','.', '.','.','.'},
        {'.','2','.', '1','.','9', '.','.','.'},

        {'.','.','7', '.','.','.', '2','4','.'},
        {'.','6','4', '.','1','.', '5','9','.'},
        {'.','9','8', '.','.','.', '3','.','.'},
        
        {'.','.','.', '8','.','3', '.','2','.'},
        {'.','.','.', '.','.','.', '.','.','6'},
        {'.','.','.', '2','7','5', '9','.','.'}*/
        {
        {'.','.','9', '7','4','8', '.','.','2'},
        {'7','.','.', '6','.','2', '.','.','9'},
        {'.','2','.', '1','.','9', '.','.','.'},

        {'.','.','7', '9','8','6', '2','4','1'},
        {'2','6','4', '3','1','7', '5','9','8'},
        {'1','9','8', '5','2','4', '3','6','7'},
        
        {'9','.','.', '8','6','3', '.','2','.'},
        {'.','.','2', '4','9','1', '.','.','6'},
        {'.','.','.', '2','7','5', '9','.','.'}
        };

    obj.solveSudoku(g);
    for(int i=0;i<9;i++)
        {
        if(i%3==0)
                cout<<endl;
        for(int j=0;j<9;j++)
            {
            if(j%3==0)
                cout<<"   ";
            cout<<g[i][j]<<" ";
            }
        
        cout<<endl;
        }
    getch();
    return 0;
    }