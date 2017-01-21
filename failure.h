#ifndef __FAILURE_H
#define __FAILURE_H

#include <stdarg.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef EXIT_FAILURE
#define EXIT_FAILURE -1
#endif

#define FAILURE_EIV static inline void
#define MAX_BUFFER 256

/* Failure handling functions, based on errno value */

/* failure with default exit code */
FAILURE_EIV perr_die(const char* err) {
    if(errno) {
        perror(err);
        exit(EXIT_FAILURE);
    }
}

FAILURE_EIV perrf_die(const char* fmt,...) {
    if(errno) {
        char target[MAX_BUFFER];
        va_list args;
        va_start(args,fmt);
        vsnprintf(target,MAX_BUFFER,fmt,args);
        va_end(args);
        perror(target);
        exit(EXIT_FAILURE);
    }
}

/* f* functions */

/**/

FAILURE_EIV err_die() {
    if(errno) {
        perror("Error");
        exit(EXIT_FAILURE);
    }
}

FAILURE_EIV err_die_no_output() {
    if(errno)
        exit(EXIT_FAILURE);
}

/* Failure with specified exit code */
FAILURE_EIV perr_die_with_code(const char* err, int code) {
    if(errno) {
        perror(err);
        exit(code);
    }
}

FAILURE_EIV perrf_die_with_code(int code, const char* fmt, ...) {
    if(errno) {
        char target[MAX_BUFFER];
        va_list args;
        va_start(args,fmt);
        vsnprintf(target,MAX_BUFFER,fmt,args);
        va_end(args);
        perror(target);
        exit(code);
    }
}

FAILURE_EIV err_die_with_code(int code) {
    if(errno) {
        perror("Error");
        exit(code);
    }
}

FAILURE_EIV err_die_no_output_with_code(int code) {
    if(errno)
        exit(code);
}

#endif
