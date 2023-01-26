#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>

#include "gravity_simulator.h"

typedef GLuint Shader;

extern Shader shader_create(const char *shader_vertex_path, const char *shader_fragment_path);

extern void shader_run(Shader shader);
extern void shader_destroy(Shader shader);
extern void shader_set_bool(const Shader *shader, const char *name, uint value);
extern void shader_set_int(const Shader *shader, const char *name, int value);
extern void shader_set_float(const Shader *shader, const char *name, float value);
// extern void shader_set_vec2(const Shader *shader, const char *name, float value);

#endif