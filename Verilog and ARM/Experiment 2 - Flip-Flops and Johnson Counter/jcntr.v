module jcntr(seven_seg, clk_in, rst, digit);

input clk_in, rst;
output [7:0] seven_seg;
output [3:0] digit = 4'b0001;

wire [2:0] cntr;

wire q0, q1, q2;
wire q0_bar, q1_bar, q2_bar;
wire out_clk;

assign cntr = {q2, q1, q0};

clk_divider cd0(out_clk, clk_in);

dff d2(q2, q2_bar, q0_bar, rst, out_clk);
dff d1(q1, q1_bar, q2, rst, out_clk);
dff d0(q0, q0_bar, q1, rst, out_clk);  

decoder dec0(cntr, seven_seg);

endmodule
