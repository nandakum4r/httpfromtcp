#include <stddef.h>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>


int main(){
    
    FILE* f;
    char buffer[1024];
    size_t bytesRead;
    int c;


    f = fopen("README.md" , "rb");
    if(!f) return 1;

    while((c = fgetc(f)) != EOF){
	if(c == '\n'){
	    printf("%s", buffer);
	    memset(buffer,'\0',1024);
	    continue;
	}
	char temp[2] = {(char) c, '\0'} ;
	strcat(buffer, temp );
	//fwrite(buffer, 1,bytesRead, stdout);    
	//printf("\n");
    }

}
