#include <stdio.h>
#include <stdlib.h>

/* Global variables */
static char vn[10];

/* Prototyping Functions */
static void startup(void);

/* Main */ 
int main(int ac, char **argv){
  vn = "1.0.0";
  startup();
  char *prompt = "(JW) $ ";
  char *lineptr;
  size_t n = 0; 

  /* declaring void variables */
  (void)ac; (void)argv;

  printf("%s", prompt);
  getline(&lineptr, &n, stdin);
  printf("%s\n", lineptr);

  free(lineptr);
  return (0);
}

void startup(void)
{
  printf("-----------------------------------------\n");
  printf("----| Discalaimer:                  |----\n");
  printf("----| This is a WIP                 |----\n");
  printf("----|     Made by William & John    |----\n");
  printf("----| • There may be critical bugs  |----\n");
  printf("----| • It lacks many features      |----\n");
  printf("-----------------------------------------\n");
  printf("----> Version: %s\n", vn); 
  printf("-----------------------------------------\n");
}
