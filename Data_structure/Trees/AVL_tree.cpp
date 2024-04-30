#include<iostream>
using namespace std;
struct AVL
    {
        int data;
        struct AVL *right;
        struct AVL *left;
    };
struct AVL *root=NULL;
int balance_factor(struct AVL *node)
    {
        int l=0,r=0;
        struct AVL *temp=new AVL;
        temp=node;
        while(temp->left!=NULL)
            {
                temp=temp->left;
                l++;
            }
        temp=node;
        while(temp->right!=NULL)
            {
                temp=temp->right;
                r++;
            }
        return (r-l);
    }
struct AVL* right_rotation(struct AVL *node)
    {
        struct AVL *temp1,*temp2;
        temp1=node->left;
        temp2=temp1->right;
        temp1->right=node;
        node->left=temp2;
        return temp1;
    }
struct AVL* left_rotation(struct AVL *node)
    {
        struct AVL *temp1,*temp2;
        temp1=node->right;
        temp2=temp1->left;
        temp1->left=node;
        node->right=temp2;
        return temp1;
    }
int insert(struct AVL *current,int n)
    {
        if(current==NULL)
            {
                current->data=n;
                current->left=NULL;
                current->right=NULL;
            }
        else    
            {
                
                if(current->data > n)
                    {
                        if(current->left==NULL)
                            {
                                struct AVL *temp=new AVL;
                                temp->data=n;
                                temp->left=NULL;
                                temp->right=NULL;
                                current->left=temp;
                            }
                        else    
                            {
                                insert(current->left,n);
                            }
                    }
                else
                    {
                        if(current->right==NULL)
                            {
                                struct AVL *temp=new AVL;
                                temp->data=n;
                                temp->left=NULL;
                                temp->right=NULL;
                                current->right=temp;
                            }
                        else    
                            {
                                insert(current->right,n);
                            }   
                    }
                
            }
        return 0;
    }

int main()
    {
     int i=0,n;
    while(i!=7)
            {
            system("cls");
            cout<<"\tBINARY TREE";
            cout<<"\n1.Add Element";
            cout<<"\n2.Inorder";
            cout<<"\n3.Preorder";
            cout<<"\n4.Postorder";
            cout<<"\n5.Modify";
            cout<<"\n6.Display";
            cout<<"\n7.Exit";
            cout<<"\n  Enter your choice=";                
            cin>>i;
            switch(i)
                {
                    case 1:
                        {
                            cout<<"Enter new element to add=";
                            cin>>n;
                            insert(root,n);
                            //getch();
                            break;
                        }    
                    /*case 2:
                        {
                            inorder(root);
                            getch();
                            break;
                        }
                    case 3:
                        {
                            preorder(root);
                            getch();
                            break;
                        }
                    case 4:
                        {
                            postorder(root);
                            getch();
                            break;
                        }
                    case 6:*/
                        {
                            display();
                            getch();
                            break;
                        }
                    case 7:
                        {
                            cout<<"Quiting!!!";
                            break;
                        }
                    default :
                        {
                            cout<<"Wrong Choice!!!";
                            getch();
                            break;
                        }
                }
            }  
    getch();
    return 0;   
    }