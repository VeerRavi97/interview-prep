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
 
int partition(vi &v,int start,int end){
int pivot=v[end];
int pindex=start-1;
for(int i=start;i<end;i++){
    if(v[i]<=pivot){
        swap(v[++pindex],v[i]);
    }

}
 swap(v[++pindex],v[end]);
return pindex;


}

int randomizedpartition(vi&v,int start,int end){
    int n=end-start;
     srand (time(NULL)); // seed the time
    int random = start + rand() % n;
swap(v[random],v[end]);
int pindex=partition(v,start,end);
return pindex;

}


void quicksort(vi &v,int start,int end){
   if(start<end){
    int pindex=randomizedpartition(v,start,end);
    quicksort(v,start,pindex-1);
    quicksort(v,pindex+1,end);

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

 quicksort(v,0,n-1);
for(auto x:v){
    cout << x << " ";
}
return 0;
}