#include <iostream>
#include <graph.hpp>

int main() {
    static std::function<int32_t(int32_t)> transform = [](int32_t i) -> int32_t { return -i; };
    local::BipCompGraph g(std::cin, transform);
    std::vector<int> m(g.nodes_count, static_cast<int>(local::MagicNodes::NULL_NODE));
    g.getMaximumPerfectMatching(m);
    int32_t sum = 0;
    for (int i = 0; i < g.nodes_count / 2; ++i)
        if (m[i] != static_cast<int>(local::MagicNodes::NULL_NODE))
            sum += g.get_weight_raw(i, m[i]);
    std::cout << transform(sum) << '\n';
    return 0;
}
