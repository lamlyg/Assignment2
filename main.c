#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;

void filestat1();
void filestat2();

int main() {
	filestat1();
	filestat2();
}

void filestat1() {
	printf("text1 information\n");
	stat("text1", &stat1);
	printf("size : %d\n", (int)stat1.st_size);
	printf("blocks : %d\n", (int)stat1.st_blocks);
}

void filestat2() {
	printf("text2 information\n");
	stat("text2", &stat2);
	printf("size : %d\n", (int)stat2.st_size);
	printf("blocks : %d\n", (int)stat2.st_blocks);
}