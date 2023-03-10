#include <iostream>
#include <graph.hpp>

int main(){

    local::BipCompGraph g(std::cin);
    std::cout << g << '\n';
    return 0;
}
