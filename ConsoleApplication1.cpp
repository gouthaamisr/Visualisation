

#include <stdio.h>


#include<GL/glew.h>
#include<GLFW/glfw3.h>

//WINDOW DIMENSIONS
const GLint WIDTH = 800, HEIGHT = 600;
GLuint VAO, VBO, shader;

void CreateTriangle()
{
    //Render Here

    GLfloat vertices[] = {
         -1.0f,-1.0f,0.0f,
         -1.0f,-1.0f,0.0f,
          0.0f,-1.0f,0.0f,

    };

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO); // Selecting the buffer and pass the array of buffer use to draw
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
}
int main()
{ 
    //initialise GLFW
    if (!glfwInit())
    {
        printf("Glfw intilisation failed");
        glfwTerminate();
        return 1;

    }

    //Setup GLFW window properties
    // OPENGL Version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    //Core Profile = No Backward compatible
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //Allow forward compatible
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "test_window", NULL, NULL);
    if (!mainWindow)
    {
        printf("GLFW WINDOW CREATED FAILED");
        glfwTerminate();
        return 1;
    }
    //Get Buffer size Information

    int bufferWidth, bufferHeight;
    glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

    //Set context for GLEW to use
    glfwMakeContextCurrent(mainWindow);

    //Allow modern extensions features
    if (glewInit() != GLEW_OK)
    {
        printf("GLEW intialised failed");
        glfwDestroyWindow(mainWindow);
        glfwTerminate();
        return 1;

      }


    //Set Viewport Size 
    glViewport(0, 0, bufferWidth, bufferHeight);

   //Loop until window closed

        while (!glfwWindowShouldClose(mainWindow))
        {
            //Get + handle user inputs
            glfwPollEvents();

            //Clear Window
            glClearColor(1.0f,0.0f,0.0f,0.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            glfwSwapBuffers(mainWindow); //swap to what user wants to draw

        }
        
    return 0;
}
