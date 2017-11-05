#include <iostream>
#include "headers/siniragi.h"
#include <GL/freeglut.h>
using namespace std;



#define EN 600
#define BOY 600
static int pencere;
static int menu_id;
static int secenek = 1;



void bolgeBelirle(int x,int y);
void mouse(int a, int b, int x, int y);
void menu(int say);
void menuOlustur();
void display();
void glutInit(int argc, char *argv[]);



void keyboard(unsigned char key, int x, int y);

void initGlut(int argc, char *argv[]);

SinirAgi *multiCategory = new SinirAgi;








int main(int argc, char *argv[])
{
    srand (time(NULL));

    glutInit(&argc, argv);
    glutInitWindowSize(EN,BOY);
    glutCreateWindow("GLUT Test");
    glutMouseFunc(mouse);
    menuOlustur();
    glutDisplayFunc(display);


    multiCategory->InitNetwork();



    //tekKatmanliSinirAgi->ogrenmeBaslat();

    glutMainLoop();





    return EXIT_SUCCESS;
}







void bolgeBelirle(int x,int y){
        float pixel = 1.0/BOY;
        float fark = BOY/2;
        float degerX = (2*(x-fark)*pixel);
        float degerY = (2*(fark-y)*pixel);
        multiCategory->Sinif[secenek-1].noktaEkle(degerX,degerY,-1);

}


void mouse(int a, int b, int x, int y)
{
 if(a == 0 && b == 0){

    bolgeBelirle(x,y);

 }
}

void menu(int say){
    if(say == 0){
       glutDestroyWindow(pencere);
       exit(0);
     }else{
       secenek = say;
     }
   glutPostRedisplay();

}
void menuOlustur(){
       string  a = "Class ";
       stringstream ss;
       menu_id = glutCreateMenu(menu);
       for(int i = 1;i <= SINIFSAYISI;i++){
          ss<<a<<i;
          glutAddMenuEntry(ss.str().c_str(),i);
          ss.str("");
   }
   glutAddMenuEntry("Hesapla",SINIFSAYISI+1);
   glutAttachMenu(GLUT_RIGHT_BUTTON);
}


void display()
{
    if(secenek ==SINIFSAYISI + 1){
    multiCategory->ogrenmeBaslat();
    secenek = 1;
    }
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_LINE_SMOOTH);
      glLineWidth(2);
      glColor3f(0,0,1);

      glBegin(GL_LINES);
      glColor3f(0,0,1);
      glVertex3f(-1,0,0);
      glVertex3f(1,0,0);
      glColor3f(0,1,0);
      glVertex3f(0,0,-1);
      glVertex3f(0,0,1);
      glColor3f(1,0,0);
      glVertex3f(0,-1,0);
      glVertex3f(0,1,0);
      glEnd();

      glColor3f(0, 0, 0);
      glBegin(GL_LINE_STRIP);
      //sag üst z ekseninde çizgi
      glVertex3f(0.5, 0.5, -0.5);
      glVertex3f(0.5, 0.5, 0.5);
      //sol üst z ekseninde
      glVertex3f(0.5, -0.5, 0.5);
      glVertex3f(0.5, -0.5, -0.5);

      glVertex3f(0.5,  0.5, -0.5);
      glVertex3f(-0.5,  0.5, -0.5);

      glVertex3f(-0.5,  0.5, 0.5);
      glVertex3f(-0.5,  -0.5, 0.5);

      glVertex3f(-0.5,  -0.5, -0.5);
      glVertex3f(0.5,  -0.5, -0.5);

      glVertex3f(-0.5,  -0.5, -0.5);
      glVertex3f(-0.5,  0.5, -0.5);
      glEnd();

      glBegin(GL_LINES);
      glVertex3f(-0.5,  0.5, 0.5);
      glVertex3f(0.5,  0.5, 0.5);
      glEnd();

      glBegin(GL_LINES);
      glVertex3f(-0.5,  -0.5, 0.5);
      glVertex3f(0.5,  -0.5, 0.5);
      glEnd();




    glPointSize(10);
    glBegin(GL_POINTS);
    Noktalar noktam;
    for(int k = 0; k < SINIFSAYISI ; k++){
        for(int ak = 0 ; ak < multiCategory->Sinif[k].getOrnekSayisi();ak++){
            switch(k){
                case 0 : glColor3f(0,0,0);
                         break;
                case 1 : glColor3f(0,0,1);
                         break;
                case 2 : glColor3f(0,1,0);
                         break;
                case 3 : glColor3f(0,1,1);
                         break;
                case 4 : glColor3f(1,0,0);
                         break;
                case 5 : glColor3f(1,0,1);
                         break;
                case 6 : glColor3f(1,1,0);
                         break;
                case 7 : glColor3f(1,1,1);
                         break;

            }

             noktam =  multiCategory->Sinif[k].sinifaAitNoktaGet(ak);
            glVertex2f(noktam.getDegerler(0),noktam.getDegerler(1));
        }
      }
    glEnd();


    for(int i = 0; i < KATMANSAYISI ; i++){

        //cout<<"Katmandaki Noron Sayisi"<<katmandakiNoronSayisi<<endl;
        for(int j = 0; j < GIRISKATMANINORONSAYISI; j++){
            switch(j){
                case 0 : glColor3f(0,0,0);
                         break;
                case 1 : glColor3f(0,0,1);
                         break;
                case 2 : glColor3f(0,1,0);
                         break;
                case 3 : glColor3f(0,1,1);
                         break;
                case 4 : glColor3f(1,0,0);
                         break;
                case 5 : glColor3f(1,0,1);
                         break;
                case 6 : glColor3f(1,1,0);
                         break;
                case 7 : glColor3f(1,1,1);
                         break;
            }
            glPointSize(3);
            glBegin(GL_POINTS);
            double a = multiCategory->noron[i][j].getGirisAgirligi(0);
            double b = multiCategory->noron[i][j].getGirisAgirligi(1);
            double c = multiCategory->noron[i][j].getGirisAgirligi(2);
           // cout<<"A: "<<a<<"B :"<<b<<" C: "<<c<<endl;
            for(double x = -1; x < 1; x = x + 0.001){
              glVertex2f(x,(a*x-c)/(-b));
            }
            glEnd();

        }
    }




    glutPostRedisplay();
    glutSwapBuffers();

}


