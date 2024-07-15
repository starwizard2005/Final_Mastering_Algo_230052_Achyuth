#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

vector < vector < long long int > > matrix_mult(int n,vector < vector <long long int> > &arr1,vector < vector <long long int> > &arr2){
    vector <vector < long long int > > new_arr(n, vector<long long>(n, 0));
    for (int i = 0;i<n;i++){
        for (int j = 0;j<n;j++){
            long long int sum = 0;
            for (int k = 0;k<n;k++){
                sum += arr1[i][k] * arr2[k][j];
                sum %= MOD;
            }
            new_arr[i][j] = sum;
        }
    }
    return new_arr;
}

int matrix_exp(int n,vector < vector <long long int> > &arr,long long int k){
    vector <vector < long long int > > result(n, vector<long long>(n, 0));
    int temp = n;
    for (int i = 0; i < n; i++) {
        result[i][i] = 1;
    }
    while(k)
    {
        if (k & 1)
            result = matrix_mult(temp,result,arr);
        k = k >> 1;
        arr = matrix_mult(temp,arr,arr);
    }
    long long int sum = 0;
    for (int i = 0;i<temp;i++){
        for (int j = 0;j<temp;j++){
            sum += result[i][j];
            sum %= MOD;
        }
    }
    return sum;
}

int main(){
    long long int n,k;
    cin >> n >> k;
    vector < vector <long long int> > arr(n,vector <long long int> (n,0));
    for (int i = 0;i<n;i++){
        for (int j = 0;j<n;j++){
            cin >> arr[i][j];
        }
    }

    cout << matrix_exp(n,arr,k) << endl;

}


