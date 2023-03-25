#include <iostream>
#include <graph.hpp>

int main() {

    std::function<int32_t(int32_t)> transformation = [](int32_t i) -> int32_t { return -i; };
    local::BipCompGraph g(std::cin, transformation);
    std::vector<int> m(g.nodes_count, static_cast<int>(local::MagicNodes::NULL_NODE));
    g.getMaximumPerfectMatching(m);
    int32_t sum = 0;
    for (int i = 0; i < g.nodes_count / 2; ++i)
        if (m[i] != static_cast<int32_t>(local::MagicNodes::NULL_NODE)) {
            std::cout << (i + 1) << " is matched with " << (m[i] + 1) << ": " << g.get_weight_raw(i, m[i]) << '\n';
            sum += g.get_weight_raw(i, m[i]);
        } else
            std::cout << i << " is not matched\n";
    std::cout << "Maximum matching is: " << (-sum) << '\n';
    return 0;
}
