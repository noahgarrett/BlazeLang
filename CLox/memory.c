#include <stdlib.h>

#include "memory.h"

void* reallocate(void* pointer, size_t oldSize, size_t newSize) {
	if (newSize == 0) {
		free(pointer);
		return NULL;
	}

	void* result = realloc(pointer, newSize);

	// Handle if there isn't enough memory to allocate
	if (result == NULL) exit(1);

	return result;
}