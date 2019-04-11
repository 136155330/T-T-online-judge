#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define mem(x) memset(x, 0, sizeof(x))
using namespace std;
typedef long long LL;
const int MOD = 1e9 + 7;
/**
 8
 10000001
 
 ORZ 我旺神
 偷偷的看眼旺神的题解
 已知01字符串要么以1结尾或者以0结尾
 那么可知当前长度下以0结尾或者以1结尾
 都是由前面的以1结尾或者以0结尾来转移
 dp[i][0 or 1]
 dp[0][0] = dp[0][1] = 0;
 if(s[i] == 1)
 {
    dp[i][1] = dp[i - 1][0] + dp[i - 1][1] + 1;
    dp[i][0] = dp[i - 1][0];
 }
 else
 {
    dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + 1;
    dp[i][1] = dp[i - 1][1];
 }
 **/
const int MAXN = 1e6 + 5;
char str[MAXN];
int n;
LL dp[MAXN][2];
int main()
{
    scanf("%d", &n);
    mem(str), mem(dp);
    scanf("%s", str);
    for(int i = 0; i < n; i ++)
    {
        if(str[i] == '1')
        {
            dp[i + 1][1] = (dp[i][0] % MOD + dp[i][1] % MOD + 1) % MOD;
            dp[i + 1][0] = dp[i][0] % MOD;
        }
        else if(str[i] == '0')
        {
            dp[i + 1][0] = (dp[i][0] % MOD+ dp[i][1] % MOD + 1) % MOD;
            dp[i + 1][1] = dp[i][1] % MOD;
        }
    }
    printf("%lld\n", (dp[n][0] % MOD + dp[n][1] % MOD) % MOD);
    return 0;
}

