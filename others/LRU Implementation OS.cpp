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

class LRU{
list<int>listA; // c++ stl doubly linked list
unordered_map<int,list<int>::iterator>mp;
int cachesize=0;
public:
LRU(int size){
    this->cachesize=size;
}

void display(){
    for(auto x:listA){
        cout << x << " ";
    }
    cout << "\n";
}
void refer(int page){
 if(mp.find(page)==mp.end()){  // not avaialable in cache
  if(listA.size()==cachesize){
    cout <<  "cache is full. so remove node from tail " << "\n";
    auto last=listA.back(); // back returns element, not iterator
    listA.pop_back();// remove last element
    mp.erase(last); // remove from hash map
  }
 } 
 else // avaibale in cache
 {
     cout << "page is already in cache. so remove from that position " << "\n";
     listA.erase(mp[page]); // remove from that position
 }
 cout << "Adding page to head of the list\n";
 listA.push_front(page);// create a new node at head of the list
 mp[page]=listA.begin(); // front returns number
 }

};

 
int main(){
 LRU A(4);
 A.refer(3);
 A.display();
 A.refer(4);
 A.display();
 A.refer(5);
 A.display();
 A.refer(6);
 A.display();
 A.refer(1);
 A.display();
 A.refer(3);
 A.display();
 A.refer(5);
 A.display();


 
return 0;
}
