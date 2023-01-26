#ifndef NLA_VEC2_H
#define NLA_VEC2_H

#include "types.h"

float nla_vec2_mag(nla_vec2 a);
float nla_vec2_mag2(nla_vec2 a);
float nla_vec2_dot(nla_vec2 a, nla_vec2 b);
float nla_vec2_cross(nla_vec2 a, nla_vec2 b);

void nla_vec2_copy(nla_vec2 a, nla_vec2 dest);
void nla_vec2_zero(nla_vec2 v);
void nla_vec2_one(nla_vec2 v);
void nla_vec2_add(nla_vec2 a, nla_vec2 b, nla_vec2 dest);
void nla_vec2_adds(nla_vec2 a, float s, nla_vec2 dest);
void nla_vec2_sub(nla_vec2 a, nla_vec2 b, nla_vec2 dest);
void nla_vec2_subs(nla_vec2 a, float s, nla_vec2 dest);
void nla_vec2_mul(nla_vec2 a, nla_vec2 b, nla_vec2 dest);
void nla_vec2_scale(nla_vec2 a, float s, nla_vec2 dest);
void nla_vec2_scale_as(nla_vec2 a, float s, nla_vec2 dest);
void nla_vec2_div(nla_vec2 a, nla_vec2 b, nla_vec2 dest);
void nla_vec2_divs(nla_vec2 a, float s, nla_vec2 dest);
void nla_vec2_add_increment(nla_vec2 a, nla_vec2 b, nla_vec2 dest);
void nla_vec2_add_decrement(nla_vec2 a, nla_vec2 b, nla_vec2 dest);
void nla_vec2_sub_increment(nla_vec2 a, nla_vec2 b, nla_vec2 dest);
void nla_vec2_sub_decrement(nla_vec2 a, nla_vec2 b, nla_vec2 dest);
void nla_vec2_mul_increment(nla_vec2 a, nla_vec2 b, nla_vec2 dest);
void nla_vec2_muls_increment(nla_vec2 a, nla_vec2 b, nla_vec2 dest);
void nla_vec2_mul_decrement(nla_vec2 a, nla_vec2 b, nla_vec2 dest);
void nla_vec2_muls_decrement(nla_vec2 a, nla_vec2 b, nla_vec2 dest);
void nla_vec2_div_increment(nla_vec2 a, nla_vec2 b, nla_vec2 dest);
void nla_vec2_divs_increment(nla_vec2 a, nla_vec2 b, nla_vec2 dest);
void nla_vec2_div_decrement(nla_vec2 a, nla_vec2 b, nla_vec2 dest);
void nla_vec2_divs_decrement(nla_vec2 a, nla_vec2 b, nla_vec2 dest);
void nla_vec2_rotate(nla_vec2 v, float angle);
void nla_vec2_rotate_to(nla_vec2 v, float angle, nla_vec2 dest);
void nla_vec2_normalize(nla_vec2 v);
void nla_vec2_normalize_to(nla_vec2 v, nla_vec2 dest);

#endif