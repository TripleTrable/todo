#ifndef UTIL_H
#define UTIL_H
#include "item.h"


#include <stdio.h>
#define MAX(A, B)               ((A) > (B) ? (A) : (B))
#define MIN(A, B)               ((A) < (B) ? (A) : (B))
#define BETWEEN(X, A, B)        ((A) <= (X) && (X) <= (B))

void die(const char *fmt, ...);
void *ecalloc(size_t nmemb, size_t size);
const char* DateToString(const Date* date);
Date StringToDate(const char* string);

#endif // !UTIL_H