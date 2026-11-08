#include <iostream>

int main() {
    size_t N;
    std::cin >> N;

    for (size_t stars = 1 + (N - 1) % 2; stars <= N; stars += 2) {
        size_t spaces = N / 2 - stars / 2;

        for (size_t i = 0; i < spaces; ++i) std::cout << ' ';
        for (size_t i = 0; i < stars; ++i) std::cout << '*';
        std::cout << '\n';
    }

    return 0;
}