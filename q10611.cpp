#include <iostream>

void sort ( int ladyChimp[] , int size )
{
	int bigger_index ;
	for ( int i = 0 ; i < size ; i ++ )
	{
		int bigger = ladyChimp[i] ;
		for ( int j = i ; j < size ; j ++ )
		{
			if ( ladyChimp[j] >= bigger )
			{
				bigger = ladyChimp[j] ;
				bigger_index = j ;
			}
		}
		int temp = ladyChimp[i] ;
		ladyChimp[i] = ladyChimp[bigger_index] ;
		ladyChimp[bigger_index] = temp ;
	}	
}

int main ( ) 
{
	int ladyChimpAmount ;
	while ( std::cin >> ladyChimpAmount )
	{
		int ladyChimp[ladyChimpAmount] ;
		for ( int i = 0 ; i < ladyChimpAmount ; i ++ )
		{
			std::cin >> ladyChimp[i] ;
		}
		sort(ladyChimp,ladyChimpAmount);
		
		int queryAmount ;
		std::cin >> queryAmount ;


		int LuchuHeight ;
		int index = -1 ;

		int chosenHigher ;
		int chosenShorter ;

		for ( int i = 0 ; i < queryAmount ; i ++ )
		{
			std::cin >> LuchuHeight ;
			chosenHigher = LuchuHeight ;
			chosenShorter = LuchuHeight ;
			
			for ( int i = 0 ; i < ladyChimpAmount ; i ++ )
			{
				if ( ladyChimp[i] > LuchuHeight )
				{
					chosenHigher = ladyChimp[i] ;
				}
				if ( ladyChimp[i] < LuchuHeight )
				{
					chosenShorter = ladyChimp[i] ;
					break ;
				}
			}
			chosenShorter == LuchuHeight ? std::cout << "X " : std::cout << chosenShorter << " " ;
			chosenHigher == LuchuHeight ? std::cout << "X"<<std::endl : std::cout << chosenHigher << std::endl ;
		}
	}
}
