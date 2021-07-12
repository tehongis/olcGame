#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

class Example : public olc::PixelGameEngine
{
public:
	Example()
	{
		sAppName = "Example";
	}

	olc::Sprite* sprBlock = nullptr;
	olc::Decal* decBlock = nullptr;
	float fAngle = 0;

public:
	bool OnUserCreate() override
	{

		sprBlock = new olc::Sprite("./Tiles/5.png");
		decBlock = new olc::Decal(sprBlock);

		// Called once at the start, so create things here
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{

		Clear(olc::VERY_DARK_BLUE);
		olc::vf2d mouse = { float(GetMouseX()),float(GetMouseY()) };

		fAngle += fElapsedTime;


		for (int count = 0; count < 512; count++) {
			olc::vf2d xy =  { ScreenWidth() / 2 + 160.0f * std::cos(fAngle + float(count/25.0f)), ScreenHeight() / 2 + 120.0f * std::sin(fAngle + (float(count/40.0f)) ) };
			olc::Pixel color = olc::Pixel(255,255,255,int(128 + 128 * std::sin(count / 40.0f)) );
			DrawRotatedDecal(xy, decBlock, -2.0 * fAngle + float(count/256.0f),
				{ float(sprBlock->width) / 2.0f, float(sprBlock->height) / 2.0f },
				{ float(0.2f), float(0.2f) },
				color
			);

		}
		//DrawDecal(mouse, decBlock);
	    // DrawDecal(const olc::vf2d& pos, olc::Decal* decal, const olc::vf2d& scale, const olc::Pixel& tint)

		return true;
	}
};


int main()
{
	Example demo;
	if (demo.Construct(320, 240, 4, 4))
		demo.Start();

	return 0;
}
