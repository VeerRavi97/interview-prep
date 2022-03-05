#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define CHAR_SIZE 26
struct Node
{
    bool exist; // true when the node is a leaf node
    Node *children[CHAR_SIZE];

    Node()
    {
        exist = false;

        for (int i = 0; i < CHAR_SIZE; i++)
        {
            children[i] = nullptr;
        }
    }
};

void freeTrie(Node *node)
{
    if (!node)
    {
        return;
    }

    for (int i = 0; i < CHAR_SIZE; i++)
    {
        freeTrie(node->children[i]);
    }

    delete node;
}

void insertTrie(Node *const head, string const &s)
{
    Node *node = head;
    for (char ch : s)
    {
        if (node->children[ch - 'a'] == nullptr)
        {
            node->children[ch - 'a'] = new Node();
        }
        node = node->children[ch - 'a'];
    }
    node->exist = true;
}

bool wordBreak(Node *const head, string const &s)
{
    // get the length of the string
    int n = s.length();

    // `good[i]` is true if the first `i` characters of `s` can be segmented
    vector<bool> good(n + 1);
    good[0] = true; // base case

    for (int i = 0; i < n; i++)
    {
        if (good[i])
        {
            Node *node = head;
            for (int j = i; j < n; j++)
            {
                if (!node)
                {
                    break;
                }

                node = node->children[s[j] - 'a'];

                if (node && node->exist)
                {
                    good[j + 1] = true;
                }
            }
        }
    }
    return good[n];
}

int main()
{
    // vector of strings to represent a dictionary
    vector<string> words =
        {
            "this", "th", "is", "famous", "word", "break", "b", "r",
            "e", "a", "k", "br", "bre", "brea", "ak", "prob", "lem"};

    // given string
    string s = "wordbreakproblem";

    // create a Trie to store the dictionary
    Node *trie = new Node();
    for (string const &s : words)
    {
        insertTrie(trie, s);
    }

    // check if the string can be segmented or not
    if (wordBreak(trie, s))
    {
        cout << "The string can be segmented";
    }
    else
    {
        cout << "The string can't be segmented";
    }

    // deallocate memory used by the Trie
    freeTrie(trie);

    return 0;
}
