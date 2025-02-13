#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    int K = 0;
    int N = 0;
    std::cin >> K >> N;
    std::vector<int> Numbers;
    Numbers.reserve(N);
    for (int i = 0, end = N; i < end; ++i) {
        int x = 0;
        std::cin >> x;
        Numbers.push_back(x);
    }
    int SashaPoints = 0;
    int LenaPoints = 0;
    constexpr auto SashaName = "Sasha";
    constexpr auto LenaName = "Lena";
    constexpr auto Draw = "Draw";
    bool WasAnswer = false;

    for (int i = 0, end = N; i < end; ++i) {
        auto CurrentNumber = Numbers[i];
        bool DivideByThree = (CurrentNumber % 3 == 0);
        bool DivideByFive = (CurrentNumber % 5 == 0);
        if (!(DivideByThree ^ DivideByFive)) continue;
        if (DivideByThree) {
            ++SashaPoints;
            if (K <= SashaPoints) {
                WasAnswer = true;
                std::cout << SashaName;
                break;
            }
        }
        if (DivideByFive) {
            ++LenaPoints;
            if (K <= LenaPoints) {
                WasAnswer = true;
                std::cout << LenaName;
                break;
            }
        }
    }
    if (!WasAnswer) {
        if (SashaPoints == LenaPoints) {
            std::cout << Draw;
        } else {
            std::cout << (SashaPoints < LenaPoints ? LenaName : SashaName);
        }
    }
    return 0;
}

/**



**/
