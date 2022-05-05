# 42-push-swap

The Push swap project is a simple algorithm project.
A "stack" with n amount of non-repeating random integers has to be sorted with the help of another "stack".
The goal is to find a solution with the lowest amount of operations possible.
Although they are called stacks in this project, they aren't limited to LIFO.
They are much similar to deques in the sense that by rotating both the top and bottom can be accessed.

https://user-images.githubusercontent.com/72362902/166651251-4310a0bf-09b2-4944-82c8-67ee403ca35a.mp4

### The following operations are possible:
- sa (swap a): Swap the first 2 elements at the top of stack a.
- sb (swap b): Swap the first 2 elements at the top of stack b.
- ss : sa and sb at the same time.
- pa (push a): Take the first element at the top of b and put it at the top of a.
- pb (push b): Take the first element at the top of a and put it at the top of b.
- ra (rotate a): Shift up all elements of stack a by 1. First  becomes  last.
- rb (rotate b): Shift up all elements of stack b by 1. First  becomes  last.
- rr : ra and rb at the same time.
- rra (reverse rotate a): Shift down all elements of stack a by 1. Last  becomes  first.
- rrb (reverse rotate b): Shift down all elements of stack b by 1. Last  becomes  first.
- rrr : rra and rrb at the same time.

### Visualizations:
- [32 Stack](https://bluegales.github.io/push-swap-pain/?&nbr=10,2,8,15,6,16,22,32,13,29,11,9,14,24,21,31,30,25,28,3,1,26,5,19,4,27,23,20,18,7,12,17&cmd=ddddkdkfkkekfkdkfkfkkfdkkkekdkddkekkekekkkkekekekekkekkekkejeejajaejddjejffjjejejajffejajeejjeejddjjjddjajdjjdjajdjdjjajjjddj)
- [100 Stack](https://bluegales.github.io/push-swap-pain/?&nbr=100,3,28,41,47,9,91,74,75,11,14,73,80,81,27,38,18,55,24,21,49,90,98,22,63,7,79,26,2,89,78,16,60,92,52,59,69,31,15,48,8,46,34,57,6,53,94,87,25,40,84,95,58,61,54,19,62,43,36,30,45,86,85,88,70,32,42,99,4,83,29,67,35,64,77,72,68,76,12,71,93,39,1,37,17,66,56,50,65,20,5,51,44,13,10,96,82,97,23,33&cmd=kkkkkkkkkekkekkkekkekkkkkekkkkekekkekekkkkkkekkekekkkekkkekkkekekekkkkekkkekkekkkkkkekekekkekkkkkkekkkkekkkekkekekkkkekkekkekekekkkekkkjjdjdjjdjjjjjdjjjjdjjdjjdjjdjdjdjjjjjjjdjjjdjjdjjdjjdjjdjdjdjjdjjjjdjjjdjjdjdjjdjjdjdjdjdjdjdjdjdjdjjdjjdjjdjdjdjdjdjdjdjdjdjjdjdjdjdjjdjdjdjjdjdjdjjdjdjdjdjjdkkekekekekekekekfddkfdkekkddkdkkkfdkkdkfkfkkfkfdkfdkekkfkekdkdkdkfkkekdddkdddkekfkddddkdkfddkekekekkfkkkkekfdkfdkdkkkkkkkkkekekekkekekekkekekkekkekkkkkekkekekekkekekekekkekekkekekekekkjjjdjjeejajdjfejjajaeeejffajejejjfdjejjfdjaeejeejjddjaeeejjeejddjaeeeejjejjddjejjddjaeeeejdjeejdjaeeejjjjffeeejjdjdjaeejdjejejfjjjddjjdjjjdjjajajddjjjddjjdjdjjajjjddjajjjddjajjjddjjjajjddjjdjjdjdjjdjjjajddj)
- [500 Stack](https://bluegales.github.io/push-swap-pain/?&nbr=56,241,420,139,431,306,149,232,469,436,262,110,161,111,54,192,178,136,172,194,485,484,398,239,387,402,408,441,220,11,419,173,15,312,288,261,158,260,22,58,480,315,75,429,252,116,393,143,80,331,326,243,425,175,416,162,421,188,494,371,474,198,495,52,363,411,189,339,78,334,183,171,226,338,364,409,89,263,168,305,69,27,266,204,234,493,359,164,153,17,201,487,32,125,276,83,463,296,466,6,399,342,120,128,44,465,196,412,236,360,403,135,355,47,267,372,250,324,138,445,343,240,488,417,41,101,376,124,59,311,426,155,391,121,31,268,435,218,459,258,170,468,467,318,176,219,106,299,197,483,449,327,448,253,482,444,30,456,180,73,407,394,146,123,414,53,48,91,354,453,165,349,365,433,133,375,460,384,103,181,255,88,490,454,366,229,461,107,380,328,313,325,496,127,422,230,270,184,385,238,113,428,401,264,367,486,35,498,303,66,67,40,60,85,237,415,319,114,26,50,222,310,447,395,345,203,329,160,39,370,358,141,65,163,147,278,10,19,404,37,179,405,25,341,322,207,134,386,332,442,390,231,174,118,397,440,43,152,285,132,20,251,199,72,265,208,353,18,290,330,235,271,491,273,191,293,84,361,489,117,277,256,16,221,209,410,321,38,413,61,126,347,63,148,119,301,248,291,269,5,481,462,292,211,259,186,287,195,446,202,233,8,477,225,34,3,142,95,57,473,99,373,90,377,87,93,475,382,246,215,499,418,150,337,289,109,368,439,193,223,182,392,281,346,316,108,145,247,452,166,4,257,51,284,244,7,14,388,97,300,317,423,340,457,115,500,151,304,314,205,13,137,434,458,479,100,336,102,55,187,298,185,167,33,21,352,92,96,29,104,323,286,381,450,282,98,476,131,383,112,350,23,24,70,228,320,333,389,335,492,424,348,130,36,307,12,351,344,275,82,274,28,427,432,105,154,356,42,122,214,210,140,49,212,472,200,76,400,129,430,77,443,1,309,64,62,79,369,159,9,81,464,374,272,46,224,497,74,156,86,254,2,217,94,177,294,45,213,297,280,227,471,302,478,378,455,245,396,279,144,169,295,242,216,438,206,283,157,470,362,437,357,406,68,379,308,190,71,249,451&cmd=dkkddddkekekkkddkfkekdddkdkdkkfkekkddkdkkekfddkkdkkkekfkkdkkdddkfdkkfkddkddkfddddkddkfdkddkdkdkekddkekdkfkkddkddkekdddkkekddkdkkfdkekdkfdkddkkkekdkekkkfdkkekfkkfdkekkdkfkfkekdkekekfddkfkdddkkdkekdkfdddkdkddkfdkekddddkfkddkekdkfkdkekddddddddddkfkfkfdkddkekkddkkekekfdkfkdkekekkddkfkfkkekkdkekkddkfkddddkfdkekfkkekddkfkdddkkkekfdkddkfkfddkekddddkdddkfkkfkkddddkfddkkkfddkkekdkdkkekekkfdddddkkfdddkfdddkekkkkekekdddkfkdddkfkkekfdkkekfkekdkkekfdkfkdddddkfdkfkfkdkdkfkdkkfdkfdddddddkekkdddddkdkekddkkekdddkkdkekfdkkekekekekddkfkekddkddkekekkkekkekkekekfkekekfddkdkkkekkekekkkkkkekkekkkkkkekekekekkekekkkekekekkkkkkkkekkkkekekkkekekkkkkekkekkekkkekkekkekkekkkkekekekkekkkkekekekkekkekkekkekekekekekkekekekkekkkekkkkkkkkekkekkekekkkkkekkkekekekekkekkekkkkekekekkekekkkekekkkekkekekkekekekkekekekekekkekekkekekkkekkkkekkekekkekekekekekkkekkekekekkkkkkkkkkekekkekkekkekekkekkekekekekekkekkekekkkekekekekekekkekkkekkekekkekkkekkkekkekkkkekekkekekkkekekeejejfeeeejfjejjeeejjjeejfejdjfjejjdjfjeeeeeeeejeeejjejjdjjjeeejdjfjejdjfeejjdjdjfjfjjfjdjfejjeeeejdjdjdjeeeeejdjjdjjfjfjfjeejdjfjfjjejdjjfjeejjeejfjdjdjdjjfejdjfeejjejdjfejeeeejfejdjejeejeeeejjejeeeejdjjeeeejdjfeejeeeejdjjdjfjfejdjjjjfjjjeejfjjdjeeejfjjjeeejejjjjdjfjejfjdjfjdjjdjjfjdjdjejjeeejdjjejjdjfejdjfjejfeeeeejjjejejjjdjdjejjjdjejejjdjeejdjdjjdjdjjdjdjdjdjfeejjjfeejdjfejeejdjejfjfeejeejdjdjfejeeejdjeeejjfeejjfeeeejejejeejejjjdjdjfeejejfejdjjejjfjdjdjejjeejdjfeeejeeejejdjfjejfejjejdjeejeejdjeejdjfejfjjjfeejfeeeejjdjdjdjdjjdjjejdjfeeeejfeeejjjfjfejejdjjfeejeejeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeejjjjjdjdjdjjdjdjdjdjjdjjjjdjdjdjdjdjdjjdjdjjjjdjjdjdjjdjdjdjjjdjdjdjdjjjjjjjjjdjjjjdjdjdjjjjdjdjjjdjdjdjdjdjdjjjdjjjjjjjdjjdjdjjjdjdjdjdjjdjdjdjjjjdjjjjjdjjdjjdjdjjjdjjdjdjjdjjdjjjdjdjdjdjjjdjjdjjdjdjjdjjdjjdjjdjdjjjjdjjjjdjdjjjjdjjdjjdjdjjjdjjjdjjdjjdjjdjjjdjdjdjdjdjdjjdjjjdjjjjjdjdjdjdjjjdjjdjdjdjdjdjdjdjjdjjjdjjdjjjjdjdjdjdjdjdjjjjdjdjjdjjjdjjjjdjdjdjjjjjdjdjdjjdkkfddkfddddkekfkfdddkfddkekdkkfkdkkddkkdkfdkekfdkfkfdkfdkfkdkkekfdddkekekkekkfkdkekdddkekddddddkkkddkekdkkfkdddkekkfdddddkekfdkekkfkkkddkdddkfdkekkfkkekfdddkfkfkkkddkkfdkekkkekdddddddkekkddkfkdkekkekddkekfddkkekkekfddddkddkfkekfkdkddddkekekkkkfddkfkdkdkkekfkfkfdddkkekkddkdkekdkkkddddkekekdddddkkekekfdkfkddkfkkdkekkkekekekekkdkddkfddddkekfdkkfdkddddkddkekekkekddddkddkekdkkddkdkekekfkfdkddkdddkekfkekekkddkdkkddkfddkfdkekekdkddkekfddkdkkfdkekekekdkdkekkdkekddkddddkdddkekkfddkddkdkekfddddkdkekkekkekkfkdkfkekkddkdkdkkekekfkddkekekfkddkdkfkfdkkekfkddkfkddkkfdkfkkkkekekddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddkekkekekekkekkkkekkkekkekkekekekkekkekkkkekkekkekekekkkekkekkkekkekekkekkkkkekekkekekkekekekkkekkkkekekkekekkekkekkekkkkekkekekekkkkkekkekekekekekkekkekkekekkkkekekkkkekkekekekkkkekekekkekkkekkekekkkekkkkekekkkekekekekkekkkkkkekekekkekekkekkekkkekekekkekkkekkekkkkekkekekekkekkkekkekekkkekekkkekekkekkkkekkekekekekekekkkkekkekkekkekkkkkekekekkkekekkekekkkkekkekekekekekkekekkekjjajddjejfjejjfejejajejffjjfejfjjejfeejdjjjajfdjaeeeejdjejdjeeeejjfjajfeejjejddjaejeeejjajffjjaejfjfeeejfjjdjejfjeejdjajejejdjfeejejeejjddjejffjjaejfjjfejaeeejfjejdjajeeejfdjjjjfjejfeejjjddjeeejeejddjjeeeejjaeejddjaeejejjejffejjajddjejejajddjeeejjeejdjfejejddjejeeejejejfjfjfjjfejajeeejdjjfeeejjejddjajfejejdjeejejjaeejfdajjaejddjeeeejdjdjjaeejjfeejdjaejjaejaejffaejjdjfjaeejjffeejjajeeejejajddajjaeeeejajffjejajjfdjjaeeejaejfdjeeejddjjjejdjaeejfjjfeeejdjeeejejdjdjaeejjejfdjeejdjejjfjeeejajejffeejjdjjdjeejajajffajdjeeejfjejfjfjejajeeejfjajdjeeejaejjffjejddjejajjfjaejfeeejjaeejajddjfejfejjejejffjjaeeeejjdjdjjjjdjdjdjjdjjdjdjjajdjjajdjjdjdjjdjjajdjdjjdjjjajddjajdjdjjajjdjjdjjajddjajjajajddjjjdjdjdjdjjajjjdjdjjjdjdjdjjdjajdjjdjajjdjajdjjdjjdjjajddjjjddjjjjdjdjjjjddjajjjddjjjjddjajdjjdjjdjjajdjjjajddjjajdjdjdjdjjjjajddjajdjjajdjdjjdjajjjddjajdjjdjajjdjjdjdjjdjjjddjjjdjjajdjjjdjdjjdjdjajdjjjdjjajajddjjjdjdjjddjjjjddjjjdjdjjajjajddjajjjdjdjjajajddjjdjdjajdjjjdjjajddjajdjjdjajjajjddjjdjdjjjdjdjjjddjjjdjjdjjdjjjdjjjjdd)

It is recommended to also have a look at the links at the bottom, since they show the sorting of sorted stacks,
which makes it a lot clearer of what the algorythm is doing.

## Algorithm

Because of the uniqueness of the task, conventional algorithms were hardly optimal.
Most conventional sorting algorithms focus on fast computation time and have access to all the data.
Computation time is of no concern in this project, and "looking" for specific numbers by rotating the stack is a very expensive operation.
<br>Depending on the top number in A **one** of the following operation is done:

|%    | Operation            | Result      |
|-----| ---------------------|-------------|
| 25% | Push B               | top of B    |
| 25% | Push B + Rotate B    | bottom of B |
| 50% | Rotate A             | bottom of A |

Once this has been done for all the Numbers in A. The 50% remaining numbers in A will do the same operation again but this time without
the option to rotate A. This splits the numbers into 4 Groups.
These groups get treated as a single number for the rotation of the operation.
<br>
Example:
- 128 Numbers in A
- 32 Groups in B
- 8 Groups in A
- 2 Groups in B
- 1 Group in A

This results in a single group in A. Which means that if the specific number always got pushed into the correct group it will result in a sorted stack.
Instead of calculating the correct group by hand, the whole operation was reversed.<br>
A very intuitive approach would be to choose the groups by number size, for example for 100 numbers first splitting them into group 1-25, 26-50, 51-75, 76-100.
The problem is that this would result in groups being in the wrong order later on. Which would always require rotations over groups to get the
correct location to the top.<br>

Instead, the algorithm starts with a sorted stack, doing exactly those operations and saving the groups of the numbers after doing it.
Visualizations can be found here:<br>
- [32 Stack](https://bluegales.github.io/push-swap-pain/?&nbr=1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32&cmd=ddkkekkddddkekekkddddkkkekfdddkkkekekekekekekkkekekkkkkekekkeejjjjeeeejjddjjeeeejjajdjfeeeeejjajdjdjjddjjjjddjjjjajdjdjdjdjja)
- [512 Stack](https://bluegales.github.io/push-swap-pain/?&nbr=1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255,256,257,258,259,260,261,262,263,264,265,266,267,268,269,270,271,272,273,274,275,276,277,278,279,280,281,282,283,284,285,286,287,288,289,290,291,292,293,294,295,296,297,298,299,300,301,302,303,304,305,306,307,308,309,310,311,312,313,314,315,316,317,318,319,320,321,322,323,324,325,326,327,328,329,330,331,332,333,334,335,336,337,338,339,340,341,342,343,344,345,346,347,348,349,350,351,352,353,354,355,356,357,358,359,360,361,362,363,364,365,366,367,368,369,370,371,372,373,374,375,376,377,378,379,380,381,382,383,384,385,386,387,388,389,390,391,392,393,394,395,396,397,398,399,400,401,402,403,404,405,406,407,408,409,410,411,412,413,414,415,416,417,418,419,420,421,422,423,424,425,426,427,428,429,430,431,432,433,434,435,436,437,438,439,440,441,442,443,444,445,446,447,448,449,450,451,452,453,454,455,456,457,458,459,460,461,462,463,464,465,466,467,468,469,470,471,472,473,474,475,476,477,478,479,480,481,482,483,484,485,486,487,488,489,490,491,492,493,494,495,496,497,498,499,500,501,502,503,504,505,506,507,508,509,510,511,512&cmd=kkddddddkekekkddddkkkekfdddddkkkekekekekekekkddddddkekekkddddkkkekfdddddkkkekekekekkddddddkekekkddddkkkekfdddddkkkekekekekekekkddddddkekekkddddkkkekfdddddkkkkddddddkekekkddddkkkekfdddddkkkekekekekekekkddddddkekekkddddkkkekfdddddkkkekekekekkddddddkekekkddddkkkekfdddddkkkekekekekekekkddddddkekekkddddkkkekfdddddkkkkddddddkekekkddddkkkekfdddddkkkekekekekekekkddddddkekekkddddkkkekfdddddkkkekekekekkddddddkekekkddddkkkekfdddddkkkekekekekekekkddddddkekekkddddkkkekfdddddkkkkddddddkekekkddddkkkekfdddddkkkekekekekekekkddddddkekekkddddkkkekfdddddkkkekekekekkddddddkekekkddddkkkekfdddddkkkekekekekekekkddddddkekekkddddkkkekfdddddkkkkkekekekekkkkkekekekekkkkkekekekekkkkkekekekekkkkkekekekekkkkkekekekekkkkkekekekekkkkkekekekekkkkkekekekekkkkkekekekekkkkkekekekekkkkkekekekekkkkkekekekekkkkkekekekekkkkkekekekekkkkkekekekekkkkkekekekekkkkkekekekekkkkkekekekekkkkkekekekekkkkkekekekekkkkkekekekekkkkkekekekekkkkkekekekekkkkkekekekekkkkkekekekekkkkkekekekekkkkkekekekekkkkkekekekekkkkkekekekekkkkkekekekekkkkkekekekekkeejjdjjeeeejdjdjjeeeejjjdjfeeejjjdjfeeejdjdjjeeeejdjdjjeeeejjjdjfeeejjjdjfeeejdjdjjeeeejdjdjjeeeejjjdjfeeejjjdjfeeejdjdjjeeeejdjdjjeeeejjjdjfeeejjjdjfeeejdjdjjeeeejdjdjjeeeejjjdjfeeejjjdjfeeejdjdjjeeeejdjdjjeeeejjjdjfeeejjjdjfeeejdjdjjeeeejdjdjjeeeejjjdjfeeejjjdjfeeejdjdjjeeeejdjdjjeeeejjjdjfeeejjjdjfejdjdjjeeeeeejdjdjjeeeejjjdjfeeeeejjjdjdjdjdjjeeeeeejdjdjjeeeejjjdjfeeeeejjjdjdjdjdjjeeeeeejdjdjjeeeejjjdjfeeeeejjjdjdjdjdjjeeeeeejdjdjjeeeejjjdjfeeeeejjjdjfejdjdjjeeeejdjdjjeeeejjjdjfeeejjjdjfeeejdjdjjeeeejdjdjjeeeejjjdjfeeejjjdjfeeejdjdjjeeeejdjdjjeeeejjjdjfeeejjjdjfeeejdjdjjeeeejdjdjjeeeejjjdjfeeejjjdjdjdjfeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeejdjdjjjdjdjjjjjdjdjjjdjdjdjdjjjdjdjjjjjdjdjjjdjdjdjdjjjdjdjjjjjdjdjjjdjdjdjdjjjdjdjjjjjdjdjjjdjdjjjdjdjjjjjdjdjjjdjdjdjdjjjdjdjjjjjdjdjjjdjdjdjdjjjdjdjjjjjdjdjjjdjdjdjdjjjdjdjjjjjdjdjjjdjdjdjdjjjdjdjjjjjdjdjjjdjdjdjdjjjdjdjjjjjdjdjjjdjdjdjdjjjdjdjjjjjdjdjjjdjdjdjdjjjdjdjjjjjdjdjjjdjdjjjdjdjdjdjjjjjdjdjdjdjjjjjdjdjdjdjjjjjdjdjdjdjjjjjdjdjdjdjjjjjdjdjdjdjjjjjdjdjdjdjjjjjdjdjdjdjjddkkekkddddkekekkddddkkkekfdddkkkekfdddkekekkddddkekekkddddkkkekfdddkkkekfdddkekekkddddkekekkddddkkkekfdddkkkekfdddkekekkddddkekekkddddkkkekfdddkkkekfdddkekekkddddkekekkddddkkkekfdddkkkekfdddkekekkddddkekekkddddkkkekfdddkkkekfdddkekekkddddkekekkddddkkkekfdddkkkekfdddkekekkddddkekekkddddkkkekfdddkkkekfdddkekekkddddkekekkddddkkkekfdddkkkekfdddkekekkddddkekekkddddkkkekfdddkkkekfdddkekekkddddkekekkddddkkkekfdddkkkekfdddkekekkddddkekekkddddkkkekfdddkkkekfdddddkekekkddddkekekkddddkkkekfdddkkkekfdkekekkddddkekekkddddkkkekfdddkkkekfdddkekekkddddkekekkddddkkkekfdddkkkekfdddkekekkddddkekekkddddkkkekfdddkkkekekekfdddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddkekekkkekekkkkkekekkkekekkkekekkkkkekekkkekekekekkkekekkkkkekekkkekekekekkkekekkkkkekekkkekekekekkkekekkkkkekekkkekekekekkkekekkkkkekekkkekekekekkkekekkkkkekekkkekekekekkkekekkkkkekekkkekekekekkkekekkkkkekekkkekekekekkkekekkkkkekekkkekekekekkkekekkkkkekekkkekekekekkkekekkkkkekekkkekekekekkkekekkkkkekekkkekekekekekekkkekekkkkkekekkkekekkkekekkkkkekekkkekekekekkkekekkkkkekekkkekeeejjdjdjfeeejjajdjfeeejjddjjeeeejjddjjeeeejjddjjeeeejjajdjfeeejjajdjfeeejjddjjeeeejjddjjeeeejjajdjfeeejjajdjfeeejjajdjfeeejjddjjeeeejjddjjeeeejjajdjfeeejjddjjeeeejjddjjeeeejjajdjfeeejjajdjfeeejjddjjeeeejjddjjeeeejjddjjeeeejjajdjfeeejjajdjfeeejjddjjeeeejjddjjeeeejjajdjfeeejjajdjfeeejjajdjfeeejjddjjeeeejjddjjeeeejjajdjfeeejjddjjeeeejjajdjfeeejjajdjfeeejjddjjeeeejjddjjeeeejjddjjeeeejjajdjfeeejjajdjfeeejjddjjeeeejjddjjeeeejjajdjfeeejjajdjfeeejjajdjfeeejjddjjeeeejjddjjeeeejjajdjfeeeeejjajdjfejjddjjeeeejjajdjfeeejjajdjfeeejjddjjeeeejjddjjeeeejjddjjeeeejjajdjfeeejjajdjfeeejjddjjeeeejjddjjeeeejjajdjfeeejjajdjfeeeeejjajdjfejjddjjeeeejjddjjeejjajdjdjjajdjdjjddjjjjddjjjjddjjjjajdjdjjajdjdjjddjjjjddjjjjajdjdjjajdjdjjajdjdjjddjjjjddjjjjajdjdjjddjjjjddjjjjajdjdjjajdjdjjddjjjjddjjjjddjjjjajdjdjjajdjdjjddjjjjddjjjjajdjdjjajdjdjjajdjdjjddjjjjddjjjjajdjdjjddjjjjajdjdjjajdjdjjddjjjjddjjjjddjjjjajdjdjjajdjdjjddjjjjddjjjjajdjdjjajdjdjjajdjdjjddjjjjddjjjjajdjdjdjdjjajjddjjjjajdjdjjajdjdjjddjjjjddjjjjddjjjjajdjdjjajdjdjjddjjjjddjjjjajdjdjjajdjdjdjdjjajjddjjjjddjj)

A few optimizations have been used, for example only splitting into 2 groups when needed and sorting the last group of 8 numbers manually.

## Performance

![Screenshot 2022-05-04 12 15 13](https://user-images.githubusercontent.com/72362902/166663157-f1f321f3-9f3f-400c-bb12-fb93d217a1ac.png)

Both n and Operations are in k<br>
For "low" amount of numbers the amount of operations is roughly n * 13, however without the optimizations the amount of operations is:<br>
(log(n) / log(4)) * 1.5n<br>
The big O notation should be O(n log n)<br>
During the evaluation, only very small stacks are tested.<br>
100 will result in something very close to 700 operations.<br>
500 is something around 4000 operations<br>
Since there are still minor bugs in my implementation, it will result in slightly higher numbers.
