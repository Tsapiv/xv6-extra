#include "types.h"
#include "stat.h"
#include "date.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  struct rtcdate r;
  datetime(&r);
  printf(1, "%d-%d-%d %d:%d:%d\n", r.year, r.month, r.day, r.hour, r.minute, r.second);
  exit();
}
