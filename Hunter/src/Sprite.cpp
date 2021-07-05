#include "pch.h"
#include "Sprite.h"
#include "stb_image.h"

namespace Hunter {
	Sprite::Sprite(const std::string& spriteFile)
	{
		if (!Load(spriteFile)) {
			HLOG("ERROR LOADING SPRITE");
		}
	}
	bool Sprite::Load(const std::string& spriteFile)
	{
		mImage = stbi_load(spriteFile.c_str(), &mWidth, &mHeight, &mNumChannels, 0);
		if (mImage) {
			return true;
		}
		else {
			return false;
		}
	}
	int Sprite::getWidth() const
	{
		return mWidth;
	}
	int Sprite::getHeight() const
	{
		return mHeight;
	}
	Sprite::~Sprite()
	{
		if (mImage != nullptr) {
			stbi_image_free(mImage);
		}
		
	}
}
