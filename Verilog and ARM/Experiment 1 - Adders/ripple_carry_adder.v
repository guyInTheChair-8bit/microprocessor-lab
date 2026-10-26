module ripple(
    input wire [3:0] a,
    input wire [3:0] b,
    input wire cin,
    output wire [3:0] s,
    output wire c
);
    wire c1;
    wire c2;
    wire c3;

    fulladd f0(.a(a[0]), .b(b[0]), .cin(cin), .s(s[0]), .c(c1));
    fulladd f1(.a(a[1]), .b(b[1]), .cin(c1), .s(s[1]), .c(c2));
    fulladd f2(.a(a[2]), .b(b[2]), .cin(c2), .s(s[2]), .c(c3));
    fulladd f3(.a(a[3]), .b(b[3]), .cin(c3), .s(s[3]), .c(c));
endmodule
