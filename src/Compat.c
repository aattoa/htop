/*
htop - Compat.c
(C) 2020 htop dev team
Released under the GNU GPLv2+, see the COPYING file
in the source distribution for its full text.
*/

#include "config.h" // IWYU pragma: keep

#include "Compat.h"

#include <errno.h>
#include <fcntl.h> // IWYU pragma: keep
#include <limits.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h> // IWYU pragma: keep

#include "XUtils.h" // IWYU pragma: keep


int Compat_faccessat(int dirfd,
                     const char* pathname,
                     int mode,
                     int flags) {
   errno = 0;

   int ret = faccessat(dirfd, pathname, mode, flags);
   if (!ret || errno != EINVAL)
      return ret;

   // Error out on unsupported configurations
   if (dirfd != (int)AT_FDCWD || mode != F_OK) {
      errno = EINVAL;
      return -1;
   }

   // Fallback to stat(2)/lstat(2) depending on flags
   struct stat statinfo;
   return flags ? lstat(pathname, &statinfo) : stat(pathname, &statinfo);
}

ssize_t Compat_readlink(openat_arg_t dirfd,
                        const char* pathname,
                        char* buf,
                        size_t bufsize) {
   char fdPath[32];
   xSnprintf(fdPath, sizeof(fdPath), "/proc/self/fd/%d", dirfd);

   char dirPath[PATH_MAX + 1];
   ssize_t r = readlink(fdPath, dirPath, sizeof(dirPath) - 1);
   if (r < 0)
      return r;

   dirPath[r] = '\0';

   char linkPath[PATH_MAX + 1];
   xSnprintf(linkPath, sizeof(linkPath), "%s/%s", dirPath, pathname);

   return readlink(linkPath, buf, bufsize);
}
