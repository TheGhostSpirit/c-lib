#include "logger.h"

static void info(const string message);
static void error(const string message);
static void sysError(const string message);

Logger logger;

void initLogger()
{
    logger.output = stdout;
    logger.errOutput = stderr;
    logger.level = LOGGER_DEFAULT_LEVEL;
    logger.info = &info;
    logger.error = &error;
    logger.sysError = &sysError;
}

void setLogger(FILE *output, FILE *errOutput, LoggingLevel loggingLevel)
{
    logger.errOutput = errOutput;
    logger.output = output;
    logger.level = loggingLevel;
}

void info(const string message)
{
    if (logger.level == LOGGER_ALL)
    {
        fprintf(logger.output, "[INFO] %s\n", message);
    }
}

void error(const string message)
{
    fprintf(logger.errOutput, "[ERROR] %s\n", message);
}

void sysError(const string message)
{
    fprintf(stderr, "[ERROR] ");
    perror(message);
}