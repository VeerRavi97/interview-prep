#include<iostream>
using namespace std;
int mat[100][20];
int n,m,ans;

void toggle(int col)
{
    for(int i=0;i<n;i++)
            mat[i][col]=!mat[i][col];
}
int cal(){
    int cnt=0;
    for(int i=0;i<n;i++){
        bool flag=true;
        for(int j=0;j<m;j++){
           if(mat[i][j]==0){
               flag=false;
               break;
           }   

        }
        if(flag) cnt++;
    }
    return cnt;
}

void func(int col,int k)
{
    //   cout << col << " " << k << " " << ans << "\n";
    if(k%2==0)
    {
        ans=max(ans,cal());
    }
    if(col==m||k==0)
        return;
    toggle(col);
    func(col+1,k-1);
    toggle(col);
    func(col+1,k);
}

int main()
{
    int t;
    t=1;
    while(t--)
    {
        int k;
        cin>>n>>m>>k;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>mat[i][j];

        // cout << "\n"; 
        ans=-99999;       
        func(0,k);
        cout<<ans<<endl;    
    }
    return 0;
}