
#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>
#include <algorithm>

class FreightTrainRoute {
//private:
public:
  std::vector<float> weightPerWagon;

public:
  int totalWeight() {
    float total(0.0f);
    total = std::accumulate(weightPerWagon.begin(), weightPerWagon.end(), 0.0F, std::plus<>());
    return static_cast<int>(total);
  }

  int totalWeightFE() {
    float total(0.0F);
    std::for_each(weightPerWagon.begin(), weightPerWagon.end(), [&total](auto v_) {
      total += v_;
    });
    return static_cast<int>(total);
  }

  int totalWeightRBL() {
    float total(0.0F);
    for (auto v_ : weightPerWagon) {
      total += v_;
    }
    return static_cast<int>(total);
  }
};


int main() {
  FreightTrainRoute troublesome { { 100.0f, 250.0f, 110.0f, }, };
  std::cout << "Total weight  (std::accumulate):" << std::setw(5) << troublesome.totalWeight() << std::endl;
  std::cout << "Total weight    (std::for_each):" << std::setw(5) << troublesome.totalWeightFE() << std::endl;
  std::cout << "Total weight (range based loop):" << std::setw(5) << troublesome.totalWeightRBL() << std::endl;

  return 0;
}
