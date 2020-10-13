int main(void) {
	execlp("test2", "test2", "abc", "def", "ghi", (char*)0);
	exit(0);
}
