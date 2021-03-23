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


void solve(vi&v){
int n=v.size();
int zero_index=-1;
int two_index=n;
for(int one_index=0;one_index<n&&one_index<two_index;one_index++){
if(v[one_index]==0){
    swap(v[one_index],v[++zero_index]);
}
else if(v[one_index]==2){
swap(v[one_index],v[--two_index]);
one_index--; // don't increase 1's index, as replaced value may be zero
}
}
}
 
int main(){
    fast;
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
  for(auto x:v)
  cout << x << " ";

  cout << "\n";
  
 }
 
return 0;
}