In 1987, the thing powered on and worked on the first try, with maybe 2000 (?) wire wrap connections!
In 2021, it still runs!!!

See: https://rtestardi.github.io/retro/retro.pdf

cl y.tab.c
cl intel.c getopt.c

# offset 0 boot loader
cl /EP boot.q >boot.qq & y.tab.exe <boot.qq >boot.x & intel.exe <boot.x

# offset 32768 test program
cl /EP test.q >test.qq & y.tab.exe -o 32768 <test.qq >test.x & intel.exe -o 32768 -s 32768 <test.x
