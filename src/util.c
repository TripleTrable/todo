#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"


void die(const char *fmt, ...) {
	va_list ap;

	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);

	if (fmt[0] && fmt[strlen(fmt)-1] == ':') {
		fputc(' ', stderr);
		perror(NULL);
	} else {
		fputc('\n', stderr);
	}

	exit(1);
}

const char* DateToString(const Date* date)
{
	char *buffer = malloc(sizeof(char) * 10);
	sprintf(buffer,"%02d.%02d.%04d",date->day,date->month,date->year);
	return buffer;
}

Date StringToDate(const char* string)
{
	Date d;
	sscanf(string,"%02d.%02d.%04d",&(d.day),&(d.month),&(d.year));
	return d;

}
