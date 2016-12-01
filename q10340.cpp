#include <iostream>

int main()
{
	std::string str1 ;
	std::string str2 ;

	while ( std::cin >> str1 >> str2 )
	{
		std::string::iterator it_str1  = str1.begin() ;
		for ( std::string::iterator it_str2 = str2.begin() ;
			 		it_str2 < str2.end() ;
					it_str2 ++ )
		{
			if ( *it_str1 == *it_str2 )
			{
				it_str1 ++ ;
				if ( it_str1 >= str1.end() ) break ;
			}
		}
		if ( it_str1 >= str1.end() ) std::cout<< "Yes" << std::endl ;
		else std::cout<<"No" <<std::endl ;
	}
}
