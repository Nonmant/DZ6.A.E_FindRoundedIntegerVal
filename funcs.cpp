//https://contest.yandex.ru/contest/27844/problems/E/

#include "funcs.h"
#include <bits/stdc++.h>

//! @brief Index of last true. If everything is false return 0
template<typename F1, typename F2>
unsigned long long binSearchLowerBound(F1 valueGenerate,
                           F2 valueCheck,
                                       unsigned long long left, unsigned long long right){
    while (left<right){
        unsigned long long cur = (left + right + 1)/2;
        auto value = valueGenerate(cur);
        if(valueCheck(value)){
            left = cur;
        } else {
            right = cur-1;
        }
    }
    return right;
}

unsigned long long mark(
        unsigned long long a,
        unsigned long long b,
        unsigned long long c,
        unsigned long long d
        ){
    auto dividend = a*2 + b*3 + c*4 + d*5;
    auto divisor = a + b + c + d;
    auto ceilPart = dividend/divisor;
    auto fraqDividend = dividend - ceilPart*divisor;

    auto ans = ceilPart;
    if(2*fraqDividend >= divisor)
        ++ans;
    return ans;
}

void parseFile(std::istream & input, std::ostream & output){

    unsigned long long a, b, c;
    input >> a >> b >> c;
    unsigned long long left = 0, right = a+b;
    auto d = binSearchLowerBound(
            [](unsigned long long d){return d;},
                [&a, &b, &c](unsigned long long d){
                    return mark(a,b,c,d)<=4;
                },
                    left, right);

    output << d;
}
