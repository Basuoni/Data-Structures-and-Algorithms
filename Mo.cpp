// problem Link => https://www.spoj.com/problems/DQUERY/
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
struct Query
{
    int l = -1;
    int r = -1;
    int bi = -1;
    int qi = -1;
    Query(int _l, int _r, int sqr, int _qi) : l(_l), r(_r), bi(_l / sqr), qi(_qi) {}
    bool operator<(const Query &q2) const
    {
        if (bi != q2.bi)
            return bi < q2.bi;
        return r < q2.r;
    }
};
void push(int i, int &res, vector<int> &data, vector<int> &fre)
{
    fre[data[i]]++;
    if (fre[data[i]] == 1)
        res++;
}
void remove(int i, int &res, vector<int> &data, vector<int> &fre)
{
    fre[data[i]]--;
    if (fre[data[i]] == 0)
        res--;
}
vector<int> MO(vector<int>& data, vector<Query>& querys)
{
    int MX = *max_element(data.begin(),data.end());
    sort(querys.begin(), querys.end());
    vector<int> ret(querys.size());
    vector<int> fre(MX+1);
    int l = 1, r = 0, res = 0;
    for (auto &item : querys)
    {
        while (l < item.l)remove(l++, res, data, fre);
        while (l > item.l) push(--l, res, data, fre);
        while (r < item.r) push(++r, res, data, fre);
        while (r > item.r) remove(r--, res, data, fre);
        ret[item.qi] = res;
    }
    return ret;
}

int main()
{
    Fast;
    int n, q, l, r;
    cin >> n;
    vector<int> data(n);
  
  for(int& x : data) cin>>x;
    cin >> q;
    vector<Query> queries;
    int sqr = (int)ceil(sqrt(n));
    for (int i = 0; i < q; i++)
    {
        cin >> l >> r;
        queries.push_back(Query(l-1, r-1, sqr, i));
    }
    auto ans = MO(data, queries);
    for (auto &x : ans)
        cout << x << '\n';
    return 0;
}