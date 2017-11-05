#include <stdio.h>
#define ll long long

/*
 * Problem statement :-  https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/hihi-and-crazy-bits/
 */

ll next (ll n) {
    ll npos = 0;
    ll x = n;
    while(n) {
        if((n&(1L)) == 0)  break;
        n = n >> 1;
        npos++;
    }
    if(n)
       return x|(1L<<npos);
    else
       return x+1L;
}

ll next2(ll n) {
    int i;
    for(i = 0; i < 64; i++){
        if( (n & (1<<i)) == 0) {
            n = n | (1 << i);
            break;
        }
    }
    return n;
}

int main()
{
    ll t, n;
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld", &n);
        printf("%lld\n", next(n));
    }
    return 0;
}
