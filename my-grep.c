#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (int argc, char ** argv) {
	if(argc == 1){
		printf("my-grep: searchterm [file ...]\n");
		exit(1);
	}
	else if(argc == 2){
		char *needle = argv[1];
		char haystack[1000];
		while(fgets(haystack,1000,stdin)!=NULL){
			char *ret = strstr(haystack,needle);
			if(ret != NULL){
				printf("%s",haystack);
			}
		}
	}
	else{
		char *needle = argv[1];
		int i;
		for(i=2;i<argc;i++){
			FILE *fp = fopen(argv[i],"r");
			if(fp == NULL){
				printf("my-grep: cannot open file\n");
				exit(1);
			}
			char haystack[1000];
			while(fgets(haystack,1000,fp)!=NULL){
				char *ret = strstr(haystack,needle);
				if(ret != NULL){
					printf("%s",haystack);
				}
			}
		}
	}
	return 0;
}