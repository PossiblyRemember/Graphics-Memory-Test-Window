#define NDEBUG
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <memory>
#include <memory.h>
#include <windows.h>
#include <thread>
#include <fstream>
#include <vector>
#include <GLFW/glfw3.h>
#include <bitset>
#include <GL/freeglut.h>
#include <string>

GLfloat red = 1.0, green = 1.0, blue = 1.0;
std::string print = "THIS IS A TEST MESSAGE";

void renderBitmapString(float x, float y, void* font, const char* string) {
    glRasterPos2f(x, y);
    for (const char* c = string; *c != '\0'; ++c) {
        glutBitmapCharacter(font, *c);
    }
}

// Function to initialize OpenGL settings
void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0); // Set the background color to black
}

// Function to display a colored box
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    // Draw a colored box
    glBegin(GL_2D); // Start rendering test message

    glColor3f(1.0,1.0,1.0);
    renderBitmapString(-0.3, 0, GLUT_BITMAP_HELVETICA_18, print.c_str());


    glEnd(); // End drawing the quad

    glFlush(); // Ensure all OpenGL commands are executed
}

int counter() {
    while (true) {
        Sleep(10);
        glutPostRedisplay(); // Reset every lil bit to check for updates
    }
}

// Function to handle window resizing
void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

void changeText() {
    Sleep(5000);
    print = "new test message";
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_SRGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Colored Box");

	init(); // Initialize OpenGL settings

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
    std::thread th01(counter);
    th01.detach();
    std::thread th02(changeText);
    th02.detach();

	glutMainLoop();
	return 0;
	//thread renderThread();
	//thread mainThread(main(window));
}
