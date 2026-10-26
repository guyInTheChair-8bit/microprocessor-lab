module fulladd(
    input wire a,
    input wire b,
    input wire cin,
    output wire s,
    output wire c
);
    assign s = a ^ b ^ cin;
    assign c = (a & b) | (b & cin) | (cin & a);
endmodule
