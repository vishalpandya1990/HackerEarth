#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

typedef long long ll;

/*
 * Problem statement :- https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/1d-isolation/description/
 */

struct city {
    ll pos, id, ccNum;
};


bool compareBool(city x, city y) {
    return x.pos < y.pos;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    ll n, t, i, u, v, w, k, m, q;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        city ct[n+1];
        for(i = 0; i < n; i++) {
            cin >> u >> v >> w;
            ct[u].id = u;
            ct[v].id = v;
            ct[u].ccNum = ct[v].ccNum = -1;
            ct[v].pos = ct[u].pos + w;
        }
        sort(ct, ct+n+1, compareBool);
        ll curCCnum = 1;
        ct[0].ccNum = curCCnum;
        for(i = 1; i <= n; i++) {
            if( (ct[i].pos - ct[i-1].pos) <= k ) {
                 ct[i].ccNum = ct[i-1].ccNum;
            } else {
                ct[i].ccNum = ++curCCnum;
            }
        }
        ll pos[n+1];
        for(i = 0; i <= n; i++) {
            pos[ct[i].id] = i;
        }
        cin >> q;
        while(q--) {
            cin >> m;
            map<ll, ll> grp;
            map<ll, ll>::iterator itr;
            for(i = 0; i < m; i++) {
                cin >> u;
                ll cc = ct[pos[u]].ccNum;
                itr = grp.find(cc);
                if(itr == grp.end()){
                    grp[cc] = (ll)1;
                } else {
                    grp[cc]++;
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
