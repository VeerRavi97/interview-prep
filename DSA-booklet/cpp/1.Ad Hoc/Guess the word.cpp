#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define MOD 10000000007
#define all(c) c.begin(), c.end()
#define endl '\n'
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
class Master
{
    string secret;
    int counter;

public:
    Master(string secret)
    {
        this->secret = secret;
        this->counter = 0;
    }
    int guess(string word)
    {
        int cnt = 0;
        this->counter++;
        for (int i = 0; i < word.length(); i++)
        {
            if (word[i] == secret[i])
                cnt++;
        }
        return cnt;
    }
    int getCounter() { return this->counter; }
};
class Solution
{
public:
    vector<string> prune(vector<string> &wordlist, string randWord, int matchCount)
    {
        vector<string> prunedList;
        for (int i = 0; i < wordlist.size(); i++)
        {
            int curMatchCount = 0;
            for (int j = 0; j < randWord.length(); j++)
            {
                if (randWord[j] == wordlist[i][j])
                {
                    curMatchCount += 1;
                }
            }

            if (curMatchCount == matchCount || (curMatchCount == 0 && matchCount == -1))
            {
                prunedList.push_back(wordlist[i]);
            }
        }
        return prunedList;
    }

    string getRandomWord(vector<string> &wordlist)
    {
        int start = 0;
        int end = wordlist.size();
        int idx = start + rand() % (end - start);
        return wordlist[idx];
    }
    void findSecretWord(vector<string> &wordlist, Master &master)
    {
        for (int i = 0; i < 10; i++)
        {
            string randWord = getRandomWord(wordlist);
            int matchCount = master.guess(randWord);
            wordlist = prune(wordlist, randWord, matchCount);
        }
    }
};

void file_io()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
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
    srandom(time(NULL));
    while (tc--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        string secret;
        cin >> secret;
        Master master(secret);
        Solution solution;
        solution.findSecretWord(v, master);
        if (master.getCounter() <= 10)
            cout << "You guessed it correctly with Limit" << endl;
        else
            cout << "you made extra calls" << endl;
    }
    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = (double)((double)end - start) / CLOCKS_PER_SEC;
    cout << "Executed in " << cpu_time_used << "s" << endl;
#endif
}