#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include<omp.h>
#define PI 3.1415926538837211
 void main(int argc,char **argv)
{
	
	double    x, totalsum, h,time;
	int Noofintervals,i,t;
printf("Enter number of intervalsand no of threads\n");
	scanf("%d%d", &Noofintervals,&t);


	/* No. of intervals should be positive integer */
	if (Noofintervals<= 0)
 	 {
		printf(" Number of intervals should be positive integer\n");
		exit(1);
	}
	totalsum = 0.0;

		h = 1.0 / Noofintervals;
time=omp_get_wtime();
omp_set_num_threads(t);

		for (i = 1; i <Noofintervals + 1; i = i+1)
              {
		x = h * (i + 0.5);
		totalsum = totalsum + 4.0/(1.0 + x * x);
	} 
time=omp_get_wtime()-time;

	totalsum = totalsum * h;
	printf("Calculated PI : \t%1.15lf \n Error : \t%1.16lf\n", totalsum, fabs(totalsum - PI));
	printf("number of threads: %d\ntime taken: %1.15lf\n ",t,time);
	return ;
}