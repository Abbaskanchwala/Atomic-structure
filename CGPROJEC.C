
  #include <stdio.h>
  #include <conio.h>
  #include <graphics.h>
  #include <dos.h>
  #include <math.h>


  /* manipulates the position of electrons on the orbit */
  void electronMotion(int xrad, int yrad, int midx, int midy, int x[60], int y[60]) {
  int i, j = 0;

  /* positions of electrons in their corresponding orbits */
  for (i = 360; i > 0; i = i - 6) {
x[j] = midx - (xrad * cos((i * 3.14) / 180));
y[j++] = midy - (yrad * sin((i * 3.14) / 180));
}

return;
 }

 int main() {
 /* request auto detection */
 int gdriver = DETECT, gmode, err;
 int i = 0,c,k,l,midx, midy,e;

 int xrad[9], yrad[9], x[9][60], y[9][60];
 int pos[16],electron[9], tmp;

 /* initialize graphic mode */
 initgraph(&gdriver, &gmode, "C:/TURBOC3/BGI");
 err = graphresult();

 if (err != grOk) {
/* error occurred */
printf("Graphics Error: %s",
grapherrormsg(err));
return 0;
}
printf("\t\t\t3D ATOMIC REPRESENTATION OF ELEMENTS\n\n\n");
printf("ENTER THE ATOMIC NUMBER OF THE ELEMENT\n");
scanf("%d",&e);
/* mid positions at x and y-axis */
midx = getmaxx() / 2;
midy = getmaxy() / 2;

/* manipulating radius of all orbits */
electron[0] = 7;
/* initial position for the electron on their corresponding orbit */
for (i = 0; i < 16; i++) {
pos[i] =i*7;
}
/* orbits  */
xrad[0] = 100, yrad[0] = 60;
for (i = 1; i < 9; i++) {
xrad[i] = xrad[i - 1] + 50;
yrad[i] = yrad[i - 1] + 25;
}
/* positions of electrons on their corresponding orbits */
for (i = 0; i < 9; i++) {
electronMotion(xrad[i], yrad[i], midx, midy, x[i], y[i]);
}
while (!kbhit()) {
/* drawing 9 orbits */
setcolor(WHITE);
for (i = 0; i <3; i++) {
ellipse(midx, midy, 0, 360, xrad[i], yrad[i]);
}

/* nucleus at the mid of the atom */
setcolor(RED);
setfillstyle(SOLID_FILL, RED);
circle(midx, midy, 40);
floodfill(midx, midy, RED);
/* electrons in first orbit */
if(e>0)
{
for(k=0;k<e && k<2;k++)
{
setcolor(YELLOW);
setfillstyle(SOLID_FILL, YELLOW);
pieslice(x[0][pos[k]], y[0][pos[k]], 0, 360, electron[0]);
 }
 }
 if(e>2)
 {
 for(c=0;c<(e-2)&& c<8;c++)
 {
   setcolor(YELLOW);
setfillstyle(SOLID_FILL, YELLOW);
  pieslice(x[1][pos[c]], y[1][pos[c]], 0, 360, electron[0]);
 }
      }
 if(e>10)
 {
 for(l=0;l<(e-10) && l<18;l++)
 {
 setcolor(YELLOW);
 setfillstyle(SOLID_FILL, YELLOW);
 pieslice(x[2][pos[l]], y[2][pos[l]], 0, 360, electron[0]);
 }
 }

 for (i = 0; i < 9; i++) {
 if (pos[i] <= 0) {
 pos[i] = 59;
 }
  else
  {
 pos[i] = pos[i] - 1;
  }
  }
  /* sleep for 100 milliseconds */
  delay(100);

 /* clears graphic screen */
	cleardevice();
	}

 /* deallocate memory allocated for graphic screen */
 closegraph();
 return 0;
  }
