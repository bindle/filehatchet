/*
 *  File Hatchet
 *  Copyright (C) 2011 Bindle Binaries <syzdek@bindlebinaries.com>.
 *
 *  @BINDLE_BINARIES_BSD_LICENSE_START@
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are
 *  met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Bindle Binaries nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 *  IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 *  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 *  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL BINDLE BINARIES BE LIABLE FOR
 *  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 *  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 *  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 *  OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 *  SUCH DAMAGE.
 *
 *  @BINDLE_BINARIES_BSD_LICENSE_END@
 */
/**
 *  @file include/b2s.h .B2S API
 */
#ifndef _B2S_H
#define _B2S_H 1

///////////////
//           //
//  Headers  //
//           //
///////////////
#pragma mark Headers

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <inttypes.h>


///////////////////
//               //
//  Definitions  //
//               //
///////////////////
#pragma mark -
#pragma mark Definitions & Macros

#define B2S_MAGIC_ID       0x42325300L

#define B2S_OPT_UNICODE    0x01L
#define B2S_OPT_LZMA       0x02L
#define B2S_OPT_SHA1DIGEST 0x04L
#define B2S_OPT_SHA1ID     0x08L


/////////////////
//             //
//  Datatypes  //
//             //
/////////////////
#pragma mark -
#pragma mark Datatypes

/// contains information about a B2S chunk
typedef struct bs2_chunk B2SChunk;
struct bs2_chunk
{
   uint64_t   offset;      ///< data offset from beginning of original file
   uint64_t   dataSize;    ///< length of encoded data
   uint8_t  * data;        ///< pointer to encoded data
   uint8_t    digest[24];  ///< digest used to verify data integrity
};


/// contains information about a File Hatchet file
typedef struct b2s_file B2SFile;
struct b2s_file
{
   char      * file_path;          ///< file system path to .B2S file
   uint64_t    magicNumber;        ///< magic number of file
   uint64_t    versionCurrent;     ///< current version number of this API
   uint64_t    versionAge;         ///< number of compatible seqential past versions
   uint64_t    flags;              ///< options for encoding file
   uint8_t     origID[24];         ///< unique identifier of original file
   uint64_t    origSize;           ///< original file size
   uint64_t    origNumOfSeg;       ///< number of file segments created
   uint64_t    origMaxSegSize;     ///< maximum size of file segments
   uint64_t    origMaxChunkSize;   ///< maximum size of chunk
   int64_t     contentIndex;       ///< index of segment within the sequence of segments
   uint64_t    contentOffset;      ///< offset of segment's content from within original file
   uint64_t    contentSize;        ///< unencoded size of segment's content
   uint64_t    origFileNameSize;   ///< size of original file's name
   uint8_t   * origFileName;       ///< encoded name of original file
   uint64_t    numOfChunks;        ///< number of chunks within file
   B2SChunk ** chunks;             ///< pointer to array of chunks
   uint8_t     digest[24];         ///< digest used to verify data integrity
};


/// contains information about a B2S chunk
typedef struct b2s_state B2S;
struct b2s_state
{
   char        * orig_file_path;   ///< file system path to original file
   const char  * orig_file_name;   ///< name of original file
   B2SFile     * index;            ///< .B2S Index File
   B2SFile    ** segments;         ///< Array of .B2S file segments
   B2SFile     * custom;           ///< Custom .B2S file segments
};


//////////////////
//              //
//  Prototypes  //
//              //
//////////////////
#pragma mark -
#pragma mark Prototypes


#endif
/* end of header */
