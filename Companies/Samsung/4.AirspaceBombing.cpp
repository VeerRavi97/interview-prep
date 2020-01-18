#include<iostream>
using namespace std;
int ans,n;
int a[20][5];
void init(){
    for(int i=0;i<20;i++)
    for(int j=0;j<5;j++)
     a[i][j]=0;
}
int max(int a,int b){
    if(a>b) return a;
    return b;
}
void solve(int cr, int cc, int val, int bomb,int effect){
if(cr==-1){
    ans=max(ans,val);
    return;
}
for(int i=-1;i<=1;i++){
int r=cr;
int c=cc+i;
if( c<0 || c>4) continue;
if(a[r][c]==2){
if(bomb==0 && effect>0)
solve(r-1,c,val,bomb,effect-1);
else if(bomb==1)
    solve(r-1,c,val,0,5);
}
else{
    
if(effect>0)
solve(r-1,c,val+a[r][c],bomb,effect-1);
else
{
    solve(r-1,c,val+a[r][c],bomb,effect);
}


}
}

}


int main(){
int tc;
cin >> tc;
int index=1;

while(tc--){
    init();
ans=-99999;
cin >> n;
for(int i=0;i<n;i++){
    for(int j=0;j<5;j++)
    cin >> a[i][j];
}

solve(n-1,2,0,1,0);
cout << "#" << index << " " << ans << "\n";
index++;

}


}


/*
5
7
1 2 0 0 1
2 0 0 1 0
0 1 2 0 1
1 0 0 2 1
0 2 1 0 1
0 1 2 2 2
1 0 1 1 0
5
1 1 0 0 0
1 2 2 2 1
1 1 2 2 1
2 2 2 1 2
2 2 0 2 0
6
2 2 2 2 2
0 0 0 0 0
0 0 2 0 0
2 0 0 0 2
0 0 0 0 0
1 2 2 2 1
10
2 2 2 2 0
1 2 0 0 2
0 2 0 0 0
2 2 0 2 2
0 2 2 2 0
0 0 0 0 0
1 0 0 0 2
0 0 0 0 0
0 2 0 2 1
0 2 2 2 0
12
2 2 0 2 2
0 1 0 2 1
0 2 0 1 0
2 1 2 1 0
0 2 2 1 2
0 1 2 2 2
0 2 1 0 2
2 0 1 1 2
2 1 1 0 1
0 2 2 0 0
2 0 1 2 2
2 2 1 2 1

#1 6
#2 3
#3 0
#4 1
#5 9




*/