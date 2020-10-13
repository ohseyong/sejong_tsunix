void do_child(int fd) {
	char buf[5] = { 0 };

	read(fd, buf, 2);
	printf("pid=%ld, %s\n", getpid(), buf);
	exit(0); 
}
int main(int argc, char ** argv) {
	int num, i, fd;
	pid_t pid;
	
	fd = open(argv[1], O_RDONLY);
	num = atoi(argv[2]);

	for (i = 0; i < num; i++) {
		pid = fork();
		if (pid==0) {
			do_child(fd);
		}
	}
	for (i = 0; i < num; i++) {
		wait(0);
	}
	return 0;
}
