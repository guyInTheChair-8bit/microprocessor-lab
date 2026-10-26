`timescale 1ns/1ps

module half_add_tb;
    reg a;
    reg b;
    wire s;
    wire c;

    halfadd dut(.s(s), .c(c), .a(a), .b(b));

    initial begin
        $monitor("t=%0t a=%b b=%b s=%b c=%b", $time, a, b, s, c);
        a = 0; b = 0; #10;
        a = 0; b = 1; #10;
        a = 1; b = 0; #10;
        a = 1; b = 1; #10;
        $finish;
    end
endmodule
