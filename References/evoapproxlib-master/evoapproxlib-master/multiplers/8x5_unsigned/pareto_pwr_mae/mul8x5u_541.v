/***
* This code is a part of EvoApproxLib library (ehw.fit.vutbr.cz/approxlib) distributed under The MIT License.
* When used, please cite the following article(s): V. Mrazek, L. Sekanina, Z. Vasicek "Libraries of Approximate Circuits: Automated Design and Application in CNN Accelerators" IEEE Journal on Emerging and Selected Topics in Circuits and Systems, Vol 10, No 4, 2020 
* This file contains a circuit from a sub-set of pareto optimal circuits with respect to the pwr and mae parameters
***/
// MAE% = 24.12 %
// MAE = 1976 
// WCE% = 96.50 %
// WCE = 7905 
// WCRE% = 100.00 %
// EP% = 96.50 %
// MRE% = 100.00 %
// MSE = 70690.462e2 
// PDK45_PWR = 0.000 mW
// PDK45_AREA = 0.0 um2
// PDK45_DELAY = 0.00 ns

module mul8x5u_541 (
    A,
    B,
    O
);

input [7:0] A;
input [4:0] B;
output [12:0] O;
assign O[12] = 1'b0;
assign O[11] = 1'b0;
assign O[10] = 1'b0;
assign O[9] = 1'b0;
assign O[8] = 1'b0;
assign O[7] = 1'b0;
assign O[6] = 1'b0;
assign O[5] = 1'b0;
assign O[4] = 1'b0;
assign O[3] = 1'b0;
assign O[2] = 1'b0;
assign O[1] = 1'b0;
assign O[0] = 1'b0;

endmodule


