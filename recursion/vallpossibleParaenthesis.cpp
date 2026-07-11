#include <iostream>
#include <vector>
#include <string>
using namespace std;

void fun(int open, int close, int n, string &temp, vector<string> &res)
{
    if (open == n && close == n)
    {
        res.push_back(temp);
        return;
    }

    if (open < n)
    {
        temp.push_back('(');
        fun(open + 1, close, n, temp, res);
        temp.pop_back();
    }

    if (close < open)
    {
        temp.push_back(')');
        fun(open, close + 1, n, temp, res);
        temp.pop_back();
    }
}

int main()
{
    int n = 4;

    string temp;
    vector<string> res;

    fun(0, 0, n, temp, res);

    cout << "Total = " << res.size() << "\n\n";

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }

    return 0;
}