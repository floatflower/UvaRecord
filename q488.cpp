#include <iostream>

int main()
{
	int time ;
	std::cin>>time ;
	int height ;
	int waveTime ;
	for ( int i = 0 ; i< time ; i ++ )
	{
		std::cin >> height >> waveTime ;
		for ( int j = 0 ; j < waveTime ; j ++ )
		{
			for ( int k = 1 ; k <= height ; k ++ )
			{
				for ( int l = 1 ; l <= k ; l ++ )
				{
					std::cout<<k ;
				}
				std::cout<<std::endl; 
			}
			for ( int k = height-1 ; k >= 1 ; k -- )
			{
				for ( int l = 1 ; l <= k ; l ++ )
				{
					std::cout<<k ;
				}
				std::cout<<std::endl ;
			}
			if ( i == time-1  && j == waveTime -1 ) break ;
			std::cout<<std::endl ;
		}
	}
}
