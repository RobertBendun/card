#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct { char const *field, *value; } Entry;

#include "config.h"

#define Reset  "\x1b[0m"
#define Bold   "\x1b[1m"

#define Len(Array) (sizeof(Array) / sizeof(*Array))

unsigned longest_field = 0, longest_value = 0;

static inline void print_frame(char const *frame[3])
{
	unsigned i;

	fputs(frame[0], stdout);
	for (i = 0; i < longest_field + longest_value + 2 + 2 * padding; ++i) 
		fputs(frame[1], stdout);
	puts(frame[2]);
}

static inline void print_in_frame(char const *frame[3], char const *field, char const *value)
{
	unsigned i, flen, vlen;

	fputs(frame[0], stdout);
	for (i = 0; i < padding; ++i) fputs(frame[1], stdout);
	
	flen = strlen(field);
	for (i = 0; i < longest_field - flen; ++i) fputs(frame[1], stdout);
#if BoldField
	fputs(Bold, stdout);
#endif
	fputs(field, stdout);
#if BoldField
	fputs(Reset, stdout);
#endif
	fputs(": ", stdout);

	vlen = strlen(value);
	fputs(value, stdout);
	for (i = 0; i < longest_value - vlen + padding; ++i) fputs(frame[1], stdout);
	puts(frame[2]);
}

int main()
{
	unsigned i, field, value, title_len, sum;

	for (i = 0; i < Len(entries); ++i) {
		field = strlen(entries[i].field);
		value = strlen(entries[i].value);

		if (field > longest_field) longest_field = field;
		if (value > longest_value) longest_value = value;
	}

	puts("");
	print_frame(T);
	print_frame(M);

	title_len = strlen(title);
	sum = longest_field + longest_value + 2;

	fputs(M[0], stdout);
	for (i = 0; i < padding + sum/2 - title_len/2; ++i) fputs(M[1], stdout);
	
#if BoldTitle
	fputs(Bold, stdout);	
#endif
	fputs(title, stdout);
#if BoldTitle
	fputs(Reset, stdout);
#endif

	for (i = 0; i < padding + sum/2 - title_len/2; ++i) fputs(M[1], stdout);
	puts(M[2]);

	print_frame(M);

	for (i = 0; i < Len(entries); ++i) {
		if (entries[i].field[0] == '\0') print_frame(M);
		else print_in_frame(M, entries[i].field, entries[i].value);
	}

	print_frame(M);
	print_frame(D);
	puts("");
	return 0;
}

