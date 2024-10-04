#ifndef MYCHAR_H
#define MYCHAR_H

#include <asm/ioctl.h>

#define MYCHAR_MAGIC 'a'

#define MYCHAR_IOCTL_GET_MAXLEN _IOR(MYCHAR_MAGIC, 1, int*)
#define MYCHAR_IOCTL_GET_CURLEN _IOR(MYCHAR_MAGIC, 2, int*)

#endif
