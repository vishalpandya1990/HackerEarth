#include <iostream>
using namespace std;

/*
 * Problem statement :- https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-campers-2/description/
 */

typedef long long ll;

ll getComponentRoot(ll compArray[], ll n, ll curIdx) {
    ll i = curIdx;
    while(i >= 0 && i < n && compArray[i] >= 0){
        i = compArray[i];
    }
    return i;
}

void mergeTwoComponents(ll compArray[], ll size[], ll rootAIndex, ll rootBIndex) {
    ll sizeA = - compArray[rootAIndex];
    ll sizeB = - compArray[rootBIndex];
    if(sizeA < sizeB) {
        compArray[rootAIndex] = rootBIndex;
        compArray[rootBIndex] = -(sizeA + sizeB);
    } else {
        compArray[rootBIndex] = rootAIndex;
        compArray[rootAIndex] = -(sizeA + sizeB);
    }
    size[sizeA + sizeB]++;
    size[sizeA]--;
    size[sizeB]--;
}

ll getMinSizeDiff(ll size[], ll n) {
   ll i = 0, prev, min = n+1;
   while(i <= n && !size[i]) i++;
   if(i > n) return min;
   if(size[i] > 1) return 0;;
   prev = i++;
   for(; i <= n; ) {
       while(i <= n && !size[i]) i++;
       if(i > n) break;
       if(size[i] > 1) return 0 ;
       if(i - prev < min) min = i - prev;
       prev = i++;
   }
   return prev == n ? 0 : min;
}

int main()
{
    ll i, n, q;
    cin >> n >> q;
    ll comp[n], size[n+1] = {0};
    size[1] = n;
    for(i = 0; i < n; i++)
        comp[i] = -1;
    while(q--) {
        ll a, b;
        cin >> a >> b;
        ll rootA = getComponentRoot(comp, n, a-1);
        ll rootB = getComponentRoot(comp, n, b-1);
        if(rootA != rootB){
            mergeTwoComponents(comp, size, rootA, rootB);
        }
        cout << getMinSizeDiff(size, n) << endl;;
    }
    return 0;
}
