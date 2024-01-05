#include <stdio.h>

void	print_rgb(long color)
{
	printf("r: %li\ng: %li\nb: %li\n\n", (color >> 24) & 0xFF, (color >> 16) & 0xFF, (color >> 8) & 0xFF);
}

int main(void)
{
	print_rgb(-2007752705);
	print_rgb(-1045609473);
	// print_rgb(-1838667777);
	// print_rgb(1346704127);
	// print_rgb(-34253825);
	// print_rgb(-1365623809);
	// print_rgb(-1449838081);
}
