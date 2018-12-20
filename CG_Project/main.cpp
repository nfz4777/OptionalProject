#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
float x_position= -70.0;
float right_man = -100.0;
float right_man1 = -100.0;
float moon = 230.0;
int state = 1;
int state1 = 1;
float star1=120;
float airplane = 230;
float airplane2 = 230;
float sun = -20.0;
float bird = -220.0;
float rain=50.0;
float rain_y=70.0;
float d_back = 1;
float n_back = 1;
float r_back = 1;
float sun_light=0.0;


void init()
{
    glClearColor(.5f, .5f, .0f, .0f);
    glOrtho(-200,200,-200,200,-15,5);
}

// To draw full circle
void circle1(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy)//radius_x,radius_y,certre_position_x,centre_position_y
{

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);

    for(int i=0;i<=100;i++)

    {
        float angle = 2.0f * 3.1416f * i/100;

        float x = rx * cosf(angle);
        float y = ry * sinf(angle);

        glVertex2f((x+cx),(y+cy));
    }
    glEnd();
}

// To draw curve of mosque
void circle(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy)//radius_x,radius_y,certre_position_x,centre_position_y
{

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);

    for(int i=0;i<=50;i++)

    {
        float angle = 2.0f * 3.1416f * i/100;

        float x = rx * cosf(angle);
        float y = ry * sinf(angle);

        glVertex2f((x+cx),(y+cy));
    }
    glEnd();
}
//  Mosque Curve End

// Left side man animation
void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);

     switch(state){
     case 1 :
           if(x_position < -45)
           {
            x_position += 0.15;

            }


            break ;


     }


}

// Right man animation
void timer1(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer1,0);

     switch(state){
     case 1 :
           if(right_man1 < -45)
           {

               right_man1 += 0.15;

            }

            break ;


     }


}

//  Moon Animation
void moon_animation(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,moon_animation,0);

     switch(state){



        case 1:
             if(moon >= 150)

            moon -= 0.5;


            break ;
     }


}

// Star animation
void star_animation(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,star_animation,0);

     switch(state){



        case 1:
             if(star1 >= 5)

            star1 -= .8;


            break ;
     }


}

// Night Airplane animation
void night_airplane_animation(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,night_airplane_animation,0);

     switch(state){



        case 1:
             if(airplane2 >= -280)

            airplane2 -= 2.5;


            break ;
     }


}


// Airplane animation
void airplane_animation(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,airplane_animation,0);

     switch(state){



        case 1:
             if(airplane >= -280)

            airplane -= .8;


            break ;
     }


}

// Sun Rise animation
void sun_animation(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,sun_animation,0);

     switch(state){



        case 1:
             if(sun <= 250  )
             {
                 sun += 0.5;


             }

           break ;
     }
}

// Day mode background animation
void day_background(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,day_background,0);

     switch(state){



        case 1:
             if(d_back <= 200  )
             {
                 d_back += .50;


             }
               break ;
     }


}


// Night mode background animation
void night_background(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,night_background,0);

     switch(state){



        case 1:
             if(n_back >= -5000  )
             {
                 n_back -= 3.00;


             }
               break ;
     }


}

// Rain mode background animation
void rain_background(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,rain_background,0);

     switch(state){



        case 1:
             if(r_back >= -30000  )
             {
                 r_back -= 3.00;


             }
               break ;
     }


}


// Bird animation
void bird_animation(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,bird_animation,0);

     switch(state){



        case 1:
             if(bird <= 280  )
             {
                 bird += .8;


             }




            break ;
     }


}

// rain animation
void rain_animation(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,rain_animation,0);

     switch(state){
     case 1 :
           if(rain_y >-500)
           {

               rain_y -=1.0;

            }


            break ;


     }


}

// Sun light  animation
void sun_light_animation(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,sun_light_animation,0);

     switch(state){
     case 1 :
           if(sun_light < 600)
           {

               sun_light += .7;


            }

            break ;
     }

}


void animation_keyboard(unsigned char key,int x, int y)//In main(), To register a callback to the keyboard function,
{

	switch (key) {

		case 'd':
          //PlaySound("airplane.wav", NULL, SND_ASYNC|SND_FILENAME);
          // PlaySound("bird.wav", NULL, SND_ASYNC|SND_FILENAME);
		   // day_background(0);
		    sun_light_animation(0);
			bird_animation(0);
			sun_animation(0);
			airplane_animation(0);
			timer1(0);
			timer(0);
			break;
        case 'n':
            night_background(0);
            break;
        case 'e':
             PlaySound("airplane.wav", NULL, SND_ASYNC|SND_FILENAME);
            //night_background(0);
            star_animation(0);
            moon_animation(0);
            night_airplane_animation(0);
            timer1(0);
			timer(0);
			break;
    case 'r':
            rain_background(0);
            break;
             case 'w':
			rain_animation(0);
			timer1(0);
			timer(0);
			break;

		case 's':
			 glutIdleFunc(NULL); //idle callback is continuously called when events are not being received
			 break;

	  default:
			break;
	}
}

void myDisplay()
{
glClear(GL_COLOR_BUFFER_BIT);
// Day mode background
/*
glBegin(GL_POLYGON);
         glColor3f(1.0f, 1.0f, .5f);
         glVertex2f(-200.0,d_back-2000.0);
        glVertex2f(-200.0,d_back-60.0);
        glVertex2f(0.0,d_back-21.0);
        glVertex2f(200.0,d_back-60.0);
        glVertex2f(200.0,d_back-2000.0);
glEnd();
*/
// Day mode background end

// Sun light
glColor3f(1.0f, 1.0f, .5f);
        circle1(sun_light,sun_light, 0.0,-30.0);

// Sun light end

// Night mode background
glBegin(GL_POLYGON);
        glColor3f(.0f, .0f, .0f);
        glVertex2f(-200.0,n_back+2000.0);
        glVertex2f(-200.0,n_back+199.0);
        glVertex2f(200.0,n_back+199.0);
        glVertex2f(200.0,n_back+2000.0);
glEnd();
// Night mode background end

// Rain mode background
glBegin(GL_POLYGON);
        glColor3f(.5f, .5f, .5f);
        glVertex2f(-200.0,r_back+2000.0);
        glVertex2f(-200.0,r_back+199.0);
        glVertex2f(200.0,r_back+199.0);
        glVertex2f(200.0,r_back+2000.0);
glEnd();
// Night mode background end



// Bird
// Bird Face
glColor3f(1.0f, 1.0f, 1.0f);
    circle1(10,10,bird,160.0);
    glColor3f(.0f, .0f, .0f);
    circle1(2,2,bird+5,160.0);

    //Bird Mouth
  glBegin(GL_TRIANGLES);
       glColor3f(1.0f, .0f, .0f);
         glVertex2f(bird+10.0,160.0);
          glVertex2f(bird+20,155);
           glVertex2f(bird+3.0,150);


  glEnd();

    // Bird Body
    glColor3f(1.0f, 1.0f, 1.0f);
    circle1(20,10,bird-27,159);
    // Bird Wing
    glBegin(GL_TRIANGLES);
       glColor3f(1.0f, .0f, 0.0f);
         glVertex2f(bird-27,159);
         glVertex2f(bird-10.0,185.0);

         glVertex2f(bird-40.0,185.0);
  glEnd();

   // Bird Tail
glBegin(GL_LINES);
       glColor3f(1.0f, 1.0f, 1.0f);
         glVertex2f(bird-45,159);
         glVertex2f(bird-70.0,159.0);
glEnd();

glBegin(GL_LINES);
       glColor3f(1.0f, 1.0f, 1.0f);
         glVertex2f(bird-45,159.0);
         glVertex2f(bird-70.0,165.0);
glEnd();
glBegin(GL_LINES);
       glColor3f(1.0f, 1.0f, 1.0f);
         glVertex2f(bird-45,159.0);
         glVertex2f(bird-70.0,154.0);
glEnd();

// Rain drops

// Right Side rain drops
glBegin(GL_LINES);
       glColor3f(1.0f, 1.0f, 1.0f);
         glVertex2f(rain,rain_y+140.0);
         glVertex2f(rain+5.0,rain_y+150.0);
glEnd();

glBegin(GL_LINES);
       glColor3f(1.0f, 1.0f, 1.0f);
         glVertex2f(rain+20.0,rain_y+140.0);
         glVertex2f(rain+25.0,rain_y+150.0);
glEnd();

glBegin(GL_LINES);
       glColor3f(1.0f, 1.0f, 1.0f);
         glVertex2f(rain+40.0,rain_y+140.0);
         glVertex2f(rain+45.0,rain_y+150.0);
glEnd();

glBegin(GL_LINES);
       glColor3f(1.0f, 1.0f, 1.0f);
         glVertex2f(0.0,rain_y+140.0);
         glVertex2f(5.0,rain_y+150.0);
glEnd();
glBegin(GL_LINES);
       glColor3f(1.0f, 1.0f, 1.0f);
         glVertex2f(rain+60.0,rain_y+140.0);
         glVertex2f(rain+65.0,rain_y+150.0);
glEnd();
glBegin(GL_LINES);
       glColor3f(1.0f, 1.0f, 1.0f);
         glVertex2f(rain+80.0,rain_y+140.0);
         glVertex2f(rain+85.0,rain_y+150.0);
glEnd();
glBegin(GL_LINES);
       glColor3f(1.0f, 1.0f, 1.0f);
         glVertex2f(rain+95.0,rain_y+140.0);
         glVertex2f(rain+100.0,rain_y+150.0);
glEnd();
glBegin(GL_LINES);
       glColor3f(1.0f, 1.0f, 1.0f);
         glVertex2f(rain+110.0,rain_y+140.0);
         glVertex2f(rain+115.0,rain_y+150.0);
glEnd();


// Left Side rain drops
glBegin(GL_LINES);
       glColor3f(1.0f, 1.0f, 1.0f);
         glVertex2f(-50.0,rain_y+140.0);
         glVertex2f(-45.0,rain_y+150.0);
glEnd();

glBegin(GL_LINES);
       glColor3f(1.0f, 1.0f, 1.0f);
         glVertex2f(-70.0,rain_y+140.0);
         glVertex2f(-65.0,rain_y+150.0);
glEnd();

glBegin(GL_LINES);
       glColor3f(1.0f, 1.0f, 1.0f);
         glVertex2f(-90.0,rain_y+140.0);
         glVertex2f(-85.0,rain_y+150.0);
glEnd();
glBegin(GL_LINES);
       glColor3f(1.0f, 1.0f, 1.0f);
         glVertex2f(-110.0,rain_y+140.0);
         glVertex2f(-105.0,rain_y+150.0);
glEnd();
glBegin(GL_LINES);
       glColor3f(1.0f, 1.0f, 1.0f);
         glVertex2f(-130.0,rain_y+140.0);
         glVertex2f(-125.0,rain_y+150.0);
glEnd();


// Rain End




// Sun
glBegin(GL_POLYGON);
        glColor3f(1.0f, .5f, .0f);
         glVertex2f(-10.0,sun);
         glVertex2f(0.0,sun+25.0);
          glVertex2f(10.0,sun);
glEnd();

glBegin(GL_POLYGON);
      glColor3f(1.0f, .5f, .0f);
         glVertex2f(8.0,sun+3.0);
         glVertex2f(40.0,sun);
          glVertex2f(10.0,sun-15.0);
glEnd();

glBegin(GL_POLYGON);
        glColor3f(1.0f, .5f, .0f);
         glVertex2f(14.5,sun-12.0);
         glVertex2f(30.0,sun-30.0);
          glVertex2f(5.0,sun-25.0);
glEnd();

glBegin(GL_POLYGON);
      glColor3f(1.0f, .5f, .0f);
         glVertex2f(5.0,sun-13.0);
         glVertex2f(-1.0,sun-45.0);
          glVertex2f(-14.0,sun-13.0);
glEnd();

glBegin(GL_POLYGON);
       glVertex2f(-11.0,sun-20.0);
        glVertex2f(-35.0,sun-20.0);
         glVertex2f(-14,sun-5.0);
glEnd();

glBegin(GL_POLYGON);
       glVertex2f(-14,sun-5.0);
        glVertex2f(-30.0,sun+10.0);
        glVertex2f(-8.0,sun+4.0);
glEnd();


  // Sun circle
    glColor3f(1.0f, .5f, .0f);
    circle1(15,15,0,sun-10);
      glColor3f(1.0f, 1.0f, .5f);
    circle1(10,10,0,sun-10);

// Sun End

// Airplane

glBegin(GL_POLYGON);
   glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(airplane,130.0);
       glVertex2f(airplane-20.0,135.0);
      glVertex2f(airplane,150.0);
      glVertex2f(airplane+5.0,170.0);
      glVertex2f(airplane+10.0,150.0);
      glVertex2f(airplane+60.0,140.0);
      glVertex2f(airplane+10.0,130.0);
      glVertex2f(airplane+5.0,110.0);
glEnd();

glBegin(GL_POLYGON);
   glColor3f(1.0f, .0f, .7f);
        glVertex2f(airplane+40.0,141.0);
       glVertex2f(airplane+60.0,160.0);
      glVertex2f(airplane+60.0,140.0);

glEnd();
// Airplane End

// Night Airplane

glBegin(GL_POLYGON);
   glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(airplane2,130.0);
       glVertex2f(airplane2-20.0,135.0);
      glVertex2f(airplane2,150.0);
      glVertex2f(airplane2+5.0,170.0);
      glVertex2f(airplane2+10.0,150.0);
      glVertex2f(airplane2+60.0,140.0);
      glVertex2f(airplane2+10.0,130.0);
      glVertex2f(airplane2+5.0,110.0);
glEnd();

glBegin(GL_POLYGON);
   glColor3f(1.0f, .0f, .7f);
        glVertex2f(airplane2+40.0,141.0);
       glVertex2f(airplane2+60.0,160.0);
      glVertex2f(airplane2+60.0,140.0);

glEnd();
// Night Airplane End



// Star 1
glBegin(GL_POLYGON);
   glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(star1,star1+155.0);
       glVertex2f(star1-10.0,star1+160.0);
      glVertex2f(star1,star1+165.0);
      glVertex2f(star1+5.0,star1+175.0);
      glVertex2f(star1+10.0,star1+165.0);
      glVertex2f(star1+20.0,star1+160.0);
      glVertex2f(star1+10.0,star1+155.0);
      glVertex2f(star1+5.0,star1+145.0);
glEnd();
// Star1 end
 // Moon
   glColor3f(1.0f, 1.0f, 1.0f);
    circle1(20,20,moon,moon);
    glColor3f(.0f, .0f, .0f);
     circle1(20,20,moon+5,moon+5);
// Moon end


// Mosque Start
glBegin(GL_LINES);
       glColor3f(1.0f, .0f, 0.0f);
         glVertex2f(0.0,30.0);
         glVertex2f(0.0,70.0);
glEnd();

   glColor3f(1.0f, 1.0f, 1.0f);
    circle1(10,10,0,19);
    glColor3f(.0f, 1.0f, 1.f);
   circle1(10,10,0,36);

 glColor3f(1.0f, 1.0f, 1.0f);
    circle(70,60,0.0,-50.0);

glColor3f(.5f, .5f, 0.5f);
    circle(25,30,0.0,-50.0);

glColor3f(.0f, .0f, 0.0f);
    circle(20,25,0.0,-50.0);
// Mosque  end

// Straight  Line start
 glBegin(GL_LINES);
       glColor3f(1.0f, 1.0f, 1.0f);
         glVertex2f(-50.0,-50.0);
         glVertex2f(50.0,-50.0);
glEnd();
// Straight  Line Finish

// Men

// Left Man start
// Head
glColor3f(.6f, .6f, .6f);
    circle1(10,10,x_position,x_position);

    //Hands
 glBegin(GL_LINES);
       glColor3f(1.0f, .0f, 0.0f);
         glVertex2f(x_position-10.0,x_position-20.0);
         glVertex2f(x_position+10.0,x_position-20.0);
glEnd();

//Body
    glBegin(GL_LINES);
       glColor3f(1.0f, .0f, 0.0f);
         glVertex2f(x_position,x_position-9.0);
         glVertex2f(x_position,x_position-30.0);
glEnd();



//Leg Left
 glBegin(GL_LINES);
       glColor3f(1.0f, .0f, 0.0f);
         glVertex2f(x_position,x_position-30.0);
         glVertex2f(x_position-5.0,x_position-45.0);
glEnd();
//Leg Right
glBegin(GL_LINES);
       glColor3f(1.0f, .0f, 0.0f);
         glVertex2f(x_position,x_position-30.0);
         glVertex2f(x_position+5.0,x_position-45.0);
glEnd();
// Left Man Finish



// Right side  Man start
// Head
glColor3f(.5f, .6f, .6f);
    circle1(10,10,right_man+120,right_man1-10);

 //Body
    glBegin(GL_LINES);
       glColor3f(1.0f, .0f, 0.0f);
         glVertex2f(right_man+120.0,right_man1-20);
         glVertex2f(right_man+120.0,right_man1-50.0);
glEnd();
//Hands
 glBegin(GL_LINES);
       glColor3f(1.0f, .0f, 0.0f);
         glVertex2f(right_man+110.0,right_man1-30.0);
         glVertex2f(right_man+130.0,right_man1-30.0);
glEnd();
//Leg Left
 glBegin(GL_LINES);
       glColor3f(1.0f, .0f, 0.0f);
         glVertex2f(right_man+120,right_man1-50.0);
         glVertex2f(right_man+115.0,right_man1-70.0);
glEnd();
//Right Leg
 glBegin(GL_LINES);
       glColor3f(1.0f, .0f, 0.0f);
         glVertex2f(right_man+120,right_man1-50.0);
         glVertex2f(right_man+125.0,right_man1-70.0);
glEnd();

// Right Man Finish
    glutSwapBuffers();
}
int main()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Graphics Project");
    init();

     //glutTimerFunc(0,timer,0);
     //glutTimerFunc(0,timer1,0);
     //glutTimerFunc(1000/60,airplane_animation,0);
     //glutTimerFunc(1000/60,sun_animation,0);
     //glutTimerFunc(1000/60,bird_animation,0);

     glutKeyboardFunc(animation_keyboard);

    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
