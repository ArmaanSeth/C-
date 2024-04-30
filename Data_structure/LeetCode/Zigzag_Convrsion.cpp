#include<iostream>
#include<strings.h>
using namespace std;
class Solution 
    {
    public:
    string convert(string s, int numRows) 
        {
        int c=0,i=0,l=s.length();
        bool turn=false;
        while(i<l)
            {
            if(turn==true && numRows>2)
                {
                turn=false;
                i+=numRows-2;
                c+=numRows-2;
                }
            else
                {
                i+=numRows;
                turn=true;
                c++;
                }
            }
        cout<<"C="<<c<<endl;
        bool down=true;
        int matrix[numRows][c],k=0;
        for(int i=0;i<numRows;i++)
            {
            for(int j=0;j<c;j++)
                {
                matrix[i][j]=0;
                }
            }
        for(int i=0;i<c;i++)
            {
            if(k==l)
                {
                break;
                }
            if(down==true || numRows<=2)
                {
                for(int j=0;j<numRows;j++)
                    {
                    if(k==l)
                        {
                        break;
                        }
                    matrix[j][i]=int(s[k]);
                    cout<<s[k]<<" ";
                    k++;
                    }
                down=false;
                }
            else
                {
                int pos=numRows-2;
                while(pos!=0 && k!=l)
                    {
                    matrix[pos][i]=int(s[k]);
                    cout<<s[k]<<" ";
                    k++;
                    pos--;
                    i++;
                    }
                i--;
                down=true;
                }
            }
    //    cout<<"K="<<k;
        k=0;
        string ans="";
        for(int i=0;i<numRows;i++)
            {
            for(int j=0;j<c;j++)
                {
                if(matrix[i][j]!=0)
                    {
                    ans+=char(matrix[i][j]);
                 //   cout<<char(matrix[i][j]);
                    k++;
                    }
              //  cout<<endl;
                }
            }
    return ans;      
    }
};
int main()
    {
    system("cls");
    Solution obj;
    string str="AB",ans=obj.convert(str,1);
    cout<<endl<<"Ans="<<ans;
    return 0;
    }