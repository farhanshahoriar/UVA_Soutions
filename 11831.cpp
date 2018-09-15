//Not AC yet
#include <stdio.h>
#include <iostream>
using namespace std;
#define P(X) printf("db %d\n",X);
#define P2(X,Y) printf("db %d %d\n",X,Y);

char sr[205][205];
int dx[] = { -1,0,1,0 }, co, cx, cy, stk,m,n;
int dy[] = { 0,1,0,-1 };
int tvs(char dr)
{
	int x, y;
    //P2(cx,cy);
	if (dr == 'F') {
		x = cx + dx[co];
		y = cy + dy[co];
		if (x < 0 || x >= m || y < 0 || y >= n || sr[x][y] == '#') {
			return 0;
		}
		else if (sr[x][y] == '*') {
			stk++;
			sr[x][y] = '.';
		}
		cx = x;
		cy = y;
		return 0;
	}
	else if (dr == 'E') {
		co--;
	}
	else if (dr == 'D') {
		co++;
	}
	co = (co + 4) % 4;

}
int main()
{
	int dn,i,j;
    //freopen("test.txt","r",stdin);
	while (scanf("%d %d %d", &m, &n, &dn)==3) {
		stk = 0;
		if (m == 0 || n == 0)return 0;
		for (i = 0; i < m; i++) {
			scanf("%s ", sr[i]);
			//P(i)
			//puts(sr[i]);
			for (j = 0; j < n; j++) {
				if (sr[i][j] == 'N') {
					co = 0;
					cx = i;
					cy = j;
				}
				else if (sr[i][j] == 'S') {
					co = 2;
					cx = i;
					cy = j;
				}
				else if (sr[i][j] == 'L') {
					co = 1;
					cx = i;
					cy = j;
				}
				else if (sr[i][j] == 'O') {
					co = 3;
					cx = i;
					cy = j;
				}

			}
			//P2(m,n)
		}
		while (dn>0) {
			char ch;
			scanf("%c", &ch);
			//cout<<ch<<endl;
			tvs(ch);
			dn--;
		}
		//P2(cx,cy);

		printf("%d\n", stk);
    }
	return 0;
}
