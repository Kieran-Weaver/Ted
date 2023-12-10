/************************************************************************/
/*									*/
/*  MD5 hash/message digest.						*/
/*									*/
/*  Borrowed/adapted from public code by RSA Data Security.		*/
/*  Refer to the copyright notice below from the original version.	*/
/*									*/
/************************************************************************/

/* Copyright (C) 1991-2, RSA Data Security, Inc. Created 1991. All
rights reserved.

License to copy and use this software is granted provided that it
is identified as the "RSA Data Security, Inc. MD5 Message-Digest
Algorithm" in all material mentioning or referencing this software
or this function.

License is also granted to make and use derivative works provided
that such works are identified as "derived from the RSA Data
Security, Inc. MD5 Message-Digest Algorithm" in all material
mentioning or referencing the derived work.

RSA Data Security, Inc. makes no representations concerning either
the merchantability of this software or the suitability of this
software for any particular purpose. It is provided "as is"
without express or implied warranty of any kind.
These notices must be retained in any copies of any part of this
documentation and/or software.
 */

#ifndef UTIL_MD5_H
#define UTIL_MD5_H

#include <config.h>
#include <stdint.h>

#define MD5_DIGEST_SIZE_BITS 128
#define MD5_DIGEST_SIZE_BYTES 16
#define MD5_DIGEST_SIZE_BASE64 (((16 + 2) / 3) * 4 + 1) /* 24+ 1 */

typedef struct MD5Context {
	uint32_t md5cState[4]; /*  state (ABCD)	*/
	uint32_t md5cCount[2]; /*  number of bits,	*/
	/*  modulo 2^64 (lsb	*/
	/*  first)		*/
	unsigned char md5cBuffer[64]; /*  input buffer	*/
} MD5Context;

void utilMD5Init(MD5Context *md5c);

void utilMD5Update(MD5Context *md5c, const unsigned char *bytes,
			  unsigned int count);

void utilMD5Final(unsigned char digest[MD5_DIGEST_SIZE_BYTES],
			 MD5Context *md5c);

void utilMD5ToBase64(char digestBase64[MD5_DIGEST_SIZE_BASE64],
			    const unsigned char digest[MD5_DIGEST_SIZE_BYTES]);

int utilMD5FromBase64(unsigned char digest[MD5_DIGEST_SIZE_BYTES],
			     const char digestBase64[MD5_DIGEST_SIZE_BASE64]);

#endif /*  UTIL_MD5_H  */
