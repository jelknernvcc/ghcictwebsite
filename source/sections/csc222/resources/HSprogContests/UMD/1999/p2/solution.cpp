#include <iostream>
using namespace std;

int abs(int a) {
  if(a>0) return a;
  else return -a;
}
    
int steps(int a, int b, int c, int d) {
  int n = 0;
  int a0;
  while (1) {
    if (a==b && a==c && a==d) return n;
    a0 = a;
    a = abs(b-a);
    b = abs(c-b);
    c = abs(d-c);
    d = abs(a0-d);
    n++;
  }
}

int search(int steplimit, int intlimit) {
  int i, j, k, l, n;

  for(i=0; i<=intlimit; i++)
    for(j=0; j<=intlimit; j++)
      for(k=0; k<=intlimit; k++)
        for(l=0; l<=intlimit; l++)
          if(i==intlimit || j==intlimit || k==intlimit || l==intlimit) {
            if( (n=steps(i,j,k,l)) >= steplimit) {
//              cout<<i<<", "<<j<<", "<<k<<", " <<l<<" : "<<n<<"\n";
              return n;
            }
          }
  return 0;
}

int main() {
  int nmax;
  int nsteps;
  int found;

  cin >> nsteps;

  found = 0;
  nmax = 1;
  while (!found) {
    found = search(nsteps, nmax);
    if (found) 
      cout << nsteps << " " << nmax << "\n";
    else nmax++;
  }
      
  return 0;
}
