#include    "../../tinylog.h"
#ifdef LOG_TIMESTAMP
#include <time.h>
#include <sys/time.h>
#endif

#ifdef LOG_TIMESTAMP
void
log_timestamp(similar_printf_t similar_printf) {
  struct timeval timestamp;
  struct tm date;
  gettimeofday(&timestamp, NULL);
  localtime_r(&timestamp.tv_sec, &date);
  similar_printf("%d-%02d-%02d %d:%02d:%02d.%"PRIu32": ", date.tm_year+1900, date.tm_mon, date.tm_mday, date.tm_hour, date.tm_min, date.tm_sec, timestamp.tv_usec);
}
#endif
