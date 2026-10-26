`timescale 1ns/1ps

module ripple_tb;
    reg [3:0] a;
    reg [3:0] b;
    reg cin;
    wire [3:0] s;
    wire c;

    ripple dut(.a(a), .b(b), .cin(cin), .s(s), .c(c));

    initial begin
        $monitor("t=%0t a=%b b=%b cin=%b s=%b c=%b", $time, a, b, cin, s, c);
        a = 4'b1001;
        b = 4'b0110;
        cin = 1'b0;
        #10;
        $finish;
    end
endmodule
