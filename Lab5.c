/*
 ============================================================================
 Name        : Lab5.c
 Author      : Ian Naeger
 Version     :
 Copyright   : N/A
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

double output[2000];
int array[2000];
int len , max , mean;

void ReadFile( int num );
void ScaleIt( double scale );
void OffsetIt( double offset );
double FindMean( );
int FindMax( );
void CenterIt( double mean );
void NormalizeIt( double max );

int main(int argc , char **argv)
{
	int num = 0;
	int OfF = 0;
	int OffCheck = 1; 
	int ScF = 0;
	int SclCheck = 1;
	int StF = 0; 
	int CeF = 0;
	int NoF = 0;
	int RFF = 0; 
	int HeF = 0;
	int k , fc = 0;
	double Off , Scl , mean , max; 
	char Renamed[100]; 
	char Output[50];
	FILE *rfp;
	FILE *fp;
	char *OutputA;
	char *OutputB;
	char *OutputC;
	char ch;
	char *Filename = malloc( 50 * sizeof( char ));
	char Fail[50][50];

	for( k = 0; k <= argc; k++ )
	{
		if( strcmp( "-n" , argv[k]) == 0 )
		{
			k++;
			if( isnumber( argv[k] ) == 0 )
			{ 
				num = 0;
			}
			else
			{
				num = atoi(argv[k]);
			}	
		}
		else if( strcmp( "-o" , argv[k]) == 0 )
		{
			OfF = 1;
			k++;
			if( isnumber( argv[k] ) == 0 )
			{ 
				OffCheck = 0;
			}
			else
			{
				Off = atof(argv[k]);
			}
		}
		else if( strcmp( "-s" , argv[k]) == 0 )
		{
			ScF = 1;
			k++;
			if( isnumber( argv[k] ) == 0 )
			{ 
				SclCheck = 0;
			}
			else
			{
				Scl = atof(argv[k]);
			}
		}
		else if( strcmp( "-S" , argv[k]) == 0 )
		{
			StF = 1;
		}
		else if( strcmp( "-C" , argv[k]) ==  0 )
		{
			CeF = 1;
		}
		else if(strcmp( "-N" , argv[k]) == 0 )
		{
			NoF = 1;
		}
		else if(strcmp( "-r" , argv[k]) == 0 )
		{
			RFF = 1;
			k++;
			Renamed = argv[k]; 
		}
		else if(strcmp( "-h" , argv[k]) == 0 )
		{
			HeF = 1;
		}
		else 
		{ 
			Fail[fc] = argv[k];
			fc++;
		}
	}
	
// Gets file and mode from user
	if( num == 0 )
	{
		printf("ERROR: Must enter a file for operation! \n"); 
		printf("Help Menu: \nHow to Call the Program: ./Lab5 -n # -o # -s # -S -C -N -r <NewName> -h \n");
		printf("Options: \n -C : Centers the selected file \n -h : opens the help menu \n -n : Selects the file to input by having the user enter the file's number \n -N : Normalizes the selected file \n");
		printf(" -o : Offsets the file by the amount entered by the user \n -s : scales the file by the number entered by the user \n -S : Finds the max and mean of the file \n -r : Renames the file to what the user entered \n");
		printf("Examples: \n ./Lab5 -o 6.8 -n 4 -r CoolFile \n ./Lab5 -n 6 -N -s 4.2 \n ./Lab5 -n 10 -S -C -h \n");
		
		fclose(fp);
		return 0; 
	}
	ReadFile( num );
// gets array from file

	if( RFF == 1)
	{
		sprintf(Filename, "Raw_data_%02d.txt", num);
		fp = fopen(Filename, "r");
		sprintf( Renamed , "%s.txt", Renamed );
		rfp = fopen( Renamed , "w"); 
		while( (ch = fgetc( fp ) ) != EOF )
		{
			fputc(ch, rfp); 
		}
		fclose(rfp);
	}
	else if( ScF == 1 )
	{
		if( SclCheck == 0 )
		{
			printf("ERROR: Must enter a number for scaling! \n"); 
			printf("Help Menu: \nHow to Call the Program: ./Lab5 -n # -o # -s # -S -C -N -r <NewName> -h \n");
			printf("Options: \n -C : Centers the selected file \n -h : opens the help menu \n -n : Selects the file to input by having the user enter the file's number \n -N : Normalizes the selected file \n");
			printf(" -o : Offsets the file by the amount entered by the user \n -s : scales the file by the number entered by the user \n -S : Finds the max and mean of the file \n -r : Renames the file to what the user entered \n");
			printf("Examples: \n ./Lab5 -o 6.8 -n 4 -r CoolFile \n ./Lab5 -n 6 -N -s 4.2 \n ./Lab5 -n 10 -S -C -h \n");
		
			fclose(fp);
			return 0; 
		}
		
		ScaleIt( Scl );
	
		if( RFF == 1)
		{ 
			sprintf(Output, "%s_Scaled.txt", Renamed);
		}
		else
		{
			sprintf(Output, "Scaled_data_%02d.txt", num);
		} 
	
		fp = fopen(Output , "w");
	
		fprintf(fp , "%d %lf\n" , len , Scl);
	
		for(k = 0; k < len; k++)
		{
			fprintf( fp , "%f\n" , output[k]);
		}
// takes array, scales it, puts it in a new array and prints it to a file
	}
	else if( OfF == 1 )
	{
		if( OffCheck == 0 )
		{
			printf("ERROR: Must enter a number for offsetting! \n"); 
			printf("Help Menu: \nHow to Call the Program: ./Lab5 -n # -o # -s # -S -C -N -r <NewName> -h \n");
			printf("Options: \n -C : Centers the selected file \n -h : opens the help menu \n -n : Selects the file to input by having the user enter the file's number \n -N : Normalizes the selected file \n");
			printf(" -o : Offsets the file by the amount entered by the user \n -s : scales the file by the number entered by the user \n -S : Finds the max and mean of the file \n -r : Renames the file to what the user entered \n");
			printf("Examples: \n ./Lab5 -o 6.8 -n 4 -r CoolFile \n ./Lab5 -n 6 -N -s 4.2 \n ./Lab5 -n 10 -S -C -h \n");
		
			fclose(fp);
			return 0; 
		}

		OffsetIt( Off );

		if( RFF == 1)
		{ 
			sprintf(Output, "%s_Offset.txt", Renamed);
		}
		else
		{
			sprintf(Output, "Offset_data_%02d.txt", num);
		}
		FILE* fp = fopen(Output , "w");

		fprintf(fp , "%d %lf\n" , len , Off);

		for(k = 0; k < len; k++)
		{
			fprintf( fp , "%f\n" , Output[k]);
		}
	// takes array, offsets it, puts it in a new array and prints it to a file
	}
	else if( StF == 1 )
	{
		OutputA = malloc( 50 * sizeof(char));

		mean = FindMean(  );
		max = FindMax(  );

		if( RFF == 1)
		{ 
			sprintf(OutputA, "%s_Statistics.txt", Renamed);
		}
		else
		{
			sprintf(OutputA, "Statistics_data_%02d.txt", num);
		}

		FILE* fpA = fopen(OutputA , "w");

		fprintf(fpA, "%lf %lf\n" , mean , max);

		fclose( fpA );
	// finds the mean and max of the array and prints it to a file
	}
	else if( CeF == 1)
	{
		CenterIt(mean);

		OutputB = malloc( 50 * sizeof(char));

		if( RFF == 1)
		{ 
			sprintf(OutputB, "%s_Centered.txt", Renamed);
		}
		else
		{
			sprintf(OutputB, "Centered_data_%02d.txt", num);
		}	
		
		FILE* fpB = fopen(OutputB , "w");

		fprintf(fpB , "%d %lf\n" , len , mean);

		for(k = 0; k < len; k++)
		{
			fprintf( fpB , "%f\n" , output[k] );
		}
		fclose(fpB);
// centers the array and prints it to a file
	}
	else if( NoF == 1)
	{
		NormalizeIt(max);
		OutputC = malloc( 50 * sizeof(char) );

		if( RFF == 1)
		{ 
			sprintf(OutputC, "%s_Normalized.txt", Renamed);
		}
		else
		{
			sprintf(OutputC, "Normalized_data_%02d.txt", num);
		}
		
		FILE* fpC = fopen(OutputC , "w");

		fprintf(fpC , "%d %lf\n" , len , max);

		for(k = 0; k < len; k++)
		{
			fprintf( fpC , "%f\n" , output[k]);
		}
		fclose(fpC);
	// normalizes the array and prints it to a file
	}
	else if( HeF == 1)
	{
		printf("Help Menu: \nHow to Call the Program: ./Lab5 -n # -o # -s # -S -C -N -r <NewName> -h \n");
		printf("Options: \n -C : Centers the selected file \n -h : opens the help menu \n -n : Selects the file to input by having the user enter the file's number \n -N : Normalizes the selected file \n");
		printf(" -o : Offsets the file by the amount entered by the user \n -s : scales the file by the number entered by the user \n -S : Finds the max and mean of the file \n -r : Renames the file to what the user entered \n");
		printf("Examples: \n ./Lab5 -o 6.8 -n 4 -r CoolFile \n ./Lab5 -n 6 -N -s 4.2 \n ./Lab5 -n 10 -S -C -h \n");
		
		fclose(fp);
		return 0; 
	}
	
	if( fc < 0)
	{
		for( k = 0; k <= fc; k++ )
		{ 
			printf("Option %s is not valid\n", Fail[k] );
		}			
	}

	
	fclose(fp);
	
	return 0;
}

void ReadFile( int num )
{
	int max , k;
	char *Filename = malloc( 50 * sizeof( char ));
	
	sprintf(Filename, "Raw_data_%02d.txt", num);
	FILE *fp = fopen(Filename, "r");

	fscanf( fp , "%d %d" , &len , &max);

	for(k = 0; k < len; k++)
	{
		fscanf(fp, "%d", &array[k]);
	}

	fclose(fp);
	free( Filename );
// Takes file number, finds the file, and makes it into an array
}

void ScaleIt( double scale )
{
	int k;
	for(k = 0; k < len; k++)
	{
		output[k] = (double)array[k] * scale;
	}
// scales the array
}

void OffsetIt( double offset )
{
	int k;
		for(k = 0; k < len; k++)
		{
			output[k] = (double)array[k] + offset;
		}
// offsets the array
}

void NormalizeIt( double max )
{
	int k;
	for(k = 0; k < len; k++)
	{
		output[k] = (double)array[k] / max;
	}
// normalizes the array
}

void CenterIt( double mean )
{
	int k;
	for(k = 0; k < len; k++)
	{
		output[k] = (double)array[k] - mean;
	}
// Centers the array
}

double FindMean( )
{
	int k;
	double mean = 0;
	for(k = 0; k < len; k++)
	{
		mean = mean + (double)array[k];
	}
	mean = mean / len;
// Finds the mean of the array
	return mean;
}

int FindMax( )
{
	int k;
	double max = 0;
	for( k = 0; k < len; k++)
	{
		if( array[k] > max )
		{
			max = array[k];
		}
	}
// Finds the max of the array
	return max;
}
