#ifndef _C_LIB_UTILS_FORMAT_H

#define _C_LIB_UTILS_FORMAT_H

#include "shared/shared.h"
#include "utils/alloc/alloc.h"

size_t getFormatLength(const string format, ...);
size_t vGetFormatLength(const string format, va_list args);
string stringFromFormat(const string format, ...);
string vStringFromFormat(const string format, va_list args);

#endif