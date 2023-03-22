#include <iostream>
#include <graph.hpp>

int main() {

    local::BipCompGraph g(std::cin);
    std::vector<int> m(g.nodes_count, static_cast<int>(local::MagicNodes::NULL_NODE));
    auto matching_sum = g.getMaximumMatching(m);
//    std::cout << g << '\n';
    std::cout << "Maximum match sum is: " << g.expected_maximum_match << '\n';
    std::cout << "Maximum match sum found: " << matching_sum << '\n';
    for (int i = 0; i < g.nodes_count / 2; ++i)
        std::cout << i << " is matched with " << m[i] << '\n';
    return 0;
}
