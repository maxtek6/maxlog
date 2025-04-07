#ifndef MAXLOG_HPP
#define MAXLOG_HPP

#include <iostream>
#include <cstdio>
#include <ctime>
#include <syslog.h>

namespace maxlog
{
    bool syslog_enabled = false;
    bool stdout_enabled = false;

    inline void maxlog_init(bool en_stdout, bool en_syslog)
    {
        /* TODO: Keep track of state, using global variable or some other way,
           of whether we are using standard out and/or syslog.
           If using syslog, open up syslog*/
        stdout_enabled = en_stdout;
        syslog_enabled = en_syslog;
    }

    /* TODO: Implement syslog and std::cout function calls with FILE:LINE_NUMBER and FUNCTION.
             Hint: Use variadic token concatenation ##__VA_ARGS__ and __FILE__, __LINE__, __func__ for
             writing to syslog. For std::cout <<, I recommend formatting a buffer using snprintf
             and then printing the buffer.*/
    #define MAXLOG_INFO(fmt, ...) \
            do { \
                   if (syslog_enabled) \
                       syslog(LOG_INFO, "[INFO] \n"); \
                   if (stdout_enabled) \
                   { \
                       char log_buf[256]; \
                       snprintf(log_buf, sizeof(log_buf), "[INFO] \n"); \
                       std::cout << log_buf; \
                   } \
               } while (0)
}

#endif
