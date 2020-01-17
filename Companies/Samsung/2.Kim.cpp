#include<iostream>
using namespace std;
int n,sx,sy,dx,dy;
int ans;
int x[10];
int y[10];
int abs(int x){
    if(x<0)return -x;
    return x;
}
int min(int a,int b){
    if(a<b) return a;
    return b;
}
int dist(int x1,int y1,int x2,int y2){
    int dx=abs(x1-x2);
    int dy=abs(y1-y2);
    return dx+dy;
}
void solve(int sx,int sy,int val,int mask){
    
    if(mask==(1<<n)-1){
        
        int num=dist(sx,sy,dx,dy)+val;
          ans=min(ans,num);
          return;
    }
    
  
   for(int i=0;i<n;i++){
       if(!(mask&(1<<i))){
           int temp=val+dist(sx,sy,x[i],y[i]);
           solve(x[i],y[i],temp,mask|(1<<i));
       }
   } 
    
    
}
int main(){
    int tc,index=1;
    tc=10;
    while(tc--){
        cin >> n;
        cin >> sx >> sy>>dx>>dy;
        for(int i=0;i<n;i++){
            cin >> x[i] >> y[i];
    //   visited[i]=0;
        }
        ans=99999;
        // cout << "step 1" << "\n";
    
        solve(sx,sy,0,0);
        cout << "# " << index << " " << ans << "\n";
        index++;
        
    }
    
    return 0;
}