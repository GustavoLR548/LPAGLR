
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>

#define EMPTY 0x3f3f3f3f

using namespace std;

#define fi first
#define se second
#define sc2(a, b) scanf("%d%d", &a, &b)
#define sc3(a, b, c) scanf("%d%d%d", &a, &b, &c)

const int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int a, b, c, n, m, k, lt;
std::map<std::string, int> dp;
typedef pair<int, int> ii;
set<pair<ii, int> > app;

bool lim(ii a) 
{
	if(a.fi < 0 || a.fi >= n || a.se < 0 || a.se >= m) return false;
	else return true;
}

int foo(ii u, int t) 
{
	if(t == lt)
		return 0;

	std::string key = std::to_string(u.fi) + "," + std::to_string(u.se) + "," + std::to_string(t);
	std::cout << "key: " << key << std::endl;
	if(dp[key] != EMPTY)
		return dp[key];
	
	int plus = app.count(make_pair(u, t));
	int _max = foo(u, t+1);
	ii v;

	for(int i = 0; i < 8; i++) 
	{
		v.fi = u.fi+dx[i];
		v.se = u.se+dy[i];
		
		if(lim(v))
			_max = max(_max, foo(v, t+1));
	}
	dp[key] = _max+plus;
	return dp[key];
}

int main()
{	
	while(sc3(n, m, k) && n) 
	{	
		app.clear();
		lt = 0;
		
		for(int i=0; i<k; i++) 
		{
			sc3(a, b, c);
			a--, b--;
			
			app.insert(make_pair(ii(a, b), c));
			lt = max(lt, c + 1);
		}
		
		ii u;
		sc2(u.fi, u.se);
		u.fi--, u.se--;

		dp.clear();
	
		printf("%d\n", foo(u, 0));
	}
}