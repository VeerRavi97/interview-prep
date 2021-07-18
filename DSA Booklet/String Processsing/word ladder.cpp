#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;

bool differByOne(string &a, string &b)
{
    int cnt = 0;
    for (int i = 0; i < a.length(); i++)
    {
        cnt += (a[i] != b[i]);
    }
    return (cnt == 1);
}

int ladderLengthII(string beginWord, string endWord, vector<string> &wordList)
{
    if (find(all(wordList), endWord) != wordList.end())
        return 0;
    int dist = 0;
    unordered_map<string, int> visited;
    for (auto word : wordList)
        visited[word] = 0;
    queue<string> q;
    q.push(beginWord);
    while (!q.empty())
    {
        dist++;
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            string curr = q.front();
            q.pop();
            for (auto word : wordList)
            {
                if (!visited[word] && differByOne(word, curr))
                {
                    if (word == endWord)
                        return dist;
                    q.push(word);
                }
            }
        }
    }
    return 0;
}

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    if (find(all(wordList), endWord) == wordList.end())
        return 0;
    int dist = 1;
    map<string, int> visited;
    for (auto word : wordList)
        visited[word] = 0;
    queue<string> q;
    q.push(beginWord);
    while (!q.empty())
    {
        dist++;
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            string curr = q.front();
            q.pop();
            for (int j = 0; j < curr.length(); j++)
            {
                string word = curr;
                for (int k = 0; k < 26; k++)
                {
                    char ch = k + 'a';
                    word[j] = ch;
                    if (visited.count(word) > 0 && !visited[word] && differByOne(word, curr))
                    {
                        if (word == endWord)
                            return dist;
                        visited[word] = 1;
                        q.push(word);
                    }
                }
            }
        }
    }
    return 0;
}

void file_io()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    auto ip = freopen("input.txt", "r", stdin);
    auto op = freopen("output.txt", "w", stdout);
#endif
}
int main()
{
    clock_t start = clock();
    file_io();
    int tc;
    cin >> tc;
    while (tc--)
    {
        string src, dest;
        cin >> src >> dest;
        int n;
        cin >> n;
        vs v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        auto ans = ladderLength(src, dest, v);
        cout << ans << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)((double)end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}