
/*
Input: Java is Great
O/p: avaJ si taerg

*/
#include <iostream>
using namespace std;

class Utility
{
public:
    void reverse(string &word)
    {
        int l = 0;
        int r = word.length() - 1;
        while (l < r)
        {
            swap(word[l], word[r]);
            l++;
            r--;
        }
    }
};

class Solution
{
public:
    string reverseText(string str)
    {
        string word = "";
        Utility utility;
        string res;
        int len = str.length();
        for (int i = 0; i <= len; i++) // Java is Great
        {
            char ch = '';
            if (ch == ' ' || word == " ")
            {
                utility.reverse(word);
                res += word;
                res += " ";
                word = "";
            }
            else
                word += ch;
        }
        //  utility.reverse(word);
        // res += word;
        return res;
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    string str;
    getline(cin, str);
    Solution solution;
    cout << solution.reverseText(str) << endl;

    return 0;
}

/*

 N sorted linked lists
 The ask is: Merge al LLs
l1 l2 l3 l4 l5  // On=(nlogn) // n= n1+n2
// l1l2
// (l1l2)l3
// K* n //

// (l1l2) -> (l1) (l3,l4)-> l3 l5
// (l1)

// LogK* N


*/

#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
    }
};

class Utility
{

public:
    Node *merge(Node *head1, Node *head2)
    {
        if (!head1 && !head2)
            return nullptr;
        if (!head1)
            return head2;
        if (!head2)
            return head1;
        Node *res = nullptr;
        if (head1->val < head2->val)
        {
            res = head1;
            res->next = merge(head1->next, head2);
        }
        else
        {
            res = head2;
            res->next = merge(head1, head2->next);
        }
        return res;
    }
};

class Solution
{
public:
    Node *MergeKLists(vector<Node *> list, int k)
    {
        Utility utility;
        for (int times = k - 1; times >= 0; times /= 2) // l1 l2 l3 l4 l5, k = 5
        {
            int l = 0;     //  0 , 0, 0
            int r = times; //  4, 2, 1
            while (l < r)
            {
                list[l] = utility.merge(list[l], list[r]); // (l1l5) (l2l4) (l3)    2nd run (l1l5l3) (l2l4)  3rd run (l1l5l3l2l4)
                l++;
                r--;
            }
        }
        return list[0];
    }
};

// k = 3
// 1 , 2, 4, 5
// 3, 4,5, 6
//  1, 5, 6,7

// k= 1
// 1, 2, 3, 4

// k=2
// 1, 4, 5,6
// null

// k= 5
// 3 4 6 8 9
// null
// null
// 1 3 4 6 7
// 1

int main()
{
    int k;
    cin >> k;
    vector<Node *> list(k, nullptr);

    return 0;
}

// 1 4 -5 7 6 10

// dp[i]:

void MSIS(vector<int> &v)
{

    int res;
    for (int i = 1; i < n; i++)
    {
        dp[i] = v[i];
        for (int j = i - 1; j > 0; j--)
        {

            if (v[i] > v[j])
            {
                res = max(res, v[i] + dp[j]);
                parent[i] = j;
                dp[i] = v[i] + dp[j];
            }
        }
    }
}