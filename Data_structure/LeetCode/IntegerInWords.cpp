#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
class Solution 
{
public:
string key1(int i)
    {
    string s;
    if(i==1)
        {
        s="One";
        }
    else if(i==2)
        {
        s="Two";
        }
    else if(i==3)
        {
        s="Three";
        }
    else if(i==4)
        {
        s="Four";
        }
    else if(i==5)
        {
        s="Five";
        }
    else if(i==6)
        {
        s="Six";
        }
    else if(i==7)
        {
        s="Seven";
        }
    else if(i==8)
        {
        s="Eight";
        }
    else if(i==9)
        {
        s="Nine";
        }
    return s;
    }
string key2(int i)
    {
    string s;
    if(i==2)
        {
        s="Twenty";
        }
    else if(i==3)
        {
        s="Thirty";
        }
    else if(i==4)
        {
        s="Forty";
        }
    else if(i==5)
        {
        s="Fifty";
        }
    else if(i==6)
        {
        s="Sixty";
        }
    else if(i==7)
        {
        s="Seventy";
        }
    else if(i==8)
        {
        s="Eighty";
        }
    else if(i==9)
        {
        s="Ninety";
        }
    return s;
    }
string key3(int i)
    {
    string s;
    if(i==1)
        {
        s="Eleven";
        }
    else if(i==2)
        {
        s="Twelve";
        }
    else if(i==3)
        {
        s="Thirteen";
        }
    else if(i==4)
        {
        s="Fourteen";
        }
    else if(i==5)
        {
        s="Fifteen";
        }
    else if(i==6)
        {
        s="Sixteen";
        }
    else if(i==7)
        {
        s="Seventeen";
        }
    else if(i==8)
        {
        s="Eighteen";
        }
    else if(i==9)
        {
        s="Nineteen";
        }
    else if(i==0)
        {
        s="Ten";
        }
    return s;
    }
string rec(int n)
    {
    string s;
    if(n==0)
        {
        return "";
        }
    int i=log10(n),k=i/3,j=i%3,x=i-j,l,num=n;
    if(j==2)
        {
        l=n/(pow(10,i));
        s+=key1(l) + " ";
        s+="Hundred ";
        n=n%(int)pow(10,i);
        i--;
        l=n/(pow(10,i));
        if(l==0)
            {
            n=n%((int)pow(10,i));
            i--;
            l=n/pow(10,i);
            if(l!=0)
                {
                s+=(key1(l) + " "); 
                }
            }
        else if(l==1)
            {
            n=n%(int)pow(10,i);
            i--;
            s+=(key3(n/pow(10,i)) + " ");
            }
        else
            {
            s+=key2(n/pow(10,i)) + " ";
            n=n%(int)pow(10,i);
            i--;
            l=n/pow(10,i);
            if(l!=0)
                {
                s+=(key1(l) + " ");
                }
            }
        }
    else if(j==1)
        {
        l=n/pow(10,i);
        if(l==1)
            {
            n=n%(int)pow(10,i);
            i--;
            s+=(key3(n/pow(10,i))) + " ";
            }
        else
            {
            s+=(key2(n/pow(10,i)) + " ");
            n=n%(int)pow(10,i);
            i--;
            l=n/pow(10,i);
            if(l!=0)
                {
                s+=(key1(n/pow(10,i)) + " ");
                }
            }
        }
    else    
        {
        s+=(key1(n/pow(10,i)) + " ");
        }
    if(k==0)
        {
        s.pop_back();
        return s;
        }
    else if(k==1)
        {
        s+=("Thousand ");
        }
    else if(k==2)
        {
        s+=("Million ");
        }
    else if(k==3)
        {
        s+=("Billion ");
        }
    x=pow(10,x);
    n=num%x;
    string temp=rec(n);
    if(temp=="")
        {
        s.pop_back();
        }
    s=s+temp;
    return s;
    }
string numberToWords(unsigned int num) 
    {
    if(num==0)
        {
        return "Zero";
        }
    return rec(num);    
    }
};
int main()
    {
    system("cls");
    Solution obj;
    string s=obj.numberToWords(50345);
    cout<<s;
    return 0;
    }