int main(void) {
	char* av[5] = { "test2", "abc", "def", "ghi", (char*)0 };
	
	execvp("test2", av);
	exit(0);
}