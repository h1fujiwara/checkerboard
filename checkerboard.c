/*
 * File name: checkerboard.c
 *
 * version, 	Date, 		Notes
 * v0.1, 	27 Aug. 2018,  	initial crreation for image test progrtam
 *
 * Function: to generate pgm image fle (800 x 600) with checker pattern with square size 100.
 * 
 * Usage:
 * $ gcc checkerboard.c - o checkerboard 
 * $ ./checkerboard <filename>.pgm
 * (for example, ./checkerboard checker.pgm)
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define BOARD_ROW	(800)
#define BOARD_COL	(600)
#define SQUARE_SIZE	(100)

int main (int argc, char* argv[])
{
	int row;	// number of row
	int col;	// number of column

	if (2 != argc)
	{
		fprintf(stderr, "USAGE: %s <PGM_filename>\n", argv[0]);
		exit( EXIT_FAILURE );
	}

	/* open PSG file */
	FILE* image = fopen(argv[1], "wb");

	if (!image)
	{
		fprintf(stderr, "Can't open output file %s for write, due to: %s\n", argv[1], strerror(errno) );
		exit( EXIT_FAILURE );
	}

	/* write header */
	fprintf(image, "P5\n%d %d\n255\n", BOARD_ROW, BOARD_COL);

	/* write gray scale image */
	for (row = 0; row <BOARD_COL; row++)
	{
		for (col = 0; col <BOARD_ROW; col++)
		{
			if ( (row/SQUARE_SIZE)%2 == 0 )
			{
				if ( (col/SQUARE_SIZE)%2 == 0 )
				{
					fprintf(image, "%c", 255);
				}
				
				else
				{
					fprintf(image, "%c", 0);
				}
			}
			
			else
			{

				if ( (col/SQUARE_SIZE)%2 == 0 )
				{
					fprintf(image, "%c", 0);
				}
				
				else
				{
					fprintf(image, "%c", 255);
				}
			}
		}
	}

	fclose(image);

	return 0;
}
