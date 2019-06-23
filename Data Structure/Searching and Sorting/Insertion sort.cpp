#include<bits/stdc++.h>
using namespace std;
void insertionsort(vector<int>&v){
int n=v.size();
for(int i=1;i<n;i++){
    int key=v[i];
    int j=i-1;
    while(j>=0&&v[j]>key){
        v[j+1]=v[j];
        j--;
    }
    v[j+1]=key;
}
}
int binarysearch(int start,int end,int key,const vector<int>&v){
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (v[mid] == key)
            return mid;
            else if(v[mid]<key)
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
            
    }  
    return mid;
}

void binaryInsertionSort(vector<int>&v){
int n=v.size();
for(int i=1;i<n;i++){
   int key=v[i];
   int c=binarysearch(0,i-1,key,v);
   int j=i-1;
   while(j>=c){
       v[j+1]=v[j];
       j--;
   }
v[j+1]=key;
}

}
int main(){
int n;
cin >> n;
vector<int>v;
for(int i=0;i<n;i++){
    int in;
    cin >> in;
    v.push_back(in);
}
insertionsort(v);
for(auto x:v){
    cout << x << " ";
}

cout << "\n";
random_shuffle(v.begin(),v.end());
binaryInsertionSort(v);
for(auto x:v){
    cout << x << " ";
}

}