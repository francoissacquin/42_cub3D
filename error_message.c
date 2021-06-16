#include "cub3D.h"

void	error_message_parsing(int index)
{
	if (index == 2)
		printf("Error\n invalid number of arguments for .cub\n");
	else if (index == 3)
		printf("Error\n invalid color combination for C or F\n");
	else if (index == 4)
		printf("Error\n rgb values for C/F superior to 255 or negative\n");
	else if (index == 5)
		printf("Error\n invalid X resolution (non-numerical character)\n");
	else if (index == 6)
		printf("Error\n invalid Y resolution (non-numerical character)\n");
	else if (index == 7)
		printf("Error\n invalid or double N, S, E or W texture path\n");
	else if (index == 8)
		printf("Error\n no valid cardinal point or sprite given\n");
	else if (index == 9)
		printf("Error\n Resolution given is invalid\n");
	else if (index == 10)
		printf("Error\nfile path given does not end with .xpm\n");
	else if (index == 11)
		printf("Error\nincorrect color code for C or F\n");
	else if (index == 12)
		printf("Error\nline containing wrong argument in .cub\n");
}

void	error_message_verify_labyrinth(int index)
{
	if (index == 1)
		printf("Error\ninvalid labyrinth, wall isolated from labyrinth\n");
	else if (index == 2)
		printf("Error\nzero or starting position on boundary of the labyrinth\n");
	else if (index == 3)
		printf("Error\ninvalid labyrinth, hole in the wall\n");
	else if (index == 4)
		printf("Error\nless than or more than one starting position\n");
	else if (index == 5)
		printf("Error\npart of the labyrinth is not reachable for the player\n");
	else if (index == 6)
		printf("Error\nmissing information in the .cub file\n");
}

void	error_message_tex(int index)
{
	if (index == 1)
		printf("Error\nwrong texture format, not an XPM file\n");
	else if (index == 2)
		printf("Error\nno static char  * decalaration found in XPM file\n");
	else if (index == 3)
		printf("Error\nerror with color keys in XPM file\n");
	else if (index == 4)
		printf("Error\ninvalid color value in texture\n");
	else if (index == 5)
		printf("Error\nkey without corresponding color in xpm file\n");
	else if (index == 6)
		printf("Error\nunable to open texture (maybe wrong texture path)\n");
	else if (index == 7)
		printf("Error\ntransition from image to texture failed\n");
	else if (index == 8)
		printf("Error\nfailed to tranform texture *img to *xpm pointer\n");
}
