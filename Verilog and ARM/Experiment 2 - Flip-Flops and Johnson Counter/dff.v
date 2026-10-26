module dff(q, q_bar, d, clk);

output q, q_bar;
input d, clk;
reg q;

assign q_bar = ~q;

always @ (posedge clk) begin
    q <= d;
end

endmodule
