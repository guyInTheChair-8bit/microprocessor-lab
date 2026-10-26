module johnson_3bit(q, clk_in, rst);

output [2:0] q;
input clk_in, rst;

wire q2, q1, q0;
wire qbar2, qbar1, qbar0;
wire clk;

assign clk = clk_in;
assign q = {q2, q1, q0};

dflipflop_with_reset d2(q2, qbar2, qbar0, clk, rst);
dflipflop_with_reset d1(q1, qbar1, q2, clk, rst);
dflipflop_with_reset d2(q0, qbar0, q1, clk, rst);

endmodule

module johnson_3bit_tb();
    
wire [3:0] q;
reg clk_in, rst;

johnson_3bit j1(q, clk_in, rst);
always #10 clk_in = ~clk_in;

initial begin

    clk_in = 1'b0;
    rst = 1'b0;
    #80 $finish;
end

initial $monitor("%b%b%b", q[2], q[1], q[0]);

endmodule








