#include "Racket.hpp"


int main()
{
    kn::window::init({ 800, 600 });
    kn::time::Clock clock;

    kn::cache::create("racket", { 20, 60 }, { 255, 255, 255 });
    Racket leftRacket({ 40, kn::window::getSize().y / 2 }, 1);
    Racket rightRacket({ kn::window::getSize().x - 40, kn::window::getSize().y / 2 }, 2);

    bool done = false;
    while (!done)
    {
        double dt = clock.tick();
        const auto* keys = kn::input::getKeysPressed();

        for (const auto& event : kn::window::getEvents())
            if (event.type == kn::QUIT)
                done = true;

        kn::window::cls();
        leftRacket.update(dt, keys);
        rightRacket.update(dt, keys);

        kn::window::flip();
    }

    kn::window::quit();
    return EXIT_SUCCESS;
}
