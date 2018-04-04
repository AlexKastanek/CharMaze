#include "Coordinate.h"

Coordinate::Coordinate()
{

	

}

Coordinate::~Coordinate()
{



}

int* Coordinate::getPos()
{

	int pos[2] = {xPos, yPos};
	return pos;

}

int Coordinate::getXPos()
{

	return xPos;

}

int Coordinate::getYPos()
{

	return yPos;

}

char Coordinate::getContent()
{

	return content;

}

void Coordinate::setPos(int xPosSource, int yPosSource)
{

	xPos = xPosSource;
	yPos = yPosSource;

}

void Coordinate::setXPos(int xPosSource)
{

	xPos = xPosSource;

}

void Coordinate::setYPos(int yPosSource)
{

	yPos = yPosSource;

}

void Coordinate::setContent(char contentSource)
{

	content = contentSource;

}

void Coordinate::operator=(const Coordinate source)
{

	xPos = source.getXPos();
	yPos = source.getYPos();
	content = source.getContent();

}

bool Coordinate::operator==(const Coordinate source)
{

	if (xPos != source.getXPos())
	{
		return false;
	}
	
	if (yPos != source.getYPos())
	{
		return false;
	}
	
	if (content != source.getContent())
	{
		return false;
	}
	
	return true;

}






























