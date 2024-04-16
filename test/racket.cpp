#include "Racket.hpp"
#include <algorithm>


Racket::Racket(kn::math::Vec2 pos, int player) : pos(pos), player(player)
{
	texture = kn::cache::getTexture("racket");
	rect = texture.get()->getRect();
}

void Racket::update(double dt, const Uint8* keys)
{
    if (player == 1)
    {
        if (keys[kn::S_w])
            pos.y -= speed * dt;
        if (keys[kn::S_s])
            pos.y += speed * dt;
    }
    else if (player == 2)
    {
        if (keys[kn::S_UP])
            pos.y -= speed * dt;
        if (keys[kn::S_DOWN])
            pos.y += speed * dt;
    }
    pos.y = std::clamp(pos.y, rect.getSize().y / 2, kn::window::getSize().y - rect.getSize().y / 2);
    rect.setCenter(pos);

    kn::window::blit(texture, {}, rect);
}