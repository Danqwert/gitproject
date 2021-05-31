#include <iostream>
#include <vector>
using namespace std;

int main(){

int M,N,j,i;
cin>>N>>M;
int x,y,c;
cin>>x>>y>>c;
typedef vector<int> vint;
vector <vint> A;
A.resize(N);
for(i=0;i<N;i++)
{
    A[i].resize(M);
}

for(i=0;i<N;i++)
{
    for(j=0;j<M;j++)
        cin>>A[i][j];
}


int t;
t=y;
y=x;
x=t;

int k=A[x-1][y-1];

if(x-2>=0)
{for(int i=x-2;i>=0;i--)
{
    if(A[i][y-1]==k)
        A[i][y-1]=c;
    else
        break;

}}

if(x<N){
for(int i=x;i<N;i++)
{
    if(A[i][y-1]==k)
        A[i][y-1]=c;
    else
        break;
}}

if(y-2>=0){
for(int i=y-2;i>=0;i++)
{
    if(A[x-1][i]==k)
        A[x-1][i]=c;
    else
        break;
}}

if(y<M){
for(int i=y;i<M;i++)
{
    if(A[x-1][i]==k)
        A[x-1][i]=c;
    else
        break;
}}



for(i=0;i<N;i++)
{
    for(j=0;j<M;j++)
        cout<<A[i][j]<<" ";
    cout<<endl;
}

}