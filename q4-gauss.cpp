#include <bits/stdc++.h>

using namespace std;

void troca_linha(double matriz[][100], int n, int m, int linha1, int linha2) {
    for (int i = 0; i < m; i++) {
        swap(matriz[linha1][i], matriz[linha2][i]);
    }
}

int main()
{
    int n, m; cin >> n >> m;

    double matriz[n][m];

    // Leitura da matriz A
    for (int i = 0; i < n ; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matriz[i][j];
        }
    }

    // Aqui vamos escalonar a matriz

    // o loop coluna serve pra percorrer COLUNAS, o loop está de fora pois em gauss jordan, limpamos primeiro linha a linha, o motivo do fim do loop em n é que só precisamos nos preocupar com o numero de linhas btw.
    for (int coluna = 0; coluna < n; coluna++)
    {
        int pivot_linha = -1;
        for (int i = coluna; i < n; i++) 
        {
            if (matriz[i][coluna] != 0) 
            {
                pivot_linha = i;
                break;
            }
        }

        if (pivot_linha == -1) continue; // Se não encontrou pivot, pula a coluna

        // Troca a linha atual com a linha do pivot
        if (pivot_linha != coluna) {
            troca_linha(matriz, n, m, coluna, pivot_linha);
        }

        // Eliminar abaixo do pivot
        for (int linha = coluna + 1; linha < n; linha++) 
        {
            if (matriz[linha][coluna] != 0) 
            {
                double escalar = -matriz[linha][coluna] / matriz[coluna][coluna];
                for (int k = 0; k < m; k++) // Só processo de operação trivial
                {
                    matriz[linha][k] += escalar * matriz[coluna][k];
                }
            }
        }
    }

    // a partir daqui, matriz[n][m] está escalonada. 

    cout << "MATRIZ ESCALONADA" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matriz[i][j] << ' ';
        }
        cout << endl;
    }

    // Vamos contar linhas não vazias agora, é um sistema de flag aqui, se a flag marcou TRUE significa que a linha NÃO ESTÁ VAZIA, então podemos adicionar ao vetor soluções na posição posto


    vector<vector<double>> base;
    int posto = 0;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        flag = false;
        for (int j = 0; j < m; j++)
        {
            if (matriz[i][j] != 0) flag = true;
        }
        if (flag) 
        {
            base.push_back(vector<double>());
            for (int j = 0; j < m; j++)
            {
                base[posto].push_back(matriz[i][j]);
            }
            posto++;
        }
    }

    cout << "DIMENSÃO DA MATRIZ: " << posto << endl;

    cout << "BASES:" << endl;

    for (auto vetores: base)
    {
        cout << '(';
        for (auto x: vetores)
        {
            cout << x << ' ';
        }
        cout << ")\n";
    }


}