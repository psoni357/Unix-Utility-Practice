#include <stdlib.h>
#include <stdio.h>


int main (int argc, char ** argv) {
	int i = argc;
	for(i=1;i<argc;i++){
		FILE *fp = fopen(argv[i],"r");
		if(fp==NULL){
			printf("my-cat: cannot open file\n");
			exit(1);
		}
		char line[500];
		while(fgets(line,500,fp)!=NULL){
			printf("%s",line);
		}
		fclose(fp);
	}
	return 0;
}