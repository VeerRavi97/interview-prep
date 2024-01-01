#include <iostream>
#include <cstring>
using namespace std;
#define ll long long
const unsigned int mod = 1e9 + 7;
struct Node
{
    char key[20];
    Node *next;
};
ll compute_hash(char s[])
{
    ll hash_value = 0;
    int p = 31;
    ll p_pow = 1;
    int i = 0;
    while (s[i] != '\0')
    {
        hash_value = (hash_value + (s[i] - 'a' + 1) * p_pow) % mod;
        p_pow = (p_pow * p) % mod;
        i++;
    }
    return hash_value;
}
const int MAX_N = 1;
Node *hashtable[MAX_N];
void copy(char *dest, char *src)
{
    int len = 0;
    while (src[len] != '\0')
    {
        dest[len] = src[len];
        len++;
    }
}
void insert(char key[])
{
    Node *newNode = new Node();
    newNode->next = nullptr;
    strcpy(newNode->key, key);
    int hash_index = compute_hash(key) % MAX_N;
    Node *curr = hashtable[hash_index];
    if (!curr)
    {
        curr = newNode;
        hashtable[hash_index] = curr;
    }
    else
    {
        while (curr->next)
        {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}
int search(char key[])
{

    int hash_index = compute_hash(key) % MAX_N;
    Node *start = hashtable[hash_index];
    if (!start)
        return 0;
    while (start)
    {
        if (strcmp(key, start->key) == 0)
            return 1;
        start = start->next;
    }
    // cout << endl;
    return 0;
}
int remove(char key[])
{
    int hash_index = compute_hash(key) % MAX_N;
    Node *start = hashtable[hash_index];
    Node *dealloc;
    if (!start)
        return 0;
    if (strcmp(key, start->key) == 0)
    {
        dealloc = start->next;
        delete start;
        hashtable[hash_index] = dealloc;
        return 1;
    }
    else
    {
        Node *pre = NULL;
        start = hashtable[hash_index];
        while (start)
        {
            if (strcmp(key, start->key) == 0)
            {
                pre->next = start->next;
                delete start;
                return 1;
            }
            pre = start;
            start = start->next;
        }
    }
    return 0;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    // cout << "Insert n Keys" << endl;
    int n;
    cin >> n;
    char s[20];
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        insert(s);
    }
    // cout << "Search n Keys" << endl;
    char out[20];
    for (int i = 0; i < n; i++)
    {
        cin >> out;
        cout << search(out) << endl;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> out;
        cout << remove(out) << endl;
    }
}