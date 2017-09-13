#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <math.h> 

int main( int argc , char *argv[])
{ 
	if( argc < 4 )
	{ 
		printf("Error! Incorrect format! \nFormat: ./3220InClassHomework3 -f FILENAME -r \nOR \n3220InClassHomework3 -f FILENAME -w Line1 Line2 ...\n");
		return 0; 
	}

	int k , rf , wf;
	rf = 0;
	wf = 0;
	char* Filename = malloc( sizeof(char) * strlen( argv[2]) ); 
	char print[100][100]; 
	FILE* fp;
	
	Filename = argv[2];
	
	if( strcmp( "-r" , argv[3]) == 0)
	{ 
		rf = 1;
	}
	else if( strcmp( "-w" , argv[3]) == 0)
	{ 
		wf = 1;
	}
	
	if( wf == 1)
	{
		fp = fopen( Filename , "w");
		for(k = 4; k < argc; k++)
		{
			fprintf(fp, "%s\n", argv[k]);
		}
		fclose(fp);
	}
	else if( rf == 1)
	{ 
		fp = fopen( Filename , "r"); 
		int i = 0;
		char c;
		
		do
		{ 
			fscanf(fp , "%s" , print[i] );
			i++; 
		}while( c = fgetc( fp ) != EOF );
		
		for( k = 0; k <= i; k++ )
		{
			printf("%s \n", print[k] );
		}
		fclose(fp);
	}
	
	return 0;
}
	





