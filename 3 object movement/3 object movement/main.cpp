#include <GLFW/glfw3.h>
#include <cmath>

float positionY = 0.0f; // Position for the up and down movement
float positionZ = 0.0f; // Position for the forward and backward movement
float angle = 0.0f;     // Angle for the rotation

void drawObject(float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glVertex3f(-0.1f, -0.1f, 0.0f);
    glVertex3f(0.1f, -0.1f, 0.0f);
    glVertex3f(0.1f, 0.1f, 0.0f);
    glVertex3f(-0.1f, 0.1f, 0.0f);
    glEnd();
    glPopMatrix();
}

void updatePositions() {
    // Update the first object's position (up and down)
    positionY = sin(glfwGetTime());

    // Update the second object's position (forward and backward)
    positionZ = sin(glfwGetTime()) * 2;

    // Update the third object's angle (rotation)
    angle += 50 * glfwGetTime(); // Rotate at a speed of 50 degrees per second
}

void render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Draw first object
    drawObject(0.0f, positionY, -5.0f);

    // Draw second object
    drawObject(2.0f, 0.0f, positionZ - 5.0f);

    // Draw third object with rotation
    glPushMatrix();
    glTranslatef(-2.0f, 0.0f, -5.0f);
    glRotatef(angle, 0.0f, 1.0f, 0.0f); // Rotate around Y-axis
    drawObject(0.0f, 0.0f, 0.0f);
    glPopMatrix();
}

int main() {
    if (!glfwInit()) return -1;

    GLFWwindow* window = glfwCreateWindow(640, 480, "OpenGL Objects", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        updatePositions();
        render();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}