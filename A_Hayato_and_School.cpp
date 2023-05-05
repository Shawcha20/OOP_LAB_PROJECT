#include <bits/stdc++.h>
using namespace std;
#define br endl
#define pr cout
#define in cin
#define v vector<int>
#define m1 map<int, int>
#define vs vector<string>
#define p pair<int, int>
#define f(n) for (int i = 1; i <= n; i++)
#define f1(n) for (int j = 0; j < n; j++)
#define lli long long int
#define ld long double
#define pb push_back
#define vpi vector<pair<int, int>>
#define vms vector<map<string, int>>
#define vmi vector<map<int, int>>
void solve()
{
    int n, odd=0, even=0;
    cin >> n;
    vector<int> vec(n, 0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x % 2 == 0)
            even++;
        else
        {
            odd++;
            vec[i] = 1;
        }
    }
    if (even >= 2 && odd >= 1)
    {
        pr<<"YES"<<br;
       int oddflag = 0, evenflag = 0,count1=0;
        for (int i = 0; i < n; i++)
        {
         if(vec[i]%2!=0){
         pr<<i+1<<" "; break;}
        }
        for( int i=0; i<n; i++)
        {
            if(vec[i]%2==0)
            {
                pr<<i+1<<" ";
                ++evenflag;
            }
            if(evenflag==2)break;
        }
        pr<<br;
    }
    else if(odd>=3&& even <2)
    {
        pr<<"YES"<<br;
        int count=0;
        for(int i=0; i<n; i++)
        {
            if(vec[i]==1)
            {
                pr<<i+1<<" ";
                ++count;
            }
            if(count==3)
            {
                break;
            }
        }
        pr<<br;
    }
    else
    {
        pr<<"NO"<<br;
    }
}
int main()
{
    int t;
    in >> t;
    bool x = true;
    if (x == true)
        while (t--)
            solve();
    else
        solve();
}