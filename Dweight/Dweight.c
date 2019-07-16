/*********************************************************
 * Author: Filip Matic
 * Title: Dweight.c 
 * Description: Computes the Dimensional weight of a
 * 12" x 10" x 8" box
 *********************************************************/
 #include <stdio.h>

 int main(void)
 {
 	// Declare variables
 	int height, length, width, volume, weight;

 	// Give values to our variables
 	height = 8;
 	length = 12;
 	width = 10;
 	volume = height * length * width;
 	weight = (volume +165)/166;

 	printf("Dimensions: %dx%dx%d\n", length, width, height); 
 	printf("Volume (Cubic Inches): %d\n", volume);
 	printf("Dimensional weight (Pounds): %d\n", weight);

 	return 0;
 }