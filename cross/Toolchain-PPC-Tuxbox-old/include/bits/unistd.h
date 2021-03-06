/* Checking macros for unistd functions.
   Copyright (C) 2005 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

#ifndef _UNISTD_H
# error "Never include <bits/unistd.h> directly; use <unistd.h> instead."
#endif

extern ssize_t __read_chk (int __fd, void *__buf, size_t __nbytes,
			   size_t __buflen) __wur;
extern ssize_t __REDIRECT (__read_alias, (int __fd, void *__buf,
					  size_t __nbytes), read) __wur;

extern __always_inline __wur ssize_t
read (int __fd, void *__buf, size_t __nbytes)
{
  if (__bos0 (__buf) != (size_t) -1
      && (!__builtin_constant_p (__nbytes) || __nbytes > __bos0 (__buf)))
    return __read_chk (__fd, __buf, __nbytes, __bos0 (__buf));
  return __read_alias (__fd, __buf, __nbytes);
}

#ifdef __USE_UNIX98
extern ssize_t __pread_chk (int __fd, void *__buf, size_t __nbytes,
			    __off_t __offset, size_t __bufsize) __wur;
extern ssize_t __pread64_chk (int __fd, void *__buf, size_t __nbytes,
			      __off64_t __offset, size_t __bufsize) __wur;
extern ssize_t __REDIRECT (__pread_alias,
			   (int __fd, void *__buf, size_t __nbytes,
			    __off_t __offset), pread) __wur;
extern ssize_t __REDIRECT (__pread64_alias,
			   (int __fd, void *__buf, size_t __nbytes,
			    __off64_t __offset), pread64) __wur;

# ifndef __USE_FILE_OFFSET64
extern __always_inline __wur ssize_t
pread (int __fd, void *__buf, size_t __nbytes, __off_t __offset)
{
  if (__bos0 (__buf) != (size_t) -1
      && (!__builtin_constant_p (__nbytes) || __nbytes > __bos0 (__buf)))
    return __pread_chk (__fd, __buf, __nbytes, __offset, __bos0 (__buf));
  return __pread_alias (__fd, __buf, __nbytes, __offset);
}
# else
extern __always_inline __wur ssize_t
pread (int __fd, void *__buf, size_t __nbytes, __off64_t __offset)
{
  if (__bos0 (__buf) != (size_t) -1
      && (!__builtin_constant_p (__nbytes) || __nbytes > __bos0 (__buf)))
    return __pread64_chk (__fd, __buf, __nbytes, __offset, __bos0 (__buf));
  return __pread64_alias (__fd, __buf, __nbytes, __offset);
}
# endif

# ifdef __USE_LARGEFILE64
extern __always_inline __wur ssize_t
pread64 (int __fd, void *__buf, size_t __nbytes, __off64_t __offset)
{
  if (__bos0 (__buf) != (size_t) -1
      && (!__builtin_constant_p (__nbytes) || __nbytes > __bos0 (__buf)))
    return __pread64_chk (__fd, __buf, __nbytes, __offset, __bos0 (__buf));
  return __pread64_alias (__fd, __buf, __nbytes, __offset);
}
# endif
#endif

#if defined __USE_BSD || defined __USE_XOPEN_EXTENDED || defined __USE_XOPEN2K
extern int __readlink_chk (__const char *__restrict __path,
			   char *__restrict __buf, size_t __len,
			   size_t __buflen)
     __THROW __nonnull ((1, 2)) __wur;
extern int __REDIRECT_NTH (__readlink_alias,
			   (__const char *__restrict __path,
			    char *__restrict __buf, size_t __len), readlink)
     __nonnull ((1, 2)) __wur;

extern __always_inline __nonnull ((1, 2)) __wur int
__NTH (readlink (__const char *__restrict __path, char *__restrict __buf,
		 size_t __len))
{
  if (__bos (__buf) != (size_t) -1
      && (!__builtin_constant_p (__len) || __len > __bos (__buf)))
    return __readlink_chk (__path, __buf, __len, __bos (__buf));
  return __readlink_alias (__path, __buf, __len);
}
#endif

extern char *__getcwd_chk (char *__buf, size_t __size, size_t __buflen)
     __THROW __wur;
extern char *__REDIRECT_NTH (__getcwd_alias,
			     (char *__buf, size_t __size), getcwd) __wur;

extern __always_inline __wur char *
__NTH (getcwd (char *__buf, size_t __size))
{
  if (__bos (__buf) != (size_t) -1
      && (!__builtin_constant_p (__size) || __size > __bos (__buf)))
    return __getcwd_chk (__buf, __size, __bos (__buf));
  return __getcwd_alias (__buf, __size);
}

#if defined __USE_BSD || defined __USE_XOPEN_EXTENDED
extern char *__getwd_chk (char *__buf, size_t buflen)
     __THROW __nonnull ((1)) __wur;
extern char *__REDIRECT_NTH (__getwd_alias, (char *__buf), getwd)
     __nonnull ((1)) __wur;

extern __always_inline __nonnull ((1)) __attribute_deprecated__ __wur char *
__NTH (getwd (char *__buf))
{
  if (__bos (__buf) != (size_t) -1)
    return __getwd_chk (__buf, __bos (__buf));
  return __getwd_alias (__buf);
}
#endif
