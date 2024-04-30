#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
class suffix
    {
    public:
    suffix()
        {
            cout<<"Enter string=";
            cin>>str;
            size=str.length(); 
            sufix=new string[size]; 
            sorted=new string[size];
            lcp=new int[size];
            si=new int[size];
            for(int i=0;i<size;i++)
                {
                    si[i]=i;
                }
        }
    void generate_suffix()
        {
            for(int i=0;i<size;i++)
                {
                    string temp;
                    int k=0;
                    for(int j=(size-i-1);j<(size);j++)
                        {
                            temp+=str[j];
                            k++;
                        }
                    sufix[i]=temp;
                    sorted[i]=temp;
                    //cout<<temp<<"\t"<<sufix[i].size()<<endl;
                }   
        }
    void print_suffix()
        {
            for(int i=0;i<size;i++)
                {
                    cout<<sufix[i]<<endl;
                }
        }
    void print_lcp()
        {
            for(int i=0;i<size;i++) 
                {
                    cout<<lcp[i]<<endl;
                }
        }
    void print_si()
        {
        //    cout<<"SI\tLCP\tSUFFIX"<<endl;
            for(int i=0;i<size;i++) 
                {
                    cout<<si[i]<<"\t"<<lcp[i]<<"\t"<<sufix[si[i]]<<endl;
                }
        }
  /*  void sortedindex()
        {
        int temp;
        for(int i=0;i<size;i++)
            {
                for(int j=0;j<size-1-i;j++)
                    {
                        if(sfix[j]>sufix[j+1])
                            {
                                temp=si[j+1];
                                si[j+1]=si[j];
                                si[j]=temp;
                            }
                    }
            }
        }*/
    void sortedindex()
        {
        string temp;
        int k;
        for(int i=0;i<size;i++)
            {
                for(int j=0;j<size-1-i;j++)
                    {
                        if(sorted[j]>sorted[j+1])
                            {
                                temp=sorted[j+1];
                                sorted[j+1]=sorted[j];
                                sorted[j]=temp;

                                k=si[j+1];
                                si[j+1]=si[j];
                                si[j]=k;
                            }
                    }
            }
        }
    void Lcp()
        {
            int i=1;
            lcp[0]=0;
            while(i<size)
                {
                    int k=0;
                    for(int j=0;j<size;j++)
                        {
                            if(sufix[si[i-1]][j]==sufix[si[i]][j])
                                {
                                    k++;
                                }
                            else
                                {
                                    break;
                                }
                        }
                    lcp[i]=k;
                    i++;
                }
        }
    private: 
    string str;
    int size,*lcp,*si;
    string *sufix;
    string *sorted;
    };
int main()
    {
        system("cls");
        suffix obj;
        obj.generate_suffix();
        obj.sortedindex();   
        obj.print_suffix();            
        obj.Lcp();
        obj.print_si();
        getch();
        return 0;
    }                