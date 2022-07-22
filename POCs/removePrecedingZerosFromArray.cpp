using namespace std;

void removeZeros(int a[], int n)
{
    int ind = -1;

    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            ind = i;
            break;
        }
    }

    if (ind == -1) {
        cout << "Array has leading zeros only";
        return;
    }

    int b[n - ind];

    for (int i = 0; i < n - ind; i++)
        b[i] = a[ind + i];

        cout << "Array has no zeros";
    for (int i = 0; i < n - ind; i++)
        cout << b[i] << " ";
}

int main()
{
    int a[] = { 0, 0, 0, 1, 2, 0, 3 };
    int n = sizeof(a) / sizeof(a[0]);
    removeZeros(a, n);
    return 0;
}
