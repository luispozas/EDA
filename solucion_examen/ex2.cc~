/*

  Intersection possitions .

 Note : indices run parallel, hence can be simplified.


   P : (N-0)>1 strictInc(V[0..N)) and   strictDec(W[0..N))
   Q : [n,m) contains L(V) \cap L(W)

L(V) stands for "polygonal defined by V" (piecewise function)

Acording to Theorem of Division, A=1, B=2, and k=0, hence O(log(n))
*/

#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 1000

/* Inmmersion */
/* Informally, we drop out side divergent sections  of plan */

// P' : P[0/i,N/j,N-0/j-i] and 0 <= i + 1 < j <= N and
//     i>0 -> |V[i]-W[i]| < |V[i-1]-W[i-1]| and
//     j<N -> |V[j-1]-W[j-1]| < |V[j]-W[j]|
// Q' : [n,m) contains L(V) \cap L(W)
void crossG(const int V[],const int W[], const int N,
	    const int i, const int j,
	    int &n, int &m)
{
  //  cout << i << " " << j << endl;
  if ((j-i)==2) // Basis. One segment
    {
      if (V[i]>W[i]) {  n = i-1 ; m = i ; return ; } // previous segment
      if (V[i]==W[i]) { n = i ; m = i + 1 ; return ;}
      if (V[i]<W[i])
	{
	  if (V[i+1]>W[i+1]) { n = i ; m = i + 1 ; return ;} // crossed 
	  if (V[i+1]<=W[i+1]) { n = i+1 ; m = i+2 ; return ;} // next segment		
	}
    }
  // size > 2
  const int h = (i+j)/2 ;
  if (V[h]==W[h])  { n = h ; m = h + 1 ; return ;}
  if (V[h]>W[h])  { crossG(V,W,N,i,h+1,n,m); return ; } // an eye!!, we must grab h as border!
  if (V[h]<W[h]) { crossG(V,W,N,h,j,n,m); return ; } 
}

/*
  P : (N-0)>1 strictInc(V[0..N)) and   strictDec(W[0..N))
  Q : [n,m) contains L(V) \cap L(W)
*/
void cross(const int V[], const int W[], const int N, int &i, int &j)
{
  return crossG(V,W,N,0,N,i,j);
}



int main(int argc, char *args[])
{
  int N ;
  int V[MAX],W[MAX];
  int i, j ;
  int n;
  for (cin >> N  ; N; cin >> N)
    {
      for (int n=0; n<N; n++) cin >> V[n];
      for (int n=0; n<N; n++) cin >> W[n];
      cross(V,W,N,i,j);
      cout << i << " " << j << endl;
    }
  return 0;
}


/*

5
1 3 4 7 8
8 7 4 2 1
2 3
6
-5 -3 -1 0 4 7
9 6 5 2 1 0

3 4
6
1 3 4 5 7 8
-1 -2 -4 -5 -7 -8
-1 0
6
1 3 4 5 7 8 
17 14 12 11 9 8 
5 6
0



*/
