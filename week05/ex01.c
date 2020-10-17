//UNIX프로그래밍 5주차 4장 강의 22분 예제

#include <sys/stat.h>
#include <ftw.h>

int list(const char *name, const struct stat *status, int type)
{
	if (type == FTW_NS) // 파일 타입이 뭔지 모를 때는 0 반환 후 종료
		return 0; 
	if (type == FTW_F) // 파일 타입이 파일인 경우
		printf("% -30s\t0 % 3o\n", name, status->st_mode & 0777);
	else
		printf("% -30s *\t0 % 3o\n", name, status->st_mode & 0777); // 디렉토리인 경우 *을 찍도록 함
	return 0;
}
int main()
{
	ftw(".", list, 1);
	return 0;
}