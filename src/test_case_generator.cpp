#include <test_case_generator.hpp>
#include <iostream>

namespace local {
    void generate_complete_bipartite_graph(int n, int max_module, std::ostream &out) {
        srand48(0xbeef);
        out << n << '\n';
        for (unsigned i = 0; i < n; i++) {
            for (unsigned j = 0; j < n; j++)
                out << lrand48() % max_module << ' ';
            out << '\n';
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 3)
        std::cout << "usage is: ./graph_generator partition_size max_module\n";
    local::generate_complete_bipartite_graph(std::atoi(argv[1]), std::atoi(argv[2]), std::cout);
    return 0;
}