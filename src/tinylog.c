#include "tinylog.h"
#include  "ringbuf.h"
#include  <string.h>
#include  <stdarg.h>
#include <stdio.h>

#define MAX_LOG_BUF_SIZE 512
#define MAX_ONE_LOG_SIZE 128

#define MAX(a,b) ( ((a)>(b)) ? (a):(b) )
#define MIN(a,b) ( ((a)>(b)) ? (b):(a) )

static RingBuf *g_log_buf = NULL;

int init_tinylog()
{
	g_log_buf = rbuf_new(MAX_LOG_BUF_SIZE);
	if(!g_log_buf){
		return -1;
	}
	return 0;
}

int printf2buf(char *fmt, ...)
{
	char tmp_buf[MAX_ONE_LOG_SIZE];
	va_list args;
	va_start(args, fmt);
	vsnprintf(tmp_buf, MAX_ONE_LOG_SIZE-1, fmt, args);
	//printf("%s",tmp_buf);
	return rbuf_put(g_log_buf, tmp_buf, strlen(tmp_buf));
}

size_t get_log_lenth()
{
	return rbuf_can_put(g_log_buf);
}

int dumplog(void *data, size_t count)
{
	int len = rbuf_can_put(g_log_buf);

	if(len <= 0){
		return -1;
	}

	len = MIN(len, count);
	rbuf_get(g_log_buf, data, len);

	return len;
}
/*---------------------------------------------------------------------------*/

#if !LOG_STATIC
uint8_t Log_timestamp = 1;
int8_t Log_level = Log_Level_DEFAULT;
uint32_t Log_services = Log_Service_DEFAULT;
#endif

/*---------------------------------------------------------------------------*/
