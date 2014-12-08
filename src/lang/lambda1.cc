#include <functional>
#include <iostream>

std::function<int(int, int)> ReturnLambda() {
    return [] (int x, int y) {
        return x * y;
    };
}

int main() {
    auto lf = ReturnLambda();
    std::cout << lf(6, 7) << '\n';
}
