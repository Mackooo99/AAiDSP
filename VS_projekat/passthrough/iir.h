#include <stdio.h>
#include <stdint.h>


double second_order_IIR(double, double*, double*, double*);

double Nth_order_IIR(double input, double coefficients[][6], double x_history[][2],	double y_history[][2], unsigned int N_STAGES);