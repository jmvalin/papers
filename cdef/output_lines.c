#include <stdio.h>
#include <stdlib.h>

#define BASEX 1800
#define BASEY 1800

#define TBASEX 2025
#define TBASEY 2070

#define SIZE 450

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
  int i, j;
  for (i=0;i<8;i++)
  {
    for(j=0;j<8;j++)
    {
      int col;
      int id;
      id = i;
      switch(pattern) {
        case 0:
          id = i + j;
          break;
        case 1:
          id = i + j/2;
          break;
        case 2:
          id = i;
          break;
        case 3:
          id = i + 3 - j/2;
          break;
        case 4:
          id = i + 7 - j;
          break;
        case 5:
          id = i/2 + 7 - j;
          break;
        case 6:
          id = j;
          break;
        case 7:
          id = j + i/2;
          break;
      }
      switch(id%3) {
        case 0:
          col = 7;
          break;
        case 1:
          col = 32;
          break;
        default:
          col = 33;
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
      printf("4 1 0 50 -1 0 12 0.0000 4 135 105 %d %d %d\\001\n", TBASEX+SIZE*j, TBASEY+SIZE*i, id);
    }
  }
  printf("4 1 0 50 -1 0 18 0.0000 4 135 105 %d %d d=%d\\001\n", (int)(TBASEX+SIZE*3.5), (int)(TBASEY+SIZE*8.2), pattern);
  return 0;
}
