#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

/*
 * Problem statement :- https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/47s-passage/
 */

typedef long long ll;

const ll mod = 1000000007;

struct component {
    ll parent;
};

ll getRoot(component c[], ll n, ll idx) {
    ll i = idx;
    while((i >= 0) && (i < n) && (c[i].parent >= 0)) {
        i = c[i].parent;
    }
    return i;
}
void merge(component c[], ll ra, ll rb) {
    ll sizeA = -(c[ra].parent);
    ll sizeB = -(c[rb].parent);
    if(sizeA < sizeB) {
        c[ra].parent = rb;
        c[rb].parent = -(sizeA + sizeB);
    } else {
        c[rb].parent = ra;
        c[ra].parent = -(sizeA + sizeB);
    }
    return;
}

ll power(ll a, ll b, ll mod) {
    if(b == 0) return 1;
    if(b == 1) return a%mod;
    ll res = 1;
    if(b&1){
        res = a;
    }
    ll tmp = power(a, b/2, mod);
    tmp = (tmp * tmp)%mod;
    tmp = (tmp * res)%mod;
    return tmp;
}

void printArray(ll arr[], ll n) {
    ll i;
    for(i = 0; i < n-1; i++) {
        cout << arr[i] << " ";
    }
    cout << arr[n-1] << endl;
}

int main(void) {
    ll t, n, m, u, v, p, i;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        component c[n];
        for(i = 0; i < n; i++) {
            c[i].parent = -1;
        }
        ll ccnum = n;
        for(i = 0; i < m; i++) {
            cin >> u >> v;
            ll ra = getRoot(c, n, u-1);
            ll rb = getRoot(c, n, v-1);
            if(ra != rb) {
                merge(c, ra, rb);
                ccnum--;
            }
        }
        ll a = m;         //count of existing safe passages
        ll b = ccnum - 1; //count of needed safe passages
        cin >> p;
        for(i = 0 ; i < p; i++) {
            cin >> u >> v;
            a++;
            ll ra = getRoot(c, n, u-1);
            ll rb = getRoot(c, n, v-1);
            if(ra != rb) {
                merge(c, ra, rb);
                ccnum--;
                b = ccnum - 1; //could have done b-- as well
            }
            cout << power(a, b, mod) << " ";
        }
        cout << endl;
    }
}
