#include <stdio.h>
int gcd(int q, int p)
{   
	return p == 0 ? q : gcd(p, q % p);
}

int main()
{
    printf("%d\n", gcd(15, 9));
}
