/*

4! = 4 * 3 * 2 * 1
15! = 15 * .. * 2 * 1
n! =
�� n / 2 �� 2 �ı���
�� n / 4 �� 4 �ı���
�� n / 8 �� 8 �ı���
...

*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int T;
    while(scanf("%d", &T)!=EOF)
    {
        while(T--)
        {
            ll n;
            scanf("%lld", &n);
            ll ans = 0;
            for (ll i = 2; i <= n; i *= 2)
            {
                ans += n / i;
            }
            printf("%lld\n", ans);
        }
    }
}
