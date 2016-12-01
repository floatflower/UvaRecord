#include <iostream>

int main()
{
	std::string input ;

	while ( getline(std::cin,input) )
	{
		int wordCount = 0 ;
		int charCount = 0 ;
		bool wordStart = false ;
		bool haveCount = false ;
		for ( std::string::iterator it_input = input.begin();
			 		it_input < input.end() ;
					it_input ++ )
		{
			int temp_ascii = (char) *it_input ;
			if ( ( temp_ascii >= (int)'A' && temp_ascii <= (int)'Z' ) || ( temp_ascii >= (int)'a' && temp_ascii <= (int)'z' ) )
			{
				if ( ! haveCount ) wordCount ++ ;
				wordStart = true ;
				haveCount = true ;
			}
			else
			{
				wordStart = false ;
				charCount = 0 ;
				haveCount = false ;
				continue ;
			}
		}
	std::cout<<wordCount <<std::endl ;
	}
}
