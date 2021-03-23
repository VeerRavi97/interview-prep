#include <bits/stdc++.h>
using namespace std;

#define all(c) (c).begin(), (c).end()
#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);
class Node
{
public:
    int key, value;
    Node *pre, *next;
    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
        this->next = this->pre = nullptr;
    }
};

class LRU
{
    int cachesize = 0; // capacity of the cache
    unordered_map<int, Node *> mp;
    Node *head, *tail; // dummy head and dummy tail
    int count = 0;

public:
    LRU(int cachesize)
    {
        this->cachesize = cachesize;
        head = new Node(-1, -1);
        tail = new Node(-2, -2);
        head->next = tail;
        tail->pre = head;
        head->pre = nullptr;
        tail->next = nullptr;
    }

    void display()
    {
        Node *ptr = head->next;
        cout << "the list is : ";
        while (ptr != tail)
        {
            cout << "(" << ptr->key << "," << ptr->value << ")"
                 << " ";
            ptr = ptr->next;
        }
        cout << "\n";
    }

    void removeNode(Node *refer)
    {
        cout << "removing " << refer->key << " from list "
             << "\n";
        refer->pre->next = refer->next;
        refer->next->pre = refer->pre;
    }
    void addNodeToHead(Node *refer)
    {
        cout << "adding " << refer->key << " to head of list "
             << "\n";
        Node *temp = head->next;
        refer->next = temp;
        temp->pre = refer;
        refer->pre = head;
        head->next = refer;
    }

    int get(int key)
    {
        int res = -1;
        if (mp.find(key) != mp.end())
        { // key found in cache
            cout << "key " << key << " is already in cache, access and bring to head of list"
                 << "\n";
            Node *refer = mp[key]; //  get the referred node
            res = refer->value;    // get the value of the key
            removeNode(refer);     // remove node from middle of linked list
            addNodeToHead(refer);  // add that node to the head of the list
        }
        else
        { // key not found in cache
            cout << "Key " << key << " not found in cache "
                 << "\n";
        }
        return res;
    }
    void put(int key, int value)
    {

        if (mp.find(key) != mp.end())
        {
            cout << "key " << key << " is already in cache, update the value"
                 << "\n"; // if key is already in cache, then update the value of key
            Node *refer = mp[key];
            refer->value = value; // update the value
            removeNode(refer);    // remove the node from middle of list
            addNodeToHead(refer); // add to the head of the list
        }
        else
        {
            cout << "key " << key << " is not in cache, insert the (" << key << "," << value << ")"
                 << "\n";
            Node *MRUelement = new Node(key, value); // create a node that will  be the most recently used
            mp[key] = MRUelement;
            if (count < cachesize)
            { // if cache is not full
                count++;
                addNodeToHead(MRUelement);
            }
            else
            {
                cout << "cache is full\n";
                Node *LRUelement = tail->pre; // if cache is full
                cout << "LRU element :" << LRUelement->key << "\n";
                mp.erase(LRUelement->key);
                removeNode(LRUelement); // delete the LRU element
                addNodeToHead(MRUelement);
            }
        }
    }
};

int main()
{
    LRU cache(4);
    cache.display();
    cache.put(1, 10);
    cache.display();
    cache.put(2, 30);
    cache.display();
    cache.put(3, 40);
    cache.display();
    cache.put(4, 70);
    cache.display();
    cache.put(6, 50);
    cache.display();
    cout << "the value of key 1:" << cache.get(1);
    cout << endl;
    cache.display();

    cout << "the value of key 3:" << cache.get(3);
    cout << endl;
    cache.display();
    cache.put(1, 50);
    cache.display();
    cache.put(12, 17);
    cache.display();
    cache.put(5, 20);
    cache.display();
    cout << "the value of key 12:" << cache.get(12);
    cout << endl;
    cache.display();
    cout << "the value of key 4:" << cache.get(4);
    cout << endl;
    cache.display();

    return 0;
}