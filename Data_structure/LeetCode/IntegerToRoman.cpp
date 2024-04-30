#include<iostream>
#include<map>
#include<math.h>
using namespace std;
class Solution {
public:
    string hash(int n)
        {
        string s;
        int arr[]={5,10,50,100,500,1000,0},i;
        string str[]={"I","V","X","L","C","D","M"};
        for(i=0;i<6;i++)
            {
            if(n<arr[i])
                {
                break;
                }
            }
        int j=log10(n);
        j=n/(pow(10,j));
        if(j==5 || j==1)
            {
            s=str[i];
            }
        else if(j==4)
            {
            s=str[i]+str[i+1];
            }
        else if(j==9)
            {
            s=str[i-1]+str[i+1];
            }
        else
            {
            int k=log10(n);
            
            if(j>5)
                {
                j=j*pow(10,k);
                j=j-arr[i-1];
                k=log10(j);
                j=j/pow(10,k);
                k=0;
                s+=str[i];
                while (k<j)
                    {
                    s+=str[i-1];
                    k++;
                    }
                }   
            else
                {
                k=0;
                while (k<j)
                    {
                    s+=str[i];
                    k++;
                    }
                }
            }
        return s;
        }
string intToRoman(int num) 
    {
    string s;
    if(num==0)
        {
        return s; 
        }
    int i=log10(num);
    s+=hash(num);
    num=num%((int)pow(10,i));
    s+=intToRoman(num);
    return s;
    }
};
int main()
    {
    system("cls");
    Solution obj;
    string s=obj.intToRoman(98);
    cout<<s;
    return 0;
    }