#include <iostream>
#include <vector>
using namespace std;

int main() {
    //[1].Input and declariation
    int K,N;
    cin>>K>>N;
    vector<int> parking(K);
    int car;
    int parkcnt=0;
    int OldK = K;

    //[2].Park the Car
    for(int i=0;i<N;i++) {
        cin>>car;
        if(parkcnt==K) {
            //for(int j=0;j<K;j++) parking.push_back(0);
            //parking.reserve(K*2);
            parking.resize(K*2);
            K*=2;
        }

        for(int j=0;j<K;j++) {
            if(car<0) {
                //cout<<"test\n";
                if(parking[j]+car==0) {
                    parking[j]=0;
                    //cout<<"test: "<<parking[j]<<"\n";
                    parkcnt--;
                    break;
                }
            }
            else if(parking[j]==0) {
                parking[j] = car;
                parkcnt++;
                break;
            }
        }
    }

    //cout<<"parkcnt:"<<parkcnt<<" K:"<<K<<" K/3:"<<K/3<<'\n';
    //[3].final resize
    if ((parkcnt <= (K / 3)) && (K > OldK)) {
        int newK = max(OldK, K / 2);
        vector<int> newpark(newK);
        int n = 0;
        for (int i = 0; i < K; i++) {
            if (parking[i] != 0) {
                newpark[n] = parking[i];
                n++;
            }
        }
        // Output the final parking slots
        for (int i = 0; i < n; i++) {
            cout << i + 1 << ' ' << newpark[i] << '\n';
        }
        exit(0);
    }

    for(int i=0;i<K;i++) if(parking[i]!=0) cout<<i+1<<' '<<parking[i]<<'\n';



    return 0;
}
