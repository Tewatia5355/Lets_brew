#include <bits/stdc++.h>
using namespace std;
bool fun(string a, string b)
{
    int i = 0, j = 0;
    int size_a = a.size(), size_b = b.size(); // size
    if (size_a != size_b)                     // if size is not equal return
        return false;
    string t = a + a;                   // t string is concatination of 2 string a
    return (t.find(b) != string::npos); // if string b is substring of string t then return true, else false;
}
int main()
{
    string a, b;
    cin >> a >> b;
    cout << fun(a, b);
    return 0;
}
