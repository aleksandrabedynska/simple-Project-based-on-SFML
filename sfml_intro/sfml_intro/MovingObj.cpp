#include "MovingObj.h"


#include <iostream>
using namespace std;


MovingObj::MovingObj(float x, float y)
{
	position.x = x;
	position.y = y;
	direction.x = 0;
	direction.y = 0;
	speed = 0.0f;
	isShot = false;
	hasGold = false;
	width = 20;
	height = 20;
	rect.setSize(Vector2f(width, height));
	rect.setPosition(position.x, position.y);
	rect.setFillColor(Color::Magenta);
}

void MovingObj::setPosition(int x, int y)
{
	position.x = x;
	position.y = y;
}

void MovingObj::setSpeed(float s)
{
	speed = s;
}

RectangleShape MovingObj::getShape()
{
	return rect;
}

vec2f MovingObj::getPosition()
{
	return position;
}

void MovingObj::setBearing(vec2f aim)
{
	direction = aim - position;
	direction.normalize();
	direction = direction*speed;


	
}

vec2f MovingObj::getBearing()
{
	return direction;
}

void MovingObj::update()
{
	vec2f dir = getBearing();
	position+=dir;
	rect.setPosition(position.x,position.y);
	
}

bool MovingObj::reachedTarget(Target target)
{
	float xmin,xmax,ymin,ymax;		//target space
	xmin = target.getPosition().x+ 10;
	xmax = target.getPosition().x + target.getWidth();
	ymin = target.getPosition().y+ 10;
	ymax = target.getPosition().y + target.getHeight();

	vec2f v1, v2, v3, v4;	//object vertices
	v1.x = position.x;
	v1.y = position.y;

	v2.x = position.x;
	v2.y = position.y + height;

	v3.x = position.x + width;
	v3.y = position.y + height;

	v4.x = position.x + width;
	v4.y = position.y;

	if (v1.x > xmin && v1.x < xmax && v1.y > ymin && v1.y < ymax)
		return true;
	if (v2.x > xmin && v2.x < xmax && v2.y > ymin && v2.y < ymax)
		return true;
	if (v3.x > xmin && v3.x < xmax && v3.y > ymin && v3.y < ymax)
		return true;
	if (v4.x > xmin && v4.x < xmax && v4.y > ymin && v4.y < ymax)
		return true;
	
	return false;
}

void MovingObj::setHome(vec2f pos)
{
	home = pos;
}

vec2f MovingObj::getHome()
{
	return home;
}

void MovingObj::changeStatus()
{
	hasGold = true;
	rect.setFillColor(Color::Black);

}
bool MovingObj::gotShot()
{
	// TO DO intersection
	
	isShot = true;
	setBearing(position);
	direction.x = 0;
	direction.y = 0;
	speed = 0.0f;
	rect.setFillColor(Color::Red);
	
	return false;
}

bool MovingObj::isDead()
{
	if (isShot == true)
		return true;
	else
		return false;
}
/*
void MovingObj::swap(MovingObj o2)
{
	MovingObj temp(0,0);
	temp.direction = o2.direction;
	temp.position = o2.position;
	temp.speed = o2.speed;
	temp.isShot = o2.isShot;
	temp.hasGold = o2.hasGold;
	temp.home = o2.home;
	temp.rect = o2.rect;
	temp.width = o2.width;
	temp.height = o2.height;

	o2.direction=direction;
	o2.position=position;
	o2.speed = speed;
	o2.isShot = isShot;
	o2.hasGold = hasGold;
	o2.home = home;
	o2.rect = rect;
	o2.width = width;
	o2.height = height; 

	direction = temp.direction;
	position = temp.position;
	speed = temp.speed;
	isShot = temp.isShot;
	hasGold = temp.hasGold;
	home = temp.home;
	rect = temp.rect;
	width = temp.width;
	height = temp.height;



}
*/







MovingObj::~MovingObj()
{
}
