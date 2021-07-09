#pragma once

#include "Hunter.h"

class Unit {
public:
	Unit(const std::string& spritePath, int newSpeed);

	//setters
	void SetXCoord(int newX);
	void SetYCoord(int newY);
	
	//getters
	int	 GetXCoord() const;
	int	 GetYCoord() const;
	int  GetWidth()  const;
	int  GetHeight()  const;

	int & Speed();


	//update coords
	void UpdateXCoord(int change);
	void UpdateYCoord(int change);

	//movement
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	void MoveXBySpeed();

	void Draw() const;

	//write overlaps with & helper
	bool OverlapsWith(const Unit& other) const;
	bool OverlapsWithHelper(const int otherX, const int otherY) const;
protected:
	
private:
	int mXcoord, mYcoord, mSpeed;
	Hunter::Sprite mImage;
	
};