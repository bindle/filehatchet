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
 *  @file include/filehatchet.h File splitting utility
 */
#ifndef _FILE_HATCHET_H
#define _FILE_HATCHET_H 1

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

#define FILEHATCHET_MAGIC_ID       0x42325300L

#define FILEHATCHET_OPT_UNICODE    0x01L
#define FILEHATCHET_OPT_LZMA       0x02L
#define FILEHATCHET_OPT_SHA1DIGEST 0x04L
#define FILEHATCHET_OPT_SHA1ID     0x08L


/////////////////
//             //
//  Datatypes  //
//             //
/////////////////
#pragma mark -
#pragma mark Datatypes

/// contains information about a File Hatchet chunk
typedef struct filehatchet_b2schunk B2SChunk;
struct filehatchet_b2schunk
{
   uint64_t   offset;      ///< data offset from beginning of original file
   uint64_t   dataSize;    ///< length of encoded data
   uint8_t  * data;        ///< pointer to encoded data
   uint8_t    digest[24];  ///< digest used to verify data integrity
};


/// contains information about a File Hatchet file
typedef struct filehatchet_b2sfile B2SFile;
struct filehatchet_b2sfile
{
   uint64_t   magicID;            ///< magic number of file
   uint64_t   versionCurrent;     ///< current version number of this API
   uint64_t   versionAge;         ///< number of compatible seqential past versions
   uint64_t   flags;              ///< options for processing file
   uint8_t    origID[24];         ///< unique identifier of original file
   uint64_t   origSize;           ///< original file size
   uint64_t   origNumOfChips;     ///< number of file "chips" created
   uint64_t   origMaxChipSize;    ///< maximum size of file "chips"
   uint64_t   origMaxChunkSize;   ///< maximum size of chunk within chip
   int64_t    contentIndex;       ///< index of chip within the sequence of chips
   uint64_t   contentOffset;      ///< offset of chip's content from within original file
   uint64_t   contentSize;        ///< unencoded size of chip's content
   uint64_t   origFileNameSize;   ///< size of original file's name
   uint8_t  * origFileName;       ///< encoded name of original file
   uint64_t   numOfChunks;        ///< number of chunks within file
   B2SChunk * chunks;             ///< pointer to array of chunks
   uint8_t    digest[24];         ///< digest used to verify data integrity
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
