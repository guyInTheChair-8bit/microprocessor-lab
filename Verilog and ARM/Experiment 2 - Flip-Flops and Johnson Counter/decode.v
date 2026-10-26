module decoder(cntr, seven_seg);

input [2:0] cntr;
output [7:0] seven_seg;
reg [6:0] val;

assign seven_seg = {1'b1, ~val};

always @ (cntr) begin
    case (cntr)
        3'b000: val = 7'b0111111;
        3'b100: val = 7'b0000110;
        3'b110: val = 7'b1011111;
        3'b111: val = 7'b0000111;
        3'b011: val = 7'b1001111;         
        3'b001: val = 7'b0000110; 
        
        default: val = 7'b0000000; 
    endcase
end

endmodule
