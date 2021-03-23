#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>ii;
typedef pair<int,ii>pii;
typedef vector<vector<int> > matrix; 
priority_queue<pii,vector<pii>,greater<pii> >pq; // min heap
void merge(matrix&m){
 vector<int>res;
 for(int i=0;i<m.size();i++)
  pq.push({m[i][0],{i,0}});

while(!pq.empty()){
pii minm=pq.top();
pq.pop();
cout << "minimum element :" << minm.first << "\n";
res.push_back(minm.first);
int ktharray=minm.second.first;
int index_array=minm.second.second;
if(index_array+1<m[ktharray].size())
 pq.push({m[ktharray][index_array+1],{ktharray,index_array+1}});

}
for(auto x:res){
    cout << x << " ";
}



}


int main(){

 int k;
 cin >> k;
  matrix m(k);
 for(int i=0;i<k;i++){
  int n;
  cin >> n;
  for(int j=0;j<n;j++){
    int in;
    cin >> in;
    m[i].push_back(in);           
  }

 }
 for(int i=0;i<m.size();i++){
  for(int j=0;j<m[i].size();j++)
  cout << m[i][j] << " ";
 cout << "\n";
 }
 merge(m);
 
return 0;
}