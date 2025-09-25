#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    int matriz[n][m];
    int transv[m][n];

    for (int i = 0; i < n ; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matriz[i][j];
            transv[j][i] = matriz[i][j];
        }
    }

    cout << "MATRIZ ORIGINAL" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matriz[i][j] << ' ';
        }
        cout << endl;
    }

    cout << "MATRIZ TRANSPOSTA" << endl;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << transv[i][j] << ' ';
        }
        cout << endl;
    }

    
}