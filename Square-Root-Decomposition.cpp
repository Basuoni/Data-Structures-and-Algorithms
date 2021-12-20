// Name  Algorithm: Square Root Decomposition ,problem Link : https://www.spoj.com/problems/GIVEAWAY/
#define Fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#include <bits/stdc++.h>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#define ll long long
const int INTMAX((int)1e9), N = (int)1e3;
using namespace std;
int get(int l, int r, int x, int sqr, vector<int> &data, vector<vector<int>> &blocks)
{
    int ret = 0; // sum >= X
    for (int i = l; i <= r;)
    {
         if(i%sqr==0 && i+sqr-1<=r){
        {
            ret += blocks[i / sqr].end() - lower_bound(blocks[i / sqr].begin(), blocks[i / sqr].end(), x);
            i += sqr;
        }
        else
        {
            if (data[i] >= x)
                ret++;
            i++;
        }
    }
    return ret;
}
void update(int i, int x, int sqr, vector<int> &data, vector<vector<int>> &blocks)
{
   
    int indx = lower_bound(blocks[i / sqr].begin(), blocks[i / sqr].end(), x) - blocks[i / sqr].begin();
     data[i] = x;
     blocks[i / sqr][indx] = data[i];
    sort(blocks[i / sqr].begin(), blocks[i / sqr].end());
}
int main()
{
    Fast;
    int n, in;
    cin >> n;
    vector<int> data(n);
    for (int &x : data)
        cin >> x;
    int sqr = (int)ceil(sqrt(n));
    vector<vector<int>> blocks(sqr);
    for (int i = 0; i < n; i++)
        blocks[i / sqr].push_back(data[i]);
    for (auto& b : blocks)
        sort(b.begin(), b.end());
    int m;
    cin >> m;
    while (m--)
    {
        int tp;
        cin >> tp;
        if (tp == 0)
        {
            int l, r, x;
            cin >> l >> r >> x;
            cout << get(l - 1, r - 1, x, sqr, data, blocks) << '\n';
        }
        else
        {
            int index, newVal;
            cin >> index >> newVal;
            update(index - 1, newVal, sqr, data, blocks);
        }
    }
    return 0;
}
