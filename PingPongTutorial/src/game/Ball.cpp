#include "../../inc/game/Ball.h"

Ball::Ball(double speed) : _speed(speed) {}

void Ball::Serve(double direction)
{
	_velocity.x = _speed * direction;
}

void Ball::Move()
{
	_pos.x += _velocity.x;
	_pos.y += _velocity.y;
}

void Ball::Bounce(const Rect& rect)
{
	Rect box = GetBorder();
	Coordinate overlap = box.Intersect(rect);
	if (overlap.x < 0.0 || overlap.y < 0.0)
	{
		return;
	}

	Coordinate ballCenter = box.GetCenter();
	Coordinate rectCenter = rect.GetCenter();
	if (overlap.x > overlap.y)
	{
		// bounce on y
		if (ballCenter.y < rectCenter.y)
		{
			//hit on top
			overlap.y = -overlap.y;
		}
		_velocity.y = -_velocity.y;
		overlap.x = 0.0;
	}
	else
	{
		// bounce on x
		if (ballCenter.x < rectCenter.x)
		{
			overlap.y = -overlap.y;
		}
		_velocity.x = -_velocity.x;
		overlap.y = 0.0;
	}

}

void Ball::Attach(const Rect& rect, bool isLeft)
{
	Coordinate center = rect.GetCenter();
	if (isLeft)
	{
		_pos.x -= rect.width * 0.5 + _width;
	}
	else
	{
		_pos.x += rect.width * 0.5;
	}
}