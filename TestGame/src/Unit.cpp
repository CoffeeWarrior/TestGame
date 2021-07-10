#include "..\include\Unit.h"
#include "Hunter.h"

Unit::Unit(const std::string& spritePath, int newSpeed):mImage(spritePath), mSpeed(newSpeed)
{
}

void Unit::SetXCoord(int newX)
{
	mXcoord = newX;
}

void Unit::SetYCoord(int newY)
{
	mYcoord = newY;
}

int Unit::GetXCoord() const
{
	return mXcoord;
}

int Unit::GetYCoord() const
{
	return mYcoord;
}

int Unit::GetWidth() const
{
	return mImage.getWidth();
}

int Unit::GetHeight() const
{
	return mImage.getHeight();
}

int & Unit::Speed() 
{
	return mSpeed;
}

void Unit::UpdateXCoord(int change)
{
	mXcoord += change;
}

void Unit::UpdateYCoord(int change)
{
	mYcoord += change;
}

void Unit::MoveLeft()
{
	UpdateXCoord(-mSpeed);
}

void Unit::MoveRight()
{
	UpdateXCoord(mSpeed);
}

void Unit::MoveUp()
{
	UpdateYCoord(mSpeed);
}

void Unit::MoveDown()
{
	UpdateYCoord(-mSpeed);
}





void Unit::MoveXBySpeed()
{
	mXcoord += mSpeed;
}



void Unit::Draw() const
{
	Hunter::Renderer::Draw(mImage, mXcoord, mYcoord, mImage.getWidth(), mImage.getHeight());
}

bool Unit::OverlapsWith(const Unit& other) const
{	
	////perform checks for each image of our sprite
	return OverlapsWithHelper(other.mXcoord, other.mYcoord) ||
		OverlapsWithHelper(other.mXcoord + other.GetWidth(), other.mYcoord) ||
		OverlapsWithHelper(other.mXcoord, other.mYcoord + other.GetHeight()) ||
		OverlapsWithHelper(other.mXcoord + other.GetWidth(), other.GetYCoord() + other.GetHeight()) ;
}

bool Unit::OverlapsWithHelper(const int otherX, const int otherY) const
{
	if (otherX > mXcoord && otherX < mXcoord + mImage.getWidth()) { //check if x is between our x's on our sprite
		if (otherY > mYcoord && otherY < mYcoord + mImage.getHeight()) { //check if y is between our y's on our sprite
			HLOG("What");
			return true;
		}
	}
	return false;

}

