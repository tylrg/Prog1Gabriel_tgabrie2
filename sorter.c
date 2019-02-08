#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

//upside down code compare function
int cmpfunc (const void * a, const void * b) {
   return *(char*)a - *(char*)b;
}

int main(int argc, char** argv, char* envp[]){
	clock_t start= clock();//starting the clock
	
	//gets user id and length
	char* id=envp[9];
	id += 5;
	int slen= strlen(id);
	
	//files for default behavior
	FILE* input= stdin;
	FILE* output= stdout;
	FILE* count= stdout;

  	int c;//used for reading in option characters
	
	//default option values
	int numInt=100;
	int min=1;
	int max=255;
	char* iFile="none";
	char* oFile="none";
	char* cFile="none";
	

	while ((c = getopt (argc, argv, "un:m:M:i:o:c:")) != -1){
    		switch (c){
      			case 'u':
				printf("prog1sorter [-u] [-n <num-integers>] [-m <min-int>] [-M <max-int>] [-i <input-file-name>] [-o <output-file-name>] [-c <count-file-name>]\n");
				return 1;	
        			break;
			case 'n':
        			if(atoi(optarg)>0){numInt = atoi(optarg);}
				else{
					fprintf(stderr,"Integer Count input not valid! Exiting\n");
					return 1;
				}
       				break;
			
      			case 'm':
        			if(atoi(optarg)>=1){min = atoi(optarg);}
				else{
					fprintf(stderr,"Minimum Integer Value input not valid! Exiting\n");
					return 1;
				}
        			break;
			case 'M':
				if((atoi(optarg)<=1000000) && (atoi(optarg)>min)){ max = atoi(optarg);}
				else{
					fprintf(stderr,"Maximum Integer Value input not valid! Exiting\n");
					return 1;
				}
        			break;
			case 'i':
        			iFile = optarg;
				//input=fopen(iFile,"r");
        			break;
			case 'o':
        			oFile = optarg;
				//output=fopen(oFile,"w");
        			break;
			case 'c':
        			cFile = optarg;
				//count=fopen(cFile,"w");
        			break;
      			case '?':
        			if (optopt == 'n')
          				fprintf (stderr, "Option -%c requires an argument.\n", optopt);
				else if (optopt == 'm')
          				fprintf (stderr, "Option -%c requires an argument.\n", optopt);
				else if (optopt == 'M')
          				fprintf (stderr, "Option -%c requires an argument.\n", optopt);
				else if (optopt == 'i')
          				fprintf (stderr, "Option -%c requires an argument.\n", optopt);
				else if (optopt == 'o')
          				fprintf (stderr, "Option -%c requires an argument.\n", optopt);
				else if (optopt == 'c')
          				fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        			else
          				fprintf (stderr,
                   				"Unknown option character `\\x%x'.\n",
                   			optopt);
        			return 1;
     			default:
        			abort ();
      		}
	}
	//printing the option flags
  	//printf ("uFlag = %d, numInt = %d, min = %d, max = %d, input =%s, output = %s, count = %s\n", uFlag,numInt,min,max,iFile,oFile,cFile); 



	int index=0;
	char base;
	char* letCount= malloc(numInt*2);

	if(strcmp(iFile,"none")==0){
		printf("Opened stdin\n");
	}
	else{
		input=fopen(iFile,"r");
	}

	
	
	if(input){
		while((base = getc(input)) != EOF){													
			if((char)base!='\n'){
				if(base<=max && base>=min){
					letCount[index]=base;
				}
				else{
					fprintf(stderr,"INVALID INPUT FROM FILE, EXITING\n");
					return 1;
				}
			}		
			index++;
		}
	}

	int location=0;
	char* final= malloc(numInt*2);
	for(int i=0;i<(numInt*2);i++){
		if(i%2==0){
			final[location]=letCount[i];
			location++;
		}	
	}
	fclose(input);
							
	//sorting here

	if(strcmp(oFile,"none")==0){
		printf("Writing to stdout\n");
	}
	else{
		output=fopen(oFile,"w");
	}

	qsort(final,numInt,sizeof(final[0]),cmpfunc);
	for(int i=0; i<numInt;i++){
		fprintf(output,"%c",final[i]);
		fprintf(output,"\n");
	}
	fclose(output);
	
	printf("\n");	
	
	//printing for output
		
	if(strcmp(cFile,"none")==0){
		printf("Writing to stdout\n");
	}
	else{
		count=fopen(cFile,"w");
	}
	

	for(int i=0;i<slen;i++){
		fprintf(count,"%c\t%d",id[i],id[i]);
		int letC=0;
		for(int k=0;k<numInt;k++){
			if(final[k]==id[i]){letC++;}			
		}
		fprintf(count,"\t%d",letC);
		fprintf(count,"\n");
	}
	fclose(count);

	
	

	free(final);	
	free(letCount);
	clock_t end = clock();
	double runtime = (double)(end-start)/CLOCKS_PER_SEC;
	printf("\nSorter Runtime: %f\n",runtime);
	return 0;
}
