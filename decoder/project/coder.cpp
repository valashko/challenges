/*
 * coder.cpp
 *
 *  Created for: GlobalLogic Bootcamp
 *       Author: vitalii.lysenko
 *
 * Coder class source.
 * You have to write an implementation of all member functions
 * except of encode(). It is already defined in encode.cpp and
 * provided to you as GCC static library.
 * 
 * This source will be used when Jenkins builds the unit tests.
 *
 */

#include "coder.h"

/*
 * The main task is to puzzle out the encode() algorithm and to
 * write the decode() one.
 *
 * Good luck!
 *
 */
void Coder::encode()
{
	::encode( m_buf, m_size );
}

