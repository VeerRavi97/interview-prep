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
 
 int  solve(int num){
 string s=to_string(num);
 int d1;
 int index1;
 for(index1=s.length()-1;index1>0;index1--){
     if(s[index1-1]-'0'<s[index1]-'0')
      break;
 }
 
 if(index1==0) return -1;
 d1=s[index1-1]-'0'; //digit which is not ascending order from right
 int index2=index1;
 for(int j=index2+1;j<s.length();j++){
      if(s[j]-'0'>d1 && s[j]-'0'<s[index2]-'0'){
        index2=j;
      }
 }
int d2=s[index2]-'0';
swap(s[index1-1],s[index2]);
reverse(s.begin()+index1,s.end()); // exclusive so +1

stringstream ss;
ss << s;
int number=0;
ss >> number;
return number;
}


int main(){
 int n;
 while(cin >> n,n>0){
     int ans=solve(n);
     cout << ans << "\n";
 }
return 0;
}



// output:
// 218765
// 251678
// 1234
// 1243
// 4321
// -1
// 536479
// 536497
// 534976
// 536479
// 1234
// 1243
// 4132
// 4213
// 4321
// -1
// 32876
// 36278
// 32841
// 34281