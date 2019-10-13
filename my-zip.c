#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (int argc, char ** argv) {
	if(argc==1){
		printf("my-zip: file1 [file2 ...]\n");
		exit(1);
	}
	else{
		int i;
		int state = 0;
		char letter;
		char target;
		int count = 0;
		int filesLeft = (argc-1);
		for(i=1;i<argc;i++){
			FILE *fp = fopen(argv[i],"r");
			if(fp==NULL){
				printf("File Error");
				exit(1);
			}
			while((letter=getc(fp))!=EOF){
				if(state==0){
					target = letter;
					state = 1;
				}
				if(target==letter){
					count++;
				}
				else{
					fwrite(&count,sizeof(int),1,stdout);
					fwrite(&target,sizeof(char),1,stdout);
					target = letter;
					count = 1;
				}
			}
			filesLeft--;
			if(filesLeft==0){
				fwrite(&count,sizeof(int),1,stdout);
				fwrite(&target,sizeof(char),1,stdout);
				state = 0;
				count = 0;
			}
		}
	}
	return 0;
}