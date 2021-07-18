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
 int solve(vi&v,int sum){
  int ans=0;
  unordered_set<int>s;
  for(int i=0;i<v.size();i++){
   int tem=sum-v[i];
   if(s.find(tem)!=s.end()) return 1;
   s.insert(v[i]);
  }
return 0;


 }

int main(){
    fast;
 int tc;
 cin >> tc;
 while(tc--){
 int n,sum;
 cin >> n >> sum;
 vi v;
 for(int i=0;i<n;i++){
   int in;
 cin >> in;
 v.push_back(in);
 }
 
 int ans=solve(v,sum);
  if(ans) cout << "Yes" << "\n";
  else cout << "No" << "\n";
  
 }
 
return 0;
}