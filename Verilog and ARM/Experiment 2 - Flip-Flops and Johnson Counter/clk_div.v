module clk_divider(clk_out, clk_in);

input clk_in;
output reg clk_out = 1'b1;

reg [31:0] count = 32'b0;
localparam THRESHOLD = 49_999_999;

always @ (posedge clk_in) begin
    if (count == THRESHOLD) begin
        count <= 32'b0;
        clk_out <= ~clk_out;
    end else
        count <= count + 1;
end

endmodule
