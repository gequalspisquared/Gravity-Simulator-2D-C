#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>

#include "gravity_simulator.h"

typedef GLuint Shader;

Shader shader_create(const char *shader_vertex_path, const char *shader_fragment_path);

void shader_run(Shader shader);
void shader_destroy(Shader shader);
void shader_set_bool(const Shader shader, const char *name, uint value);
void shader_set_int(const Shader shader, const char *name, int value);
void shader_set_float(const Shader shader, const char *name, float value);
void shader_set_vec2_directly(const Shader shader, const char *name, const vec2 value);
void shader_set_vec2(const Shader shader, const char* name, float x, float y);
void shader_set_vec3_directly(const Shader shader, const char *name, const vec3 value);
void shader_set_vec3(const Shader shader, const char* name, float x, float y, float z);
void shader_set_vec4_directly(const Shader shader, const char *name, const vec4 value);
void shader_set_vec4(const Shader shader, const char* name, float x, float y, float z, float w);
void shader_set_mat2(const Shader shader, const char* name, const mat2 value);
void shader_set_mat3(const Shader shader, const char* name, const mat3 value);
void shader_set_mat4(const Shader shader, const char* name, const mat4 value);
/* extern void shader_set_vec2(const Shader *shader, const char *name, float value); */

#endif