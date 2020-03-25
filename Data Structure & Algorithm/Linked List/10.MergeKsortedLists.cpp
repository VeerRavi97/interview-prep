
#include<bits/stdc++.h>
using namespace std;
  struct ListNode {
     int val;
   ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *Merge(ListNode *a, ListNode *b){
        if(!a && !b) return nullptr;
        if(!a) return b;
        if(!b) return a;
        ListNode *result;
        if(a->val<b->val){
            result=a;
            result->next=Merge(a->next,b);
        }
        else
        { result=b;
        result->next=Merge(a,b->next);
        }
        return result;  
    }
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        if(!k) return NULL;
        for(int b=k-1;b>0;b/=2){
        int l=0;
        int r=b;
        while(l<r){
            lists[l]=Merge(lists[l],lists[r]);
            l++;
            r--;
        }
        
        }
        return lists[0];
    }
};