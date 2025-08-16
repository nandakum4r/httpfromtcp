#include <stddef.h>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>


char** readLines(FILE* f){
    char** lines = (char **) malloc(sizeof(char *) * 1);
    char buffer[1024] = "\0"; 

    size_t linesRead = 0, curChar = 0;
    int c = '\0';
    
    while((c = fgetc(f)) != EOF){
	if(c == '\n' ){

	    lines[linesRead] = (char*) malloc(curChar + 1); // allocate space to the string of strings
	    strncpy(lines[linesRead] , buffer, curChar + 1); // copy the string to the allocated space

	    linesRead++; 
	    lines = (char**) realloc(lines, sizeof(char *) * (linesRead + 1)); // add some more space to add another string
	    lines[linesRead] = '\0'; // if in case next line doesn't exist
	

	    curChar = 0;
	    memset(buffer,'\0',1024);
	    continue;
	}
	buffer[curChar++] = (char) c;
	buffer[curChar] = '\0';
    }
    
    if (curChar > 0) {
        buffer[curChar] = '\0';
        lines[linesRead] = malloc(curChar + 1);
        strncpy(lines[linesRead], buffer, curChar + 1);
        linesRead++;
    }

    lines = (char**) realloc(lines, sizeof(char *) * (linesRead+1)); // add some more space to add another string
    lines[linesRead] = '\0'; // if in case next line doesn't exist

    memset(buffer, '\0', 1024);

    return lines;

}


int main(){
    
    FILE* f;
   
    f = fopen("README.md" , "rb");
    if(!f) return 1;

    char **lines =  readLines(f);

    for(size_t i = 0 ; lines[i] != NULL ; ++i){
    	   printf("%s\n" , lines[i]);	
    }


   
    fclose(f); 

}
