#include<stdio.h>
#include<math.h>

// define the function f(x) = x^3 + x^2 - 4x - 2
double f(double x){
	return x * x * x + x * x - 4 * x - 2;
}

int main(){
	double a, b, c;
	int iteration = 0;
	
	a=1;
	b=2;
	if(f(a) * f(b) >= 0){
		printf("Invalid interval: f(a) and f(b) must have opposite signs.\n");
		return 1;
	}
	
	printf("Bisection Method for f(x) = x^3 + x^2 - 4x - 2\n");
	printf("Initial interval: [%.3f, %.3f]\n\n",a,b);
	
	while((b - a) >= 0.001){
		iteration++;
		c = (a + b) / 2.0; //midpoint
		
		printf("Iteration %d: a=%.3f, b=%.3f, c=%.3f, f(c)=%.3f\n",iteration, a, b, c, f(c));
		
		if(fabs(f(c))<=0.001)
			b = c;
		else
		    a = c;
	}
	
	printf("\nApproximate root after %d iteration: %.3f\n",iteration, c);
	
	return 0;
}
