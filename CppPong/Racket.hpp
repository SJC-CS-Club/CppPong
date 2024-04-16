#include <KrakenEngine.hpp>
#include <memory>

class Racket
{
public:
	Racket(kn::math::Vec2 pos, int player);

	void update(double dt, const Uint8* keys);

private:
	std::shared_ptr<kn::Texture> texture;
	kn::Rect rect;
	kn::math::Vec2 pos;
	float speed = 300;
	int player;
};