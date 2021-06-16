#pragma once
#include <HunterCentral.h>

namespace Hunter {
	class HUNTER_API HunterApp {
	public:
		void RunGame(); //The method that starts the game
		
		static HunterApp* GetApplication(); //return our instance pointer - the method is static because people should be able to call this method without an object.
		static void Init(); //create the first instance of our singleton - this should also be able to be called wtihout creating an object.
	private:
		HunterApp();
		inline static HunterApp* instance{ nullptr }; //inline allows us to specify nullptr right in the class definition
	};
}
