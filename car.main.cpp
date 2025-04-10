#include<GL/glut.h>   //library used to open the window
#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

float CarX=0.0f;   //CarX is a global variable here speed till 0
void specialkeys(int key,int x,int y)    //This function is used to press the arrow keys 
{
	switch(key){
	
	case GLUT_KEY_LEFT:   // used to move the car left
	CarX-=0.1f;  //move left
	break;
	case GLUT_KEY_RIGHT:
		CarX+=0.1f;  // move right
		break;
}
glutPostRedisplay();  // used to refresh the screen so that we see the movement on screen
}
void drawCar()  //Car ko draw krny k lie
{
	glColor3f(1.0f,0.0f,0.0f);   //ye red color btaye ga
	        // R   , G, B
	        glBegin(GL_QUADS);   // Points dyna h so that 4 vertices mil kr Rectangle bnein(Quad)
	        // glBegin means start hona shape draw krny k lie
	        glVertex2f(CarX -0.2f,-0.2f);
	        glVertex2f(CarX +0.2f,-0.2f);
	        glVertex2f(CarX +0.2f,0.0f);
	        glVertex2f(CarX -0.2f,0.0f);
	        glEnd();   // ye btata h k shape draw kena complete hu gya h
	        
	        glColor3f(0.0f,0.0f,0.0f);  // For black color wheels
	        glBegin(GL_QUADS);  //1st wheel
	        glVertex2f(CarX -0.15f,-0.25f);
	        glVertex2f(CarX -0.05f,-0.25f);
	        glVertex2f(CarX -0.05f,-0.2f);
	        glVertex2f(CarX -0.15f,-0.2f);
	        glEnd();
	        
	        glBegin(GL_QUADS);  //2nd wheel
	        glVertex2f(CarX +0.15f,-0.25f);
	        glVertex2f(CarX +0.05f,-0.25f);
	        glVertex2f(CarX +0.05f,-0.2f);
	        glVertex2f(CarX +0.15f,-0.2f);
	        glEnd();
}
void display(){
	glClear(GL_COLOR_BUFFER_BIT);   //Purnani screen saaf krta h
	glLoadIdentity();  //Coordinate system ko reset krta h
	drawCar();  // Drawing screen pr show krta
	glFlush();	
}

void init() // OpenGl initialization k lie
{
	glClearColor(0.8f,0.8f,1.0f,1.0f); //y line screen k background ko skyblue kr deti
	glMatrixMode(GL_PROJECTION);  // y btaye ga k screen 2D mode mei h y 3D
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
	glutSpecialFunc(specialkeys);  //Handling keys
	glutMainLoop();  //Loop continue until user wish
	return 0;
}
