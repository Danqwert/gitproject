#include <iostream>
using namespace std;

int main(){
int a,b;
cin>>a>>b;
int qq=0;
if(a<0 && b<0)
{
qq=-a;
a=-b;
b=qq;
}

int aa=0;
int bb=0;
int sch=0;
int c=0;
int m;
if(qq==0)
    m=0;
else
	m=999999;
int i1=0;
for(int i=a; i<=b;i++)
{   if(i<10){}
else{

    i1=i;
    bb=i1%100;
    while(i1>100)
        i1=i1/10;
    aa=i1%100;
    c=aa-bb;
        if(c==0){}
        else
    {if(i%c==0)
        {
        sch++;
        if(qq==0)
        {if(i>m)
            m=i;}}
        else
        {if(i<m)
            m=i;}

        }}
}
if(qq==0)
cout<<sch<<" "<<m;
else
cout<<sch<<" "<<-m;
}
