// API
bool isBadVersion(int num)
{
    false;
}

int firstBadVersion(int n)
{
    int start = 1;
    int end = n;
    int ans = 0;
    while (start <= end)
    {
        int mid = start + ((end - start) >> 1L);
        if (isBadVersion(mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}