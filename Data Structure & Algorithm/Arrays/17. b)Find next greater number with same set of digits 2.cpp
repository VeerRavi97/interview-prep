#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll>vi;
typedef pair<ll,ll>ii;
typedef vector<ii>vii;
 
#define all(c) (c).begin(),(c).end()
#define fast ios::sync_with_stdio(0);cin.tie(0);
 
const ll MOD=1e9+7;
const ll INF=0x3f3f3f3f;
const double EPS=1e-9;
const ll MAX_N=1e5+5;


void solve(vi &v){
int n=v.size();
int index1;
for( index1=n-1;index1>0;index1--){
     if(v[index1-1]<v[index1])
      break;
}
if(index1==0) 
{
return;
}
int d1=v[index1-1];
int index2=index1;

for(int j=index2+1;j<n;j++){
    if(v[j]>d1 && v[j]<v[index2]){
        index2=j;
    }
}
int d2=v[index2];
// cout << d1 <<  " " << d2 << "\n";
swap(v[index1-1],v[index2]);
// for(auto x:v){
//       cout << x << " ";
//   }
//   cout << "\n";
//   cout << index1 << " " << index2+1 << "\n";
reverse(v.begin()+index1,v.end());
// for(auto x:v){
//       cout << x << " ";
//   }
//    cout << "\n";
return;
}

 
int main(){
 int tc;
 cin >> tc;
 while(tc--){
 int n;
 cin >> n;
 vi v;
 for(int i=0;i<n;i++){
   int in;
 cin >> in;
 v.push_back(in);
 }
  solve(v);
  for(auto x:v){
      cout << x << " ";
  }
  cout << "\n";
  
 }
 
return 0;
}