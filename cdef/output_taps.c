#include <stdio.h>
#include <stdlib.h>

#define BASEX 1800
#define BASEY 1800

#define TBASEX 2025
#define TBASEY 2070

#define SIZE 450

#define FSIZE 7*SIZE

char ctaps[7] = {'A', 'B', 'C', 'X', 'D', 'E', 'F'};

int main(int argc, char **argv)
{
  int pattern;
  if (argc!=2) {
    fprintf(stderr, "usage: %s <pattern>\n", argv[0]);
    return 1;
  }
  pattern = atoi(argv[1]);
  printf("#FIG 3.2  Produced by output_lines\n");
  printf("Landscape\n");
  printf("Center\n");
  printf("Metric\n");
  printf("A4      \n");
  printf("100.00\n");
  printf("Single\n");
  printf("-2\n");
  printf("1200 2\n");
  printf("0 32 #c5c5c5\n");
  printf("0 33 #808080\n");
  printf("0 34 #e0e0e0\n");
  /* Create white bounding box */
  printf("2 2 0 0 0 7 50 -1 -1 0.000 0 0 -1 0 0 5\n");
  printf("         %d %d %d %d %d %d %d %d %d %d\n", BASEX+FSIZE*0, BASEY+FSIZE*0,
         BASEX+FSIZE*1, BASEY+FSIZE*0,
         BASEX+FSIZE*1, BASEY+FSIZE*1,
         BASEX+FSIZE*0, BASEY+FSIZE*1,
         BASEX+FSIZE*0, BASEY+FSIZE*0);
  int i, j,k;
  for (k=0;k<7;k++)
  {
    int col;
    int dx, dy;
    dx = 2;
    dy = 2;
      switch(pattern) {
        case 0:
          dx = 2;
          dy = -2;
          break;
        case 1:
          dx = 2;
          dy = -1;
          break;
        case 2:
          dx = 2;
          dy = 0;
          break;
        case 3:
          dx = 2;
          dy = 1;
          break;
        case 4:
          dx = 2;
          dy = 2;
          break;
        case 5:
          dx = 1;
          dy = 2;
          break;
        case 6:
          dx = 0;
          dy = 2;
          break;
        case 7:
          dx = -1;
          dy = 2;
          break;
      }

    i = 3 + dy*(k-3)/2;
    j = 3 + dx*(k-3)/2;
      switch(abs(k-3)) {
        case 0:
          col = 7;
          break;
        case 1:
          col = 33;
          break;
        case 2:
          col = 32;
          break;
        default:
          col = 34;
      }

      printf("2 2 0 1 0 %d 50 -1 20 0.000 0 0 -1 0 0 5\n", col);
      printf("         %d %d %d %d %d %d %d %d %d %d\n", BASEX+SIZE*(j+0), BASEY+SIZE*(i+0),
        BASEX+SIZE*(j+1), BASEY+SIZE*(i+0),
        BASEX+SIZE*(j+1), BASEY+SIZE*(i+1),
        BASEX+SIZE*(j+0), BASEY+SIZE*(i+1),
        BASEX+SIZE*(j+0), BASEY+SIZE*(i+0)
      );
      printf("2 2 0 1 0 7 50 -1 -1 0.000 0 0 -1 0 0 5\n");
      printf("         %d %d %d %d %d %d %d %d %d %d\n", BASEX+SIZE*(j+0), BASEY+SIZE*(i+0),
        BASEX+SIZE*(j+1), BASEY+SIZE*(i+0),
        BASEX+SIZE*(j+1), BASEY+SIZE*(i+1),
        BASEX+SIZE*(j+0), BASEY+SIZE*(i+1),
        BASEX+SIZE*(j+0), BASEY+SIZE*(i+0)
      );
      printf("4 1 0 50 -1 0 12 0.0000 4 135 105 %d %d %c\\001\n", TBASEX+SIZE*j, TBASEY+SIZE*i, ctaps[k]);
  }
  printf("4 1 0 50 -1 0 18 0.0000 4 135 105 %d %d d=%d\\001\n", (int)(TBASEX+SIZE*3), (int)(TBASEY+SIZE*7.5), pattern);
  return 0;
}
