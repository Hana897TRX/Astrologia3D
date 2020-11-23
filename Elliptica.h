#pragma once
class Elliptica
{
private:
	float solarAngle;
	int hour, minutes;
	int solarPosition = 0;
	int zodiacSign;
public:
	Elliptica(float _solarAngle, int _hour, int _minutes);
	void Thingy(int, int, float, float, float, float, float, float, float, bool, float);
};

