/***
* This code is a part of EvoApproxLib library (ehw.fit.vutbr.cz/approxlib) distributed under The MIT License.
* When used, please cite the following article(s): V. Mrazek, Z. Vasicek, L. Sekanina, H. Jiang and J. Han, "Scalable Construction of Approximate Multipliers With Formally Guaranteed Worst Case Error" in IEEE Transactions on Very Large Scale Integration (VLSI) Systems, vol. 26, no. 11, pp. 2572-2576, Nov. 2018. doi: 10.1109/TVLSI.2018.2856362 
* This file contains a circuit from a sub-set of pareto optimal circuits with respect to the pwr and ep parameters
***/
// MAE% = 0.043 %
// MAE = 7166 
// WCE% = 0.17 %
// WCE = 28665 
// WCRE% = 100.00 %
// EP% = 87.48 %
// MRE% = 0.69 %
// MSE = 97831.256e3 
// PDK45_PWR = 0.790 mW
// PDK45_AREA = 1213.6 um2
// PDK45_DELAY = 1.98 ns


module mul12u_2PM ( A, B, O );
  input [11:0] A;
  input [11:0] B;
  output [23:0] O;

  wire C_10_0,C_10_1,C_10_10,C_10_2,C_10_3,C_10_4,C_10_5,C_10_6,C_10_7,C_10_8,C_10_9,C_11_0,C_11_1,C_11_10,C_11_2,C_11_3,C_11_4,C_11_5,C_11_6,C_11_7,C_11_8,C_11_9,C_12_0,C_12_1,C_12_10,C_12_2,C_12_3,C_12_4,C_12_5,C_12_6,C_12_7,C_12_8,C_12_9,C_4_0,C_4_1,C_4_10,C_4_2,C_4_3,C_4_4,C_4_5,C_4_6,C_4_7,C_4_8,C_4_9,C_5_0,C_5_1,C_5_10,C_5_2,C_5_3,C_5_4,C_5_5,C_5_6,C_5_7,C_5_8,C_5_9,C_6_0,C_6_1,C_6_10,C_6_2,C_6_3,C_6_4,C_6_5,C_6_6,C_6_7,C_6_8,C_6_9,C_7_0,C_7_1,C_7_10,C_7_2,C_7_3,C_7_4,C_7_5,C_7_6,C_7_7,C_7_8,C_7_9,C_8_0,C_8_1,C_8_10,C_8_2,C_8_3,C_8_4,C_8_5,C_8_6,C_8_7,C_8_8,C_8_9,C_9_0,C_9_1,C_9_10,C_9_2,C_9_3,C_9_4,C_9_5,C_9_6,C_9_7,C_9_8,C_9_9,S_10_0,S_10_1,S_10_10,S_10_11,S_10_2,S_10_3,S_10_4,S_10_5,S_10_6,S_10_7,S_10_8,S_10_9,S_11_0,S_11_1,S_11_10,S_11_11,S_11_2,S_11_3,S_11_4,S_11_5,S_11_6,S_11_7,S_11_8,S_11_9,S_12_0,S_12_1,S_12_10,S_12_11,S_12_2,S_12_3,S_12_4,S_12_5,S_12_6,S_12_7,S_12_8,S_12_9,S_3_0,S_3_1,S_3_10,S_3_11,S_3_2,S_3_3,S_3_4,S_3_5,S_3_6,S_3_7,S_3_8,S_3_9,S_4_0,S_4_1,S_4_10,S_4_11,S_4_2,S_4_3,S_4_4,S_4_5,S_4_6,S_4_7,S_4_8,S_4_9,S_5_0,S_5_1,S_5_10,S_5_11,S_5_2,S_5_3,S_5_4,S_5_5,S_5_6,S_5_7,S_5_8,S_5_9,S_6_0,S_6_1,S_6_10,S_6_11,S_6_2,S_6_3,S_6_4,S_6_5,S_6_6,S_6_7,S_6_8,S_6_9,S_7_0,S_7_1,S_7_10,S_7_11,S_7_2,S_7_3,S_7_4,S_7_5,S_7_6,S_7_7,S_7_8,S_7_9,S_8_0,S_8_1,S_8_10,S_8_11,S_8_2,S_8_3,S_8_4,S_8_5,S_8_6,S_8_7,S_8_8,S_8_9,S_9_0,S_9_1,S_9_10,S_9_11,S_9_2,S_9_3,S_9_4,S_9_5,S_9_6,S_9_7,S_9_8,S_9_9;

  assign S_3_0 = (A[3] & B[0]);
  assign S_3_1 = (A[3] & B[1]);
  assign S_3_2 = (A[3] & B[2]);
  assign S_3_3 = (A[3] & B[3]);
  assign S_3_4 = (A[3] & B[4]);
  assign S_3_5 = (A[3] & B[5]);
  assign S_3_6 = (A[3] & B[6]);
  assign S_3_7 = (A[3] & B[7]);
  assign S_3_8 = (A[3] & B[8]);
  assign S_3_9 = (A[3] & B[9]);
  assign S_3_10 = (A[3] & B[10]);
  assign S_3_11 = (A[3] & B[11]);
  PDKGENHAX1 U31801 (.A(S_3_1), .B((A[4] & B[0])), .YS(S_4_0), .YC(C_4_0));
  PDKGENHAX1 U31802 (.A(S_3_2), .B((A[4] & B[1])), .YS(S_4_1), .YC(C_4_1));
  PDKGENHAX1 U31803 (.A(S_3_3), .B((A[4] & B[2])), .YS(S_4_2), .YC(C_4_2));
  PDKGENHAX1 U31804 (.A(S_3_4), .B((A[4] & B[3])), .YS(S_4_3), .YC(C_4_3));
  PDKGENHAX1 U31805 (.A(S_3_5), .B((A[4] & B[4])), .YS(S_4_4), .YC(C_4_4));
  PDKGENHAX1 U31806 (.A(S_3_6), .B((A[4] & B[5])), .YS(S_4_5), .YC(C_4_5));
  PDKGENHAX1 U31807 (.A(S_3_7), .B((A[4] & B[6])), .YS(S_4_6), .YC(C_4_6));
  PDKGENHAX1 U31808 (.A(S_3_8), .B((A[4] & B[7])), .YS(S_4_7), .YC(C_4_7));
  PDKGENHAX1 U31809 (.A(S_3_9), .B((A[4] & B[8])), .YS(S_4_8), .YC(C_4_8));
  PDKGENHAX1 U31810 (.A(S_3_10), .B((A[4] & B[9])), .YS(S_4_9), .YC(C_4_9));
  PDKGENHAX1 U31811 (.A(S_3_11), .B((A[4] & B[10])), .YS(S_4_10), .YC(C_4_10));
  assign S_4_11 = (A[4] & B[11]);
  PDKGENFAX1 U31813 (.A(S_4_1), .B(C_4_0), .C((A[5] & B[0])), .YS(S_5_0), .YC(C_5_0));
  PDKGENFAX1 U31814 (.A(S_4_2), .B(C_4_1), .C((A[5] & B[1])), .YS(S_5_1), .YC(C_5_1));
  PDKGENFAX1 U31815 (.A(S_4_3), .B(C_4_2), .C((A[5] & B[2])), .YS(S_5_2), .YC(C_5_2));
  PDKGENFAX1 U31816 (.A(S_4_4), .B(C_4_3), .C((A[5] & B[3])), .YS(S_5_3), .YC(C_5_3));
  PDKGENFAX1 U31817 (.A(S_4_5), .B(C_4_4), .C((A[5] & B[4])), .YS(S_5_4), .YC(C_5_4));
  PDKGENFAX1 U31818 (.A(S_4_6), .B(C_4_5), .C((A[5] & B[5])), .YS(S_5_5), .YC(C_5_5));
  PDKGENFAX1 U31819 (.A(S_4_7), .B(C_4_6), .C((A[5] & B[6])), .YS(S_5_6), .YC(C_5_6));
  PDKGENFAX1 U31820 (.A(S_4_8), .B(C_4_7), .C((A[5] & B[7])), .YS(S_5_7), .YC(C_5_7));
  PDKGENFAX1 U31821 (.A(S_4_9), .B(C_4_8), .C((A[5] & B[8])), .YS(S_5_8), .YC(C_5_8));
  PDKGENFAX1 U31822 (.A(S_4_10), .B(C_4_9), .C((A[5] & B[9])), .YS(S_5_9), .YC(C_5_9));
  PDKGENFAX1 U31823 (.A(S_4_11), .B(C_4_10), .C((A[5] & B[10])), .YS(S_5_10), .YC(C_5_10));
  assign S_5_11 = (A[5] & B[11]);
  PDKGENFAX1 U31825 (.A(S_5_1), .B(C_5_0), .C((A[6] & B[0])), .YS(S_6_0), .YC(C_6_0));
  PDKGENFAX1 U31826 (.A(S_5_2), .B(C_5_1), .C((A[6] & B[1])), .YS(S_6_1), .YC(C_6_1));
  PDKGENFAX1 U31827 (.A(S_5_3), .B(C_5_2), .C((A[6] & B[2])), .YS(S_6_2), .YC(C_6_2));
  PDKGENFAX1 U31828 (.A(S_5_4), .B(C_5_3), .C((A[6] & B[3])), .YS(S_6_3), .YC(C_6_3));
  PDKGENFAX1 U31829 (.A(S_5_5), .B(C_5_4), .C((A[6] & B[4])), .YS(S_6_4), .YC(C_6_4));
  PDKGENFAX1 U31830 (.A(S_5_6), .B(C_5_5), .C((A[6] & B[5])), .YS(S_6_5), .YC(C_6_5));
  PDKGENFAX1 U31831 (.A(S_5_7), .B(C_5_6), .C((A[6] & B[6])), .YS(S_6_6), .YC(C_6_6));
  PDKGENFAX1 U31832 (.A(S_5_8), .B(C_5_7), .C((A[6] & B[7])), .YS(S_6_7), .YC(C_6_7));
  PDKGENFAX1 U31833 (.A(S_5_9), .B(C_5_8), .C((A[6] & B[8])), .YS(S_6_8), .YC(C_6_8));
  PDKGENFAX1 U31834 (.A(S_5_10), .B(C_5_9), .C((A[6] & B[9])), .YS(S_6_9), .YC(C_6_9));
  PDKGENFAX1 U31835 (.A(S_5_11), .B(C_5_10), .C((A[6] & B[10])), .YS(S_6_10), .YC(C_6_10));
  assign S_6_11 = (A[6] & B[11]);
  PDKGENFAX1 U31837 (.A(S_6_1), .B(C_6_0), .C((A[7] & B[0])), .YS(S_7_0), .YC(C_7_0));
  PDKGENFAX1 U31838 (.A(S_6_2), .B(C_6_1), .C((A[7] & B[1])), .YS(S_7_1), .YC(C_7_1));
  PDKGENFAX1 U31839 (.A(S_6_3), .B(C_6_2), .C((A[7] & B[2])), .YS(S_7_2), .YC(C_7_2));
  PDKGENFAX1 U31840 (.A(S_6_4), .B(C_6_3), .C((A[7] & B[3])), .YS(S_7_3), .YC(C_7_3));
  PDKGENFAX1 U31841 (.A(S_6_5), .B(C_6_4), .C((A[7] & B[4])), .YS(S_7_4), .YC(C_7_4));
  PDKGENFAX1 U31842 (.A(S_6_6), .B(C_6_5), .C((A[7] & B[5])), .YS(S_7_5), .YC(C_7_5));
  PDKGENFAX1 U31843 (.A(S_6_7), .B(C_6_6), .C((A[7] & B[6])), .YS(S_7_6), .YC(C_7_6));
  PDKGENFAX1 U31844 (.A(S_6_8), .B(C_6_7), .C((A[7] & B[7])), .YS(S_7_7), .YC(C_7_7));
  PDKGENFAX1 U31845 (.A(S_6_9), .B(C_6_8), .C((A[7] & B[8])), .YS(S_7_8), .YC(C_7_8));
  PDKGENFAX1 U31846 (.A(S_6_10), .B(C_6_9), .C((A[7] & B[9])), .YS(S_7_9), .YC(C_7_9));
  PDKGENFAX1 U31847 (.A(S_6_11), .B(C_6_10), .C((A[7] & B[10])), .YS(S_7_10), .YC(C_7_10));
  assign S_7_11 = (A[7] & B[11]);
  PDKGENFAX1 U31849 (.A(S_7_1), .B(C_7_0), .C((A[8] & B[0])), .YS(S_8_0), .YC(C_8_0));
  PDKGENFAX1 U31850 (.A(S_7_2), .B(C_7_1), .C((A[8] & B[1])), .YS(S_8_1), .YC(C_8_1));
  PDKGENFAX1 U31851 (.A(S_7_3), .B(C_7_2), .C((A[8] & B[2])), .YS(S_8_2), .YC(C_8_2));
  PDKGENFAX1 U31852 (.A(S_7_4), .B(C_7_3), .C((A[8] & B[3])), .YS(S_8_3), .YC(C_8_3));
  PDKGENFAX1 U31853 (.A(S_7_5), .B(C_7_4), .C((A[8] & B[4])), .YS(S_8_4), .YC(C_8_4));
  PDKGENFAX1 U31854 (.A(S_7_6), .B(C_7_5), .C((A[8] & B[5])), .YS(S_8_5), .YC(C_8_5));
  PDKGENFAX1 U31855 (.A(S_7_7), .B(C_7_6), .C((A[8] & B[6])), .YS(S_8_6), .YC(C_8_6));
  PDKGENFAX1 U31856 (.A(S_7_8), .B(C_7_7), .C((A[8] & B[7])), .YS(S_8_7), .YC(C_8_7));
  PDKGENFAX1 U31857 (.A(S_7_9), .B(C_7_8), .C((A[8] & B[8])), .YS(S_8_8), .YC(C_8_8));
  PDKGENFAX1 U31858 (.A(S_7_10), .B(C_7_9), .C((A[8] & B[9])), .YS(S_8_9), .YC(C_8_9));
  PDKGENFAX1 U31859 (.A(S_7_11), .B(C_7_10), .C((A[8] & B[10])), .YS(S_8_10), .YC(C_8_10));
  assign S_8_11 = (A[8] & B[11]);
  PDKGENFAX1 U31861 (.A(S_8_1), .B(C_8_0), .C((A[9] & B[0])), .YS(S_9_0), .YC(C_9_0));
  PDKGENFAX1 U31862 (.A(S_8_2), .B(C_8_1), .C((A[9] & B[1])), .YS(S_9_1), .YC(C_9_1));
  PDKGENFAX1 U31863 (.A(S_8_3), .B(C_8_2), .C((A[9] & B[2])), .YS(S_9_2), .YC(C_9_2));
  PDKGENFAX1 U31864 (.A(S_8_4), .B(C_8_3), .C((A[9] & B[3])), .YS(S_9_3), .YC(C_9_3));
  PDKGENFAX1 U31865 (.A(S_8_5), .B(C_8_4), .C((A[9] & B[4])), .YS(S_9_4), .YC(C_9_4));
  PDKGENFAX1 U31866 (.A(S_8_6), .B(C_8_5), .C((A[9] & B[5])), .YS(S_9_5), .YC(C_9_5));
  PDKGENFAX1 U31867 (.A(S_8_7), .B(C_8_6), .C((A[9] & B[6])), .YS(S_9_6), .YC(C_9_6));
  PDKGENFAX1 U31868 (.A(S_8_8), .B(C_8_7), .C((A[9] & B[7])), .YS(S_9_7), .YC(C_9_7));
  PDKGENFAX1 U31869 (.A(S_8_9), .B(C_8_8), .C((A[9] & B[8])), .YS(S_9_8), .YC(C_9_8));
  PDKGENFAX1 U31870 (.A(S_8_10), .B(C_8_9), .C((A[9] & B[9])), .YS(S_9_9), .YC(C_9_9));
  PDKGENFAX1 U31871 (.A(S_8_11), .B(C_8_10), .C((A[9] & B[10])), .YS(S_9_10), .YC(C_9_10));
  assign S_9_11 = (A[9] & B[11]);
  PDKGENFAX1 U31873 (.A(S_9_1), .B(C_9_0), .C((A[10] & B[0])), .YS(S_10_0), .YC(C_10_0));
  PDKGENFAX1 U31874 (.A(S_9_2), .B(C_9_1), .C((A[10] & B[1])), .YS(S_10_1), .YC(C_10_1));
  PDKGENFAX1 U31875 (.A(S_9_3), .B(C_9_2), .C((A[10] & B[2])), .YS(S_10_2), .YC(C_10_2));
  PDKGENFAX1 U31876 (.A(S_9_4), .B(C_9_3), .C((A[10] & B[3])), .YS(S_10_3), .YC(C_10_3));
  PDKGENFAX1 U31877 (.A(S_9_5), .B(C_9_4), .C((A[10] & B[4])), .YS(S_10_4), .YC(C_10_4));
  PDKGENFAX1 U31878 (.A(S_9_6), .B(C_9_5), .C((A[10] & B[5])), .YS(S_10_5), .YC(C_10_5));
  PDKGENFAX1 U31879 (.A(S_9_7), .B(C_9_6), .C((A[10] & B[6])), .YS(S_10_6), .YC(C_10_6));
  PDKGENFAX1 U31880 (.A(S_9_8), .B(C_9_7), .C((A[10] & B[7])), .YS(S_10_7), .YC(C_10_7));
  PDKGENFAX1 U31881 (.A(S_9_9), .B(C_9_8), .C((A[10] & B[8])), .YS(S_10_8), .YC(C_10_8));
  PDKGENFAX1 U31882 (.A(S_9_10), .B(C_9_9), .C((A[10] & B[9])), .YS(S_10_9), .YC(C_10_9));
  PDKGENFAX1 U31883 (.A(S_9_11), .B(C_9_10), .C((A[10] & B[10])), .YS(S_10_10), .YC(C_10_10));
  assign S_10_11 = (A[10] & B[11]);
  PDKGENFAX1 U31885 (.A(S_10_1), .B(C_10_0), .C((A[11] & B[0])), .YS(S_11_0), .YC(C_11_0));
  PDKGENFAX1 U31886 (.A(S_10_2), .B(C_10_1), .C((A[11] & B[1])), .YS(S_11_1), .YC(C_11_1));
  PDKGENFAX1 U31887 (.A(S_10_3), .B(C_10_2), .C((A[11] & B[2])), .YS(S_11_2), .YC(C_11_2));
  PDKGENFAX1 U31888 (.A(S_10_4), .B(C_10_3), .C((A[11] & B[3])), .YS(S_11_3), .YC(C_11_3));
  PDKGENFAX1 U31889 (.A(S_10_5), .B(C_10_4), .C((A[11] & B[4])), .YS(S_11_4), .YC(C_11_4));
  PDKGENFAX1 U31890 (.A(S_10_6), .B(C_10_5), .C((A[11] & B[5])), .YS(S_11_5), .YC(C_11_5));
  PDKGENFAX1 U31891 (.A(S_10_7), .B(C_10_6), .C((A[11] & B[6])), .YS(S_11_6), .YC(C_11_6));
  PDKGENFAX1 U31892 (.A(S_10_8), .B(C_10_7), .C((A[11] & B[7])), .YS(S_11_7), .YC(C_11_7));
  PDKGENFAX1 U31893 (.A(S_10_9), .B(C_10_8), .C((A[11] & B[8])), .YS(S_11_8), .YC(C_11_8));
  PDKGENFAX1 U31894 (.A(S_10_10), .B(C_10_9), .C((A[11] & B[9])), .YS(S_11_9), .YC(C_11_9));
  PDKGENFAX1 U31895 (.A(S_10_11), .B(C_10_10), .C((A[11] & B[10])), .YS(S_11_10), .YC(C_11_10));
  assign S_11_11 = (A[11] & B[11]);
  PDKGENHAX1 U31897 (.A(S_11_1), .B(C_11_0), .YS(S_12_0), .YC(C_12_0));
  PDKGENFAX1 U31898 (.A(S_11_2), .B(C_12_0), .C(C_11_1), .YS(S_12_1), .YC(C_12_1));
  PDKGENFAX1 U31899 (.A(S_11_3), .B(C_12_1), .C(C_11_2), .YS(S_12_2), .YC(C_12_2));
  PDKGENFAX1 U31900 (.A(S_11_4), .B(C_12_2), .C(C_11_3), .YS(S_12_3), .YC(C_12_3));
  PDKGENFAX1 U31901 (.A(S_11_5), .B(C_12_3), .C(C_11_4), .YS(S_12_4), .YC(C_12_4));
  PDKGENFAX1 U31902 (.A(S_11_6), .B(C_12_4), .C(C_11_5), .YS(S_12_5), .YC(C_12_5));
  PDKGENFAX1 U31903 (.A(S_11_7), .B(C_12_5), .C(C_11_6), .YS(S_12_6), .YC(C_12_6));
  PDKGENFAX1 U31904 (.A(S_11_8), .B(C_12_6), .C(C_11_7), .YS(S_12_7), .YC(C_12_7));
  PDKGENFAX1 U31905 (.A(S_11_9), .B(C_12_7), .C(C_11_8), .YS(S_12_8), .YC(C_12_8));
  PDKGENFAX1 U31906 (.A(S_11_10), .B(C_12_8), .C(C_11_9), .YS(S_12_9), .YC(C_12_9));
  PDKGENFAX1 U31907 (.A(S_11_11), .B(C_12_9), .C(C_11_10), .YS(S_12_10), .YC(C_12_10));
  assign S_12_11 = C_12_10;
  assign O = {S_12_11,S_12_10,S_12_9,S_12_8,S_12_7,S_12_6,S_12_5,S_12_4,S_12_3,S_12_2,S_12_1,S_12_0,S_11_0,S_10_0,S_9_0,S_8_0,S_7_0,S_6_0,S_5_0,S_4_0,S_3_0,1'b0,1'b0,1'b0};

endmodule

/* mod */
module PDKGENHAX1( input A, input B, output YS, output YC );
    assign YS = A ^ B;
    assign YC = A & B;
endmodule
/* mod */
module PDKGENFAX1( input A, input B, input C, output YS, output YC );
    assign YS = (A ^ B) ^ C;
    assign YC = (A & B) | (B & C) | (A & C);
endmodule
