#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int MAXN = 3005;
int t;
ll dp[MAXN][MAXN];
deque<ll>que;
int main(){
    scanf("%d", &t);
    while(t --){
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 1; i <= n; i ++){
            scanf("%lld", &dp[1][i]);
        }
        for(int i = 2; i <= m; i ++){
            while(!que.empty()){
                que.pop_back();
            }
            int l = i - k;
            if(l <= 0){
                l = 1;
            }
            for(int j = l; j < i; j ++){
                if(que.empty()){
                    que.push_back(j);
                }
                else{
                    if(dp[i - 1][j] >= dp[i - 1][que.front()]){
                        while(!que.empty()){
                            que.pop_back();
                        }
                        que.push_back(j);
                    }
                    else{
                        while(dp[i - 1][j] >= dp[i - 1][que.back()]){
                            que.pop_back();
                        }
                        que.push_back(j);
                    }
                }
            }
            for(int j = i; j <= n; j ++){
                if(que.front() < j - k){
                    que.pop_front();
                }
                dp[i][j] = dp[i - 1][que.front()] + dp[1][j];
                if(dp[i - 1][j] >= dp[i - 1][que.front()]){
                    while(!que.empty()){
                        que.pop_back();
                    }
                    que.push_back(j);
                }
                else{
                    while(dp[i - 1][j] >= dp[i - 1][que.back()]){
                        que.pop_back();
                    }
                    que.push_back(j);
                }
            }
        }
        ll re = 0;
        for(int i = 1; i <= n; i ++){
            re = max(re, dp[m][i]);
        }
        printf("%lld\n", re);
    }
    return 0;
}

