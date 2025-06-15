#include <iostream>
#include <memory>

struct MoveStrategy
{
    virtual ~MoveStrategy() = default;
    virtual void move() = 0;
};

struct WalkStrategy : MoveStrategy
{
    void move() override { std::cout << "walk" << std::endl; }
};
struct DriveStrategy : MoveStrategy
{
    void move() override { std::cout << "automobile" << std::endl; }
};
struct ScooterStrategy : MoveStrategy
{
    void move() override { std::cout << "scooter" << std::endl; }
};

class Human
{
    std::unique_ptr<MoveStrategy> moveStrategy;

public:
    void setStrategy(std::unique_ptr<MoveStrategy> newStrategy)
    {
        moveStrategy = std::move(newStrategy);
    }
    void move() const
    {
        if (moveStrategy)
            moveStrategy->move();
    }
};

int main()
{
    Human hmn;
    hmn.setStrategy(std::make_unique<WalkStrategy>());
    hmn.move();
    hmn.setStrategy(std::make_unique<DriveStrategy>());
    hmn.move();
    hmn.setStrategy(std::make_unique<ScooterStrategy>());
    hmn.move();

    return 0;
}