// C++ program to find the maximum angle
// at which we can tilt the bottle
// without spilling any water

#include <bits/stdc++.h>
using namespace std;

float find_angle(int x, int y, int z)
{

	// Now we have the volume
	// of rectangular prism a*a*b
	int volume = x * x * y;

	float ans = 0;

	// Now we have 2 cases!
	if (z < volume / 2) {

		float d = (x * y * y) / (2.0 * z);

		// Taking the tangent inverse of value d
		// As we want to take out the required angle
		ans = atan(d);
	}
	else {

		z = volume - z;
		float d = (2 * z) / (float)(x * x * x);

		// Taking the tangent inverse of value d
		// As we want to take out the required angle
		ans = atan(d);
	}

	// As of now the angle is in radian.
	// So we have to convert it in degree.
	ans = (ans * 180) / 3.14159265;

	return ans;
}

int main()
{
	// Enter the Base square side length
	int x = 10;

	// Enter the Height of rectangular prism
	int y = 50;

	// Enter the volume of water in the bottle
	float mx = 0, idx = -1;
	for (int i = 1; i < x * x * y; i++) {
		int res =  find_angle(x, y, i);
		if (res > mx) mx = res, idx = i;
	}
	cout << mx << ' ' << idx;
}
