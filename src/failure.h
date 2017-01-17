#ifndef __FAILURE_H
#define __FAILURE_H

/* Failure handling functions, based on errno value */

#ifdef __cplusplus
extern "C" {
#endif

/* failure with default exit code */
void perr_die(const char* err);
void perrfln_die(const char* fmt,...);
void err_die();
void err_die_println(const char* err);
void err_die_printfln(const char* fmt,...);
void err_die_no_strerror();
void err_die_no_strerror_println(const char* err);
void err_die_no_strerror_printfln(const char* fmt,...);

/* Failure with specified exit code */
void perr_die_with_code(const char* err, int code);
void perrfln_die_with_code(int code, const char* fmt, ...);
void err_die_with_code(int code);
void err_die_println_with_code(const char* err, int code);
void err_die_printfln_with_code(int code, const char* fmt,...);
void err_die_no_strerror_with_code(int code);
void err_die_no_strerror_println_with_code(const char* err , int code);
void err_die_no_strerror_printfln_with_code(int code, const char* fmt,...);

#ifdef __cplusplus
}
#endif

#endif