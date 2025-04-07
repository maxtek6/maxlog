#include "maxlog.hpp"

using namespace maxlog;

int main(void)
{
    maxlog_init(true,true);
    MAXLOG_INFO("Log severity info");
    // TODO: Implement at least the following severities DEBUG, INFO, WARNING, ERROR, CRITICAL and FATAL.
    // See syslog.h in man pages for all available severities.
//    MAXLOG_WARNING("Log severity warning");
//    MAXLOG_ERROR("Log severity error");
    return 0;
}
