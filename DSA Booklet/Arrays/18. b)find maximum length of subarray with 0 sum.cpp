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

int solve(vi&arr){

    unordered_map<int, int> presum; 
  
    int sum = 0;  
    int max_len = 0; 
     int n=arr.size();

    for (int i = 0; i < n; i++) { 
      
        sum += arr[i]; 
  
       
        if (sum == 0) 
            max_len = i + 1; 
  
        if (presum.find(sum) != presum.end()) { 
            max_len = max(max_len, i - presum[sum]); 
        } 
        else { 
            presum[sum] = i; 
        } 
    } 
  
    return max_len; 


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
int ans=solve(v);
cout << ans << "\n";

  
 }
 
return 0;
}