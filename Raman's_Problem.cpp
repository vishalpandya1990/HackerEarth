#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

/*
 * Problem statement :- https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/ramans-problem/
 */

typedef long long ll;

const ll mod = 1000000007;

struct edge {
    ll u, v, w;
};

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

ll merge(component c[], ll ra, ll rb) {
    ll sizeA = -(c[ra].parent);
    ll sizeB = -(c[rb].parent);
    if(sizeA < sizeB) {
        c[ra].parent = rb;
        c[rb].parent = -(sizeA + sizeB);
    } else {
        c[rb].parent = ra;
        c[ra].parent = -(sizeA + sizeB);
    }
    return sizeA * sizeB;
}

int compare(const void *a, const void *b) {
    edge *e1 = (edge *)a;
    edge *e2 = (edge *)b;
    return e1->w - e2->w;
}

int main(void) {

    ll t, n, i, u, v, w;
    cin >> t;
    while(t--) {
        cin >> n;
        edge e[n-1];
        component c[n];
        for(i = 0; i < n; i++) {
            c[i].parent = -1;
        }
        for(i = 0; i < n-1; i++) {
            cin >> u >> v >> w;
            e[i].u = u-1;
            e[i].v = v-1;
            e[i].w = w;
        }
        qsort(e, n-1, sizeof(edge), compare);
        ll ans = 0;
        for(i = 0; i < n-1; i++) {
            ll ra = getRoot(c, n, e[i].u);
            ll rb = getRoot(c, n, e[i].v);
            ll wt = e[i].w;
            if(ra != rb) {
                ans += (wt * merge(c, ra, rb));
            }
        }
        cout << ans%mod << endl;
    }
}
