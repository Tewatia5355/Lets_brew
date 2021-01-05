#include <bits/stdc++.h>
using namespace std;

int middle(int A, int B, int C)
{
    int x = max(A, B);
    int y = max(A, C);

    if (x == y)
        return max(B, C);
    else
        return min(x, y);
}