#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class myclass
{

public:
    void create();
    void new_string();
    void new_stobik();
    void vivesti_stroky();
    void izmenit_stroky();
    void delete_string();
    void print();
    void help();
};

void myclass::create()
{
    ofstream f;
    f.open("file.txt");
    f<<"Name,Familia,Otchestvo,vozrast,clas\n";
    f.close();
}

void myclass::new_string()
{
    ofstream fout;
    fstream fin;
    fout.open("file.txt",  ios::out | ios::app);
    fin.open("file.txt");
    string word,line;
    getline(fin,line);
    int a=0;
    cout<<"Vvedite cherez probel: ";
    for(int i=0; i<line.size(); i++)
    {
        if(line[i]==',')
        {
            a++;
            cout<<" ";
        }
        else
            cout<<line[i];
    }
    cout<<endl;

    while(a>0)
    {
        cin>>word;
        fout<<word<<',';
        a--;
    }
    cin>>word;
    fout<<word<<"\n";
    cout<<endl;
}

void myclass::new_stobik()
{
    cout<<"Vvedite nazvanie stolbika: "<<endl;
    string name;
    cin>>name;

    fstream fin1;
    ofstream fout2;
    fin1.open("file.txt");
    fout2.open("temp.txt");
    string line;
    getline(fin1,line);

    //line=line.erase(line.end()-2, line.end());
    //line.erase(line.end()-2, line.end());

    string line1=line+","+name+"\n";
    fout2<<line1;

    while(getline(fin1,line))
    {
        fout2 << line <<",NAN"<< "\n";
    }

    fout2.close();

    fstream fin2;
    fin2.open("temp.txt");
    ofstream fout1;
    fout1.open("file.txt");

    while(getline(fin2,line))
    {
        fout1 << line<< "\n";
    }
    fout1.close();
    cout<<endl;

}

void myclass::vivesti_stroky()
{
    cout<<"Vvedite nomer stroki: "<<endl;
    fstream fin;
    fin.open("file.txt");

    int n;
    cin>>n;
    string stroka;

    while(n>0)
    {
        if(getline(fin,stroka))
            n--;
        else
            {cout<<"Out of range!"<<endl;
            return;}

    }
    //if(n>0)
    //    cout<<"Out of range!"<<endl;


        for(int i=0; i<stroka.size(); i++)
        {
            if(stroka[i]==',')
                cout<<" ";
            else
                cout<<stroka[i];
        }
        cout<<endl;

}

void myclass::izmenit_stroky()
{
    int n;
    cout<<"Vvedite nomer stroki: "<<endl;
    cin>>n;
    n=n-1;

    fstream fin1;
    ofstream fout2;
    fin1.open("file.txt");
    fout2.open("temp.txt");



    string line;
    getline(fin1,line);
    int a=0;
    cout<<"Vvedite cherez probel: ";
    for(int i=0; i<line.size(); i++)
    {
        if(line[i]==',')
        {
            a++;
            cout<<" ";
        }
        else
            cout<<line[i];
    }
    cout<<endl;
    fout2<<line<<"\n";
    string stroka;
    while(n>0)
    {
        if(getline(fin1,stroka))
            fout2 << stroka<< "\n";
        else
            {cout<<"Out of range!"<<endl;
            return;}
        n--;

    }
    getline(fin1,stroka);

    string word;
    while(a>=0)
    {
        cin>>word;
        fout2<<word<<',';
        a--;
    }
    fout2<<"\n";

    while(getline(fin1,stroka))
    {
        fout2 << stroka<< "\n";
    }

    fout2.close();

    fstream fin2;
    fin2.open("temp.txt");
    ofstream fout1;
    fout1.open("file.txt");

    while(getline(fin2,line))
    {
        fout1 << line<< "\n";
    }
    fout1.close();
    cout<<endl;
}

void myclass::delete_string()
{
    int n;
    cout<<"Vvedite nomer stroki dlya ydalenia: "<<endl;
    cin>>n;
    //n=n-1;

    fstream fin1;
    ofstream fout2;
    fin1.open("file.txt");
    fout2.open("temp.txt");
    string stroka;

    while(n>0)
    {
        if(getline(fin1,stroka))
            fout2 << stroka<< "\n";
        else
            {cout<<"Out of range!"<<endl;
            return;}
        n--;

    }
    getline(fin1,stroka);

    while(getline(fin1,stroka))
    {
        fout2 << stroka<< "\n";
    }

    fout2.close();

    fstream fin2;
    fin2.open("temp.txt");
    ofstream fout1;
    fout1.open("file.txt");

    while(getline(fin2,stroka))
    {
        fout1 << stroka<< "\n";
    }
    fout1.close();
}

void myclass::print()
{
    cout<<endl;
    cout<<endl;
    fstream fin;
    fin.open("file.txt");
    int A=0;
    int a=0;
    string line;
    getline(fin,line);
    //cout<<line;
    for(int i=0; i<line.size(); i++)
    {
        if(line[i]==',')
            A++;
    }
    for(int i=0; i<A; i++)
        cout<<"##############";
    cout<<endl;


    /////

    a=0;
    for(int i=0; i<line.size(); i++)
    {
        a++;
        if(line[i]==',')
        {
            cout<<":";
            while(12-a>0)
            {
                cout<<" ";
                a++;
            }
            a=0;
            //cout<<"|";
        }
        else
            cout<<line[i];
    }
    cout<<":";
    cout<<endl;
    for(int i=0; i<A; i++)
        cout<<"**************";
    cout<<endl;

    //////

    while(getline(fin,line))
    {
        a=0;
        for(int i=0; i<line.size(); i++)
        {
            a++;
            if(line[i]==',')
            {
                while(13-a>0)
                {
                    cout<<" ";
                    a++;
                }
                a=0;
                //cout<<"|";
            }
            else
                cout<<line[i];
        }
        cout<<endl;
        for(int i=0; i<A; i++)
            cout<<"______________";
        cout<<endl;
    }
    for(int i=0; i<A; i++)
        cout<<"##############";
    cout<<endl;
    cout<<endl;
}

void myclass::help()
{
    cout<<"1 - create new string"<<endl;
    cout<<"2 - create new stolbik"<<endl;
    cout<<"3 - print string by string number"<<endl;
    cout<<"4 - izmenit stroky po nomery stroki"<<endl;
    cout<<"5 - delete string by string number"<<endl;
    cout<<"6 - print table"<<endl;
    cout<<"7 - print help"<<endl;
    cout<<"0 - exit"<<endl;
}

int main()
{

    cout<<" _    _ ______ _      _      ____"<<endl;
    cout<<"| |  | |  ____| |    | |    / __ \\ " <<endl;
    cout<<"| |__| | |__  | |    | |   | |  | |"<<endl;
    cout<<"|  __  |  __| | |    | |   | |  | |"<<endl;
    cout<<"| |  | | |____| |____| |___| |__| |"<<endl;
    cout<<"|_|  |_|______|______|______\\____/" <<endl;

    myclass myobj;
    myobj.create();
    myobj.help();
    while(true)
    {
        cout<<"Tape number: "<<endl;
        int n;
        cin>>n;
        if(n==0)
        {
            cout<<"Bye!";
            break;
        }
        if(n==1)
            myobj.new_string();
        if(n==2)
            myobj.new_stobik();
        if(n==3)
            myobj.vivesti_stroky();
        if(n==4)
            myobj.izmenit_stroky();
        if(n==5)
            myobj.delete_string();
        if(n==6)
            myobj.print();
        if(n==7)
            myobj.help();
    }
}
