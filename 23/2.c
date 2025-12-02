#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LENGTH 256

int main() {
	FILE *filePointer = fopen("input/2.txt", "r");
	char buffer[MAX_LENGTH];
	int powerSum = 0;

	for (int gameIndex = 0; fgets(buffer, MAX_LENGTH, filePointer); gameIndex++) {
		int maxRed = 0, maxGreen = 0, maxBlue = 0;
		char* ptr = strtok(buffer, " ");
		ptr = strtok(NULL, " ");
		ptr = strtok(NULL, " ");
		char token[512];
		while (ptr) {
			int number = atoi(ptr);
			ptr = strtok(NULL, " ");
			strcpy(token, ptr);
			ptr = strtok(NULL, " ");
			if (strstr(token, "red") && number > maxRed) {
				maxRed = number;
				continue;
			}
			if (strstr(token, "green") && number > maxGreen) {
				maxGreen = number;
				continue;
			}
			if (strstr(token, "blue") && number > maxBlue) {
				maxBlue = number;
				continue;
			}
		}
		powerSum = powerSum + (maxRed * maxGreen * maxBlue);
	}

	fclose(filePointer);
	printf("%d", powerSum);

	return 0;
}

// Ariel, listen to me
// OO languages?
// It's a mess
// Programming in C
// is better than anything they got over there.

// The syntax might seem much sweeter
// Where objects and subtypes play
// But frills like inheritance
// Will only get in the way
// Admire C's simple landscape
// Efficiently dangerous
// No templates or fancy pitfalls
// ...like Java and C++!

// Program in C
// Program in C
// Pointers, assembly,
// Manage your memory
// With malloc() and free()!
// Don't sink your app with runtime bloat
// Software in C will stay afloat
// Do what you want there
// Close to the hardware!
// Program in C

// memset()
// (cast)
// register
// void*
// #define
// strcpy()
// asm
// SEGFAULT