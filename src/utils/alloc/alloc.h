#ifndef _C_LIB_UTILS_ALLOC_H

#define _C_LIB_UTILS_ALLOC_H

#include "shared/shared.h"
#include "utils/logger/logger.h"

void *xmalloc(size_t nbBlocks, size_t blockSize);
void *xcalloc(size_t nbBlocks, size_t blockSize);
void *xrealloc(void *ptr, size_t nbBlocks, size_t blockSize);

#endif