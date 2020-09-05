
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef double (*fn)(double base, double fac, double divisor);

static
inline
double powdiv(double base, double fac, double divisor) {
  return pow(base, fac) / divisor;
}

static
inline
double powmul(double base, double fac, double divisor) {
  return pow(base, fac) * divisor;
}

static
inline
double * calc(fn mf,
              double * array,
              double const fac,
              double divisor,
              size_t az) {
  for (size_t i = 0; i <= az; ++i) {
    array[i] = mf((double) i, fac, divisor);
  }

  return array;
}

int main(int argc, char const * argv[]) {
  printf("VastPromotedStartups\n");

  size_t ary_sz = 15;
  double * ap;
  ap = malloc(sizeof(double) * ary_sz);

  ap = calc(powdiv, ap, 6.0, 13.0, ary_sz);
  for (size_t a = 0; a <= ary_sz; ++a) {
    printf("%5zu: %30.3f\n", a, ap[a]);
  }

  ary_sz = 10;
  free(ap);

  ap = malloc(sizeof(double) * ary_sz);

  ap = calc(powmul, ap, 6.0, 13.0, ary_sz);
  for (size_t a = 0; a <= ary_sz; ++a) {
    printf("%5zu: %30.3f\n", a, ap[a]);
  }

  free(ap);

  return 0;
}