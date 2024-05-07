#include <iostream>
#include <cmath>
using namespace std;
int n;
int** mat;
double** comm;
int Max;
int u;
int v;
int main()
{
    Max = 2000000001;
    cin >> n;
    mat = new int* [n];
    for (int i = 0; i < n; i++)
    {
        int a1, a2;
        cin >> a1;
        cin >> a2;
        mat[i] = new int[2];
        mat[i][0] = a1;
        mat[i][1] = a2;
    }
    comm = new double* [n];
    for (int j = 0; j < n; j++) {
        comm[j] = new double[n];
        for (int k = 0; k < n; k++) {
            if (k == j) {
                comm[j][k] = Max;
            }
            if (k > j) {
                comm[j][k] = sqrt(pow((mat[k][0] - mat[j][0]), 2) + pow((mat[k][1] - mat[j][1]), 2));
            }
            if (k < j) {
                comm[j][k] = comm[k][j];
            }
        }
    }
    int Min = Max;
    for (int l = 0; l < n; l++) {
        for (int f = 0; f < n; f++) {
            if (comm[l][f] < Min) {
                Min = comm[l][f];
                v = l;
            }
        }
    }
    for (int _ = 0; _ < n; _++) {
        Min = Max;
        for (int d = 0; d < n; d++) {            
            if (comm[v][d] < Min)
            {
                u = d;
                Min = comm[v][u];
            }
        }
        for (int __ = 0; __ < n; __++) {
            comm[__][u] = Max;
        }
        cout << u + 1 << " ";
        v = u;
    }
}
