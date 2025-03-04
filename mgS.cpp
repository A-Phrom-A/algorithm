#include <bits/stdc++.h>
using namespace std;

int ar[10000];

void mg(int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int a[n1], b[n2];

    for (i = 0; i < n1; i++) {
        a[i] = ar[l + i]; 
    }
    for (j = 0; j < n2; j++) {
        b[j] = ar[m + 1 + j];  
    }

    i = 0; j = 0; k = l;  
    
    
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            ar[k] = a[i];
            i++;  
        } else {
            ar[k] = b[j];
            j++;
        }
        k++;
    }


    while (i < n1) {
        ar[k] = a[i];
        i++;
        k++;
    }


    while (j < n2) {
        ar[k] = b[j];
        j++;
        k++;
    }
}

void mgS(int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;  
        mgS(l, m);
        mgS(m + 1, r);
        mg(l, m, r);
    }
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> ar[i];  
    }

    mgS(0, n - 1);

    int ct = 1;
    for (int i = 1; i < n; i++) {  
        if (ar[i] - ar[i - 1] != 1) {
            ct++;
        }
    }

    cout << ct << endl;
    return 0;
}

