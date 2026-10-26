module dff_with_reset(q, q_bar, d, rst, clk);

input d, rst, clk;
output q, q_bar;
reg q;

assign q_bar = ~q;

always @ (posedge clk) begin
    if (rst)
        q <= 1'b0;
    else
        q <= d;
end

endmodule
