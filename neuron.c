#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RATE .0005
#define WEIGHT 3.0
#define BIAS 1.0

double aa = 1;
double bb = 1;

double get_random_double();
double real_value (double x);
double prediction (double a, double x, double b);
double error_quad (double a, double x, double b);
double derivative_a (double a, double x, double b);
double derivative_b (double a, double x, double b);
void train(double x);

int main (int argc, char *argv[]) {
	for (int opt_i = 0; opt_i < argc; opt_i++) {
		char parameter[] = argv[opt_i];
		printf("opt_i=%d parameter=%s", opt_i, parameter);
	}
	int calc ();
}

int calc (void) {
	// Seed the random number generator
	srand(time(NULL));

	double x = get_random_double();
	double error = 0.0;
	do {
		double x = get_random_double();
		error = error_quad(aa,x,bb);
		printf("-----\nNew Epoch\n-----\n"); 
		printf("Weight is: %f\n", aa);
		printf("Bias is: %f\n", bb);
		printf("x is: %f\n", x);
		printf("Predicted y is: %f\n", prediction(aa, x, bb));
		printf("Real y is: %f\n", real_value(x));
		printf("Error is: %f\n", error);
		train(x);
	} while (error > 0.000000000001);
	puts("-----\nBest fit found");
	return 0;
}

double error_quad (double a,double x,double b) {
	double error = ((a*x+b)-(WEIGHT *x + BIAS))*((a*x+b)-(WEIGHT * x + BIAS));
	return(error);
}

double derivative_a (double a,double x,double b) {
	double derivative = 2 * a * x * x + 2 * b * x - 2 * WEIGHT * x * x - 2 * BIAS * x;
	return(derivative);
}

double derivative_b (double a, double x, double b) {
	double derivative = 2 * a * x + 2 * b - 2 * WEIGHT * x - 2 * BIAS;
	return(derivative);
}

double prediction (double a, double x, double b) {
	double prediction_is = a*x + b;
	return(prediction_is);
}

double real_value (double x) {
	double real_value_is = WEIGHT * x + BIAS;
	return(real_value_is);
}

double get_random_double () {
	return ((double)rand() / RAND_MAX) * 50.0;
}

void train (double x) {
	aa -= RATE * derivative_a(aa, x, bb);
	bb -= RATE * derivative_b(aa, x, bb);
}

