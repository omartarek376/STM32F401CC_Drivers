#include "Logger.h"

static FILE *log_file = NULL;
static bool log_to_console = false;
static bool log_to_file = false;
static LogLevel display_log_level = INFO;

void set_output_destination(bool to_console, bool to_file)
{
    log_to_console = to_console;
    log_to_file = to_file;
}

void configure_log_file(const char *path)
{
    if (log_to_file)
    {
        log_file = fopen(path, "a");
        if (log_file == NULL)
        {
            fprintf(stderr, "Failed to open log file\n");
        }
    }
}

void log_message(LogLevel level, const char *format, ...)
{
    if (level < display_log_level)
        return;

    va_list args;
    va_start(args, format);

    // Get current time
    time_t rawtime;
    struct tm *timeinfo;
    char timestamp[20];
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);

    if (log_to_console) {
        // Output to console
        fprintf(stdout, "[%s] ", timestamp);
        // Print severity level
        switch (level) {
            case DEBUG:
                fprintf(stdout, "[DEBUG] ");
                break;
            case INFO:
                fprintf(stdout, "[INFO] ");
                break;
            case WARNING:
                fprintf(stdout, "[WARNING] ");
                break;
            case ERROR:
                fprintf(stdout, "[ERROR] ");
                break;
            case CRITICAL:
                fprintf(stdout, "[CRITICAL] ");
                break;
            default:
                fprintf(stdout, "[UNKNOWN] ");
        }
        vfprintf(stdout, format, args);
        fprintf(stdout, "\n");
    }

    if (log_to_file && log_file != NULL) {
        // Output to file
        fprintf(log_file, "[%s] ", timestamp);
        // Print severity level to file
        switch (level) {
            case DEBUG:
                fprintf(log_file, "[DEBUG] ");
                break;
            case INFO:
                fprintf(log_file, "[INFO] ");
                break;
            case WARNING:
                fprintf(log_file, "[WARNING] ");
                break;
            case ERROR:
                fprintf(log_file, "[ERROR] ");
                break;
            case CRITICAL:
                fprintf(log_file, "[CRITICAL] ");
                break;
            default:
                fprintf(log_file, "[UNKNOWN] ");
        }
        vfprintf(log_file, format, args);
        fprintf(log_file, "\n");
    }

    va_end(args);
}

void set_log_severity(LogLevel level)
{
    display_log_level = level;
}
