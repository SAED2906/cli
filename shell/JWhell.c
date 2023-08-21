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
static void refresh_prompt(char *lineptr, size_t *n);
static void get_tokens(char tokens[][100], char* lineptr, int maxTokens);

/* Main */ 
int main(int ac, char **argv){
        char *lineptr;
        size_t *n = 0; 

        prompt = "(JW) $ ";
        strcpy(vn, "1.0.1");
        startup();

        /* declaring void variables */
        (void)ac; (void)argv;
        while (1 == 1){
                /* we are parsing an ununutalized pointer pls fix (malloc or use an array) */
                refresh_prompt(lineptr, n);
                free(lineptr);
        }
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

void get_tokens(char tokens[][100], char* lineptr, int maxTokens) {
    char *token;
    char *saveptr;
    int i = 0;

    token = strtok_r(lineptr, " ", &saveptr);
    while (token != NULL && i < maxTokens) {
        strcpy(tokens[i], token);
        i++;
        token = strtok_r(NULL, " ", &saveptr);
    }
}
/* 
* TODO: refresh current prompt to the newest generation
*/
void refresh_prompt(char* lineptr, size_t *n)
{
        char tokens[10][100];
        printf("%s | %s ", getcwd(cwd, sizeof(cwd)), prompt);
    	getline(&lineptr, &n, stdin);
    	/*get_tokens(tokens, lineptr);*/
    	get_tokens(tokens, lineptr, 10);
	/* Will make function for each command or bash script */
        if (strcmp(tokens[0],"cd") == 0) {
                if (strcmp(tokens[1], "..")) {
                                chdir("..");
                }
                printf("%d\n", strlen(tokens[1]));
                printf("%s\n", tokens[1]);
        }
        printf("%s\n", tokens[0]);
        /* chdir(".."); */
}
/* 
 * get_promt_length() method gets the promt length
 * */
int get_promt_length(char *str){
        int i = 0;
        while (str[i]!='\0') {
                i++;
        }
        return i;
}
