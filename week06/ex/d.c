int main(void) {
	char* av[5] = { "test1", "abc", "def", "ghi", (char*)0 };

	execv("./test1", av);
	exit(0);
}
