#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <sstream>
#include <cstdio>

using namespace std;

typedef unsigned long long ullong;
typedef long long llong;
typedef vector<llong> VI;
typedef vector<VI> VII;

VI V;
void _run(llong cur)
{
    if(cur > 44444444444)
        return ;
    V.push_back(cur);
    _run(cur * 10 + 4);
    _run(cur * 10 + 7);
}
inline llong next(llong val)
{
    return V[lower_bound(V.begin(), V.end(), val) - V.begin()];
}

int main()
{
    _run(4);
    _run(7);
    sort(V.begin(), V.end());
    llong l, r;
    cin >> l >> r;
    llong sum = 0;
    while(l <= r)
    {
        llong nxt = next(l);
        if( nxt > r )
            sum += ( (r - l + 1) * nxt );
        else
            sum += ( (nxt - l + 1) * nxt );
        l = nxt + 1;
    }
    cout << sum;
}
