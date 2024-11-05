#include <iostream>

//struct CodHero
//{
//    void shoot()
//    {
//        std::cout << "Tire comme un militaire" << std::endl;
//    }
//};
//
//struct HarryPotterHero
//{
//    void launchAttack()
//    {
//        std::cout << "Lance un sort avec sa baguette" << std::endl;
//    }
//};
//struct Shoot : public HarryPotterHero
//{
//    Shoot(HarryPotterHero* hero) : m_hero(hero) {}
//    void shoot()
//    {
//        return launchAttack();
//    }
//protected:
//    HarryPotterHero* m_hero;
//};
//
//int main()
//{
//    HarryPotterHero* hero = new HarryPotterHero();
//    Shoot* herog = new Shoot(hero);
//    herog->shoot();
//
//    delete hero;
//    hero = nullptr;
//    delete herog;
//    herog = nullptr;
//
//    return 0;
//}

struct CodHero
{
    virtual ~CodHero() = default;
    virtual void shoot()
    {
        std::cout << "Tire comme un militaire" << std::endl;
    }
};

struct HarryPotterHero
{
    void castASpell()
    {
        std::cout << "Lance un sort avec sa baguette" << std::endl;
    }
};
struct AdapterHpHero : public CodHero, public HarryPotterHero
{
    void shoot() override
    {
        castASpell();
    }
};
struct BetterAdapterHero : public CodHero
{
    HarryPotterHero hero;
    void shoot() override
    {
        hero.castASpell();
    }
};

int main()
{
    CodHero* hero = new BetterAdapterHero();
    hero->shoot();

    delete hero;
    hero = nullptr;

    return 0;
}
