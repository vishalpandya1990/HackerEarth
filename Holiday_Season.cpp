#include <iostream>
using namespace std;

/*
 * Problem statement :- https://www.hackerearth.com/fr/practice/algorithms/searching/linear-search/practice-problems/algorithm/holiday-season-ab957deb/description/
 */


long long solve1(char ch[], long long n) {
    long long f[27] = {0};
    long long b, d, c, count = 0;
    for(b = 0; b < n; b++) {
        for(d = b+1; d < n; d++){
            if(ch[b] == ch[d]){
              for(c = b+1; c < d; c++)
                 count += f[ch[c] - 'a'];
            }
        }
        f[ch[b] - 'a']++;
    }
    return count;
}

long long solve2(char ch[], long long n) {
    long long f[27] = {0};
    long long b, d, count = 0;
    for(b = 0; b < n; b++) {
        long long freqSum_range_bd_exclusive = 0;
        for(d = b+1; d < n; d++){
            if(ch[b] == ch[d]){
                 count += freqSum_range_bd_exclusive;
            }
            freqSum_range_bd_exclusive += f[ch[d] - 'a'];
        }
        f[ch[b] - 'a']++;
    }
    return count;
}

int main()
{
    long long n, i;
    cin >> n;
    char ch[n+1];
    for(i = 0; i < n; i++){
       cin >> ch[i];
    }
    ch[n] = 0;
    cout << solve2(ch, n) << endl;
    return 0;
}
