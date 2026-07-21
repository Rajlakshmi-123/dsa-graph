#include <bits/stdc++.h>
using namespace std;

class Solution {
    static const int MOD = 1000000007;
    int n, m;
    vector<vector<int>> pref;
    vector<vector<vector<int>>> dp;

    bool hasOne(int r1, int c1, int r2, int c2) {
        int cnt = pref[r1][c1] - pref[r2][c1] - pref[r1][c2] + pref[r2][c2];
        return cnt > 0;
    }

    int solve(int r, int c, int cuts) {
        if (!hasOne(r, c, n, m))
            return 0;

        if (cuts == 0)
            return 1;

        if (dp[r][c][cuts] != -1)
            return dp[r][c][cuts];


            
        long long ans = 0;

        for (int nr = r + 1; nr < n; nr++) {
            if (hasOne(r, c, nr, m)) {
                ans += solve(nr, c, cuts - 1);
                ans %= MOD;
            }
        }

        for (int nc = c + 1; nc < m; nc++) {
            if (hasOne(r, c, n, nc)) {
                ans += solve(r, nc, cuts - 1);
                ans %= MOD;
            }
        }

        return dp[r][c][cuts] = ans;
    }

public:
    int countWays(vector<vector<int>> &mat, int k) {
        n = mat.size();
        m = mat[0].size();

        pref.assign(n + 1, vector<int>(m + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                pref[i][j] = mat[i][j] + pref[i + 1][j] + pref[i][j + 1] - pref[i + 1][j + 1];
            }
        }

        dp.assign(n, vector<vector<int>>(m, vector<int>(k, -1)));

        return solve(0, 0, k - 1);
    }
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> mat(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    Solution obj;
    cout << obj.countWays(mat, k) << endl;

    return 0;
}