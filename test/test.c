#include  <stdio.h>
#include  <string.h>
#include    "tinylog.h"
#define     TAG "MAIN"

int main(int argc, char *argv[])
{
	init_tinylog();
	LOG_FATAL("log fatal\n");
	LOG_ERROR("log error\n");
	LOG_WARN("log warn\n");
	LOG_INFO("log info\n");
	LOG_DEBUG("log debug\n");
	int len = get_log_lenth();
	char *tmp_buf = (char *)malloc(len);
	dumplog((void *)tmp_buf, len);
	printf("%s", tmp_buf);
	return 0;
}
