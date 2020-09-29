//UNIX프로그래밍 5주차 4장 강의 28분 예제

#include <sys/stat.h>
#include <ftw.h>

int list(const char *name, const struct stat *status, int type)
{
	if (type == FTW_F)
		printf("F % -30s\n", name);
	if (type == FTW_D)
		printf("D % -30s\n", name);
	if (type == FTW_DNR)
		printf("DNR % -30s\n", name);
	if (type == FTW_SL)
		printf("SL % -30s\n", name);
	if (type == FTW_NS)
		printf("NS % -30s\n", name);
	return 0;
}
int main()
{
	ftw(".", list, 1);
	return 0;
}

// 리스트를 출력함
// READ 퍼미션이 없는 경우, DNR이 출력함


