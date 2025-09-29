#include <bits/stdc++.h>

using namespace std;

double norma(vector<double> v)
{
    double resultado = 0;
    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        resultado += v[i] * v[i];
    }

    return resultado;
}

double produtoInterno(vector<double> v, vector<double> u)
{
    double resultado = 0;
    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        resultado += v[i] * u[i];
    }

    return resultado;
}

void ortogGramSmichdt(vector<vector<double>> v, vector<vector<double>> &u, int tam)
{
    int n = v.size();
    u[0] = v[0];
    // Como u1 sempre será igual a v1, então já copio o vetor direto

    for (int i = 1; i < n; i++)
    {
        vector<double> vi = v[i];
        // Seleciono Vi, ou V(i+1), enfim, é o vetor original da fórmula

        for (int j = 0; j < i; j++)
        {
            vector<double> uAnterior = u[j];
            double escalar = produtoInterno(vi, uAnterior)/norma(uAnterior);

            for (int k = 0; k < tam; k++)
            {
                u[i][k] += escalar * uAnterior[k]; 
            }
        }
        // Somatorio da formúla
        
        for (int j = 0; j < tam; j++)
        {
            u[i][j] = vi[j] - u[i][j];
        }
        // Vi - Somatório
    }

    return;
}

signed main()
{
    cout << "Insira quantos vetores tem a sua base: " << endl;

    int dim;
    cin >> dim;

    cout << "Insira a quantidade de elemento por vetor: " << endl;

    int n;
    cin >> n;

    vector<vector<double>> v(dim, vector<double>(n, 0));
    vector<vector<double>> u(dim, vector<double>(n, 0));

    for (int i = 0; i < dim; i++)
    {
        cout << "Digite os elementos do vetor #" << i + 1 << ":" << endl;
        for (int j = 0; j < n; j++)
        {
            double x;
            cin >> x;

            v[i][j] = x;
        }
    }

    ortogGramSmichdt(v, u, n);

    for (int i = 0; i < dim; i++)
    {
        cout << "Vetor #" << i + 1 << ": {";

        for (int j = 0; j < n; j++)
        {
            if (j == 0) cout << u[i][j];
            else cout << ", " << u[i][j];
        }

        cout << "}" << endl;
    }

    return 0;
}