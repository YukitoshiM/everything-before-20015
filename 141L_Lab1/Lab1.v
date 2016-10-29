`timescale 1ns / 1ps
/*
 * CSE141L Lab1: Tools of the Trade
 * University of California, San Diego
 * 
 * Written by Donghwan Jeon, 4/1/2007
 * Modified by Vikram Bhatt, 30/3/2011
 * Modified by Nikolaos Strikos, 4/8/2012
 */

module Lab1#(parameter W = 8)
(
 input clk,
 input [W-1:0] a_i, b_i,
 output [W:0] sum_o,
 output is_odd_o
);

   logic [W-1:0] a_r, b_r;
   logic [W:0]   sum_r;
   logic         is_odd_r;
   logic [W:0]  sum_next;

   assign sum_next = a_r + b_r;
   assign sum_o = sum_r;
   assign is_odd_o= is_odd_r;

   always_ff @(posedge clk) //enable SystemVerilog to make always_ff work!
     begin
        a_r <= a_i;
        b_r <= b_i;
        sum_r <= sum_next;
        is_odd_r <= (sum_o[0]) ? 1'b1: 1'b0;
     end

endmodule