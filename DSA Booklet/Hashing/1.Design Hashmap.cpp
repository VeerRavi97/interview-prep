// https://leetcode.com/problems/design-hashmap

#include <bits/stdc++.h>
using namespace std;
const unsigned int table_size = 111111;
const unsigned int mod = 1e9 + 7;
class Node
{
public:
    int key;
    int value;
    Node *next;

    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
        this->next = nullptr;
    }
};

int compute_hash(int key)
{
    int p = 31;
    int p_pow = 1;
    int hash_value = 0;
    while (key)
    {
        int last_digit = key % 10;
        hash_value = (hash_value + last_digit * p_pow) % mod;
        p_pow = (p_pow * p) % mod;
        key /= 10;
    }
    return hash_value;
}

class MyHashMap
{
    Node *hashtable[table_size];

public:
    /** Initialize your data structure here. */
    MyHashMap()
    {
        for (int i = 0; i < table_size; i++)
        {
            hashtable[i] = nullptr;
        }
    }
    bool search(int key)
    {
        int index = compute_hash(key) % table_size;
        Node *start = hashtable[index];
        if (!start)
            return 0;
        while (start)
        {
            if (start->key == key)
                return 1;
            start = start->next;
        }
        return 0;
    }
    void insert(int key, int value)
    {
        int index = compute_hash(key) % table_size;
        Node *start = hashtable[index];
        Node *newNode = new Node(key, value);

        /* option 1: Insert at beginning (Best)
         newNode->next = hashtable[index];
         hashtable[index] = newNode; // always recently added

        */
        //***************** Option 2 **************
        if (!start)
        {
            hashtable[index] = newNode;
            return;
        }

        while (start->next)
        {
            start = start->next;
        }
        start->next = newNode;

        // ************END****************
    }
    void insert2(int key, int value)
    {
        int index = compute_hash(key) % table_size;
        Node *start = hashtable[index];
        Node *newNode = new Node(key, value);
        newNode->next = hashtable[index];
        hashtable[index] = newNode;
    }

    void update(int key, int value)
    {
        int index = compute_hash(key) % table_size;
        Node *start = hashtable[index];
        if (!start)
            return;
        while (start)
        {
            if (start->key == key)
            {
                start->value = value;
                return;
            }
            start = start->next;
        }
    }
    /** value will always be non-negative. */
    void put(int key, int value)
    {
        bool exists = search(key);
        if (exists)
            update(key, value);
        else
            insert(key, value);
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key)
    {
        int index = compute_hash(key) % table_size;
        Node *start = hashtable[index];
        if (!start)
            return -1;
        while (start)
        {
            if (start->key == key)
                return start->value;
            start = start->next;
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key)
    {
        int index = compute_hash(key) % table_size;
        Node *start = hashtable[index];
        if (!start)
            return;

        if (start->key == key)
        {
            Node *dealloc = start->next;
            hashtable[index] = dealloc;
            delete start;
            return;
        }
        Node *pre = start;
        start = start->next;

        while (start)
        {
            if (start->key == key)
            {
                pre->next = start->next;
                delete start;
                return;
            }
            pre = start;
            start = start->next;
        }
    }
};

int main()
{

    MyHashMap *hashMap = new MyHashMap();
    freopen("output.txt", "w", stdout);
    hashMap->put(1, 1);
    hashMap->put(2, 2);
    cout << hashMap->get(1) << endl; // returns 1
    cout << hashMap->get(3) << endl; // returns -1 (not found)
    hashMap->put(2, 1);              // update the existing value
    cout << hashMap->get(2) << endl; // returns 1
    hashMap->remove(2);              // remove the mapping for 2
    cout << hashMap->get(2) << endl; // returns -1 (not found)
}
