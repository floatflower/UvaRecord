#include <iostream>

int main ( )
{
	int input ;
	std::cin >> input ;
	for ( int i = 0 ; i < input ; i ++ )
	{
		int farmers ;
		std::cin >> farmers ;
		int total = 0 ;
		for ( int j = 0 ; j < farmers ; j ++ )
		{
			int farmSize ; 
			int animalAmount ;
			int ecoLevel ;
			std::cin >> farmSize >> animalAmount >> ecoLevel ;
		
			total += farmSize * ecoLevel ;
		}
		
		std::cout << total << std::endl ;

	}
}
