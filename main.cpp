#include <iostream>
#include <iomanip>
#include <math.h>

const uint64_t initState = 0x1234354435;

class RNG
{
public:
	uint64_t state;
	RNG()                        { state = 0xffffffff; };
	RNG(uint64_t _state)         { state = _state ? _state : 0xffffffff; };
	operator unsigned char()     { return (unsigned char)next(); };
	operator char()              { return (char)next(); };
	operator unsigned short()    { return (unsigned short)next(); };
	operator short()             { return (short)next(); };
	operator int()               { return (int)next(); };
	operator unsigned()          { return next(); };

	inline unsigned next()
	{
	    state = (uint64_t)(unsigned)state* /*CV_RNG_COEFF*/ 4164903690U + (unsigned)(state >> 32);
	    return (unsigned)state;
	}
};

int main()
{
        using namespace std;

	RNG a(initState);

        cout << "----------------" << endl;
	for(unsigned int i = 0;i < 10;i++)
	{
		unsigned short temp;
		while(temp = (unsigned short)a, 9999 < temp);
		cout << temp << endl;
	}
        return 0;
}
