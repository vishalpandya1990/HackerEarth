#include <iostream>
#include <list>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

/*
 * Problem statement :- https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-fireman-vincent/
 */

struct component {
    int parent;
    int minRisk;
    int minRiskCount;
};

int getRoot(component elts[], int n, int a) {
    int i = a;
    while( (i >= 1) &&  (i <= n) && (elts[i].parent >= 0) )
         i = elts[i].parent;
    return i;
}

void merge(component elts[], int ra, int rb) {
    int newmin, newmincount;
    if(elts[ra].minRisk < elts[rb].minRisk) {
        newmin = elts[ra].minRisk;
        newmincount = elts[ra].minRiskCount;
    } else if (elts[rb].minRisk < elts[ra].minRisk) {
        newmin = elts[rb].minRisk;
        newmincount = elts[rb].minRiskCount;
    } else {
        newmin = elts[ra].minRisk;
        newmincount = elts[ra].minRiskCount + elts[rb].minRiskCount;
    }
    elts[ra].parent = rb;
    elts[rb].minRisk = newmin;
    elts[rb].minRiskCount = newmincount;
}

int main(void) {
    int n, k, i, a, b, u = 1000000007;
    cin >> n;
    int e[n+1] = {0};
    component elts[n+1];
    for(i = 1; i <= n; i++){
       cin >> e[i];
       elts[i].parent = -1;
       elts[i].minRisk = e[i];
       elts[i].minRiskCount = 1;
    }
    cin >> k;
    i  = k;
    while(i--) {
        cin >> a >> b;
        int rootA = getRoot(elts, n, a);
        int rootB = getRoot(elts, n, b);
        if(rootA != rootB){
            merge(elts, rootA, rootB);
        }
    }

    int ways = 1;
    for(i = 1; i <= n; i++) {
        if(elts[i].parent < 0) {
            ways *= (elts[i].minRiskCount % u);
            ways %= u;
        }
    }

    cout << ways << endl;
}
