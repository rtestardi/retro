# offset 0 boot loader
cl /EP boot.q >boot.qq & y.tab.exe <boot.qq >boot.x

# offset 32768 test program
cl /EP test.q >test.qq & y.tab.exe -o 32768 <test.qq >test.x & intel.exe -o 32768 -s 32768 <test.x
