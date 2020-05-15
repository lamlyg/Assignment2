#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm *time1, * time2;


void filestat1();
void filestat2();
void filetime1();
void filetime2();
void sizecmp();
void blockcmp();
void datecmp();
void timecmp();

int main() {
	filestat1();
	filestat2();
	filetime1();
	filetime2();
	sizecmp();
	blockcmp();
	datecmp();
	timecmp();
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

void filetime2() {
	printf("file2 time information\n");
	time2 = localtime(&stat2.st_mtime);
	printf("month : %d\n", time2->tm_mon + 1);
	printf("date : %d\n", time2->tm_mday);
	printf("hour : %d\n", time2->tm_hour);
	printf("min : %d\n", time2->tm_min);
}

void sizecmp(void)
{
	int size1, size2;
	stat("text1", &stat1);
	stat("text2", &stat2);

	size1 = (int)stat1.st_size;
	size2 = (int)stat2.st_size;
	printf("size compare\n");

	if (size1 > size2)
		printf("text1 is bigger\n");
	else if (size1 == size2)
		printf("sizes are equal\n");
	else
		printf("text2 is bigger\n");
	printf("\n");


	return;
}

void blockcmp(void)

{
	int size1, size2;
	stat("text1", &stat1);
	stat("text2", &stat2);

	size1 = (int)stat1.st_blocks;
	size2 = (int)stat2.st_blocks;
	printf("block compare\n");

	if (size1 > size2)
		printf("text1 is bigger\n");
	else if (size1 == size2)
		printf("sizes are equal\n");
	else
		printf("text2 is bigger\n");
	printf("\n");

	return;
}

void datecmp(void)

{

	stat("text1", &stat1);
	time1 = localtime(&stat1.st_mtime);
	int time1_mon = time1->tm_mon;
	int time1_day = time1->tm_mday;

	stat("text2", &stat2);
	time2 = localtime(&stat2.st_mtime);
	int time2_mon = time2->tm_mon;
	int time2_day = time2->tm_mday;


	printf("date compare\n");

	if (time1_mon < time2_mon)
		printf("text1 is early\n");
	else if (time1_mon > time2_mon)
		printf("text2 is early\n");
	else
	{
		if (time1_day < time2_day) {
			printf("text1 is early\n");
		}
		else if (time1_day > time2_day) {
			printf("text2 is early\n");
		}
		else {
			printf("same date\n");
		}
	}
	printf("\n");

	return;
}

void timecmp(void) {

	stat("text1", &stat1);
	time1 = localtime(&stat1.st_mtime);
	int time1_hour = time1->tm_hour;
	int time1_min = time1->tm_min;

	stat("text2", &stat2);
	time2 = localtime(&stat2.st_mtime);
	int time2_hour = time2->tm_hour;
	int time2_min = time2->tm_min;

	printf("time compare\n");

	if (time1_hour < time2_hour) {
		printf("text1 is early\n");
	}
	else if (time1_hour > time2_hour) {
		printf("text2 is early\n");
	}
	else {
		if (time1_min < time2_min) {
			printf("text1 is early\n");
		}
		else if (time1_min > time2_min) {
			printf("text2 is early\n");
		}
		else {
			printf("same time\n");
		}
	}
	printf("\n");
}
