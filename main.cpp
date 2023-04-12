#include <bits/stdc++.h>

uint64_t calls = 0;
// uint64_t test(uint64_t arr[], uint64_t index, uint64_t val, uint64_t size) {
uint64_t test(uint64_t val, uint64_t size, std::string str) {
    std::cout << str << val << ' ' << size << '\n';
    if (size <= 1) {
        // arr[index] = val;
        // std::cout << "    ";
        // for (int i = 0; i < size; i++)
        //     std::cout << arr[i] << ' ';
        // std::cout << '\n';
        return 1;
    }
    calls++;
    uint64_t tmp = 0, i = val + 1;
    while (i--) {
        // arr[index] = i;
        // tmp += (val > i)? test(index + 1, val - i, size) : 1;
        uint64_t v = test(i, size - 1, str + "    ");
        tmp += v;
        // tmp += test(arr, index + 1, val - i, size);
    }
    return tmp;
}


int main() {
    uint64_t amt, tmp, size = 0;
    std::string str;

    std::getline(std::cin, str);
    std::stringstream ss(str);
    ss >> amt;


    while (ss >> tmp) {
        size++;
        amt -= tmp;
    }
    uint64_t arr[size] = {0};
    std::cout << test(amt, size, "") << std::endl;
    std::cout << calls;
    // for (auto& i : args) {
    //     for (auto& j : i) {
    //         std::cout << j << ' ';
    //     }
    //     std::cout << '\n';
    // }

}
