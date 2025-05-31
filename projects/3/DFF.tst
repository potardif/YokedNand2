load DFF.hdl,
output-file DFF.out,
compare-to DFF.cmp,
output-list time%S1.4.1 in out;

eval,
output;

set in 1,
tick,
output;

tock,
output;

set in 0,
eval,
output;

tick,
output;

tock,
output;
