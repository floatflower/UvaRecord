#include <iostream>

int main()
{ 
	int setCount = 0 ; 
	while ( true )
	{
		setCount ++ ;
		int dataAmount ;
		std::cin >> dataAmount ;
		if ( dataAmount == 0 ) break ;
		int data[dataAmount] ;
		int total = 0 ;
		for ( int i = 0 ; i < dataAmount ; i ++ )
		{
			std::cin >> data[i] ;
			total += data[i] ;
		}		
		int average = total / dataAmount ;
		int step = 0 ;
		for ( int i = 0 ; i < dataAmount ; i++ )
		{
			if ( data[i] > average )
			{
				step += ( data[i] - average ) ;
			} 
		}
		std::cout << "Set #" << setCount << std::endl ;
		std::cout << "The minimum number of moves is "<<step<<"." <<std::endl;
		std::cout << std::endl ;
	}
}
