#include "nila/vec2.h"
#include <math.h>

float nla_vec2_mag(nla_vec2 a)
{
    return sqrt(a[0]*a[0] + a[1]*a[1]);
}

float nla_vec2_mag2(nla_vec2 a)
{
    return a[0]*a[0] + a[1]*a[1];
}

float nla_vec2_dot(nla_vec2 a, nla_vec2 b)
{
    return a[0]*b[0] + a[1]*b[1];
}

float nla_vec2_cross(nla_vec2 a, nla_vec2 b)
{
    return a[0]*b[1] - a[1]*b[0];
}

void 
nla_vec2_copy(nla_vec2 a, nla_vec2 dest) 
{
    dest[0] = a[0];
    dest[1] = a[1];
}

void 
nla_vec2_zero(nla_vec2 v)
{
    v[0] = 0.0f;
    v[1] = 0.0f;
}

void 
nla_vec2_one(nla_vec2 v)
{
    v[0] = 1.0f;
    v[1] = 1.0f;
}

void
nla_vec2_add(nla_vec2 a, nla_vec2 b, nla_vec2 dest)
{
    dest[0] = a[0] + b[0];
    dest[1] = a[1] + b[1];
}

void
nla_vec2_adds(nla_vec2 a, float s, nla_vec2 dest)
{
    dest[0] = a[0] + s;
    dest[1] = a[1] + s;
}

void
nla_vec2_sub(nla_vec2 a, nla_vec2 b, nla_vec2 dest)
{
    dest[0] = a[0] - b[0];
    dest[1] = a[1] - b[1];
}

void
nla_vec2_subs(nla_vec2 a, float s, nla_vec2 dest)
{
    dest[0] = a[0] - s;
    dest[1] = a[1] - s;
}