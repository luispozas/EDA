/*

  1 - Space solution Sol[0..J)
  2 - Explicit conditions: sol[i] in [0..N)
  3 - Implicit conditions:
      + \forall q :  0 <= q < N : num(sol,J,q)>=M
      + \forall p,q :  0 <= q < J , 0 <= p < N : (V[q]=p -> AGE[p] >= REC[q])
      where num(sol,J,q) = #i : 0 <= i < J : V[i]=q
      3.1 Marking strategy
         value = \sum i : 0 <= i < J : Pref[V[i],i]
         \forall i : 0 <= i < N : many[i] = num(sol,k,i)
         totalMin = M*N - \sum i : 0 <= i < N : many[i] 
         
  4 - Solution  k == N-1 and totalMin=0
  5 - Init main
     val = 0
     bestVal = 0
     k = 0
     many[0..N) = M
     totalMin = M*N
     backTracking(J,k,many,totalMin,val,bestVal)  
      
*/




#include <algorithm>
#include <iostream>
#include <cassert>
using namespace std;

#define MAX 10000
// As they are constant per-case, take them as globals.

int M ; // minimum aassignment
int J ; // number of toys;
int N ; // number of children;
int Age[MAX] ; // childerns age
int Recomm[MAX]; // Minium agge recommended.
int Pref[MAX][MAX] ; // Preference kid-toy

// O(1)
int feasible(const int J,const int j,
             const int n, 
	     const int totalMin, const int many[])
{
  if (Age[n] < Recomm[j]) return 0;
  if (totalMin - (many[n]<M)  > (J - j)) return 0;
  return 1;
}




void backtracking(const int J,
                 const int j,
		 int totalMin,
		 int many[],
		 int val,
		 int &bestVal)
{
  for (int n=0 ; n < N ; n++) 
    {
      if (feasible(J,j,n,totalMin, many))
	{
	  totalMin -= (many[n] < M);
	  many[n] +=1;
	  val += Pref[n][j];
	  if (j==J-1)
	    {
	      if (totalMin==0)
		bestVal = max(bestVal,val);
	    }
	  else
	    backtracking(J,j+1,totalMin,many,val,bestVal);
	  val -= Pref[n][j];
	  many[n] -=1;
	  totalMin += (many[n] < M);	  
	}
    }
  return ;
}

#include <iostream>
#include <algorithm>

using namespace std;
int main(int argc, char *args[])
{
  // Take as global vars every thing but markers...
  for(cin >> J>> N >> M ; J || N || M ; cin >> J >> N >> M)
    {
      for (int j=0; j<J ; j++) cin >> Recomm[j];
      for (int n=0; n<N ; n++) cin >> Age[n];
      for (int n=0; n<N ; n++) 
	for (int j=0; j<J ; j++) cin >> Pref[n][j];
      int totalMin,val,bestVal,k;
      int many[MAX];
      totalMin = M*N;
      for (int n=0; n<N ; n++) many[n]=0;
      val = k = bestVal = 0 ;
      backtracking(J,k,totalMin,many,val,bestVal);
      cout << bestVal << endl;
    }
}


//	  cout << " j " << j << " J " << J << " n " << n << " N " << N << " val " << val << endl;
