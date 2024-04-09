## Building & Gadgets Puzzle - 1

A firm wants to determine the `highest floor of its n-story` headquarters from which a gadget can fall without breaking.

The firm has two identical gadgets to experiment with. If one of them gets broken, it cannot be repaired, and the experiment will have to be completed with the remaining gadget.

Design an algorithm in the best efficiency class you can to solve this problem.

## Solution

This solution uses Binary search algorithm design technique.

### 1st Gadget Breaks on n/2 <sup>th</sup> floor.

- You could throw the 1<sup>st</sup> gadget from the `n/2th` floor, if the gadget breaks you should sequentially start throwing the 2<sup>nd</sup> gadget from the 1st floor upto the floor untill the 2<sup>nd</sup> Gadget breaks.

- The floor on which the 2nd gadget breaks is the `highest floor of his n-story headquaters` from where this gadget can survive.

### 1st Gadget doesn't break on n/2 <sup>th</sup> floor.

- You could throw the 1<sup>st</sup> gadget from the `n/2th` floor, if the gadget `doesn't` breaks you should sequentially start throwing the 2<sup>nd</sup> gadget from the `n/2th + 1` floor upto nth floor untill the 2<sup>nd</sup> Gadget breaks.

- The floor on which the 2nd gadget breaks is the `highest floor of his n-story headquaters` from where this gadget can survive, if the gadget doesn't break it is safe to say that the n<sup>th</sup> floor is the highest floor.
