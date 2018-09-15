//Not AC Yet
#include <bits/stdc++.h>
#define P(X) cout<<"db "<<X<<endl;
#define P2(X,Y) cout<<"d2 "<<X<<" "<<Y<<endl;
#define ll long long
#define rep(i,n) for(i=1;i<=n;i++)
#define FO freopen("t.txt","w",stdout);
#define MS(XX,YY) memset(XX,YY,sizeof(XX));
#define pii pair<int,int>
using namespace std;
int dr[50009],len[50009],ft,lev[50009],incr,ln;
int dfs(int u){
    int v=dr[u],i;
    if(len[v]>0){
        ln=len[v]+1;
        len[u]=ln;
        incr=1;
        return 0;
    }
    if(lev[v]!=-1){
        ln=lev[u]+1-lev[v];
        len[u]=len[v]=ln;
        return 0;
    }
    if(len[v]==-1){
        lev[v]=lev[u]+1;
        dfs(v);
    }
    ln+=incr;
    if(len[u]!=-1)incr=1;
    len[u]=ln;
}

int main()
{
    int i,j,a,b,ts,cn=0,n,mx=0;
    //freopen("test.txt","r",stdin);
    scanf("%d",&ts);
    while(ts--){
        scanf("%d",&n);
        mx=0;
        int mi=1;
        for(i=0;i<=n;i++)dr[i]=lev[i]=len[i]=-1;
        for(i=0;i<n;i++){
            scanf("%d %d",&a,&b);
            dr[a]=b;
        }
        for(i=1;i<=n;i++){

            if(len[i]==-1){
                ln=incr=0;
                lev[i]=0;
                dfs(i);
                //P2(i,len[i]);
                if(len[i]>mx){
                    mx=len[i];
                    mi=i;
                }
            }
        }
        printf("Case %d: %d\n",++cn,mi);
    }
    return 0;
}
