#include <iostream>

long long int reverse ( long long int input )
{
	long long int result = 0 ;
	int remainder = 0 ;
	while ( true )
	{
		remainder = input % 10 ;
		result += remainder ;
		input /= 10 ;
		if ( input == 0 ) break ;
		result *= 10 ;
	}
	return result ;
}

bool isPalindromes ( long long int input )
{
	long long int reverseInput = reverse ( input ) ;
	return reverseInput == input ;
}

int main ()
{
	int times ;
	std::cin >> times ;
	for ( int i = 0 ; i < times ; i ++ )
	{
		int countTime = 0 ;
		long long int input ;
		std::cin >> input ;
		// std::cout << reverse (input) ;
		while ( true )
		{
			input = input + reverse ( input ) ;
			countTime ++ ;
			if ( isPalindromes ( input ) ) break ;
		}	
		std::cout << countTime << " " << input << std::endl  ;
	}
}
