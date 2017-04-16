#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <cctype>
#include <climits>
#include <vector>
#include <bitset>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <deque>
#include <string>
#include <list>
#include <iterator>
#include <sstream>
#include <complex>
#include <fstream>
#include <functional>
#include <numeric>
#include <utility>
#include <algorithm>
#include <assert.h>
 
using namespace std;
 
#define endl '\n'
#define MOD 1000000007ULL
#define INF 1000000000
#define eps 1e-8
#define ll long long
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define debug(X) cerr << " --> " << #X << " = " << X << endl
#define sd(x) scanf("%d",&(x))
#define slld(x) scanf("%lld",&(x))
#define pd(x) printf("%d\n",(x))
#define plld(x) printf("%lld\n",(x))
#define gcd __gcd
#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
 
typedef vector< vector<int> > vvi;
typedef vector< vector<ll> > vvl;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
 
class mypoint {
    public:
        int x, y;
};

int Orient(mypoint p, mypoint q, mypoint r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
 
    if (val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}

void convexHull(mypoint ConvexArray[], int n)
{
    if (n < 3)
        return;
 
    int nextPoint[n];
    for (int i = 0; i < n; i++)
        nextPoint[i] = -1;

    int l = 0;
    for (int i = 1; i < n; i++)
        if (ConvexArray[i].x < ConvexArray[l].x)
            l = i;

    int p = l, q;
    do
    {
        q = (p + 1) % n;
        for (int i = 0; i < n; i++)
            if (Orient(ConvexArray[p], ConvexArray[i], ConvexArray[q]) == 2)
                q = i;
        nextPoint[p] = q;
        p = q;
    } while (p != l);

    for (int i = 0; i < n; i++)
    {
        if (nextPoint[i] != -1)
            cout << "(" << ConvexArray[i].x << ", " << ConvexArray[i].y << ")\n";
    }
}

int main()
{
    int n;cin>>n;
    mypoint ConvexArray[n];
    for(int i=0;i<n;i++) cin>>ConvexArray[i].x>>ConvexArray[i].y;
    convexHull(ConvexArray, n);
    return 0;
}   
/*
Input:
6
5 6
1 1
0 4
2 -1 
-5 -4
1 2

Output:
(5, 6)
(0, 4)
(2, -1)
(-5, -4)

*/
