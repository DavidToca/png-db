/* public api for steve reid's public domain SHA-1 implementation */
/* this file is in the public domain */

#ifndef __SHA1_H
#define __SHA1_H

#include <string>
#include <stdint.h>

#define SHA1_DIGEST_SIZE 20

struct Sha1Context {
    uint32_t state[5];
    uint32_t count[2];
    uint8_t  buffer[64];

	Sha1Context();
	void update(const char* data, size_t len);
	std::string final();
};

std::string calc_sha1(const char* data, size_t s);

inline std::string calc_sha1(const std::string& data) {
	return calc_sha1(&data[0], data.size());
}

#endif /* __SHA1_H */
