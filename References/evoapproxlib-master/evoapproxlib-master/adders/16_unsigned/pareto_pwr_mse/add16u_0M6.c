/***
* This code is a part of EvoApproxLib library (ehw.fit.vutbr.cz/approxlib) distributed under The MIT License.
* When used, please cite the following article(s):  
* This file contains a circuit from a sub-set of pareto optimal circuits with respect to the pwr and mse parameters
***/
// MAE% = 0.54 %
// MAE = 712 
// WCE% = 1.80 %
// WCE = 2365 
// WCRE% = 700.00 %
// EP% = 99.96 %
// MRE% = 1.50 %
// MSE = 761357 
// PDK45_PWR = 0.022 mW
// PDK45_AREA = 46.9 um2
// PDK45_DELAY = 0.43 ns
#include <stdint.h>
#include <stdlib.h>

uint64_t add16u_0M6(uint64_t a, uint64_t b) {
  int wa[16];
  int wb[16];
  uint64_t y = 0;
  wa[0] = (a >> 0) & 0x01;
  wb[0] = (b >> 0) & 0x01;
  wa[1] = (a >> 1) & 0x01;
  wb[1] = (b >> 1) & 0x01;
  wa[2] = (a >> 2) & 0x01;
  wb[2] = (b >> 2) & 0x01;
  wa[3] = (a >> 3) & 0x01;
  wb[3] = (b >> 3) & 0x01;
  wa[4] = (a >> 4) & 0x01;
  wb[4] = (b >> 4) & 0x01;
  wa[5] = (a >> 5) & 0x01;
  wb[5] = (b >> 5) & 0x01;
  wa[6] = (a >> 6) & 0x01;
  wb[6] = (b >> 6) & 0x01;
  wa[7] = (a >> 7) & 0x01;
  wb[7] = (b >> 7) & 0x01;
  wa[8] = (a >> 8) & 0x01;
  wb[8] = (b >> 8) & 0x01;
  wa[9] = (a >> 9) & 0x01;
  wb[9] = (b >> 9) & 0x01;
  wa[10] = (a >> 10) & 0x01;
  wb[10] = (b >> 10) & 0x01;
  wa[11] = (a >> 11) & 0x01;
  wb[11] = (b >> 11) & 0x01;
  wa[12] = (a >> 12) & 0x01;
  wb[12] = (b >> 12) & 0x01;
  wa[13] = (a >> 13) & 0x01;
  wb[13] = (b >> 13) & 0x01;
  wa[14] = (a >> 14) & 0x01;
  wb[14] = (b >> 14) & 0x01;
  wa[15] = (a >> 15) & 0x01;
  wb[15] = (b >> 15) & 0x01;
  int sig_35 = wa[11];
  int sig_37 = 0;
  int sig_42 = 0;
  int sig_48 = 0;
  int sig_67 = 0;
  int sig_80 = wa[10] & wa[10];
  int sig_83 = sig_80;
  int sig_84 = wa[11] ^ wb[11];
  int sig_85 = wa[11] & wb[11];
  int sig_86 = sig_84 & sig_83;
  int sig_87 = sig_84 ^ sig_83;
  int sig_88 = sig_85 | sig_86;
  int sig_89 = wa[12] ^ wb[12];
  int sig_90 = wa[12] & wb[12];
  int sig_91 = sig_89 & sig_88;
  int sig_92 = sig_89 ^ sig_88;
  int sig_93 = sig_90 | sig_91;
  int sig_94 = wa[13] ^ wb[13];
  int sig_95 = wa[13] & wb[13];
  int sig_96 = sig_94 & sig_93;
  int sig_97 = sig_94 ^ sig_93;
  int sig_98 = sig_95 | sig_96;
  int sig_99 = wa[14] ^ wb[14];
  int sig_100 = wa[14] & wb[14];
  int sig_101 = sig_99 & sig_98;
  int sig_102 = sig_99 ^ sig_98;
  int sig_103 = sig_100 | sig_101;
  int sig_104 = wa[15] ^ wb[15];
  int sig_105 = wa[15] & wb[15];
  int sig_106 = sig_104 & sig_103;
  int sig_107 = sig_104 ^ sig_103;
  int sig_108 = sig_105 | sig_106;
  y |=  (wb[14] & 0x01) << 0; // default output
  y |=  (wa[0] & 0x01) << 1; // default output
  y |=  (sig_42 & 0x01) << 2; // default output
  y |=  (sig_35 & 0x01) << 3; // default output
  y |=  (sig_37 & 0x01) << 4; // default output
  y |=  (sig_85 & 0x01) << 5; // default output
  y |=  (sig_48 & 0x01) << 6; // default output
  y |=  (sig_67 & 0x01) << 7; // default output
  y |=  (wb[7] & 0x01) << 8; // default output
  y |=  (wb[6] & 0x01) << 9; // default output
  y |=  (wa[9] & 0x01) << 10; // default output
  y |=  (sig_87 & 0x01) << 11; // default output
  y |=  (sig_92 & 0x01) << 12; // default output
  y |=  (sig_97 & 0x01) << 13; // default output
  y |=  (sig_102 & 0x01) << 14; // default output
  y |=  (sig_107 & 0x01) << 15; // default output
  y |=  (sig_108 & 0x01) << 16; // default output
   return y;
}
