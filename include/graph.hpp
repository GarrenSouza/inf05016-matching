
#pragma once

#include <heap.hpp>
#include <unordered_map>
#include <vector>
#include <string>
#include <functional>
#include <iostream>

namespace local {

    enum class MagicNodes {
        NULL_NODE = -1
    };

    struct edge_to {
        edge_to() = default;

        edge_to(uint32_t v, int32_t w) : _v(v), _w(w) {}

        uint32_t _v;
        int32_t _w;
    };

    struct vertex : HeapNode {
        int32_t id, _potential;
        bool _free;

        vertex() : id(static_cast<int> (MagicNodes::NULL_NODE)),
                   _potential(0),
                   _free(true) {}
    };

    class BipCompGraph {
    public:

        enum class Partition {
            S,
            T
        };

        explicit BipCompGraph(std::istream &in, std::function<int32_t(int32_t)> &t);

        void getMaximumMatching(std::vector<int> &matching);

        void getMaximumPerfectMatching(std::vector<int> &matching);

        [[nodiscard]] Partition getPartition(int n) const;

        [[nodiscard]] bool validNodeIndex(int n) const;

        int32_t get_weight_raw(int32_t u, int32_t v);

        int32_t get_weight_johnson(int32_t u, int32_t v, std::vector<int32_t> &matching);

        int32_t get_weight(int32_t u, int32_t v, bool matched);

        friend std::ostream &operator<<(std::ostream &os, const BipCompGraph &graph);

        int32_t edges_count, nodes_count;

    private:

        local::vertex *get_augmenting_path_end_node(std::vector<int32_t> &pred, std::vector<int> &match);

        int32_t net_score_over_new_augmenting_path(int32_t s,
                                                   int32_t t,
                                                   const std::vector<int32_t> &pred,
                                                   std::vector<int32_t> &matching);

        void update_matching(int32_t s,
                             int32_t t,
                             const std::vector<int32_t> &pred,
                             std::vector<int32_t> &match);

        void update_potentials();

        std::vector<edge_to> edges;
        std::vector<vertex> nodes;
    };

    std::ostream &operator<<(std::ostream &os, const local::BipCompGraph &graph);
}
