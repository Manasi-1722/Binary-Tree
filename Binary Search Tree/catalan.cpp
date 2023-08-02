#include <bits/stdc++.h>
using namespace std;

int calatan(int n)
{
    if(n <= 1)
    {
        return 1;
    }
    int ans = 0;
    for(int i=0; i<=n-1; i++)
    {
        ans += calatan(i) * calatan(n-i-1);
    }
    return ans;
}
int main()
{
    for(int i=0; i<10; i++)
    {
        cout << calatan(i) << " ";
    }
    cout << endl;

    return 0;
}