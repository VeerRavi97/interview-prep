#include <iostream>
#include <set>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

class Solution
{
public:
    Node *insert(Node *head, int val)
    {
        Node *nn = new Node(val);
        if (!head)
        {
            head = nn;
            return head;
        }
        Node *ptr = head;
        while (ptr->next)
        {
            ptr = ptr->next;
        }
        ptr->next = nn;
        return head;
    }
    void display(Node *head)
    {
        Node *ptr = head;
        while (ptr)
        {
            cout << ptr->val << " ";
            ptr = ptr->next;
        }
        cout << "\n";
    }

    Node *RemoveDuplicates(Node *head) // Complex
    {
        if (!head || !head->next)
            return head;
        Node *curr = head;
        while (curr->next)
        {
            if (curr->val == curr->next->val)
            {
                // cout << "duplicates " << curr->val << "\n";
                Node *next = curr->next->next;
                delete (curr->next);
                curr->next = next;
            }
            else
                curr = curr->next;
        }
        curr->next = NULL;
        return head;
    }
    Node *removeDuplicates(Node *head)
    {
        if (!head || !head->next)
            return head;
        Node *curr = head->next;
        Node *pre = head;
        while (curr)
        {
            if (curr->val == pre->val) // Same
                curr = curr->next;
            else // different
            {
                pre->next = curr;
                pre = curr;
                curr = curr->next;
            }
        }
        pre->next = nullptr;
        return head;
    }

    Node *removeDuplicatesII(Node *head) // All duplicates including itself
    {
        if (!head || !head->next)
            return head;
        Node *dummy = new Node(-1);
        dummy->next = head;
        Node *curr = head;
        Node *pre = dummy;
        while (curr)
        {
            while (curr->next && curr->next->val == curr->val)
                curr = curr->next; // last occurrence of ele
            if (pre->next == curr)
            {
                pre = curr;
                //  pre = pre->next;
            }
            else
            {
                pre->next = curr->next;
            }
            curr = curr->next;
        }
        // pre->next = nullptr;
        return dummy->next;
    }

    Node *RemoveDuplicatesUnsorted(Node *head)
    {
        if (!head || !head->next)
            return head;
        set<int> st;
        Node *curr = head;
        Node *pre = NULL;
        while (curr)
        {
            if (st.find(curr->val) != st.end())
            {
                pre->next = curr->next;
                delete (curr);
            }
            else
            {
                st.insert(curr->val);
                pre = curr;
            }
            curr = pre->next;
        }

        return head;
    }
};
int main()
{
    Node *head = NULL;
    Solution obj;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        head = obj.insert(head, in);
    }

    head = obj.RemoveDuplicatesUnsorted(head);
    obj.display(head);
}
