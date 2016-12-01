#include <iostream>
#include <cmath>
#include <cstdlib>

int main()
{
	int digitNumber ;
	while ( std::cin >> digitNumber )
	{
		int input ;
		int data[digitNumber] ;
		

		bool check[digitNumber]={0};
		for ( int i = 0 ; i < digitNumber ; i ++ )
		{
			std::cin >> data[i] ;
		}
		for ( int i = 0 ; i < digitNumber-1 ; i ++ )
		{
			int temp = abs ( data[i] - data[i+1] ) ;
			if ( temp < digitNumber )
			{
				check[temp] = true ;
			}
		}
		bool isjolly = true ;
		for ( int i = 1 ; i < digitNumber ; i++ )
		{
			// std::cout<<check[i]<<std::endl ;
			if ( ! check[i] )
			{
				isjolly = false ;
				std::cout << "Not jolly" << std::endl;
				break ;
			}
		}
		if ( isjolly ) 
		{
			std::cout << "Jolly"<<std::endl ;
		}
	}
}
