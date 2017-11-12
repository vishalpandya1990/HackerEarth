#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

/*
 * Problem statement :- https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/1d-isolation/description/
 */

typedef long long ll;

struct component {
    ll parent;
};

struct city {
    ll pos, id;
};

ll getRoot(component c[], ll n, ll idx) {
    ll i = idx;
    while((i >= 0) && (i <= n) && (c[i].parent >= 0)) {
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

int compare(const void *a, const void *b) {
    city *x = (city *)a;
    city *y = (city *)b;
    return x->pos - y->pos;
}

bool compareBool(city x, city y) {
    return x.pos < y.pos;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    ll n, t, i, u, v, w, k, m, q;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        component c[n+1];
        city ct[n+1];
        for(i = 0; i <= n; i++) {
            c[i].parent = -1;
            ct[i].pos = 0;
            ct[i].id = i;
        }
        for(i = 0; i < n; i++) {
            cin >> u >> v >> w;
            ct[v].pos = ct[u].pos + w;
        }
        //qsort(ct, n+1, sizeof(city), compare);
        sort(ct, ct+n+1, compareBool);
        for(i = 1; i <= n; i++) {
            if( (ct[i].pos - ct[i-1].pos) <= k ) {
                ll ra = getRoot(c, n, ct[i].id);
                ll rb = getRoot(c, n, ct[i-1].id);
                merge(c, ra, rb);
            }
        }
        cin >> q;
        while(q--) {
            cin >> m;
            map<ll, ll> grp;
            map<ll, ll>::iterator itr;
            for(i = 0; i < m; i++) {
                cin >> u;
                ll root = getRoot(c, n, u);
                itr = grp.find(root);
                if(itr == grp.end()){
                    grp[root] = (ll)1;
                } else {
                    grp[root]++;
                }
            }

            if(grp.size() == 1) {
                cout << "YES\n";
                continue;
            }

            for(itr = grp.begin(); itr != grp.end(); itr++) {
                if(itr->second == (ll)1) {
                    cout << "NO\n";
                    break;
                }
            }

            if(itr == grp.end()) {
                cout << grp.size() << endl;
            }
        }
    }
}
