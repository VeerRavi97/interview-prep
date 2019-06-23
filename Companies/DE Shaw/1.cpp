#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,string>pi;
typedef vector<ll>vi;

#define fast ios::sync_with_stdio(0);cin.tie(0);
#define all(v) v.begin(),v.end()
#define endl "\n"
#define del cout << "\n"
#define pb push_back()

const ll MOD=1e9+7;s
const ll INF=0x3f3f3f3f;
const ll MINF=-INF;
const double EPS=1e-9;
ll count( string s){
unordered_set<int>st;
for(auto x:s){
if(isupper(x))
x=tolower(x);
st.insert(x);
}
return st.size();
}
bool comp(pi a,pi b){
  return a.first>b.first;
}

vector<string> solve(int n,vector<string>&input){
vector<pi>v;
vector<string>ans;
for(auto x:input){
    int cnt=count(x);
    v.push_back({cnt,x});
}
sort(all(v),comp);
for(auto x:v)
{
    ans.push_back(x.second);
}
return ans;
}


int main(){
    int n;
    cin >> n;
    vector<string>in;
  for(int i=0;i<n;i++){
     string s;
     cin >> s;
     in.push_back(s);
  }
    vector<string>ans=solve(n,in);
    for(auto x:ans){
        cout << x <<  "\n";
    }
    
    
    
    
}

