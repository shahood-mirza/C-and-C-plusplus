#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#ifdef __cplusplus
extern "C" {
#endif

double __declspec(dllexport) nop(double x, int n);

double __declspec(dllexport) ln(double x, int n);