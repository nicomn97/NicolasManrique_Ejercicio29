#include <stdio.h>
#include <omp.h>

int main(int argc, char **argv)
{

  double L=4;
  double tmax=10;
  double dx=0.1;
  double dt=0.1;
   int nx,nt,n,i;
  double F[nx];
  nx=L/dx+1;
  nt=tmax/dt+1;

  //inicializa u
  double u[nx];
  double cu[nx];
  #pragma omp for
  for(n=0;n<nx;n++)
  {
    if(n<200) u[n]=1;
    else u[n]=0;
    cu[n]=u[n];
    F[n]=u[n]*u[n];
  }



  for(i=0;i<nt;i++)
  {
    #pragma omp for
    for(n=1;n<nx-1;n++)
    {
      double p =u[n]-0.25*dt*(F[n+1]-F[n-1])/dx;
      cu[n]=p;
    }

    #pragma omp for
    for(n=1;n<nx-1;n++)
    {
      u[n]=cu[n];
    }

    #pragma omp for
    for(n=1;n<nx-1;n++)
    {
      F[n]=u[n]*u[n];
    }
  printf("loop: %d\n",i);
  }
  
  return 0;

}
