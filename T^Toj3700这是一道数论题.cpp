#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN = 505;
const int inf = 0x7fffffff;
struct EDGE
{
    int maps[MAXN][MAXN];
    int dist[MAXN];
    int vids[MAXN];
    int flag[MAXN];
    int tot;
    int arr[MAXN];
    int re = inf;
    struct NODE
    {
        int num, value;
        bool friend operator < (const NODE &a, const NODE &b)
        {
            return a.value > b.value;///最小值优先
        }
    };
    priority_queue<NODE>que;
    void Init()
    {
        memset(flag, 0, sizeof(flag));
        memset(vids, 0, sizeof(vids));
        re = 0x7fffffff;
        tot = 0;
        memset(maps, -1, sizeof(maps));
        memset(arr, 0, sizeof(arr));
    }
    void my_push_back(int num)
    {
        arr[tot] = num;
        tot ++;
        vids[num] = 1;
    }
    void bfs(NODE a)
    {
        for(int i = 0; i < MAXN; i ++)
            dist[i] = inf;
        memset(flag, 0, sizeof(flag));
        while(!que.empty())
            que.pop();
        que.push(a);
        while(!que.empty())
        {
            NODE begins = que.top();
            que.pop();
            if(begins.num != a.num && vids[begins.num])
            {
                re = min(re, begins.value);
                return ;
            }
            if(!flag[begins.num])
            {
            flag[begins.num] = 1;
            for(int i = 1; i <= 500; i ++)
            {
                if(maps[begins.num][i] != -1 && i != begins.num)
                {
                    NODE ends;
                    ends.num = i;
                    ends.value = begins.value + maps[begins.num][i];
                    if(dist[i] > ends.value)
                        dist[i] = ends.value, que.push(ends);
                    else
                        continue;
                }
            }
            }
        }
    }
    void solve()
    {
        for(int i = 0; i < tot; i ++)
        {
            NODE a;
            a.num = arr[i];
            a.value = 0;
            bfs(a);
        }
    }
}ma;
int t, n, m;
int main()
{
    scanf("%d", &t);
    while(t --)
    {
        scanf("%d%d", &n, &m);
        ma.Init();
        for(int i = 0; i < m; i ++)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            if(ma.maps[u][v] != -1)
                ma.maps[u][v] = min(w, ma.maps[u][v]);
            else
                ma.maps[u][v] = w;
        }
        int k;
        scanf("%d", &k);
        for(int i = 0; i < k; i ++)
        {
            int num;
            scanf("%d", &num);
            ma.my_push_back(num);
        }
        ma.solve();
        printf("%d\n", ma.re);
    }
    return 0;
}

