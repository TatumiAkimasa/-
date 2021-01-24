#include"Piyoko_Move.h"
#include<math.h>

void Piyoko_Move(float* x, float* y, float* vx, float* vy, float* r)
{

	*r += 2.0f;

	if (*r > 360)
	{
		*r = 0;
	}

	*vx = cos(3.14 / 180 * *r);
	*vy = sin(3.14 / 180 * *r);

	float angle = 0.0f;
	*r = *vx * *vx + *vy * *vy;
	*r = sqrt(angle);

	if (*r == 0.0f)
	{
		;
	}
	else
	{
		*vx = 1.0 / *r * *vx;
		*vy = 1.0 / *r * *vy;
	}

	*vx *= 1.5f;
	*vy *= 1.5f;

	*x += *vx;
	*y += *vy;
}