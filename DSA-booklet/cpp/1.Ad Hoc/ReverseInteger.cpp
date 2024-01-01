#include <iostream>
#include <algorithm>
#include <vector>
#include<unordered_map>
#define ll long long
#define MOD 1e9 + 7
#define all(c) c.begin(), c.end()
#define endl '\n'
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
bool isPalindrome(int x)
{
    string word = to_string(x);
    int l= 0;
    int r= word.length()-1;
    while(l<r){
        if(word[l]!=word[r]) return false;
        l++;
        r--;
    }
    return true;

}

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
    while (tc--)
    {
        int num;
        cin >> num;
        auto ans = isPalindrome(num);
        cout << ans << endl;
    }
    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = (double)((double)end - start) / CLOCKS_PER_SEC;
    cout << "Executed in " << cpu_time_used << "s" << endl;
#endif
}