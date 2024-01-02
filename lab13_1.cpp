#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double datas[], int N, double stats[]){
    double aSum = 0, sSum = 0, prod = 1, hSum = 0, minVal = __DBL_MAX__, maxVal = 0;
    for(int i = 0; i < N; i++){
        double data = datas[i];
        aSum += data;
        sSum += data * data;
        prod *= data;
        hSum += 1/data;
        minVal = min(minVal, data);
        maxVal = max(maxVal, data);
    }

    stats[0] = aSum / N;
    stats[1] = sqrt(sSum / N - stats[0] * stats[0]);
    stats[2] = pow(prod, 1.0 / N);
    stats[3] = N / hSum;
    stats[4] = maxVal;
    stats[5] = minVal;
}