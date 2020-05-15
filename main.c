#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm *time1;

void filestat1();
void filestat2();
void filetime1();

int main() {
	filestat1();
	filestat2();
	filetime1();
}

void filestat1() {
	printf("file1 information\n");
	stat("text1", &stat1);
	printf("size : %d\n", (int)stat1.st_size);
	printf("blocks : %d\n", (int)stat1.st_blocks);
}


void filestat2() {
	printf("file2 information\n");
	stat("text2", &stat2);
	printf("size : %d\n", (int)stat2.st_size);
	printf("blocks : %d\n", (int)stat2.st_blocks);
}

void filetime1() {
	printf("file1 time information\n");
	time1 = localtime(&stat1.st_mtime);
	printf("month : %d\n", time1->tm_mon + 1);
	printf("date : %d\n", time1->tm_mday);
	printf("hour : %d\n", time1->tm_hour);
	printf("min : %d\n", time1->tm_min);
}


