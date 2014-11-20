/*
 * coder.h
 *
 *  Created for: GlobalLogic Bootcamp
 *       Author: vitalii.lysenko
 *
 * Coder class header.
 * You can change it if you need.
 *
 * This header will be used when Jenkins builds the unit tests.
 *
 *
 */

#ifndef CODER_H
#define CODER_H

/*
 * This function is defined in encode.cpp and provided as
 * GCC static library.
 *
 */
void encode( char* buf, int size );

#pragma pack(push, 1)

/*
 * Coder class header.
 *
 */
class Coder
{
public:
	void set( const char* buf, int size );
	char* buf() const;
	int size() const;

	void encode();
	void decode();

private:
	char* m_buf;
	int m_size;
};

#pragma pack(pop)

#endif // CODER_H