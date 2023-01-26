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
void shader_set_vec2_vec2(const Shader shader, const char *name, const vec2 value);
void shader_set_vec2(const Shader shader, float x, float y);
/* extern void shader_set_vec2(const Shader *shader, const char *name, float value); */

#endif