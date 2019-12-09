//Copyright 2019 <boikov3>

#include <Runner.hpp>
Runner::Runner(int a){
   size = a;
   cache_levels();
   run();
}

void Runner::cache_levels(){
    int *arr = new int[size];
    for (int i = 0; i < size; i++) {
        std::cout << "№" << i + 1 << " Размер уровня = ";
        std::cin >> arr[i];
    }
    levels.resize(size+2);
    levels[0] = arr[0]/2;
    levels[levels.size()-1] = arr[size-1]*3/2;
    for (unsigned int i = 1; i < (levels.size()-1); i++) {
        levels[i] = arr[i-1];
    }
    delete[] arr;
    int i = 0;
    for (auto& e : levels) {
        std::cout << "№" << i + 1 << " "
        "Level's size = " << e << " " << std::endl;
        i++;
    }
}

void Runner::create(vector<int> &level, int a) {
    static unsigned int onek;
    level.resize(a * 1024 * 1024 / sizeof(int));
    for (unsigned int i = 0; i < level.size(); i++) {
        level[i] = rand_r(&onek) % 1000;
    }
}

void Runner::heat(vector <int> &level){
    for (unsigned int i = 0; i < level.size(); i++) {
        level[i];
    }
}

time_t Runner::timer1(vector <int> &level){
    auto start = std::chrono::system_clock::now();
    for (int j = 0; j < 1000; j++) {
        for (unsigned int i = 0; i < level.size(); i++) {
            level[i];
        }
    }
    auto end = std::chrono::system_clock::now();
    time_t start_time = std::chrono::system_clock::to_time_t(start);
    time_t end_time = std::chrono::system_clock::to_time_t(end);
    return end_time-start_time;
}

time_t Runner::timer2(vector <int> &level){
    auto start = std::chrono::system_clock::now();
    for (int j = 0; j < 1000; j++) {
        for (unsigned int i =level.size()-1 ; i >0 ; i--) {
            level[i];
        }
    }
    auto end = std::chrono::system_clock::now();
    time_t start_time = std::chrono::system_clock::to_time_t(start);
    time_t end_time = std::chrono::system_clock::to_time_t(end);
    return end_time-start_time;
}

time_t Runner::timer3(vector <int> &level){
    auto start = std::chrono::system_clock::now();
    std::random_shuffle(level.begin(), level.end());
    for (int j = 0; j < 1000; j++) {
        for (unsigned int i = 0; i < level.size(); i++) {
            level[i];
        }
    }
    auto end = std::chrono::system_clock::now();
    time_t start_time = std::chrono::system_clock::to_time_t(start);
    time_t end_time = std::chrono::system_clock::to_time_t(end);
    return end_time-start_time;
}

void Runner::run() {
    for (unsigned int i = 0; i < levels.size(); i++){
        vector <int> level;
        create(level, levels[i]);
        heat(level);
        std::cout << "Эксперимент №" << i + 1 <<
        " time  = " << timer1(level) << " "<< timer2(level)
        << " "<< timer3(level) << std::endl;
    }
}
