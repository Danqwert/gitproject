#include <iostream>
#include <fstream>
using namespace std;
main()
{
  ifstream Fin;

    string a="QWERTYUIOPLKJHGFDSAZXCVBNM";
  Fin.open ( "input.txt" );
    string s;
  // cin>>s;
  getline(Fin, s);
    int d=0;
    int m=0;
    char simb;
  for(int i=0;i<a.length();i++)
    {int sch=0;
    int x=0;
    int y=0;
    int k=0;
    x=s.find(a[i]);
    while(k!=-1)
    {

        k=s.find(a[i]);
        if(k!=-1)
            y=k;
        else
            break;
        s.erase(y,1);
        sch++;

    }
        y=y+sch;
        if(y-x==1)
        d=0;
        else
        d=y-x;
        if(m<d)
            {m=d;
            simb=a[i];}
    }

   Fin.close();

if(m==0)
cout<<0;
else
cout<<simb<<" "<<m-1;

}