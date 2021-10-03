#include "htop.h"
#include "types.h"
#include "stat.h"
#include "date.h"
#include "user.h"
#include "param.h"
#include "memlayout.h"

enum procstate { UNUSED, EMBRYO, SLEEPING, RUNNABLE, RUNNING, ZOMBIE };
static char *states[] = {
        [UNUSED]    "U",
        [EMBRYO]    "E",
        [SLEEPING]  "S",
        [RUNNABLE]  "R*",
        [RUNNING]   "R",
        [ZOMBIE]    "Z",
};

int
main(int argc, char *argv[])
{
    iproc iptable[NPROC];
    struct rtcdate rtcdate;

    datetime(&rtcdate);
    htop(iptable);

    int statistics[] = {
            [UNUSED]    0,
            [EMBRYO]    0,
            [SLEEPING]  0,
            [RUNNABLE]  0,
            [RUNNING]   0,
            [ZOMBIE]    0,
    };
    int mem = 0;
    int total = 0;
    for (int i = 0; i < NPROC; ++i) {
        iproc iProc = iptable[i];
        if(iProc.pid == 0) continue;
        statistics[iProc.state]++;
        total++;
        mem += iProc.sz;
    }

    printf(1, "Datetime: %d-%d-%d %d:%d:%d\n", rtcdate.year, rtcdate.month, rtcdate.day, rtcdate.hour, rtcdate.minute, rtcdate.second);
    printf(1, "Tasks: %d total, %d running, %d sleeping, %d runnable, %d zombie\n", total, statistics[RUNNING], statistics[SLEEPING], statistics[RUNNABLE], statistics[ZOMBIE]);
    printf(1, "KiB Mem: %d total, %d free, %d used\n", PHYSTOP / (1<<10), (PHYSTOP - mem) / (1<<10), mem / (1<<10));
    printf(1, "PID \tName \tStatus \tMem \tOpen Files\n");
    for (int i = 0; i < NPROC; ++i) {
        iproc iProc = iptable[i];
        if(iProc.pid == 0) continue;
        printf(1, "%d \t%s \t%s \t%d \t%d\n", iProc.pid, iProc.name, states[iProc.state], iProc.sz, iProc.ofile);
    }
    exit();
}
