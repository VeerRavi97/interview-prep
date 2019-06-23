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
    
     cin.ignore();
    while(tc--){
     string s;
    
     getline(cin,s);
     stringstream ss;
     ss << s;
     string word;
     int maxlen=0;
     string ans;
     while(ss >> word)
  {
    //   cout << word << "\n";
      if(!(word.length()&1)){
        if(maxlen<word.length()){
            maxlen=word.length();
            ans=word;
        }
      }
  }
   cout << ans << "\n";
        
    }
    
    
    
    
}

