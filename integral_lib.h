#ifndef INTEGRAL_H
#define INTEGRAL_H

float computeMachineEpsilon();
float func(float x);
float RectangleMethod(float A, float B, float e);
float TrapezoidalMethod(float A, float B, float e);
float SinIntegral(float A, float B, float e, int method);

#endif  // INTEGRAL_H
