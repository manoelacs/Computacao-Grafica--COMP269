#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
//#include "flor.h"

const double PI = 3.141592654;
int direcao = 1;
int grau = 0;
int cor = 0;
const float cores[4][3] =
    {
        {0.0f,1.0f,0.0f},
        {1.0f,0.0f,0.0f},
        {0.0f,0.0f,1.0f},
        {1.0f,1.0f,0.0f}
    };



void desenha(void) {
    glClear (GL_COLOR_BUFFER_BIT);

  glPushMatrix();
    glLineWidth(5.0f);
    glBegin(GL_LINES);
        glColor3f(139, 60, 19);
        glVertex2i(0.1, 0);
        glVertex2i(0.1, -0.5);
      glEnd();
  glPopMatrix();


    glColor3f(1.0f, 1.0f, 0.0f);

if(cor%2 != 0 ){
     glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 1.0f, 0.0f); // vermelho
        glVertex2f(-0.1, 0);
        glVertex2f(0, 0.2);
        glVertex2f(-0.2, 0.2);

        glColor3f(1.0f, 1.0f, 0.0f); // vermelho
        glVertex2f(-0.1, 0);
        glVertex2f(-0.2, -0.2);
        glVertex2f(0, -0.2);

        glColor3f(0.0f, 1.0f, 0.0f); // verde
        glVertex2f(-0.1, 0);
        glVertex2f(-0.3, 0.1);
        glVertex2f(-0.3, -0.1);

         glColor3f(0.0f, 1.0f, 0.0f); // verde
        glVertex2f(-0.1, 0);
        glVertex2f(0.1, 0.1);
        glVertex2f(0.1, -0.1);
    glEnd();}
    else{
        glBegin(GL_TRIANGLES);
         glColor3f(1.0f, 1.0f, 1.0f); // vermelho
        glVertex2f(-0.1, 0);
        glVertex2f(0, 0.2);
        glVertex2f(-0.2, 0.2);

        glColor3f(1.0f, 1.0f, 1.0f); // vermelho
        glVertex2f(-0.1, 0);
        glVertex2f(-0.2, -0.2);
        glVertex2f(0, -0.2);

        glColor3f(0.0f, 1.0f, 0.0f); // verde
        glVertex2f(-0.1, 0);
        glVertex2f(-0.3, 0.1);
        glVertex2f(-0.3, -0.1);

         glColor3f(0.0f, 1.0f, 0.0f); // verde
        glVertex2f(-0.1, 0);
        glVertex2f(0.1, 0.1);
        glVertex2f(0.1, -0.1);
        glEnd();

}

}
void MouseRotate(int button, int x, int y, int state)

{
    switch(button)
    {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN) {
                    cor++;
                     glutPostRedisplay();
            }
        break;
        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_DOWN) {
                   cor++;
                     glutPostRedisplay();
            }
        break;
    }
}

void displayFnc() {

    glClear(GL_COLOR_BUFFER_BIT);

    glutMouseFunc(MouseRotate);

    desenha();

    glutSwapBuffers();

}

void desenha_Frame(int v) {
    grau += direcao; ///se o bot�o esquerdo do mouse for acionado os graus ficam negativos
    glutPostRedisplay();
    glutTimerFunc(20,desenha_Frame,0);
}

void init() {
    glClearColor(1.0f, 0.5f, 0, 1);
}
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(700, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Flor de Abril");

    init();

    glutDisplayFunc(displayFnc);
    glutTimerFunc(200, desenha_Frame, 0);

    glutMainLoop();
	return 0;
}

