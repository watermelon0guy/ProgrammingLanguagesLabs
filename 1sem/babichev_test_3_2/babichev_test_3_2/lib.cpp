#include "lib.h"


void RemoveChr(char* str, char c) {
	char* p, * q;
	for (p = q = str; *p != '\0'; *p++ = *q++)
		while (*q == c)
			q++;
}