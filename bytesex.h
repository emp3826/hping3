#ifndef ARS_BYTESEX_H
#define ARS_BYTESEX_H

#if 	defined(__i386__) \
	|| defined(__alpha__) \
	|| (defined(__mips__) && (defined(MIPSEL) || defined (__MIPSEL__)))
#define BYTE_ORDER_LITTLE_ENDIAN
#elif 	defined(__mc68000__) \
	|| defined (__sparc__) \
	|| defined (__sparc) \
	|| defined (__PPC__) \
	|| defined (__BIG_ENDIAN__) \
	|| (defined(__mips__) && (defined(MIPSEB) || defined (__MIPSEB__)))
#define BYTE_ORDER_BIG_ENDIAN
#else
# error can not find the byte order for this architecture, fix bytesex.h
#endif

#endif /* ARS_BYTESEX_H */
