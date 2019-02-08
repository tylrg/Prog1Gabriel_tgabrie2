#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>       
#include <unistd.h>


int main(int argc, char** argv){
	
	/*prog1sorter [-u] [-n <num-integers>] [-m <min-int>] [-M <max-int>] [-i <input-file-name>] [-o <output-file-name>] [-c <count-file-name>]*/

	/*prog1generator [-u] [-n <num-integers>] [-m <min-int>] [-M <max-int>] [-s <seed>] [-o <output-file-name>]*/	

	//int index;
  	int c;
	opterr = 0;
	
	bool uFlag=false;
	int numInt=100;
	int min=1;
	int max=255;
	
	char* iFile="none";
	char* oFile="none";
	char* cFile="none";
	//FILE* output= stdout;

	//fprintf(stderr,"YOOOOOOOOOO");

	while ((c = getopt (argc, argv, "un:m:M:i:o:c:")) != -1){
    		switch (c){
      			case 'u':
        			uFlag=true;
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
        			break;
			case 'o':
        			oFile = optarg;
        			break;
			case 'c':
        			cFile = optarg;
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
  	printf ("uFlag = %d, numInt = %d, min = %d, max = %d, input =%s, output = %s, count = %s\n", uFlag,numInt,min,max,iFile,oFile,cFile); 

	return 0;
}
