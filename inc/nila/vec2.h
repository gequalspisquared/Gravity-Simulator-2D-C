#ifndef NLA_VEC2_H
#define NLA_VEC2_H

#include "types.h"

float nla_vec2_mag(nla_vec2 a);
float nla_vec2_mag2(nla_vec2 a);
float nla_vec2_dot(nla_vec2 a, nla_vec2 b);

void nla_vec2_add(nla_vec2 a, nla_vec2 b, nla_vec2 dest);
void nla_vec2_adds(nla_vec2 a, float s, nla_vec2 dest);
void nla_vec2_sub(nla_vec2 a, nla_vec2 b, nla_vec2 dest);
void nla_vec2_subs(nla_vec2 a, float s, nla_vec2 dest);

#endif