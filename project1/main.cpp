#include<iostream>
#include<new>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<stdlib.h>

void generellalgo(double*, double*, double*, double*, double*, int);
void spesifikalgo(double*, double*, double*, double*, double*, int);

using namespace std;
int main(int argc, char* argv[]) {

  //create outfile
  ofstream outfile;
  outfile.open("data.txt");
  int n = atoi(argv[1]);

  //initilize a,c,d,g,u,x

  double* a; double* c; double* d;
  a = new double[n+1]; c = new double[n+1]; d = new double[n+1];

  double* x; double* u; double* g;
  x = new double[n+1]; u = new double[n+1]; g = new double[n+1];

  double h = 1.0/(n+1.0); //step length

  a[0] = c[0] = d[0] = 0;

  for (int i = 1; i <= n; i++) {
    a[i] = c[i] = -1; //set values of a,c
    d[i] = 2; //set values of d
  }

  for (int i = 0; i <= n; i++) {
    x[i] = i*h; //set values of x
    g[i] = h*h*100.0*exp(-10.0*x[i]); //set initial values of g.
  }

  u[0] = u[n] = 0;
  generalalgo(a, c, d, g, u, n); //use general algorythm

  //cout << "verdier for u[x(i)]" << endl;
  //for (int i = 0; i <= n; i++) {
    //cout << u[i] << " " << x[i] << endl;
  //}

  for (int i = 0; i <= n; i++) {
    outfile << setw(15) << setprecision(8) << x[i] << " " << u[i] << endl;
  }
  outfile.close();

  delete[] a;
  delete[] c;
  delete[] d;
  delete[] g;
  delete[] u;

  return 0;
}

void generellalgo(double* under, double* over, double* diagonal, double* funksjon, double* solution, int dimensjon) {
  for (int i = 2; i <= dimensjon; i++) {
    diagonal[i] = diagonal[i] - ((under[i-1]*over[i-1])/diagonal[i-1]);
    funksjon[i] = funksjon[i] - ((under[i-1]*funksjon[i-1])/diagonal[i-1]);
  }
  solution[dimensjon-1] = funksjon[dimensjon-1]/diagonal[dimensjon-1];
  for (int i = dimensjon-2; i > 0 ; i--) {
    solution[i] = (funksjon[i]- over[i]*solution[i+1])/diagonal[i];
  }

}
void spesifikalgo(double* under, double* over, double* diagonal, double* funksjon, double* solution, int dimensjon) {
  
}
