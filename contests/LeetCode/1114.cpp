#include <iostream>
#include <functional>
#include <memory>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <vector>

class Foo {
public:
    Foo() = default;

    void first(std::function<void()> printFirst) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this] { return order == 1; });
        printFirst();
        order = 2;
        cv.notify_all();
    }

    void second(std::function<void()> printSecond) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this] { return order == 2; });
        printSecond();
        order = 3;
        cv.notify_all();
    }

    void third(std::function<void()> printThird) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this] { return order == 3; });
        printThird();
    }
private:
    std::mutex mtx;
    std::condition_variable cv;
    int order = 1;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n = 3;
    std::vector<int> order;
    order.reserve(3);
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        order.push_back(x);
    }
    std::function<void()> printFirst = []() {
        std::cout << "First" << std::endl;
    };
    std::function<void()> printSecond = []() {
        std::cout << "Second" << std::endl;
    };
    std::function<void()> printThird = []() {
        std::cout << "Third" << std::endl;
    };
    
    std::unique_ptr<Foo> solve = std::make_unique<Foo>();

    std::vector<std::jthread> threads;

    for (const auto& i : order) {
        if (i == 1) {
            threads.emplace_back(&Foo::first, solve.get(), printFirst); 
        }
        if (i == 2) {
            threads.emplace_back(&Foo::second, solve.get(), printSecond);
        }
        if (i == 3) {
            threads.emplace_back(&Foo::third, solve.get(), printThird);
        }
    }
    return 0;
}

/**



**/
