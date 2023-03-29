#define _USE_MATH_DEFINES
#include <GLFW/glfw3.h>
#include<iostream>

void upperPolygon(float h, float k, float r1) {
    float angle;
    // Start to drawing the circle
    glBegin(GL_POLYGON);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    //The pointed circle is created using two circles one of radius r1 and the other of radius r1+0.04.
    //Lines are drawn every iteration,Upper half of the polygon
    //Point i of inner circle is joined with point (i+1) of the outer circle 
    for (int i = 0; i < 8; i++) {
        angle = i * 2 * (M_PI / 16);
        glVertex2f(h + (cos(angle) * r1),
            k + (sin(angle) * r1));
        angle = ((i + 1) % 16) * 2 * (M_PI / 16);
        glVertex2f(h + (cos(angle) * (r1+0.04)),
            k + (sin(angle) * (r1+0.04)));
    }
    //Point i of outer circle is joined with point (i+1) of the inner circle 
    for (int i = 0; i < 8; i++) {
        angle = i * 2 * (M_PI / 16);
        glVertex2f(h + (cos(angle) * (r1+0.04)),
            k + (sin(angle) * (r1+0.04)));
        angle = ((i + 1) % 16) * 2 * (M_PI / 16);
        glVertex2f(h + (cos(angle) * r1),
            k + (sin(angle) * r1));
    }
    //Approximately lower half of the circle is not pointed but smooth
    for (int i = 10; i < 14; i++) {
        angle = i * 2 * (M_PI / 16);
        glVertex2f(h + (cos(angle) * (r1)),
            k + (sin(angle) * (r1)));
    }
    glEnd();
}

void lowerPolygon(float h, float k, float r) {

    float angle;
    // Start to drawing the circle
    glLineWidth(1.0f);
    glBegin(GL_POLYGON);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    //Point i of inner circle is joined with point (i+1) of the outer circle 
    for (int i = 0; i < 12; i++) {

        angle = i * 2 * (M_PI / 12);
        glVertex2f(h + (cos(angle) * r),
            k + (sin(angle) * r));
        angle = ((i + 1) % 12) * 2 * (M_PI / 12);
        glVertex2f(h + (cos(angle) * (r + 0.1)),
            k + (sin(angle) * (r + 0.1)));
    }

    //Point i of outer circle is joined with point (i+1) of the inner circle 
    for (int i = 0; i < 12; i++) {

        angle = i * 2 * (M_PI / 12);
        glVertex2f(h + (cos(angle) * (r + 0.1)),
            k + (sin(angle) * (r + 0.1)));
        angle = ((i + 1) % 12) * 2 * (M_PI / 12);
        glVertex2f(h + (cos(angle) * r),
            k + (sin(angle) * r));
    }
        
    glEnd();
}



int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(800, 600, "Learn OpenGl", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);


    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

    std::cout << "Display Resolution\t" << mode->width << "x" << mode->height <<
    std::endl;

   
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        
        glClearColor(1.0,1.0,1.0,1.0);
        
        glClear(GL_COLOR_BUFFER_BIT);
        
        //This draws the outer area of the flag
        glBegin(GL_TRIANGLES);

        glColor4f(0.78431f, 0.06275f, 0.18039f, 1.0f);
        glVertex2f(1.0f, 0.0f);
        glVertex2f(0.0f, 1.0f);
        glVertex2f(0.0f, 0.0f);

        glVertex2f(0.0f, 0.5f);
        glVertex2f(1.0f, -1.0f);
        glVertex2f(0.0f, -1.0f);

        glEnd();

        //This draws the blue strips on the sides of the flag 
        glLineWidth(10.0f);
        glBegin(GL_LINES);
        glColor4f(0.0f, 0.18824f, 0.52941f, 1.0f);

        glVertex2f(1.0f, 0.0f);
        glVertex2f(0.0f, 1.0f);

        glVertex2f(0.0f, 1.0f);
        glVertex2f(0.0f, -1.0f);

        glVertex2f(0.0f, -1.0f);
        glVertex2f(1.0f, -1.0f);
        
        glVertex2f(1.0f, -1.0f);
        glVertex2f(0.325f, 0.0f);

        glVertex2f(0.325f, 0.0f);
        glVertex2f(1.0f, 0.0f);

        glEnd();

        //First two parameters are center of the inner circle and its radius
        upperPolygon(0.28f, 0.24f, 0.10f); 

        lowerPolygon(0.28f, -0.44f, 0.10f);

        //For the Crescent Moon Part of the upperPolygon
        glBegin(GL_TRIANGLES);
        glColor4f(1.0f,1.0f,1.0f,1.0f);
        float angle;

        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        
        for (int i = 8; i < 16; i++) {

            angle = i * 2 * (M_PI / 16);
            glVertex2f(0.28f + (cos(angle) * 0.2f), 0.3f + (sin(angle) * 0.15f));
            angle = ((i + 1) % 16) * 2 * (M_PI / 16);
            glVertex2f(0.28f + (cos(angle) * 0.2f), 0.3f + 0.04f + (sin(angle) * 0.12f));
            glVertex2f(0.28f + (cos(angle) * 0.2f), 0.3f + (sin(angle) * 0.15f));
        }

        for (int i = 8; i < 16; i++) {

            angle = i * 2 * (M_PI / 16);
            glVertex2f(0.28f + (cos(angle) * 0.2f), 0.3f + (sin(angle) * 0.15f));
            glVertex2f(0.28f + (cos(angle) * 0.2f), 0.3f + 0.04f + (sin(angle) * 0.12f));
            angle = ((i + 1) % 16) * 2 * (M_PI / 16);
            glVertex2f(0.28f + (cos(angle) * 0.2f), 0.3f + 0.04f + (sin(angle) * 0.12f));
        }
        
        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}