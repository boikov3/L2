//Copyright 2019 <boikov3>
#ifndef INCLUDE_RUNNER_HPP_
#define INCLUDE_RUNNER_HPP_
#include <vector>
#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>
#include <array>
using std::vector;
class Runner{
private:
    vector <int> levels;

    int size;

    void create(vector <int> &level, int a);

    void heat(vector <int> &level);

    time_t timer1(vector <int> &level);

    time_t timer2(vector <int> &level);

    time_t timer3(vector <int> &level);

public:
    void run();
    void cache_levels();
    explicit Runner(int a);
};
#endif // INCLUDE_RUNNER_HPP_
