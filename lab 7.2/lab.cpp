#include <iostream>
#include <iomanip>
#include <climits>
#include <time.h>

using namespace std;

void Create(int** a, const int k, const int n, const int Low, const int High);
void Print(int** a, const int k, const int n);
void SwapMinMax(int** a, const int k, const int n);

int main() {
    srand((unsigned)time(NULL));
    int Low = 7;
    int High = 65;
    int k, n;

    cout << "Enter the number of rows (k): ";
    cin >> k;

    cout << "Enter the number of columns (n): ";
    cin >> n;

    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    Create(a, k, n, Low, High);

    cout << "Original Matrix:\n";
    Print(a, k, n);

    SwapMinMax(a, k, n);

    cout << "Modified Matrix:\n";
    Print(a, k, n);

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int k, const int n, const int Low, const int High) {
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int k, const int n) {
    cout << endl;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void SwapMinMax(int** a, const int k, const int n) {
    for (int j = 0; j < n; j += 2) {
        int minIndex = 0;
        int maxIndex = 0;

        for (int i = 1; i < k; i++) {
            if (a[i][j] < a[minIndex][j])
                minIndex = i;
            if (a[i][j] > a[maxIndex][j])
                maxIndex = i;
        }

        swap(a[minIndex][j], a[maxIndex][j]);
    }
}
