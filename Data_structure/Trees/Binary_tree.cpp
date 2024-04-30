#include<iostream>
#include<conio.h>
using namespace std;
struct binarytree
    {
        int data;
        struct binarytree *left;
        struct binarytree *right;
    };
struct binarytree *root;
int addelement(struct binarytree *current,int n)
    {
        struct binarytree *ob=new binarytree;
        ob->data=n;
        ob->left=NULL;
        ob->right=NULL;
        if(current==NULL)
            {
                root=ob;
            }
        else   
            {
                if(current->data>n)
                    {
                        if(current->left==NULL)
                            {
                                current->left=ob;
                            }
                        else    
                            {
                                addelement(current->left,n);
                            }
                    }
                else    
                    {
                        if(current->right==NULL)
                            {
                                current->right=ob;
                            }
                        else    
                            {
                                addelement(current->right,n);
                            }

                    }
            }
    return 0;
    }
void display()
    {
        cout<<"Root(10)="<<root->data;
        cout<<"\nRoot->left(8)"<<root->left->data;
        cout<<"\nRoot->right(12)"<<root->right->data;
        cout<<"\nRoot->left->left(6)"<<root->left->left->data;
        cout<<"\nRoot->left->right(9)"<<root->left->right->data;
    }
int inorder(struct binarytree *current)
    {
        if(current==NULL)
            {
                return 0;
            }
        inorder(current->left);
        cout<<current->data<<" ";
        inorder(current->right);
    return 0;
    }
int preorder(struct binarytree *current)
    {
        if(current==NULL)
            {
                return 0;
            }
        cout<<current->data<<" ";
        preorder(current->left);
        preorder(current->right);
    return 0;
    }
int postorder(struct binarytree *current)
    {
        if(current==NULL)   
            {
                return 0;
            }
        postorder(current->left);
        postorder(current->right);
        cout<<current->data<<" ";
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
                            addelement(root,n);
                            //getch();
                            break;
                        }    
                    case 2:
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
                    case 6:
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