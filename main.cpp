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
    //cout << x[i] << " " << g[i]  << " " << exp(-10.0*x[i]) << endl;
  }
  /*
  for (int i = 0; i <= n; i++) {
    cout << d[i] << " " << g[i] << endl;
  }
  cout << " " << endl;
*/
  //forward substitution
  for (int i = 2; i <= n; i++) {
    d[i] = d[i] - ((a[i-1]*c[i-1])/d[i-1]);
    g[i] = g[i] - ((a[i-1]*g[i-1])/d[i-1]);
  }
  /* print updated values
  for (int i = 1; i <= n; i++) {
    cout << d[i] << " " << g[i] << endl;
  }
  */

  u[0] = u[n] = 0; //boundary conditions for solution u(x) x e(0,1)
  //backward substitution
  u[n-1] = g[n-1]/d[n-1];
  for (int i = n-2; i > 0 ; i--) {
    u[i] = (g[i]- c[i]*u[i+1])/d[i];
  }
  cout << "verdier for u[x(i)]" << endl;
  for (int i = 0; i <= n; i++) {
    cout << u[i] << " " << x[i] << endl;
  }

  outfile << setw(15) << setprecision(8) << "verdier for x: col[0], verdier for u: col[1]" << endl; 
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
