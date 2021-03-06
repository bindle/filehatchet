#
#   File Hatchet
#   Copyright (C) 2011 Bindle Binaries <syzdek@bindlebinaries.com>.
#
#   @BINDLE_BINARIES_BSD_LICENSE_START@
#
#   Redistribution and use in source and binary forms, with or without
#   modification, are permitted provided that the following conditions are
#   met:
#
#      * Redistributions of source code must retain the above copyright
#        notice, this list of conditions and the following disclaimer.
#      * Redistributions in binary form must reproduce the above copyright
#        notice, this list of conditions and the following disclaimer in the
#        documentation and/or other materials provided with the distribution.
#      * Neither the name of Bindle Binaries nor the
#        names of its contributors may be used to endorse or promote products
#        derived from this software without specific prior written permission.
#
#   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
#   IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
#   THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
#   PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL BINDLE BINARIES BE LIABLE FOR
#   ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
#   DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
#   SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
#   CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
#   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
#   OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
#   SUCH DAMAGE.
#
#   @BINDLE_BINARIES_BSD_LICENSE_END@
#
#   configure.in - automate compiling on a unix platform
#

AC_PREREQ([2.68])

AC_COPYRIGHT([Copyright (c) 2011 Bindle Binaries <syzdek@bindlebinaries.com>.])
AC_REVISION(0.1)
AC_INIT([File Hatchet],[0.1],[syzdek@bindlebinaries.com],[filehatchet])

AC_SUBST([RELEASE_MONTH],["January 2011"])

# Version Info:
#    Current    -- the current version number of this API
#    Revision   -- the revision of the implementation of the API version
#    Age        -- How many seqential past API versions is supported by
#                  this implementation
# Format => Current:Revision:Age
AC_SUBST([LIB_VERSION_CURRENT],  [0])
AC_SUBST([LIB_VERSION_REVISION], [0])
AC_SUBST([LIB_VERSION_AGE],      [0])
AC_SUBST([LIB_VERSION_INFO],     [${LIB_VERSION_CURRENT}:${LIB_VERSION_REVISION}:${LIB_VERSION_AGE}])
AC_SUBST([LIB_RELEASE_INFO],     [${LIB_VERSION_CURRENT}]) # used by Win32 DLLs

AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_SRCDIR([configure.ac])
#AC_CONFIG_LIBOBJ_DIR(compat)
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])

# determines host type
AC_CANONICAL_BUILD
AC_CANONICAL_HOST
AC_CANONICAL_TARGET

# configures for automake
AM_INIT_AUTOMAKE(gnu std-options subdir-objects)

# Compilers
AC_PROG_CC
#AC_PROG_OBJC
#AC_PROG_CXX
AM_PROG_CC_C_O
AC_PROG_INSTALL
AC_USE_SYSTEM_EXTENSIONS # replaces AC_AIX AC_GNU_SOURCE AC_MINIX
AC_C_BIGENDIAN

# binary locations
AC_PROG_INSTALL
AC_PATH_PROG([SHELL],   sh bash,        [AC_MSG_ERROR([missing "sh"])], [$PATH])
AC_CHECK_TOOLS(AR,      ar gar,         [AC_MSG_ERROR([missing binutil "ar"])])
AC_CHECK_TOOLS(LD,      ld gld,         [AC_MSG_ERROR([missing binutil "ld"])])
AC_CHECK_TOOLS(NM,      nm gnm,         [AC_MSG_ERROR([missing binutil "nm"])])
AC_CHECK_TOOLS(RANLIB,  ranlib granlib, [AC_MSG_ERROR([missing binutil "ranlib"])])
AC_CHECK_TOOLS(STRIP,   strip gstrip,   [AC_MSG_ERROR([missing binutil "strip"])])

# shell programs
AC_PROG_AWK
AC_PROG_EGREP
AC_PROG_FGREP
AM_PROG_LEX
AC_PROG_LN_S

# GNU Libtool Support
LT_INIT(dlopen disable-fast-install win32-dll)

# custom configure options
AC_FILEHATCHET_ENABLE_WARNINGS

# Geek Humor check
AC_CHECK_LIB([aundry],[clean socks],,[AC_MSG_NOTICE([No clean socks found.])])

# enables getopt_long if header and functions were found
AC_CHECK_HEADERS([getopt.h], [AC_DEFINE_UNQUOTED(USE_GETOPT_LONG, 1, [Use GNU getopt_long])])

# checks for cross compile (need to verify the following checks)
test "x$host" == "x$build"  && COMPILE_MODE='native compile';
test "x$host" != "x$build"  && COMPILE_MODE='cross compile';
test "x$host" != "x$target" && COMPILE_MODE='Canadian cross compile';

# checks for build variants in order to include system specific source files
case $host in
   *cygwin*)  COMPILE_CYGWIN=true;;
   *darwin*)  COMPILE_DARWIN=true;;
   *freebsd*) COMPILE_FREEBSD=true;;
   *linux*)   COMPILE_LINUX=true;;
   *mingw*)   COMPILE_MINGW=true;;
   *solaris*) COMPILE_SOLARIS=true;;
esac
AM_CONDITIONAL([COMPILE_CYGWIN],  [test "x$COMPILE_CYGWIN"  == "xtrue"])
AM_CONDITIONAL([COMPILE_DARWIN],  [test "x$COMPILE_DARWIN"  == "xtrue"])
AM_CONDITIONAL([COMPILE_FREEBSD], [test "x$COMPILE_FREEBSD" == "xtrue"])
AM_CONDITIONAL([COMPILE_LINUX],   [test "x$COMPILE_LINUX"   == "xtrue"])
AM_CONDITIONAL([COMPILE_MINGW],   [test "x$COMPILE_MINGW"   == "xtrue"])
AM_CONDITIONAL([COMPILE_SOLARIS], [test "x$COMPILE_SOLARIS" == "xtrue"])

# determine PACKAGE_VERSION via Git
AC_DMS_GIT_PACKAGE_VERSION

# Creates outputs
AC_CONFIG_FILES([Makefile])
AC_OUTPUT

# Show local config
AC_MSG_NOTICE([ ])
AC_MSG_NOTICE([   File Hatchet])
AC_MSG_NOTICE([ ])
AC_MSG_NOTICE([   Please send suggestions to:   $PACKAGE_BUGREPORT])
AC_MSG_NOTICE([ ])
AC_MSG_NOTICE([   run 'make all'])
AC_MSG_NOTICE([ ])

# end of configure.ac
