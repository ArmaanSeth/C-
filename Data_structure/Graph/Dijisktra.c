#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define INT_MAX 5000
struct node{
    int d;
    char c;
    int flag;
    int e[100];
    struct node* next[100];
};
struct node* shortest_path(struct node* arr){
    printf("\n***HIII***");
    int i=0,min_dis=INT_MAX,id=0;
    struct node *child=NULL,*temp=arr,par=NULL;
    while(temp!=NULL){
        int j=0;
        while(temp->next[j]!=NULL){
            printf("\n%c",temp->c);
            printf(", J=%d",j);
            printf(",E=%d",temp->e[j]);
            if(temp->e[j]<min_dis && (temp->next[j])->flag==0){
                // printf("\ntest");
                par=temp;
                min_dis=temp->e[j];
                id=j;
            }
            j++;
        }
        temp=temp->next[0];
    }
    // printf("\ntest");
    if(i==5)
        return;
    child=par->next[id];
    child->flag=1;
    // printf("\n%c",child->c);
    if(child->d>(min_dis+par->d))
        child->d=min_dis+par->d;
    // printf("\n%d",child->d);
    temp=arr;
    while(temp->next[0]!=NULL){
        temp=temp->next[0];
    }

    temp->next[0]=child;
    if(i<4)
        arr[i+1]=NULL;
    shortest_path(arr);
}
int main(){
    system("cls");
    struct node* s=(struct node*)malloc(sizeof(struct node*)),*t=(struct node*)malloc(sizeof(struct node*)),*x=(struct node*)malloc(sizeof(struct node*)),*y=(struct node*)malloc(sizeof(struct node*)),*z=(struct node*)malloc(sizeof(struct node*));
    
    s->d=0;
    s->c='S';
    s->flag=1;
    s->next[0]=t;
    s->next[1]=y;
    s->next[2]=NULL;
    
    t->d=INT_MAX;
    t->c='T';
    t->flag=0;
    t->next[0]=x;
    t->next[1]=y;
    t->next[2]=NULL;

    x->d=INT_MAX;
    x->c='X';
    x->flag=0;
    x->next[0]=z;
    x->next[1]=NULL;
    
    y->d=INT_MAX;
    y->c='Y';
    y->flag=0;
    y->next[0]=z;
    y->next[1]=t;
    y->next[2]=x;
    y->e[2]=9;
    y->next[3]=NULL;
    
    z->d=INT_MAX;
    z->c='Z';
    z->flag=0;
    z->next[0]=x;
    z->next[1]=s;
    z->next[2]=NULL;
    
    s->e[0]=10;
    s->e[1]=5;
    t->e[0]=1;
    t->e[1]=2;
    x->e[0]=4;
    y->e[0]=2;
    y->e[1]=3;
    z->e[0]=6;
    z->e[1]=7;
    printf("%d",s->next[0]->d);
    // printf("\n%d",s->e[1]);
    // printf("\n%d",t->e[1]);
    // printf("\n%d",x->e[0]);
    // printf("\n%d",y->e[1]);
    // printf("\n%d",z->e[1]);

    // printf("test");
    struct node* arr=s;
    shortest_path(arr);
    printf("\nANSWER\n");
    // for(int i=0;i<5;i++){
    //     printf("\n%c\t\t%d",arr[i]->c,arr[i]->d);
    // }
    return 0;
    
}