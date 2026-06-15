/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
#ifndef __SOCK_DIAG_H__
#define __SOCK_DIAG_H__

#include <linux/types.h>

#define SOCK_DIAG_BY_FAMILY 20
#define SOCK_DESTROY 21

struct sock_diag_req {
	__u8	sdiag_family;
	__u8	sdiag_protocol;
};

enum {
	SK_MEMINFO_RMEM_ALLOC,
	SK_MEMINFO_RCVBUF,
	SK_MEMINFO_WMEM_ALLOC,
	SK_MEMINFO_SNDBUF,
	SK_MEMINFO_FWD_ALLOC,
	SK_MEMINFO_WMEM_QUEUED,
	SK_MEMINFO_OPTMEM,
	SK_MEMINFO_BACKLOG,
	SK_MEMINFO_DROPS,

	SK_MEMINFO_VARS,
};

/* SOL_SOCKET-level boolean options (see socket(7)), reported per socket via
 * each family's *_DIAG_SK_OPTS attribute. Filled by sock_diag_put_sk_opts()
 * from the generic struct sock, so every family reports them the same way.
 */
struct sock_diag_sk_opts {
	__u8	reuseaddr:1,	/* SO_REUSEADDR  (sk_reuse)         */
		reuseport:1,	/* SO_REUSEPORT  (sk_reuseport)     */
		keepalive:1,	/* SO_KEEPALIVE  (SOCK_KEEPOPEN)    */
		broadcast:1,	/* SO_BROADCAST  (SOCK_BROADCAST)   */
		oobinline:1,	/* SO_OOBINLINE  (SOCK_URGINLINE)   */
		dontroute:1,	/* SO_DONTROUTE  (SOCK_LOCALROUTE)  */
		linger:1,	/* SO_LINGER     (SOCK_LINGER)      */
		timestamp:1;	/* SO_TIMESTAMP  (SOCK_RCVTSTAMP)   */
	__u8	debug:1,	/* SO_DEBUG      (SOCK_DBG)         */
		zerocopy:1,	/* SO_ZEROCOPY   (SOCK_ZEROCOPY)    */
		txtime:1,	/* SO_TXTIME     (SOCK_TXTIME)      */
		rxq_ovfl:1,	/* SO_RXQ_OVFL   (SOCK_RXQ_OVFL)    */
		select_err_queue:1, /* SO_SELECT_ERR_QUEUE (SOCK_SELECT_ERR_QUEUE) */
		nofcs:1,	/* SO_NOFCS      (SOCK_NOFCS)       */
		rcvmark:1,	/* SO_RCVMARK    (SOCK_RCVMARK)     */
		unused:1;
};

enum sknetlink_groups {
	SKNLGRP_NONE,
	SKNLGRP_INET_TCP_DESTROY,
	SKNLGRP_INET_UDP_DESTROY,
	SKNLGRP_INET6_TCP_DESTROY,
	SKNLGRP_INET6_UDP_DESTROY,
	__SKNLGRP_MAX,
};
#define SKNLGRP_MAX	(__SKNLGRP_MAX - 1)

enum {
	SK_DIAG_BPF_STORAGE_REQ_NONE,
	SK_DIAG_BPF_STORAGE_REQ_MAP_FD,
	__SK_DIAG_BPF_STORAGE_REQ_MAX,
};

#define SK_DIAG_BPF_STORAGE_REQ_MAX	(__SK_DIAG_BPF_STORAGE_REQ_MAX - 1)

enum {
	SK_DIAG_BPF_STORAGE_REP_NONE,
	SK_DIAG_BPF_STORAGE,
	__SK_DIAG_BPF_STORAGE_REP_MAX,
};

#define SK_DIAB_BPF_STORAGE_REP_MAX	(__SK_DIAG_BPF_STORAGE_REP_MAX - 1)

enum {
	SK_DIAG_BPF_STORAGE_NONE,
	SK_DIAG_BPF_STORAGE_PAD,
	SK_DIAG_BPF_STORAGE_MAP_ID,
	SK_DIAG_BPF_STORAGE_MAP_VALUE,
	__SK_DIAG_BPF_STORAGE_MAX,
};

#define SK_DIAG_BPF_STORAGE_MAX        (__SK_DIAG_BPF_STORAGE_MAX - 1)

#endif /* __SOCK_DIAG_H__ */
