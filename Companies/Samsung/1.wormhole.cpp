#include<iostream>
using namespace std;
int dx,dy;
int w[10][5];
int ans,n;
int min(int a,int b){
	if(a<b) return a;
	return b;
}
int abs(int x){
	if(x<0) return -x;
	return x;
}
int dist(int x1,int y1,int x2,int y2){
	int dx=abs(x1-x2);
	int dy=abs(y1-y2);
	return dx+dy;
}

void solve(int sx,int sy,int val,int mask){

ans=min(ans,(dist(sx,sy,dx,dy)+val));
for(int i=0;i<n;i++){
   if(!(mask&(1<<i))){
     int temp1=dist(sx,sy,w[i][0],w[i][1])+w[i][4];
	 int temp2=dist(sx,sy,w[i][2],w[i][3])+w[i][4];
	 if(temp1<temp2)
	 solve(w[i][2],w[i][3],val+temp1,mask|(1<<i));
	 else
	 {
		 solve(w[i][0],w[i][1],val+temp2,mask|(1<<i));
	 }

   }
}


}
int main(){
int tc;
cin >> tc;
while(tc--){
cin >> n;
int sx,sy;
cin >> sx >> sy >> dx >> dy;
for(int i=0;i<n;i++){
	cin >> w[i][0] >> w[i][1] >> w[i][2] >> w[i][3] >> w[i][4];
}
ans=99999;
solve(sx,sy,0,0);
cout << ans << "\n";

}


}


/*

1
3
0 0 100 100
1 2 120 120 16
2 5 120 100 21
6 8 150 180 16

48


*/