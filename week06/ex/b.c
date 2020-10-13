int main(void) {
	execl("./test1", "test1", "abc", "def", "ghi", (char*)0);

	exit(0);
}
