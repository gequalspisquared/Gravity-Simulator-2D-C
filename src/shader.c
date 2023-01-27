#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "shader.h"

/* Shamelessly stolen from jdah: https://github.com/jdah/minecraft-weekend/blob/master/src/gfx/shader.c */
static void _shader_log_and_fail(
    GLint handle, const char *adverb, const char *path,
    void (*getlog)(GLuint, GLsizei, GLsizei *, GLchar*),
    void (*getiv)(GLuint, GLenum, GLint *)) {
    GLint loglen;
    getiv(handle, GL_INFO_LOG_LENGTH, &loglen);

    char *logtext = calloc(1, loglen);
    getlog(handle, loglen, NULL, logtext);
    fprintf(stderr, "Error %s shader at %s:\n%s", adverb, path, logtext);

    free(logtext);
    exit(1);
}

/* Shamelessly stolen from jdah: https://github.com/jdah/minecraft-weekend/blob/master/src/gfx/shader.c */
static Shader _shader_compile(const char *shader_path, GLenum shader_type)
{
    FILE *f;
    char *text;
    long len;

    f = fopen(shader_path, "rb");
    if (f == NULL) {
        fprintf(stderr, "error loading shader at %s\n", shader_path);
        exit(1);
    }

    fseek(f, 0, SEEK_END);
    len = ftell(f);
    assert(len > 0);
    fseek(f, 0, SEEK_SET);
    text = calloc(1, len);
    assert(text != NULL);
    fread(text, 1, len, f);
    assert(strlen(text) > 0);
    fclose(f);

    GLuint handle = glCreateShader(shader_type);
    glShaderSource(handle,1, (const GLchar *const *) &text, (const GLint *) &len);
    glCompileShader(handle);

    GLint compiled;
    glGetShaderiv(handle, GL_COMPILE_STATUS, &compiled);

    /* Check OpenGL logs if compilation failed */
    if (compiled == 0) {
        _shader_log_and_fail(handle, "compiling", shader_path, glGetShaderInfoLog, glGetShaderiv);
    }

    free(text);
    return handle;
}

Shader shader_create(const char *shader_vertex_path, const char *shader_fragment_path)
{
    Shader shader = glCreateProgram();
    Shader vertex = _shader_compile(shader_vertex_path, GL_VERTEX_SHADER);
    Shader fragment = _shader_compile(shader_fragment_path, GL_FRAGMENT_SHADER);

    glAttachShader(shader, vertex);
    glAttachShader(shader, fragment);

    glLinkProgram(shader);

    GLint successfully_linked;
    glGetProgramiv(shader, GL_LINK_STATUS, &successfully_linked);
    if (!successfully_linked) {
        char buf[512];
        snprintf(buf, 512, "[%s, %s]", shader_vertex_path, shader_fragment_path);
        _shader_log_and_fail(shader, "linking", buf, glGetProgramInfoLog, glGetProgramiv);
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
    return shader;
}

void shader_destroy(Shader shader) 
{
    glDeleteProgram(shader);
}

void shader_run(const Shader shader)
{
    glUseProgram(shader);
}

void shader_set_bool(const Shader shader, const char *name, uint value)
{
    glUniform1i(glGetUniformLocation(shader, name), (int) value);
}

void shader_set_int(const Shader shader, const char *name, int value)
{
    glUniform1i(glGetUniformLocation(shader, name), value);
}

void shader_set_float(const Shader shader, const char *name, float value)
{
    glUniform1f(glGetUniformLocation(shader, name), value);
}

void shader_set_vec2_directly(const Shader shader, const char *name, const vec2 value)
{
    glUniform2fv(glGetUniformLocation(shader, name), 1, value);
}

void shader_set_vec2(const Shader shader, const char *name, float x, float y)
{
    glUniform2f(glGetUniformLocation(shader, name), x, y);
}

void shader_set_vec3_directly(const Shader shader, const char *name, const vec3 value)
{
    glUniform3fv(glGetUniformLocation(shader, name), 1, value);
}

void shader_set_vec3(const Shader shader, const char *name, float x, float y, float z)
{
    glUniform3f(glGetUniformLocation(shader, name), x, y, z);
}

void shader_set_vec4_directly(const Shader shader, const char *name, const vec4 value)
{
    glUniform4fv(glGetUniformLocation(shader, name), 1, value);
}

void shader_set_vec4(const Shader shader, const char *name, float x, float y, float z, float w)
{
    glUniform4f(glGetUniformLocation(shader, name), x, y, z, w);
}

void shader_set_mat2(const Shader shader, const char *name, const mat2 value)
{
    glUniformMatrix2fv(glGetUniformLocation(shader, name), 1, GL_FALSE, value[0]);
}

void shader_set_mat3(const Shader shader, const char *name, const mat3 value)
{
    glUniformMatrix3fv(glGetUniformLocation(shader, name), 1, GL_FALSE, value[0]);
}

void shader_set_mat4(const Shader shader, const char *name, const mat4 value)
{
    glUniformMatrix4fv(glGetUniformLocation(shader, name), 1, GL_FALSE, value[0]);
}