//
// Created by Nikhil on 31-05-2021.
//

#include "CountingBits.h"
#include <string>
#include <bitset>
#include <algorithm>

std::vector<int> CountingBits::countBits(int n) {
    std::vector<int> solution ;
    for(int i = 0 ; i <= n ; ++i){
        std::string temp = std::bitset<32>(i).to_string();
        solution.push_back(std::count(temp.begin(),temp.end(), '1'));
    }
    return solution;

    // dp solution
    /*std::vector<int> table(10000);
    table[0] = 0 ;
    table [1] = 1;
    table [2] = 1;
    for(int i = 3 ; i <= n ; ++i){
        if(i %2 == 0 ){
            table[i] = table[i/2];
        }else{
            table[i] = table[i/2] +1;
        }
    }
    for(int i = 0 ; i <= n ; ++i){
        solution.push_back(table[i]);
    }
    return  solution;*/
}

/*
 * 159
199
123
113
38
0
114
48
84
145
123
184
86
49
72
184
49
133
61
45
185
104
89
81
98
118
176
153
116
83
19
23
170
30
72
91
154
141
101
47
128
129
145
64
106
82
146
119
177
30
173
15
105
187
116
189
3
89
196
122
102
108
147
25
7
184
153
110
167
32
144
63
139
145
92
177
80
106
154
42
93
44
152
156
37
118
140
73
106
20
10
152
44
199
86
134
199
112
46
179

 Run config

 while (curRun != noOfTimesToRun) {
        auto start = std::chrono::high_resolution_clock::now();
        int n = getRandomNumber(0, 200);
        std::cout << n << std::endl;
        CountingBits countingBits = CountingBits();
        auto ans = countingBits.countBits(0);
        for(auto x: ans){
            std::cout<<x<< "  ";
        }
//        std::cout << "" << std::endl;
if (verbrose) {
auto stop = std::chrono::high_resolution_clock::now();
auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
std::cout << "Time taken by function: "
<< duration.count() << " nanosecond\n" << std::endl;
}
curRun++;
}
 */
