 #include <iostream>
#include<GL/glut.h>
#include <cmath>

void drawCircle(float x, float y, float radius, int segments = 100) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= segments; i++) {
        float angle = 2.0f * 3.1416f * i / segments;
        glVertex2f(x + radius * cosf(angle), y + radius * sinf(angle));
    }
    glEnd();
}

//for sun
void drawSun() {
    glColor3f(1.0f, 0.9f, 0.0f); // Yellow sun
    drawCircle(0.75f, 0.75f, 0.1f);
}

//for cloud
void drawCloud(float x, float y) {
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(x, y, 0.06f);
    drawCircle(x + 0.07f, y + 0.02f, 0.06f);
    drawCircle(x + 0.14f, y, 0.06f);
}




/* run this program using the console pauser or add your own getch, system("pause") or input loop */
float houseX =0.0f;

void specialkeys(int key, int x, int y )
{
	switch(key)
	{
		case GLUT_KEY_LEFT:
			houseX -0.1f;
			break;
			case GLUT_KEY_RIGHT:
				houseX +=0.1f;
				break;
	}
	glutPostRedisplay();
	
}
void drawhouse()
{

//glColor3f(1.0f, 0.0f, 0.0f);//triangle



glBegin(GL_QUADS);
  glColor3f(0.5f, 0.5f, 0.5f); // Greyish chimney
  glVertex2f(-0.4f, 0.1f);
  glVertex2f(-0.5f, 0.1f);
  glVertex2f(-0.5f, 0.5f);
  glVertex2f(-0.4f, 0.5f);
  glEnd();
  

glBegin(GL_TRIANGLES);
	glColor3f(0.3f,0.0f,0.0f);
	glVertex2f(-0.65f,0.06f);
	glVertex2f(0.65f,0.06f);
	glVertex2f(0.0f,0.87f);
	glEnd();

//square
glBegin(GL_QUADS);
  glColor3f(0.8f, 0.8f, 0.8f);
  glVertex2f(-0.65f, 0.06f);
  glVertex2f(0.65f, 0.06f);
  glVertex2f(0.65f, -0.85f);
  glVertex2f(-0.65f, -0.85f);
  glEnd();
  



 glBegin(GL_QUADS);
  glColor3f(0.8f, 0.6f, 0.4f); // Brownish door
  glVertex2f(  -0.15f, -0.85f);
 glVertex2f(  0.15f, -0.85f);
  glVertex2f(  0.15f, -0.2f);
  glVertex2f(  -0.15f, -0.2f);
  glEnd();
 

  //window1
  glBegin(GL_QUADS);
  glColor3f(0.7f, 0.9f, 1.0f); 
  glVertex2f(-0.5f, -0.4f);
  glVertex2f(-0.3f, -0.4f);
  glVertex2f(-0.3f, -0.2f);
  glVertex2f(-0.5f, -0.2f);
  glEnd();
 

  //window2
  glBegin(GL_QUADS);
  glColor3f(0.7f, 0.9f, 1.0f); 
  glVertex2f(0.3f, -0.4f);
  glVertex2f(0.5f, -0.4f);
  glVertex2f(0.5f, -0.2f);
  glVertex2f(0.3f, -0.2f);
  glEnd();
  
  glColor3f(1.0f, 1.0f, 1.0f); // White clouds

glColor3f(0.0f, 0.7f, 0.0f); // Green grass
glBegin(GL_QUADS);
  glVertex2f(-1.0f, -1.0f); // Bottom-left corner of the grass area
  glVertex2f(1.0f, -1.0f);  // Bottom-right corner of the grass area
  glVertex2f(1.0f, -0.85f); // Top-right corner of the grass area (same y as bottom of door)
  glVertex2f(-1.0f, -0.85f); // Top-left corner of the grass area (same y as bottom of door)
glEnd();



	
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	drawhouse();
	drawSun();
    drawCloud(-0.8f, 0.75f);
    drawCloud(-0.4f, 0.8f);
    drawCloud(0.1f, 0.75f);
    drawCloud(0.6f, 0.7f);

	glFlush();
	
}

void init()
{
	glClearColor(0.8f, 0.8f, 1.0f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}
int main(int argc, char** argv) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); // y btata h k display mode aik hi hu ga yani screen aik hi open hu geor RGB colors hun ge
	glutInitWindowSize(500,500); // window k size set kry ga
	glutInitWindowPosition(100,100);  //Starting position btata h
	glutCreateWindow("My OpenGL Window");  // y screen k name hu ga
	init();
	glutDisplayFunc(display);
	glutSpecialFunc(specialkeys);

	glutMainLoop();
	return 0;
}
