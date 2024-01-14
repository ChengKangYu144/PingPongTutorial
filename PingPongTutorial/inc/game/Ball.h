#pragma once

#ifndef _BALL_H_
#define _BALL_H_

#include "GameObject.h"
#include "../Defines.h"

class Ball : public GameObject
{
protected:
	double _speed;
	Vector _velocity;

public:
	Ball(double speed);

	void Serve(double direction);
	void Stop();
	void Move();

	void Bounce(const Rect& rect);
	void Attach(const Rect& rect, bool isLeft);
};

#endif