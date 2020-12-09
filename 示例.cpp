// spmulight.cpp : 定义控制台应用程序的入口点。
//
//在示例代码中加上光源

//#include "stdafx.h"

#include <windows.h>
#include <glut.h>

void myinit(void);
void myReshape(GLsizei w, GLsizei h);
void display(void);

//  初始化材质特性、光源、光照模型和深度缓冲区
void myinit(void)
{
	GLfloat mat_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat mat_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };

	GLfloat light0_diffuse[] = { 0.0, 0.0, 1.0, 1.0 };
	GLfloat light0_position[] = { 1.0, 1.0, 1.0, 0.0 };

	//聚光灯
	GLfloat light1_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat light1_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
	GLfloat light1_specular[] = { 1.0, 0.6, 0.6, 1.0 };
	GLfloat light1_position[] = { -3.0, -3.0, 3.0, 1.0 };

	//2
	GLfloat light2_ambient[] = { 1.0, 0, 0, 1.0 };
	GLfloat light2_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
	GLfloat light2_specular[] = { 1.0, 0.0, 0.0, 1.0 };
	GLfloat light2_position[] = { -3.0, 3.0, 3.0, 1.0 };

	GLfloat spot_direction[] = { 3.0,3.0,-3.0 };
	GLfloat spot_direction_[] = { 3.0,-3.0,-3.0 };


	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, light0_position);

	//聚光灯
	glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);
	glLightfv(GL_LIGHT1, GL_POSITION, light1_position);//位置

	//2
	glLightfv(GL_LIGHT2, GL_AMBIENT, light2_ambient);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, light2_diffuse);
	glLightfv(GL_LIGHT2, GL_SPECULAR, light2_specular);
	glLightfv(GL_LIGHT2, GL_POSITION, light2_position);//位置

	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 30.0);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);

	//2
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 30.0);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spot_direction_);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	//2
	glEnable(GL_LIGHT2);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);

}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glTranslated(-3.0, -3.0, 3.0);
	glDisable(GL_LIGHTING);
	glColor3f(1.0, 0.0, 0.0);
	glutSolidSphere(0.1f, 50.0f, 50.0f);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	glutSolidSphere(2.0f, 50.0f, 50.0f);
	glFlush();
}

void myReshape(GLsizei w, GLsizei h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-5.5, 5.5, -5.5 * (GLfloat)h / (GLfloat)w,
			5.5 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
	else
		glOrtho(-5.5 * (GLfloat)w / (GLfloat)h,
			5.5 * (GLfloat)w / (GLfloat)h, -5.5, 5.5, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

//  主函数，初始化窗口大小、RGBA显示模式和处理输入事件
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("位置光源和多光源演示");
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
	return 0;
}

