// https://gcc.gnu.org/onlinedocs/gcc/Zero-Length.html

#include <stdlib.h>

struct line {
  int length;
  char contents[0];
};

int main() {
	int this_length = 16;
	struct line *thisline = (struct line *)malloc (sizeof (struct line) + this_length);
	thisline->length = this_length;
	return 0;
}

