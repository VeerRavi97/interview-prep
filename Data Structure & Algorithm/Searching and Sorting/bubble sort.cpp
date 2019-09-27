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
 
void bubblesort(vi &v){
    int isswapped=0;
 for(int i=0;i<v.size()-1;i++){
  for(int j=0;j<v.size()-i-1;j++){
      if(v[j]>v[j+1]) {
          isswapped=1;
          swap(v[j],v[j+1]);
      }
     
  }
 if(!isswapped) break;
 }



}

int main(){
 vi v;
 int n;
 cin >> n;
 for(int i=0;i<n;i++){
int in;
cin >> in;
v.push_back(in);
 }
 bubblesort(v);
for(auto x:v){
    cout << x << " ";
}
return 0;
}