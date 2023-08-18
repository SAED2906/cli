#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

/* Global variables */
static char vn[10];
static char cwd[PATH_MAX];

/* Prototyping Functions */
static void startup(void);

/* Main */ 
int main(int ac, char **argv){
  char *prompt = "(JW) $ ";
  char *lineptr;
  size_t n = 0; 
  strcpy(vn, "1.0.0");
  startup();

  /* declaring void variables */
  (void)ac; (void)argv;

  printf("%s | %s ", getcwd(cwd, sizeof(cwd)), prompt);
  getline(&lineptr, &n, stdin);
  get_tokens(lineptr);
  
  printf("%s\n", lineptr);

  free(lineptr);
  return (0);
}

void startup(void)
{
  printf("-----------------------------------------\n");
  printf("----| Discalaimer:                  |----\n");
  printf("----| This is a\033[0;34m WIP  \033[0m               |----\n");
  printf("----|     Made by William & John    |----\n");
  printf("----| • There may be critical bugs  |----\n");
  printf("----| • It lacks many features      |----\n");
  printf("-----------------------------------------\n");
  printf("----> Version: %s\n", vn); 
  printf("-----------------------------------------\n");
}
/* TODO: 
*  we need to add a parser 
*/
void get_tokens(char line) {
    /* 
    separate lines into tokens
    replace whitespaces (strtok)
    parse commands 
    code gen 
    */
}
/* 
* TODO: refresh current prompt to the newest generation
*/
void refresh_promt(){
	printf("%s | %s ", getcwd(cwd, sizeof(cwd)), prompt);
    getline(&lineptr, &n, stdin);
    get_tokens(lineptr);
	printf("%s\n", lineptr);
}
