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
 
int main(){
    fast;
 ll tc;
 cin >> tc;
 while(tc--){
  ll n;
  cin >> n;
  ll sum=0;
  vector<ll>v;
  for(int i=0;i<n;i++){
   ll in;
   cin >> in;
   sum+=in;
   v.push_back(in);
  }
   double mean=(double)sum/n;
  ll ans=-1;
   double reqmean=mean*(n-1);
  for(ll i=0;i<n;i++){
      double calc=(sum-v[i]);
    //   cout << calc << " " << reqmean << " "  << calc-reqmean << "\n";
      if(abs(calc-reqmean)<EPS){
          ans=i;
          break;
      }
  }
  if(ans>=0) {
      ans+=1;
   cout << ans << "\n";
  }
  else
  {
      cout << "Impossible" << "\n";
  }
  

 }
 
return 0;
}