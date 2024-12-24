#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    const int MAX_HOUR = 100000; 
    vector<int> diff(MAX_HOUR + 2, 0);

    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        diff[start] += 1;        
        diff[end + 1] -= 1;      
    }

    int maxCustomers = 0;
    int currentCustomers = 0;
    int maxStart = -1, maxEnd = -1;

    bool inMaxRange = false; 

    for (int hour = 0; hour <= MAX_HOUR; hour++) {
        currentCustomers += diff[hour]; 

        if (currentCustomers > maxCustomers) {
            maxCustomers = currentCustomers;
            maxStart = hour;
            inMaxRange = true;
        }

        if (currentCustomers < maxCustomers && inMaxRange) {
            maxEnd = hour - 1;
            inMaxRange = false;
        }
    }

    cout << maxStart << " " << maxEnd << " " << maxCustomers << endl;

    return 0;
}

