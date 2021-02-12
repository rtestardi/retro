int getopt(int nargc, char * const nargv[], const char *ostr) ;

static char sccsID[] = "@(#)intel.c	1.3 07/04/88";

/* intel -o<offset> -s<offset> -0123 */

#include <stdio.h>
#include <ctype.h>

#define DATA_RECORD  0
#define EOF_RECORD   1
#define START_RECORD 3

static int q[4];
static int offset;
static int start = -1;

#define RECLEN 16

record(count, address, type, bytes)
int count;
int address;
int type;
int bytes[];
{
  int sum;
  int i;

  sum = count + address/256 + address%256 + type;
  printf(":%02X%04X%02X", count, address, type);
  for (i = 0; i < count; i++) {
    sum += bytes[i];
    sum %= 256;
    printf("%02X", bytes[i]);
  }
  printf("%02X\n", (-sum) & 0xff);
}

dumpit()
{
  int bytes[RECLEN];
  int bytesi = 0;
  int quarter = 0;
  int address = 0;
  int c;

  while ((c = getchar()) != EOF) {
    if (q[quarter]) {
      bytes[bytesi++] = c;
      if (bytesi == RECLEN) {
        record(bytesi, address+offset, DATA_RECORD, bytes);
        address += bytesi;
        bytesi = 0;
      }
    }
    quarter = (quarter + 1) % 4;
  }
  if (bytesi != 0) {
    record(bytesi, address+offset, DATA_RECORD, bytes);
  }
  if (start != -1) {
    record(0, start, START_RECORD, 0);
  }
  record(0, 0, EOF_RECORD, 0);
}

main(argc, argv)
int argc;
char *argv[];
{
  extern char *optarg;
  extern int optind, opterr;
  char *terminal;
  int c;
  int error;

  error = 0;
  opterr = 0;
  while ((c = getopt(argc, argv, "0123o:s:")) != EOF) {
    switch (c) {
      case '0': q[0] = 1;
                break;
      case '1': q[1] = 1;
                break;
      case '2': q[2] = 1;
                break;
      case '3': q[3] = 1;
                break;
      case 'o': offset = strtol(optarg, &terminal, 0);
                if (*terminal != 0 && ! isspace(*terminal)) {
                  error = 1;
                }
                break;
      case 's': start = strtol(optarg, &terminal, 0);
                if (*terminal != 0 && ! isspace(*terminal)) {
                  error = 1;
                }
                break;
      case '?': error = 1;
                break;
    }
  }
  if (error) {
    fprintf(stderr,
            "USAGE: %s [-0] [-1] [-2] [-3] [-o <offset>] [-s <offset>]\n",
            argv[0]);
    exit(1);
  }
  if (q[0] == 0 && q[1] == 0 && q[2] == 0 && q[3] == 0) {
    q[0] = q[1] = q[2] = q[3] = 1;
  }
  dumpit();
  exit(0);
}

