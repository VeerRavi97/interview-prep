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


void  solve(string s){
int n=s.length();
vector<int>index(26,-1);
for(int i=0;i<n;i++){
int idx=s[i]-'a';
if(index[idx]==-1){ // occured first time
    index[idx]=i;
}
else{
    index[idx]=-2;
}

}
int minm=9999999;
int ans=-1;
for(int i=0;i<26;i++)
{
    // cout << index[i] << " ";
    if(index[i]>=0 && index[i]<minm){
       ans=i;
       minm=index[i];
    }
}
// cout << "\n";
// cout << ans << "\n";

if(ans>=0 && ans <26) 
{
    char c=ans+'a';
    cout <<  c << "\n";
}
else
{
    cout << "-1" << "\n";
}



}


int main(){
    fast;
 int tc;
 cin >> tc;
 while(tc--){
 int n;
 cin >> n;
 string s;
 cin >> s;
 solve(s);
 
 }
 
return 0;
}