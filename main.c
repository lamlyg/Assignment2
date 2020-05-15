#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1;

void filestat1();


int main() {
	filestat1();
}

void filestat1() {
	printf("text1 information\n");
	stat("text1", &stat1);
	printf("size : %d\n", (int)stat1.st_size);
	printf("blocks : %d\n", (int)stat1.st_blocks);
}

