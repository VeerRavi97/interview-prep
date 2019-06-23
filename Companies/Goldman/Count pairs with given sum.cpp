#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pi;
typedef vector<pi>vi;

#define fast ios::sync_with_stdio(0);cin.tie(0);
#define all(v) v.begin(),v.end()
#define endl "\n"
#define pb push_back()

const ll MOD=1e9+7;
const ll INF=0x3f3f3f3f;
const ll MINF=-INF;
const double EPS=1e-9;


int main(){
    fast;
    int tc;
    cin >> tc;
    while(tc--){
     vector<int>v;
     int n,sum;
     cin >> n >> sum;
     for(int i=0;i<n;i++){
         int in;
         cin >> in;
         v.push_back(in);
     }
      unordered_multiset<int>set;
      int cnt=0;
      for(int i=0;i<n;i++){

       cnt+=set.count(sum-v[i]);
          set.insert(v[i]);
      }


cout << cnt << "\n";

        
    }
    
    
    
    
}

