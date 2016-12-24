#include <iostream>

int main()
{
	std::string input ;
	while ( std::cin >> input ) 
	{
		if ( input.at(2) == input.at(7) && input.at(3) == input.at(8) )
		{
			input.erase ( input.begin() + 2 ) ;
			input.erase ( input.begin() + 7 ) ;
			input.erase ( input.begin() + 3 ) ;
			input.erase ( input.begin() + 8 ) ;
		}
		else if ( input.at(0) == input.at(6) && input.at(5) == input.at(11) )
		{
			input.erase ( input.begin() + 0 ) ;
			input.erase ( input.begin() + 6 ) ;
			input.erase ( input.begin() + 5 ) ;
			input.erase ( input.begin() + 11 ) ;	
		}
		
	}
}
