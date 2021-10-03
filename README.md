## Task 1:

#### Usage:
In order to enable printing additional info on syscalls,
one need to define variable `SYS_DETAILS` in file `syscall.c`.
After compilation, launch the emulator.

Additional information has the following format:

`<syscall name>(<type>: <arg1>, <type>: <arg2>, ..., [optinal <char printed to console>]) -> <eax content after syscall>`
There are 3 supported types: `int`, `str`, `obj` (pointer to non-string)

Example:
```shell
sys_open(int: 11664, str: ./console, int: 0, ) -> 4

sys_fstat(int: 4, int: 11644, obj: 2d7c, ) -> 0

sys_close(int: 4, ) -> 0

sys_write(int: 1, int: 1, int: 11519, obj: 2cff, c) -> 1

sys_write(int: 1, int: 1, int: 11519, obj: 2cff, o) -> 1

sys_write(int: 1, int: 1, int: 11519, obj: 2cff, n) -> 1

sys_write(int: 1, int: 1, int: 11519, obj: 2cff, s) -> 1

sys_write(int: 1, int: 1, int: 11519, obj: 2cff, o) -> 1

sys_write(int: 1, int: 1, int: 11519, obj: 2cff, l) -> 1

sys_write(int: 1, int: 1, int: 11519, obj: 2cff, e) -> 1
```
#### Changes in xv6 code:
* `syscall.c`:
  * modified function `void syscall(void)` in order to get value of `eax` register and then determine the name of syscall. After syscall register `eax` contains return value of corresponding syscall.
  * modified functions (`int argstr(int n, char **pp), int argptr(int n, char **pp, int size), int argint(int n, int *ip)`) in order to print out arguments with which syscalls are called.

## Task 2:

#### Usage:
```shell
$ date
2021-10-3 13:53:19
```
Utility outputs the datetime in standard format: `year-month-day hour:minute:second`. Note that it's GMT.
#### Changes in xv6 code:
* `syscall.c`
* `syscall.h`
* `sysproc.c`
* `user.h`
* `usys.S`
* `date.c`

Note: each file contains comments on what has been done and why.

## Task 3:

#### Usage:
```shell
$ htop
Datetime: 2021-10-3 14:24:0
Tasks: 3 total, 1 running, 2 sleeping, 0 embryo, 0 zombie
KiB Mem: 229376 total, 229336 free, 40 used
PID     Name    Status  Mem     Open Files
1       init    S       12288   3
2       sh      S       16384   3
3       htop    R       12288   3

$ ls | zombie | htop > f
zombie!
$ cat f
Datetime: 2021-10-3 16:35:22
Tasks: 8 total, 2 running, 5 sleeping, 0 runnable, 1 zombie
KiB Mem: 229376 total, 229204 free, 172 used
PID     Name    Status  Mem     Open Files
1       init    S       12288   3
2       sh      S       16384   3
3       sh      S       49152   3
4       ls      R       12288   4
5       sh      S       49152   3
6       zombie  S       12288   3
7       htop    R       12288   3
8       zombie  Z       12288   0
```
#### Changes in xv6 code:
* `syscall.c`
* `syscall.h`
* `sysproc.c`
* `user.h`
* `usys.S`
* `defs.h`
* `proc.c`
* `sysfile.c`
* `htop.c/h`

Note: each file contains comments on what has been done and why.
