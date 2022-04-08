#include "streamcollection.h"
#include <iostream>
#include <vector>

int main() {
    size_t cnt;
    std::cin >> cnt;
    std::vector<int> homes(cnt), distances(cnt, cnt);
    std::cin >> homes;

    size_t pos_empty = cnt;
    for(size_t pos = 0;pos < homes.size();++pos){
        if(homes[pos] == 0){
            pos_empty = pos;
            distances[pos] = 0;
        }else if(pos_empty < homes.size()){
            distances[pos] = pos - pos_empty;
        }
    }
    pos_empty = cnt;
    for(size_t pos = homes.size();pos > 0;--pos){
        if(homes[pos - 1] == 0){
            pos_empty = pos - 1;
        }else if(pos_empty < homes.size() &&
           static_cast<int>(pos_empty - pos + 1) < distances[pos - 1]){
            distances[pos - 1] = static_cast<int>(pos_empty - pos + 1);
        }
    }
    std::cout << distances << std::endl;
    return 0;
}
