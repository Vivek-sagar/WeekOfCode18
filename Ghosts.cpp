#include <iostream>

using namespace std;

bool is_gcd_1(int a, int b)
{
	int smallest = (a<b)?a:b;
	for (int i=2; i<=smallest; i++)
	{
		if (a%i == 0 && b%i==0)
			return false;
	}
	return true;
}


int main()
{
    int A;
    int B;
    int C;
    int D;
    int count = 0;
    cin >> A >> B >> C >> D;

    for (int a=1; a<=A; a++)
    {
    	for (int b=1; b<=B; b++)
    	{
    		for (int c=1; c<=C; c++)
    		{
    			for (int d=1; d<=D; d++)
    			{
    				if ((a-b)%3 == 0)
    				{
    					if ((b+c)%5 == 0)
    					{
    						if ((a*c)%4 == 0)
    						{
    							if (is_gcd_1(a,d))
    							{
    								//cout << a << " " << b << " " << c << " " << d << endl;
    								count++;
    							}
    						}
    					}
    				}
    			}
    		}
    	}
    }
    cout << count;
    return 0;
}
