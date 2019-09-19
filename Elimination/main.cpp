#include <iostream>
#include <vector>

using namespace std;
int main() {
    int m;
    cout << "Number of equations: ";
    cin >> m;
    int n;
    cout << "Number of variables: ";
    cin >> n;

    cout << "Enter variable coefficients" << endl;
    auto ** a = new double*[m];
    for (int i = 0; i < m; i++) {
        a[i] = new double[n];
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    cout << "Enter free terms" << endl;
    auto * b = new double[m];
    for (int i  =0;  i< m; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < m; i++) {
        if (a[i][i] == 0) {
            for (int j = i + 1; j < m; j++) {
                if (a[j][i] != 0) {
                    double * tmp = a[j];
                    a[j] = a[i];
                    a[i] = tmp;
                }
            }
        }
    }

    for (int i = 0; i < m; i++) {
        double divider = a[i][i];
        for (int j = 0; j < n; j++) {
            a[i][j] /= divider;
        }
        b[i] /= divider;
        for (int j = i + 1; j < n; j++) {
            double factor = a[j][i];
            for (int r = 0; r < n; r++) {
                a[j][r] -= a[i][r] * factor;
            }
            b[j] -= b[i] * factor;
        }
    }

    /*for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << b[i] << endl;
    }*/

    auto * x = new float[m];
    for (int i = m - 1; i >= 0; i--) {
        float value = b[i];
        for (int j = i + 1; j < m; j++) {
            value -= x[j] * a[i][j];
        }
        x[i] = value / a[i][i];
    }

    cout << "Answer: ";

    for (int i = 0; i < m; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}