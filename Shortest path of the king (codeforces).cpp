#define Fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
// problem Link => https://codeforces.com/contest/3/problem/A
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#define ll long long
const int INTMAX = 1000000000;
const int N = 100005;
using namespace std;
bool vis[10][10];
int moveX[8] = {-1 , 0,1,-1,1,-1,0,1 , };
int moveY[8] = {1,1,1, 0,0,-1,-1,-1 };
string moves[8] = {"LU","U","RU" , "L" ,"R" ,"LD" ,"D","RD" };
struct Points
{
	int x, y;
	Points* perant = NULL;
	string moves = "00";
	Points(int _x, int _y, Points* _perant) {
		x = _x;
		y = _y;
		perant = _perant;
	}
	Points* moveTo(int _x, int _y) {
		int retX = x + _x, retY = y + _y;

		if (retX >= 1 && retX <= 8 && retY >= 1 && retY <= 8)
			return new Points(retX, retY, NULL);
		else
			return NULL;
	}
	int getCost(Points* goal) {
		return 0;//	  abs(x - goal->x) + abs(y - goal->y);
	}
	bool isGoal(Points* goal) {
		return (x == goal->x) && (y == goal->y);
	}
};
Points* _Goal = new Points(0, 0, NULL);
bool com(pair < int, Points > a, pair < int, Points > b) {
	return a.first < b.first;
}
Points* BFS(Points* root) {
	queue < pair < int, Points* >> Que;
	Que.push(make_pair(0, root));
	vis[root->x][root->y] = true;
	while (!Que.empty()) {
		int u = Que.front().first;
		Points* c = Que.front().second;
		Que.pop();
		if (c->isGoal(_Goal))
			return c;
		for (int x = 0; x < 8; x++)
		{
			Points* cur = c->moveTo(moveX[x], moveY[x]);
			if (cur != NULL && !vis[cur->x][cur->y])
			{
				vis[cur->x][cur->y] = true;
				cur->perant = c;
				cur->moves = moves[x];
				Que.push({ cur->getCost(_Goal),  cur });
			}
		}
	}
}

int main() {
	string inite, goal;
	cin >> inite >> goal;
	_Goal = new Points(goal[0] - 'a' + 1, goal[1] - '0', NULL);
	Points* root = new Points(inite[0] - 'a' + 1, inite[1] - '0', NULL);
	Points* res = BFS(root);
	int cnt = 0;
	vector<string> out;
	while (res->perant != NULL)
	{
		//cout << res->x << " " << res->y << endl;
		cnt++;
		out.push_back(res->moves);
		res = res->perant;
	}
	cout << cnt << "\n";
	for (int i = out.size() - 1; i > -1; i--)
		cout << out[i] << "\n";
}
