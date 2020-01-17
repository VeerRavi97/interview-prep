#include <iostream>
using namespace std;
int det[5][5];
int mat[13][5];

void detonate(int r)
{
    for(int i=r;i>r-5 && i>=0;i--)
    {
        for(int j=0;j<5;j++)
        {
            det[r-i][j]=0;
            if(mat[i][j]==2)
            {
                det[r-i][j]=2;
                mat[i][j]=0;
            }
        }
    }
}

void undet(int r)
{
    for(int i=r;i>r-5 && i>=0;i--)
        for(int j=0;j<5;j++)
        {
            if( det[r-i][j]==2)
                mat[i][j]=2;
        }
}
void func(int n,int pos,int coins,int &maxCoins)
{
    if(pos>4||pos<0||coins<0)
        return;

    if(mat[n][pos]==2)
        coins-=1;
    else if(mat[n][pos]==1)
        coins+=1;

    if(n==1)
    {
        if(coins>maxCoins)
            maxCoins=coins;
        return;
    }
    else
    {
        func(n-1,pos+1,coins,maxCoins);
        func(n-1,pos-1,coins,maxCoins);
        func(n-1,pos,coins,maxCoins);
    }
}
int main()
{
    int t;
    cin>>t;
    int count=1;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            for(int j=0;j<5;j++)
                cin>>mat[i][j];
        int coins=0, maxCoins=-1;
        for(int j=0;j<5;j++)
            mat[n][j]=0;
        mat[n][2]=3;
        for(int j=n-1;j>=4;j--)
        {
            coins=-1;
            detonate(j);
            func(n,2,0,coins);
            if(coins>maxCoins)
                maxCoins=coins;
            undet(j);
        }
        if(maxCoins<0)
            maxCoins=-1;
        cout<<"#"<<count<<" "<<maxCoins<<endl;
        count++;
    }
}