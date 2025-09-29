#include <bits/stdc++.h>

using namespace std;

#define int long long int

int expansaoLaplace(vector<vector<int>> matriz)
{
    int n = matriz.size();
    if (n == 2) return (matriz[0][0] * matriz[1][1]) - (matriz[0][1] * matriz[1][0]);
    // O determinante de uma matriz 2x2 é o nosso caso base, afinal é bem tranquila de calcular

    int det = 0;

    for (int i = 0; i < n; i++)
    {
        int coef = matriz[0][i];
        /* 
        Irei cortar sempre a primeira linha e coluna, eu poderia fazer uma verificação para
        pegar sempre a linha, ou coluna com mais zeros para calcular mais rapidamente e facilmente,
        mas eu não tenho pena de botar o pc para trabalhar
        */

        vector<vector<int>> matrizReduzida(n - 1, vector<int>(n - 1));

        // Indices da matriz reduzida (na vdd é de outro nome, mas vou deixar assim msm)
        int l = 0, m = 0;
    
        for (int j = 1; j < n; j++) 
        // Já inicio na segunda linha, pois estou cortando sempre a primeira
        {
            for (int k = 0; k < n; k++)
            {
                // Adicionando somente o que não for da coluna do coeficiente
                if (k != i) matrizReduzida[l][m++] = matriz[j][k];
            }
            // Indo para a próxima linha e resetando o indice de colunas (SIM, EU TINHA ESQUECIDO)
            l++;
            m = 0;

            // Curiosidade: os indices são l e m, não j e k, pq eu tinha esquecido e botei j - 1 e k - 1
        }

        int sentidoCofator;

        // O pow() do C/C++ dá muito problema, prefiro fazer verificação no if msm
        if ((1 + (i + 1)) % 2 == 0) sentidoCofator = 1;
        else sentidoCofator = -1;


        det += (coef * expansaoLaplace(matrizReduzida)) * sentidoCofator;
    }

    return det;
}

signed main()
{
    // Deixei o mínimo de interação com o usuário, só para não ficar feio
    cout << "Insira o tamanho da matriz quadrada:" << endl;

    int n;
    cin >> n;

    vector<vector<int>> matriz(n, vector<int>(n));

    cout << "Insira os elementos da matriz:" << endl;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> matriz[i][j];
        }
    }

    int det = expansaoLaplace(matriz);
    
    cout << "Determinante: " << det << endl;

    return 0;
}