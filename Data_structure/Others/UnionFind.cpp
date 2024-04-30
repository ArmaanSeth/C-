#include<iostream>
#include<conio.h>
using namespace std;
class unionfind
    {
    public:
        unionfind()
            {
                noc=0;
                size=0;
                p_id=NULL;
                c_size=NULL;
            }
        unionfind(int k)
            {
                size=k;
                noc=0;
                for(int i=0;i<size;i++)
                    {
                        p_id[i]=i;
                    }
            }
        int findroot(int k)
            {
                int root=k;
                while(root!=p_id[root])
                    {
                        root=p_id[root];
                    }
                return root;
            }
        void pathcompression(int k)
            {
                int root=findroot(k);
                while(p_id[k]!=root)
                    {
                        int temp=p_id[k];
                        p_id[k]=root;
                        k=temp;
                    }
            }
        bool check(int p, int q)
            {
                if(findroot(p)==findroot(q))
                    {
                        return true;
                    }
                else
                    {
                        return false;
                    }
            }
        void swap(int p,int q)
            {
                int temp=c_size[p];
                c_size[p]=c_size[q];
                c_size[q]=temp;

            }
        int unify(int p,int q)
            {
                if(findroot(p)==findroot(q))
                    {
                        return -1;
                    }
                else if(findroot(p)==p && findroot(q)==q)
                    {
                        noc++;
                        c_size[noc-1]=2;
                        if(p<q)
                            {
                                p_id[q]=p;
                            }
                        else    
                            {
                                p_id[p]=q;
                            }
                        c_track[noc-1]=findroot(p);
                    }
                else if(findroot(p)==p)
                    {
                        p_id[p]=q;
                        int i=0;
                        for(i=0;i<noc;i++)
                            {
                                if(c_track[i]==findroot(p))
                                    {
                                        break;
                                    }
                            }
                        c_size[i]++;
                    }
                else if(findroot(q)==q)
                    {
                        p_id[q]=p;
                        int i=0;
                        for(i=0;i<noc;i++)
                            {
                                if(c_track[i]==findroot(p))
                                    {
                                        break;
                                    }
                            }
                        c_size[i]++;
                    }
                else if(findroot(p)!=findroot(q))
                    {
                        int i=0,j=0;
                        for(i=0;i<noc;i++)
                            {
                                if(c_track[i]==findroot(p))
                                    {
                                        break;
                                    }
                            }
                        for(j=0;j<noc;j++)
                            {
                                if(c_track[j]==findroot(p))
                                    {
                                        break;
                                    }
                            }
                        if(c_size[i]>c_size[j])
                            {
                                p_id[findroot(q)]=p;
                                c_size[i]+=j;
                                c_size[j]=c_size[noc-1];
                                c_track[j]=c_track[noc-1];
                                noc--;
                            }
                        else
                            {
                                p_id[findroot(p)]=q;
                                c_size[j]+=i;
                                c_size[i]=c_size[noc-1];
                                c_track[i]=c_track[noc-1];
                                noc--;
                            }
                    }
                return 1;
            }
    private:
        int noc,size,*p_id=new int[size],*c_size=new int[noc],*c_track=new int[noc];
    };