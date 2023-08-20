#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

/* Global variables */
static char vn[10];
static char cwd[PATH_MAX];
static char *prompt;

/* Prototyping Functions */
static void startup(void);
static void refresh_prompt(char* lineptr, size_t n, char* tokens);
/* Main */ 
int main(int ac, char **argv){
  char *lineptr;
  size_t n = 0; 
  char *tokens[3][1024];

  prompt = "(JW) $ ";
  strcpy(vn, "1.0.1");
  startup();

  /* declaring void variables */
  (void)ac; (void)argv;
  while (1 == 1){
	/* we are parsing an ununutalized pointer pls fix (malloc or use an array) */
  	refresh_prompt(lineptr, n, tokens);
  }

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
void get_tokens(char* tokens, char* lineptr) {
	/* TODO: 
	 * our tokenisation is wrong ong i think this is where we are getting the
	 * seg fault, we should store tokens using a delimeter of some sort bcus rn
	 * istn it just adding to the string? (without anyway of seperating the
	 * tokens what if a token is longer than 1 char? am i being sill?
	 * i dont want to code so i just added comments that i think we need lol*/
	
	char *token;
	int i = 0;

	token = strtok(*lineptr, 32);
	while( token != NULL ) {
      token = strtok(NULL, 32);
	  strcpy(tokens[i++], *token);
   }
}
/* 
* TODO: refresh current prompt to the newest generation
*/
void refresh_prompt(char* lineptr, size_t n, char* tokens)
{
	printf("%s | %s ", getcwd(cwd, sizeof(cwd)), prompt);
    	getline(&lineptr, &n, stdin);
    	get_tokens(tokens, lineptr);
	printf("%s", tokens[0]);
	/* chdir(".."); */
}
/* get_promt_length() method gets the promt length
 * */
int get_promt_length(char *str){
	int i = 0;
	while (str[i]!='\0') {
		i++;
	}
	return i;
}
