#include <iostream>

int main ()
{
	while ( true )
	{
		int input1 ;
		int input2 ;
		int input1Digit[10] = { 0 };
		int input2Digit[10] = { 0 };
		std::cin >> input1 >> input2 ;
		
		if ( input1 == 0 && input2 == 0 )
		{
			break ;
		}
		
		int remainder ;
		int flag = 0 ;
		int input1Length ;
		int input2Length ;
		while ( 1 )
		{
			remainder = input1 % 10 ;
			input1Digit[flag++] = remainder ;
			input1 /= 10 ;
			if ( input1 == 0 ) break ;
		}
		input1Length = flag - 1 ;
		flag = 0 ;
		while ( 1 )
		{
			remainder = input2 % 10 ;
			input2Digit[flag++] = remainder ;
			input2 /= 10 ;
			if ( input2 == 0 ) break ;
		}
		input2Length = flag - 1 ;

		int longer = input1Length < input2Length ? input2Length : input1Length ;

		int carryCount = 0 ;
		int carry = 0 ;
		for ( int i = 0 ; i <= longer ; i ++ )
		{
			int digitResult = input1Digit[i] + input2Digit[i] + carry ;
			carry = 0 ;
			if ( digitResult >= 10 )
			{
				carry = digitResult / 10 ;		
				carryCount ++ ;
			}
		}
		switch ( carryCount )
		{
			case 0 : std::cout << "No carry operation." << std::endl ; break ;
			case 1 : std::cout << carryCount << " carry operation." << std::endl ; break ;
			default : std::cout << carryCount << " carry operations." << std::endl ; break ;
		}

	}
}
