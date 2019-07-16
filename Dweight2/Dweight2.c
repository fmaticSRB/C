/*********************************************************
 * Author: Filip Matic
 * Title: Dweight2.c 
 * Description: Computes the Dimensional weight of a
 * box based on user input.
 *********************************************************/
 #include <stdio.h>

 int main(void)
 {
 	// Declare variables
 	int height, length, width, volume, weight;

 	// Give values to our variables
 	printf("Enter height of the box: \n");
 	scanf("%d", &height);
 	printf("Enter length of the box: \n");
 	scanf("%d", &length);
 	printf("Enter width of the box: \n");
 	scanf("%d", &width);
 	volume = height * length * width;
 	weight = (volume +165)/166;

 	printf("Dimensions: %dx%dx%d\n", length, width, height); 
 	printf("Volume (Cubic Inches): %d\n", volume);
 	printf("Dimensional weight (Pounds): %d\n", weight);

 	return 0;
 }