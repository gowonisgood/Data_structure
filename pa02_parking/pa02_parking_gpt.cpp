#include <iostream>
#include <vector>
using namespace std;

int main() {
    //[1].
    int K, N;
    cin >> K >> N;
    vector<int> parking(K, 0);
    int car;
    int parkcnt = 0;
    int OldK = K;

    //[2].
    for (int i = 0; i < N; i++) {
        cin >> car;

        if (car < 0) {
            bool found = false;
            for (int j = 0; j < K; j++) {
                if (parking[j] == -car) {
                    parking[j] = 0;
                    parkcnt--;
                    found = true;
                    break;
                }
            }


            if ((parkcnt <= (K / 3)) && (K > OldK)) {
                int NewK = max(OldK, K / 2);
                vector<int> newpark(NewK, 0);
                int n = 0;
                for (int i = 0; i < K; i++) {
                    if (parking[i] != 0) {
                        newpark[n] = parking[i];
                        n++;
                    }
                }
                K = NewK;
                parking = newpark;
            }

        } else {

            if (parkcnt == K) {

                parking.resize(K * 2, 0);
                K *= 2;
            }
            for (int j = 0; j < K; j++) {
                if (parking[j] == 0) {
                    parking[j] = car;
                    parkcnt++;
                    break;
                }
            }
        }
    }

    // [4]
    for (int i = 0; i < K; i++) {
        if (parking[i] != 0) {
            cout << i + 1 << ' ' << parking[i] << '\n';
        }
    }

    return 0;
}
