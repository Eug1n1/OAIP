typedef unsigned char HashIndexType;
unsigned char Rand8[256];

HashIndexType Hash(char* str) {
	unsigned char h = 0;
	while (*str) {
		h = Rand8[h ^ *str++];
	}
	return h;
}

int main()
{
	int key;
	string str;
	for (int i = 0; i < 250; i++) {
		key = rand();
		str = to_string(key);
		unsigned char chr = Hash((char*)str.c_str());
		printf("%d\n", chr);
	}
}