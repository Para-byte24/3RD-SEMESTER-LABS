//Newton Raphson Method

#include<stdio.h>
#include<math.h>

double f(double x){  //x^3 + x^2 - 4x - 2
	return (x * x * x) + (x * x) - (4 * x) - 2;
}

double f_prime(double x){
	return 3 * x * x + 2 * x - 4;
}

int main(){
	double x0, x1;
	int iteration = 0;
	const double tolerance = 0.001;
	
	printf("Newton-Raphson Method for f(x) = X^3 + X^2 -4x - 2\n");
	printf("Enter initial guess x0: ");
	scanf("%lf",&x0);
	while(iteration < 100){
		iteration++;
		
		if(fabs(f_prime(x0))< le - 5){
			printf("Error:f'(x) is zero");
		}
		
		x1=x0-f(x0)/f_prime(x0);
		printf("iteration")
	}
}

