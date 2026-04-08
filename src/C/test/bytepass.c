/*
 * bytepass.c
 *
 * Version: 1.0
 * Date: 2026-04-07
 * Author: Matteo Zapparoli
 *
 * Binary byte stream filter.
 * Usefull for filter the half lower/higer bytes in a byte stream
 *
 * Compile: gcc -O3 bytepass.c -o bytepass
 *
 * Sintax:
 * 	 bytepass [2|4|8|16] [low|high]
 *
 *             2|4|8|16   is the length in byte of the input stream
 *             low        prints the lower half
 *             high       prints the higher half
 *
 */

#include <stdio.h>
#include <stdint.h> // uint32_t
#include <string.h> // strcmp()

void usage(void)
{
	printf("bytepass - binary byte stream filter\n");
	printf("Usage: bytepass [2|4|8|16] [low|high]\n");
	printf("       2|4|8|16   is the length in byte of the input stream\n");
	printf("       low        prints the lower half\n");
	printf("       high       prints the higher half\n");
}

int main(int argc, char *argv[])
{
	if(argc < 1 ) {
		usage();
		return 0;
	}
	
	if(argc != 3) {
		fprintf(stderr, "*** Error: invalid arguments\n");
		return 1;
	}
	
	size_t input_length;
	if(sscanf(argv[1], "%u", (unsigned int*)&input_length) != 1 || 
	        input_length != 2 && input_length != 4 && input_length != 8 && input_length != 16) {
		fprintf(stderr, "*** Error: invalid length\n");
		return 1;
	}
	
	int low = strcmp(argv[2], "low");
	
	if(low && strcmp(argv[2], "high")) {
		fprintf(stderr, "*** Error: second must be low or high\n");
		return 1;
	}
	
	size_t output_length = input_length / 2;
	uint8_t buffer[16];
	uint8_t *low_buffer = buffer + output_length;
	size_t n;
	
	while((n = fread(&buffer, input_length, 1, stdin)) > 0) {
		if(low) {
			fwrite(low_buffer, output_length, 1, stdout);
		}
		else {
			fwrite(buffer, output_length, 1, stdout);
		}
	}
	
	return 0;
}