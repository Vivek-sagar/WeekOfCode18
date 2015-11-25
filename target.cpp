#include <iostream>

using namespace std;


int main(){
    int64_t K;
    int64_t N;
    cin >> K >> N;
    vector<int64_t> R(K);
    for(int64_t R_i = 0;R_i < K;R_i++){
       cin >> R[R_i];
        R[R_i] = R[R_i]*R[R_i];
    }
    vector< vector<int64_t> > x(N,vector<int64_t>(2));
    for(int64_t x_i = 0;x_i < N;x_i++){
       for(int64_t x_j = 0;x_j < 2;x_j++){
          cin >> x[x_i][x_j];
       }
    }
   int64_t squared_dist;
    int64_t sum = 0;
    for(int64_t x_i = 0;x_i < N;x_i++)
    {
        squared_dist = x[x_i][0]*x[x_i][0] + x[x_i][1]*x[x_i][1];
        bool done = false;
        for (int64_t y=0; y<K; y++)
        {
            if (squared_dist > R[y])
            {
                //cout << y << " points\n";
                sum += y;
                done = true;
                break;
            }
        }
        if (!done)
        {
                //cout << K << " points\n";
                sum += K;        
        }
    }
    cout << sum;
    return 0;
}
