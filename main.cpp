#include <iostream>
#include <stdio.h>
#include <thread>
#include <atomic>

using namespace std;

void multiply_threading(int a[], int b[][3], int matrixC[][3], int n, int i){
  for (int j=0; j< n; j++){
    int sum=0;
    for (int k=0; k< n; k++){
      sum+=a[k] * b[k][j];
    }
    matrixC[i][j]=sum;
  }
}

int main(){
  const int n=3; //tamaño de la matriz
  int matrixA[n][n]={ {0,1,2},
                {3,4,5},
                {6,7,8}};
  int matrixB[n][n]={ {0,12,2},
                {3,4,5},
                {10,7,8}};
  int matrixC[n][n];

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
        matrixC[i][j]=0;
    }
  }

  int THREADS_NUMBER=n;

  thread threads[THREADS_NUMBER];

  for (int i = 0; i < THREADS_NUMBER; ++i) {
    threads[i] = thread(multiply_threading, matrixA[i], matrixB, matrixC, n, i);
  }

  for (int i = 0; i < THREADS_NUMBER; ++i) {
    threads[i].join();
  }

  cout << endl << "Matriz Resultante " << endl;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
        cout << " " << matrixC[i][j];
      }
    cout << endl;
    }

    return 0;
}
