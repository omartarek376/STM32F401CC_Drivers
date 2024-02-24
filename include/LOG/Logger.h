#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <time.h>

typedef enum {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL
} LogLevel;

void set_output_destination(bool to_console, bool to_file);
void configure_log_file(const char *path);
void log_message(LogLevel level, const char *format, ...);
void set_log_severity(LogLevel level);

#endif // LOG_H