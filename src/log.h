/**
 * Copyright (c) 2017 rxi
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the MIT license. See `log.c` for details.
 */

/**
 * MODIFICATIONS
 *
 * I made some changes to rxi's original version of this.  I made it so that
 * full file paths are not printed in log entries.
 * - Addison Schuhardt (2020)
 */

#ifndef LOG_H
#define LOG_H

#include <stdarg.h>
#include <stdio.h>

#define LOG_VERSION "0.1.0"

typedef void (*log_LockFn)(void *udata, int lock);

enum { LOG_TRACE, LOG_DEBUG, LOG_INFO, LOG_WARN, LOG_ERROR };

#define log_trace(...) log_log(LOG_TRACE, NULL, -1, __VA_ARGS__)
#define log_debug(...) log_log(LOG_DEBUG, NULL, -1, __VA_ARGS__)
#define log_info(...) log_log(LOG_INFO, NULL, -1, __VA_ARGS__)
#define log_warn(...) log_log(LOG_WARN, NULL, -1, __VA_ARGS__)
#define log_error(...) log_log(LOG_ERROR, NULL, -1, __VA_ARGS__)

void log_set_udata(void *udata);
void log_set_level(int level);
void log_set_quiet(int enable);

void log_log(int level, const char *file, int line, const char *fmt, ...);

#endif
