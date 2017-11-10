#include <iostream>
#include <list>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

/*
 * Problem statement :- https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/marriage-problem/
 */

struct person {
    long parent;
    long menc;
    long womenc;
};

long getRoot(person elts[], long n, long a) {
    long i = a;
    while( (i >= 0) &&  (i < n) && (elts[i].parent >= 0) )
         i = elts[i].parent;
    return i;
}

void merge(person elts[], long ra, long rb) {
     long mena   = elts[ra].menc;
     long womena = elts[ra].womenc;
     long menb   = elts[rb].menc;
     long womenb = elts[rb].womenc;
     long totala = mena + womena;
     long totalb = menb + womenb;
     if(totala < totalb) {
        elts[ra].parent = rb;
        elts[rb].menc = mena + menb;
        elts[rb].womenc = womena  + womenb;
     } else {
        elts[rb].parent = ra;
        elts[ra].menc = mena + menb;
        elts[ra].womenc = womena  + womenb;
     }
}

int main(void) {
    long n, q1, q2, q3, i, x, y, a, b;
    cin >> x >> y;
    n = x+y;
    person elts[n];
    for(i = 0; i < n; i++){
        if(i < x) {
            elts[i].menc = 1;
            elts[i].womenc = 0;
        } else {
            elts[i].womenc = 1;
            elts[i].menc = 0;
        }
        elts[i].parent = -1;
    }
    cin >> q1;
    while(q1--) {
        cin >> a >> b;
        long rootA = getRoot(elts, n, a-1);
        long rootB = getRoot(elts, n, b-1);
        if(rootA != rootB){
            merge(elts, rootA, rootB);
        }
    }

    cin >> q2;
    while(q2--) {
        cin >> a >> b;
        long rootA = getRoot(elts, n, x+a-1);
        long rootB = getRoot(elts, n, x+b-1);
        if(rootA != rootB){
            merge(elts, rootA, rootB);
        }
    }

    cin >> q3;
    while(q3--) {
        cin >> a >> b;
        long rootA = getRoot(elts, n, a-1);
        long rootB = getRoot(elts, n, x+b-1);
        if(rootA != rootB){
            merge(elts, rootA, rootB);
        }
    }

    long long ways = 0;
    for(i = 0; i < n; i++) {
        if(elts[i].parent < 0) {
            ways += (elts[i].menc*(y - elts[i].womenc));
        }
    }

    cout << ways << endl;
}
