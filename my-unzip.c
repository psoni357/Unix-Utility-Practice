#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (int argc, char ** argv) {
	if(argc==1){
		printf("my-unzip: file1 [file2 ...]\n");
		exit(1);
	}
	else{
		int i;
		for(i=1;i<argc;i++){
			FILE *fp = fopen(argv[i],"r");
			if(fp==NULL){
				printf("Error: File not found");
				exit(1);
			}
			char line[5];
			char letter;
			while(fread(line,5,1,fp)){
				letter = line[4];
				char num[4];
				strcpy(num,line);
				unsigned int *number = (unsigned int*)num;
				int j;
				for(j=0;j<(*number);j++){
					printf("%c",letter);
				}
			}
		}
	}
    return 0;
}