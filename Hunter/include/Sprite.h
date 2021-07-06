#pragma once

#include "HunterCentral.h"
#include "pch.h"

namespace Hunter {
	class HUNTER_API Sprite {
	public:
		Sprite(const std::string& spriteFile);
		bool Load(const std::string& spriteFile);
		
		int getWidth() const;
		int getHeight() const;

		const unsigned char* GetImagePointer() const;

		~Sprite();

	private:
		unsigned char* mImage{ nullptr };
		int mWidth{ 0 }, mHeight{ 0 }, mNumChannels{ 0 };
	};
}