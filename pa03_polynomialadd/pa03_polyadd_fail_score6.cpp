#include <iostream>
#include <vector>


using namespace std;

int main()
{
    //1.number of fucntion
    int N=0;
    cin>>N;

    //int coef[1103];
    //int exp[1103];

    int poly[1103];

    for(int i=0;i<1103;i++) {
        poly[i]=-1000;
    }


    /*int *a_strat = coef;
    int *b_start = exp; //
    int *a_end = coef+1; */


    int gaesu = 0;
    int jisu = 0;
    int cnt = 0;

    for(int i=0;i<N;i++) {
        int p=0; //2. number of hang
        cin>>p;
        for(int j=0;j<p;j++) {
            cin>>gaesu;
            cin>>jisu;

            jisu = jisu + 100;
            if(poly[jisu]==-1000) {
                //cout<<"debug: "<<gaesu<<'\n';
                poly[jisu] = gaesu;
                cnt++;
            }
            else {
                poly[jisu] += gaesu;
                if(poly[jisu]==0) cnt--;
            }

        }
    }

    //3.print
    cout<<cnt<<'\n';
    for(int i=1102;i>=0;i--) {
        if(poly[i]!=-1000&&poly[i]!=0) cout<<poly[i]<<' '<<i-100<<'\n';
    }

    return 0;
}
