#include <stdio.h>

#include "mzr64.h"

int main(void)
{
	mzr64_init(1234567890);
	for(;;) {
		uint64_t n = mzr64();
		fwrite(&n, sizeof(uint64_t), 1, stdout);
	}
}
