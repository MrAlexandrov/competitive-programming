#include <condition_variable>
#include <iostream>
#include <functional>
#include <mutex>
#include <thread>

class FooBar {
private:
    int n_;
    bool chose = false; // false means foo, true means bar
    std::mutex mtx;
    std::condition_variable cv;

public:
    FooBar(int n) : n_(n) {}

    void foo(std::function<void()> printFoo) {
        for (int i = 0; i < n_; i++) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this](){ return chose == false; });                
            printFoo();
            chose = true;
            cv.notify_all();
        }
    }

    void bar(std::function<void()> printBar) {
        for (int i = 0; i < n_; i++) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this](){ return chose == true; });
            printBar();
            chose = false;
            cv.notify_all();
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n;
    std::cin >> n;
    FooBar solve(n);
    std::function<void()> printFoo = []() {
        std::cout << "foo";
    };
    std::function<void()> printBar = []() {
        std::cout << "bar";
    };
    
    std::jthread fooThread(&FooBar::foo, &solve, printFoo);
    std::jthread barThread(&FooBar::bar, &solve, printBar);
    return 0;
}

/**



**/
