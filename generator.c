#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char** argv){
	clock_t start= clock();//starting the clock	
		
	/*prog1generator [-u] [-n <num-integers>] [-m <min-int>] [-M <max-int>] [-s <seed>] [-o <output-file-name>]*/	

  	int c;
	//opterr = 0;
	
	//bool uFlag=false;
	int numInt=100;
	int min=1;
	int max=255;
	
	
	time_t seconds;
	seconds = time(NULL);
	int seed=(int)seconds;
	
	char* oFile="none";
	FILE* output= stdout;


	while ((c = getopt (argc, argv, "un:m:M:s:o:")) != -1){
    		switch (c){
      			case 'u':
				printf("prog1generator [-u] [-n <num-integers>] [-m <min-int>] [-M <max-int>] [-s <seed>] [-o <output-file-name>]\n");
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
			case 's':
        			seed = atoi(optarg);
        			break;
			case 'o':
        			oFile = optarg;
				output=fopen(oFile,"w");
        			break;
      			case '?':
        			if (optopt == 'n')
          				fprintf (stderr, "Option -%c requires an argument.\n", optopt);
				else if (optopt == 'm')
          				fprintf (stderr, "Option -%c requires an argument.\n", optopt);
				else if (optopt == 'M')
          				fprintf (stderr, "Option -%c requires an argument.\n", optopt);
				else if (optopt == 's')
          				fprintf (stderr, "Option -%c requires an argument.\n", optopt);
				else if (optopt == 'o')
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
  	//printf ("uFlag = %d, numInt = %d, min = %d, max = %d, seed =%d, output = %s\n", uFlag,numInt,min,max,seed,oFile); 

	srand(seed);
	for(int i=0; i<numInt;i++){
		int outNum= (rand() %(max-min+1))+min;
		//printf("%c\n",outNum);
		fprintf(output,"%c\n",outNum);
	}



	fclose(output);//close the stream

	

	clock_t end = clock();
	double runtime = (double)(end-start)/CLOCKS_PER_SEC;
	printf("Generator Runtime: %f\n",runtime);	
	return 0;
}
