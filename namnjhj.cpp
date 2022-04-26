//#define Fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
// problem Link =>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#define ll long long
const int INTMAX((int)1e9 - 1);
using namespace std;
long long Fast_Power(int X, int N);
int main()
{   // 2^5
    cout << Fast_Power(1, 2);
    return 0;
}
long long Fast_Power(int X, int N)
{//1125899906842624 
    if (N == 0)
        return 1;
    long long ret = Fast_Power(X, N / 2);
    ret *= ret;
    if (N & 1)
        ret *= 2;
    return ret;
}
