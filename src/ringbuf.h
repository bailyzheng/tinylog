#ifndef _RINGBUF_H_
#define _RINGBUF_H_

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif


typedef struct {
	size_t rbuf_size;
	void *rbuf_start;
	void *rbuf_head;
	void *rbuf_tail;
} RingBuf;

RingBuf *rbuf_new(size_t size);
void rbuf_free(RingBuf *rbuf);

size_t rbuf_size(const RingBuf *rbuf);
size_t rbuf_can_get(const RingBuf *rbuf);
size_t rbuf_can_put(const RingBuf *rbuf);

size_t rbuf_put(RingBuf *rbuf, const void *data, size_t count);
size_t rbuf_get(RingBuf *rbuf, void *data, size_t count);
void rbuf_flush(RingBuf *rbuf);

#ifdef __cplusplus
}
#endif

#endif
