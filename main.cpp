#include<thread>
#include<cstdlib>
#include<print>
#include<string>
#include<algorithm>
#include<iostream>

class RandomSum {
    private:
        int sum;
        int threadId;
    public:
        RandomSum() : sum(0), threadId(0) {}
        void randomSum() {
            sum = 0;
            for (int i = 0; i < 100; i++) {
                sum += rand() % 1000;
            }
            
            std::println("Thread #{}: sum = {}", threadId, sum);
        }
        int Sum() const {
            return sum;
        }
        int ThreadId() const {
            return threadId;
        }
        RandomSum(int threadId):threadId(threadId), sum(0) {
        }
};

int main() {
    srand(time(nullptr)); 
    RandomSum sum1(1), sum2(2), sum3(3), sum4(4), sum5(5), sum6(6), sum7(7), sum8(8), sum9(9), sum10(10);
    RandomSum highestSum(0);

    std::thread threadSum1([&](){ 
        sum1.randomSum(); 
    });
    std::thread threadSum2([&](){ 
        sum2.randomSum(); 
    });
    std::thread threadSum3([&](){ 
        sum3.randomSum(); 
    });
    std::thread threadSum4([&](){ 
        sum4.randomSum(); 
    });
    std::thread threadSum5([&](){ 
        sum5.randomSum(); 
    });
    std::thread threadSum6([&](){ 
        sum6.randomSum(); 
    });
    std::thread threadSum7([&](){ 
        sum7.randomSum(); 
    });
    std::thread threadSum8([&](){ 
        sum8.randomSum(); 
    });
    std::thread threadSum9([&](){ 
        sum9.randomSum(); 
    });
    std::thread threadSum10([&](){ 
        sum10.randomSum(); 
    });

    threadSum1.join();
    threadSum2.join();
    threadSum3.join();
    threadSum4.join();
    threadSum5.join();
    threadSum6.join();
    threadSum7.join();
    threadSum8.join();
    threadSum9.join();
    threadSum10.join();

    RandomSum sums[10] = {sum1, sum2, sum3, sum4, sum5, sum6, sum7, sum8, sum9, sum10};
    std::sort(sums, sums + 10, [](const RandomSum& a, const RandomSum& b) {
        return a.Sum() > b.Sum();
    });
    highestSum = sums[0];
    std::println("Max: thread #{} = {}", highestSum.ThreadId(), highestSum.Sum());

    return 0;
}