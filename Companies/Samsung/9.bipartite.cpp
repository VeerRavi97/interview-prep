#include<iostream>
using namespace std;

int color[1000];
bool edge[1000][1000];
int e,v;
int q[1000]={0};
int front=0,back=0;
void push(int x){
    q[back++]=x;
}
int pop(){
    int temp=q[front];
    front++;
    return temp;
}
bool isEmpty(){
    return(front==back);
}
void reset(){
 for(int i=0;i<1000;i++){
    for(int j=0;j<1000;j++){
        edge[i][j]=false;
    }
    color[i]=-1;
 }
}

bool isBipartite(int src){
 color[src]=1;
 push(src);

  while(!isEmpty()){
    int node = pop();
    if(edge[node][node]){  // self loop
        return false;
    }
    for(int i=0;i<v;i++){
        if(edge[node][i]){
            if(color[i]==-1){
                color[i]=1-color[node];
                push(i);
            }
            else if(color[i]==color[node]){
                return false;
            }
        }
    }
  }
  return true;
}

int main(){

 reset();
 cin >> v >> e;
 for(int i=0;i<e;i++){
    int x,y;
    cin >> x >> y;
    edge[x-1][y-1]=true;
 }
  int flag = 0;
  for(int i=0;i<v;i++){
    if(color[i]==-1){
        if(!isBipartite(i)){
            flag=1;
            cout << "No" << endl;
        }
    }
  }
  if(flag==0){
    for(int i=0;i<v;i++){
        if(color[i]==0){
            cout << color[i] << " ";
        }
    }
  }
 cout << endl;
 return 0;
}