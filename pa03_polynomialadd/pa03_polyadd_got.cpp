#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // 1. Number of functions
    int N = 0;
    cin >> N;

    int poly[1103] = {0}; // Initialize all coefficients to 0
    bool used[1103] = {false}; // Track used exponents

    int gaesu = 0;
    int jisu = 0;
    int cnt = 0;

    for (int i = 0; i < N; i++) {
        int p = 0; // 2. Number of terms
        cin >> p;
        for (int j = 0; j < p; j++) {
            cin >> gaesu;
            cin >> jisu;

            jisu = jisu + 100;

            poly[jisu] += gaesu;

            if (!used[jisu] && poly[jisu] != 0) {
                used[jisu] = true;
                cnt++;
            } else if (used[jisu] && poly[jisu] == 0) {
                used[jisu] = false;
                cnt--;
            }
        }
    }

    // 3. Print
    if (cnt == 0) {
        cout << "1\n0 0\n";
    } else {
        cout << cnt << '\n';
        for (int i = 1102; i >= 0; i--) {
            if (used[i]) {
                cout << poly[i] << ' ' << i - 100 << '\n';
            }
        }
    }

    return 0;
}
