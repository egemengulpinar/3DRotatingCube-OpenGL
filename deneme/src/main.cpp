#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <GL/glut.h>
#include <vector>

double PI = 3.14159265358979;

void init(void);  // ayarlari init ettiðimiz fonksiyon
void display(void); // tüm çizim iþlemlerinin bulunduðu fonksiyon

int i = 0;
float ver[8][3] =
{
    {-1.0,-1.0,1.0},
    {-1.0,1.0,1.0},
    {1.0,1.0,1.0},
    {1.0,-1.0,1.0},
    {-1.0,-1.0,-1.0},
    {-1.0,1.0,-1.0},
    {1.0,1.0,-1.0},
    {1.0,-1.0,-1.0},
};

GLfloat color[8][3] =
{
    {0.5,0.0,0.5},
    {0.5,0.0,0.0},
    {0.5,0.5,0.0},
    {0.0,0.5,0.0},
    {0.0,0.0,0.5},
    {0.5,0.5,0.5},
    {0.0,0.5,0.5},
};




void quad(int a, int b, int c, int d,int e) //sondaki deðer (yani"e" oluyor),küpün yüzüne  hangi rengi vermek istediðimi  seçebilmek için vermiþ olduðum bir index.
{
    glBegin(GL_QUADS);
 

   
        glColor3fv(color[e]);
        glVertex3fv(ver[a]);

        glColor3fv(color[e]);
        glVertex3fv(ver[b]);

        glColor3fv(color[e]);
        glVertex3fv(ver[c]);

        glColor3fv(color[e]);
        glVertex3fv(ver[d]);
   
    glEnd();
    
}

void colorcube()
{
   
    quad(0, 3, 2, 1,0); 
    
    quad(2, 3, 7, 6,1);   
   
    quad(0, 4, 7, 3,2);
    
    quad(1, 2, 6, 5,3);
    
    quad(4, 5, 6, 7,4);
    quad(0, 1, 5, 4,5);
}

double rotate_y = 0;
double rotate_x = 0;
void specialKeys(int key, int x, int y)
{
    if (key == GLUT_KEY_RIGHT)// OK TUÞLARI ÝLE OBJEYÝ  HAREKET ETTÝRME
        rotate_y += 5;
    else if (key == GLUT_KEY_LEFT)// OK TUÞLARI ÝLE OBJEYÝ  HAREKET ETTÝRME
        rotate_y -= 5;
    else if (key == GLUT_KEY_UP)// OK TUÞLARI ÝLE OBJEYÝ  HAREKET ETTÝRME
        rotate_x += 5;
    else if (key == GLUT_KEY_DOWN)   // OK TUÞLARI ÝLE OBJEYÝ  HAREKET ETTÝRME
        rotate_x -= 5;
    glutPostRedisplay();
}

void display()
{
   glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    /*                                            // Bu kýsým gene Init() fonksiyonunda olduðu gibi 2D projeyi buraya atýp birleþtirmeye çalýþtým.
    glColor3f(0, 0.50, 100);// R,G,B
    glPointSize(4); // nokta boyutu
    glBegin(GL_POINTS);
    float i, r = 0.1;

    for (i = -1.0; i <= 1.0; i += 0.0001) {
        glVertex2f(cos(i * PI) * 2 * r, sin(i * PI) * 2 * r);

    }

    glEnd();
    glFlush();

    glColor3ub(122, 0, 0);
    glLineWidth(1000); // çizgi kalýnlýðý
    glBegin(GL_LINES);
    glVertex2f(0.3, 0.3);
    glVertex2f(0.3, -0.3);
    glEnd();
    glFlush();

    glColor3ub(100, 100, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.7, -0.2);
    glVertex2f(-0.7, 0.2);
    glVertex2f(-0.3, 0.2);
    glVertex2f(-0.3, -0.2);
    glEnd();
    glFlush();

    */

   
    glLoadIdentity();
    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);
    gluPerspective(20, w / h, 0.1, 100);  //görüntünün oluþabilmesi için gerekli.3D objelerin perspektif ayarý
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);

    gluLookAt  //bu kýsým küp'ün ekranda yer alacak konumunu belirliyor.
    (
        7 ,7, 7,
        1, 1, 1,
        1, 0, 1
    );

   
   
  
    
    //init();
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    colorcube();

    glutSwapBuffers();
}

int main(int argc, char** argv)
{



    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(1024, 768);
    glutCreateWindow("Computer Graphics Final Projesi 17-155-014 H.Egemen Gulpinar");
   
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;



}



/*void init(void) // 2D objelerin olduðu dosyayý buraya atýp birleþtirmeye çalýþtým.Ancak 3D Küp ile 2D cisimleri üst üste biniyor,birbirinden ayýramýyorum.
{
    // arka plan rengini belirle
    glClearColor(0.95, 0.95, 0.5, 1.0);// kýrmýzý,yeþil,mavi,alpha [0-1]
    glShadeModel(GL_FLAT);
    // bakis degerlerini ilkle
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);

   


    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
}

*/