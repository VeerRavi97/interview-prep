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

int BitonicPoint(vi&v){
int n=v.size();
int start=0;
int end=n-1;
while(start<=end){

int mid=(start+end)/2;
int nxt=(mid+1)%n; // for edge case, array is only increasing
int pre=(mid-1+n)%n; // for edge case, array is only decreasing
if(v[mid]>v[pre] && v[mid]>v[nxt]) return mid;
else if(v[mid]<v[mid+1]) // the array is ascending order, search in right subarray
start=mid+1;
else
{
    end=mid-1;
}

}
return -1;

}

int binarysearch_asc(vi&v,int start,int end,int num){
while(start<=end){
    
int mid=(start+end)/2;
if(v[mid]==num){
return mid;
} 
else if(v[mid]>num){
    end=mid-1;
}
else
{
   start=mid+1;
}

}
// cout << "not found " << "\n";
return -1;

}
int binarysearch_desc(vi&v,int start,int end,int num){
while(start<=end){
int mid=(start+end)/2;
if(v[mid]==num) return mid;
else if(v[mid]<num){
    end=mid-1;
}
else
{
   start=mid+1;
}

}

return -1;

}

int search(vi&v,int num){
  int pindex=BitonicPoint(v);
  // cout << pindex << "\n";
  int start=0;
  int end=v.size()-1;
  if(v[pindex]==num) return pindex;
	int l=binarysearch_asc(v,0,pindex,num);
	if(l==-1)
	return binarysearch_desc(v,pindex+1,v.size()-1,num);
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
 int num;
 cin >> num;
  int index=search(v,num);
  cout << index << "\n";

  
 }
 
return 0;
}