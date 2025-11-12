#include "complex_numbers.h"
#define PI 3.14159265358979323846
#define TERMS 25

complex_t c_add(complex_t a, complex_t b) {
    complex_t new = {0};
    new.real = a.real + b.real;
    new.imag = a.imag + b.imag;
    return new;
}

complex_t c_sub(complex_t a, complex_t b) {
    complex_t new = {0};
    new.real = a.real - b.real;
    new.imag = a.imag - b.imag;
    return new;
}

complex_t c_mul(complex_t a, complex_t b) {
    complex_t new = {0};
    new.real = (a.real * b.real) + ((a.imag * b.imag) * -1);
    new.imag = (a.real * b.imag) + (a.imag * b.real);
    return new;
}

complex_t c_div(complex_t a, complex_t b) {
   complex_t new = {0};
    new.real = (a.real * b.real + a.imag * b.imag) 
                / ((b.real * b.real) + (b.imag * b.imag));
    new.imag = (a.imag * b.real - a.real * b.imag)
                / ((b.real * b.real) + (b.imag * b.imag));
    return new;
}

double c_abs(complex_t x) {
    double magnitude_squared = (x.real * x.real) + (x.imag * x.imag);
    double error = 0.01; // precision
    double s = magnitude_squared;

    while(s - magnitude_squared / s > error) {
        s = (s + magnitude_squared / s) / 2; //babylonian sqrt
    }
    return s;
}

complex_t c_conjugate(complex_t x) {
    complex_t new = {0};
    new.real = x.real;
    new.imag = x.imag * -1; //flipping imaginary number
    return new;
}

double c_real(complex_t x) {
    complex_t new = {0};
    new.real = x.real;
    return new.real;
}

double c_imag(complex_t x) {
    complex_t new = {0};
    new.imag = x.imag;
    return new.imag;
}

double power(double base, int exp) {
    double res = 1.0;
    for(int i = 0; i < exp; i++) res *= base;
    return res;
}

double fact(int n) {
    double res = 1.0;
    for(int i = 2; i <= n; i++) res *= i;
    return res;
}

double sine(double x) {
    x = x - ((int)(x / (2 * PI))) * (2 * PI); // wrap angle
    double sum = 0.0;
    for(int n = 0; n < TERMS; n++) {
        double term = power(-1, n) * power(x, 2 * n + 1) / fact(2 * n + 1);
        sum += term;
    }
    return sum;
}

double cosine(double x) {
    x = x - ((int)(x / (2 * PI))) * (2 * PI); // wrap angle
    double sum = 0.0;
    for(int n = 0; n < TERMS; n++) {
        double term = power(-1, n) * power(x, 2 * n) / fact(2 * n);
        sum += term;
    }
    return sum;
}

double exp_taylor(double x) {
    if(x == 0.0) return 1.0;

    int neg = 0;
    if(x < 0) { neg = 1; x = -x; }

    double sum = 1.0;
    double term = 1.0;
    double c = 0.0;  // compensation

    for(int n = 1; n < TERMS; n++) {
        term *= x / n;
        double y = term - c;
        double t = sum + y;
        c = (t - sum) - y;
        sum = t;
    }

    if(neg) return 1.0 / sum;
    return sum;
}

complex_t c_exp(complex_t x)
{
    complex_t new;
    double ea = exp_taylor(x.real);
    new.real = ea * cosine(x.imag);
    new.imag = ea * sine(x.imag);
    return new;
}
