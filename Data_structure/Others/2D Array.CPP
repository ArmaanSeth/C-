#include <iostream>
#include<conio.h>
using namespace std;
int main()
	{
	//clrscr();
	int a[2][4],i,j;
	int b[3],s=0;
	for(i=0;i<2;i++)
		{
		s=0;
		for(j=0;j<3;j++)
			{
			cout<<"Enter Sale=";
			cin>>a[i][j];
			cout<<endl;
			s=s+a[i][j];
			}
		b[i]=s;
		}

	for(j=0;j<3;j++)
		{
		a[j][3]=b[j];
		}
	for(i=0;i<2;i++)
		{
		for(j=0;j<4;j++)
			cout<<a[i][j]<<"  ";
		cout<<endl<<endl;
		}
	getch();
	return 0;
	}
