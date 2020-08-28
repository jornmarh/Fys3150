#include<iostream>
#include<new>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<stdlib.h>

using namespace std;

int main(int argc, char* argv[]) {

  ofstream outfile;
  outfile.open("data.txt");

  int n = atoi(argv[1]);
  double* a; double* c; double* d;
  a = new double[n-1]; c = new double[n-1]; d = new double[n];
  for (int i = 0; i < n-1; i++) {
    a[i] = rand() % 9 + 1;
    c[i] = rand() % 9 + 1;
    d[i] = rand() % 9 + 1;
  }
  d[n-1] = rand() % 9 + 1;

  double h = 1.0/(n+1.0);
  double* g;
  g = new double[n];
  for (int i = 0; i < n; i++) {
    g[i] = h*h*100*exp(-10*i*h);
  }
  /*
  cout << "a, c :" << endl;
  for (int i = 0; i < n-1; i++) {
    cout << a[i] << " " << c[i] << endl;
  }

  cout << "g_start:" << endl;
  for (int i = 0; i < n; i++) {
    cout << g[i] << endl;
  }
  */

  //forward substitution
  for (int i = 1; i < n; i++) {
    d[i] = d[i] - (a[i-1]*c[i-1])/d[i-1];
    g[i] = g[i] - (a[i-1]*g[i-1])/d[i-1];
  }

  //backward substitution
  double* u;
  u = new double[n];
  u[n-1] = g[n-1]/d[n-1];
  for (int i = n-1; i != 0 ; i--) {
    u[i-1] = (g[i-1]- c[i-1]*u[i])/d[i-1];

  }

  double* x;
  x = new double[n];
  for (int i = 0; i < n; i++) {
    x[i] = i*h;
  }


  //write to outfile
  int rows = 2;
  double** data;
  data = new double*[rows];
  for (int i = 0; i < rows; i++) {
    data[i] = new double[n];
  }
  for (int j = 0; j < n; j++) {
    data[0][j] = u[j];
    data[1][j] = x[j];
  }

  for (int i = 0; i < n; i++) {
    outfile << setprecision(8) << data[0][i] << " " << data[1][i] << endl;
  }
  outfile.close();

  /*
  cout << "d_oppdatert:" << endl;
  for (int i = 0; i < n; i++) {
    cout << d[i] << endl;
  }

  cout << "g_oppdatert :" << endl;
  for (int i = 0; i < n; i++) {
    cout << g[i] << endl;
  }
  */












  delete[] a;
  delete[] c;
  delete[] d;
  delete[] g;
  delete[] u;

  return 0;
}
