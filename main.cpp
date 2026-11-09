#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <memory>

// Abstract Base Class
class Enemy {
public:
    virtual ~Enemy() = default;
    virtual void move() = 0; // Pure virtual function
};

// Derived Class 1: Basic Drone with straight movement
class BasicDrone : public Enemy {
public:
    void move() override {
        std::cout << "BasicDrone moving straight down.\n";
    }
};

// Derived Class 2: Fast Interceptor with zigzag movement
class FastInterceptor : public Enemy {
public:
    void move() override {
        std::cout << "FastInterceptor moving in a zigzag pattern.\n";
    }
};
// Added by Mohammad Anater: Robust High-Score File Loading Utility
int loadBestScore(const std::string& filename) {
std::ifstream file(filename);
if (!file.is_open()) {
std::cout << "[Warning] Score file '" << filename << "' missing. Defaulting best score to 0.\n";
return 0; // Fallback default best score
}
int bestScore = 0;
file >> bestScore;
if (file.fail()) {
std::cout << "[Warning] Score file malformed. Using default best score.\n";
return 0;
}
return bestScore;
}

int main() {
    std::cout << "=== Sky Defending Starting Program ===\n\n";

    // Demonstration of runtime dispatch via base class pointers
    std::vector<std::unique_ptr<Enemy>> enemies;
    enemies.push_back(std::make_unique<BasicDrone>());
    enemies.push_back(std::make_unique<FastInterceptor>());

    // Iterate through enemies vector and trigger polymorphic movement behavior
    for (const auto& enemy : enemies) {
        enemy->move();
    }

    std::cout << "\nStarting program compiled and ran successfully!\n";
    return 0;
}
