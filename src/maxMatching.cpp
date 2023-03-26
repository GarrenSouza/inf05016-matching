#include <iostream>
#include <graph.hpp>
#include <chrono>
#include <fstream>

using namespace std::chrono;

int main(int argc, char **argv) {
    static std::function<int32_t(int32_t)> transform = [](int32_t i) -> int32_t { return i; };
    std::ifstream in(argv[1]);
    local::BipCompGraph g(in, transform);

    uint64_t interchanges;

    time_point<system_clock> start;
    uint64_t ticks = 0, iterations = 25;
    std::cout << std::fixed;

    for (int i = 0; i < iterations; ++i) {
        std::vector<int> m(g.nodes_count, static_cast<int>(local::MagicNodes::NULL_NODE));
        start = system_clock::now();
        interchanges = g.getMaximumMatching(m);
        ticks += duration_cast<nanoseconds>((system_clock::now() - start)).count();
    }

    std::cout << argv[1] << ";" << interchanges << ";" << (ticks / iterations) << '\n';

    return 0;
}
