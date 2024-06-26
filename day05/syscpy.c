#include <stdio.h>
#include <fcntl.h>
#define BUF_SIZE 3	// 배열의 길이를 최소한으로 구성

int main(int argc, char *argv[])
{
	int fd1, fd2;	// fd1, fd2에 저장되는 것은 파일 디스크립터
	int len;
	char buf[BUF_SIZE];
	// 300 Mbyte 이상의 파일로 실행해보기 -> news.txt 변경
	fd1 = open("news.txt", O_RDONLY);
	fd2 = open("cpy.txt", O_WRONLY | O_CREAT | O_TRUNC);

	while((len = read(fd1, buf, sizeof(buf))) > 0)
		write(fd2, buf, len);

	close(fd1);
	close(fd2);
	return 0;
}
