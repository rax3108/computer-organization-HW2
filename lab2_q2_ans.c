"addi t1, x0, 8\n\t"
"vsetvli t0, t1, e16, ta, ma\n\t"
"vle16.v v1, (%[p_x])\n\t"

"Loop:\n\t"
"lh t2, 0(%[p_x])\n\t"
"vadd.vx v2, v1, t2\n\t"
"vmseq.vx v3, v2, %[target]\n\t"
"vse16.v v3, (%[p_tmp1])\n\t"
"lh t3, 0(%[p_tmp1])\n\t"
"bnez t3, True\n\t"
"addi %[p_x], %[p_x], 2\n\t"
"addi t1, t1, -1\n\t"
"bnez t1, Loop\n\t"
"j False\n\t"

"True:\n\t"
"addi %[flag], x0, 1\n\t"
"False:\n\t"
