cmd_/source/linux-3.x-virtual-headers/usr/include/linux/byteorder/.install := perl scripts/headers_install.pl /source/linux-3.x-virtual-headers/include/linux/byteorder /source/linux-3.x-virtual-headers/usr/include/linux/byteorder arm big_endian.h little_endian.h; perl scripts/headers_install.pl /source/linux-3.x-virtual-headers/include/linux/byteorder /source/linux-3.x-virtual-headers/usr/include/linux/byteorder arm ; for F in ; do echo "\#include <asm-generic/$$F>" > /source/linux-3.x-virtual-headers/usr/include/linux/byteorder/$$F; done; touch /source/linux-3.x-virtual-headers/usr/include/linux/byteorder/.install