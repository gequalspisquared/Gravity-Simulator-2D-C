#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "gravity_simulator.h"
// #include "nila/nila.h"
#include <cglm/cglm.h>
#include "shader.h"

#define WINDOW_WIDTH 1600
#define WINDOW_HEIGHT 900

#define M_PI 3.14159265358979323846 /* pi */

GLFWwindow *window_create(const uint window_width, const uint window_height, const char *window_name);

void draw_circle_2d(vec2 pos, float radius);

int main()
{
    GLFWwindow *window = window_create(WINDOW_WIDTH, WINDOW_HEIGHT, "2D Gravity Simulator");

    /* Testing vector stuff */
    // nla_vec2 v1 = {};
    // nla_vec2 v2 = {1.0f, 2.0f};
    // nla_vec2 v3 = {}; 
    // nla_vec2_add(v1, v2, v3);
    // printf("v = {%0.1f, %0.1f}\n", v3[0], v3[1]);
    vec2 v = {};

    mat4 ortho; glm_ortho(-WINDOW_WIDTH / 2.0f, WINDOW_WIDTH / 2.0f, -WINDOW_HEIGHT / 2.0f, WINDOW_HEIGHT / 2.0f, -0.1f, 100.0f, ortho);

    // mat4 view;  glm_mat4_identity(view);
    vec3 camera_pos = {0.0f, 0.0f, 1.0f};
    vec3 camera_front = {0.0f, 0.0f, -1.0f};
    vec3 camera_up = {0.0f, 1.0f, 0.0f};
    vec3 camera_center; glm_vec3_add(camera_pos, camera_front, camera_center);
    mat4 view; glm_lookat(camera_pos, camera_center, camera_up, view);

    mat4 model; glm_mat4_identity(model);

    /* Create simple shader for drawing circle */
    Shader shader_circle = shader_create("../res/shaders/circle.vs", "../res/shaders/circle.fs");

    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader_run(shader_circle);
        shader_set_mat4(shader_circle, "projection", ortho);
        shader_set_mat4(shader_circle, "view", view);
        shader_set_mat4(shader_circle, "model", model);
        // vec2 v1 = {WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f};
        draw_circle_2d(v, 100.0f);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    shader_destroy(shader_circle);
    glfwTerminate();
    return 0;
}

GLFWwindow *window_create(const uint window_width, const uint window_height, const char *window_name)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    GLFWwindow *window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "2D GS", NULL, NULL);
    if (window == NULL) {
        printf("Failed to create GLFW window\n");
        glfwTerminate();
        exit(1);
    }
    
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("Failed to initialize GLAD\n");
        glfwTerminate();
        exit(1);
    }

    return window;
}

void draw_circle_2d(vec2 pos, float radius)
{
    const uint number_of_segments = 36;
    const uint number_of_vertices = number_of_segments + 2;
    const double two_pi = 2.0 * M_PI;
    const float x = pos[0];
    const float y = pos[1];

    uint i;

    float circle_vertices_x[number_of_vertices];
    float circle_vertices_y[number_of_vertices];
    /* float circle_vertices_z[number_of_vertices]; */

    circle_vertices_x[0] = x;
    circle_vertices_y[0] = y;

    for (i = 1; i < number_of_vertices; i++) {
        circle_vertices_x[i] = x + (radius * cos(i*two_pi / number_of_segments));
        circle_vertices_y[i] = y + (radius * sin(i*two_pi / number_of_segments));
    }

    float circle_vertices[number_of_vertices*2];

    for (i = 0; i < number_of_vertices; i++) {
        circle_vertices[2*i    ] = circle_vertices_x[i];
        circle_vertices[2*i + 1] = circle_vertices_y[i];
    }

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(circle_vertices), circle_vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0); 
    glBindVertexArray(0);

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLE_FAN, 0, number_of_vertices);
}