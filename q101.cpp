#include <iostream>
#include <vector>

int main()
{
	int brickAmount ;
	while ( std::cin >> brickAmount )
	{
		std::vector < std::vector < int > * > place ( brickAmount ) ;
		int *location = new int [brickAmount] ;
		for ( int i = 0 ; i < brickAmount ; i ++ )
		{
			std::vector<int> *temp_vector = new std::vector<int> ;
			temp_vector -> push_back ( i ) ;
			place[i] = temp_vector ;
			location[i] = i ;
		}
		std::string action1 ;
		std::string action2 ;
		int begin ;
		int end ;
		while ( std::cin >> action1 )
		{
			if ( action1 == "quit" ) break ;
			std::cin >> begin >> action2 >> end ;
			if ( location[begin] == location[end] ) continue ;
			if ( action1 == "move" )
			{
				if ( action2 == "onto" )
				{	
					int endAtPile = location[end] ;
					while ( place.at( endAtPile ) -> back() != end )
					{
						int popBrick = place.at(endAtPile)->back() ;
						place.at(endAtPile) -> pop_back() ;
						place.at( popBrick ) -> push_back(popBrick) ;
						location[popBrick] = popBrick ;
					}
				}
					int beginAtPile = location[begin] ;
					while ( place.at( beginAtPile )->back() != begin )
					{
						int popBrick = place.at(beginAtPile)->back() ;
						place.at(beginAtPile) -> pop_back() ;
						place.at( popBrick ) -> push_back(popBrick) ;
						location[popBrick] = popBrick ;
					}
						int targetBrick =  place.at(beginAtPile) -> back() ;
						place.at( beginAtPile ) -> pop_back() ;
						place.at( location[end] ) -> push_back(targetBrick) ;
						location[begin] = location[end] ;
			}
			if ( action1 == "pile" )
			{
				if ( action2 == "onto" )
				{
					int endAtPile = location[end] ;
					while ( place.at( endAtPile ) -> back() != end )
					{
						int popBrick = place.at(endAtPile)->back() ;
						place.at( endAtPile ) -> pop_back() ;
						place.at( popBrick ) -> push_back(popBrick) ;
						location[popBrick] = popBrick ;
					}	
				}
				int beginAtPile = location[begin] ; 
				std::vector<int> buffer ;
				while ( place.at(beginAtPile) -> back() != begin )
				{
					int popBrick = place.at(beginAtPile) -> back() ; 
					place.at(beginAtPile) -> pop_back() ;
					buffer.push_back ( popBrick ) ;
				}
				buffer.push_back(place.at(beginAtPile)->back() ) ;
				place.at(beginAtPile) -> pop_back();
				for( std::vector<int>::reverse_iterator it_buffer = buffer.rbegin();
						 it_buffer < buffer.rend() ;
						 it_buffer ++ )
				{
					place.at( location[end] ) -> push_back ( *it_buffer ) ;
				}
				for( std::vector<int>::reverse_iterator it_buffer = buffer.rbegin();
						 it_buffer < buffer.rend() ;
						 it_buffer ++ )
				{
					location[*it_buffer] = location[end];
				}
			}
		int index = 0 ;
		for ( std::vector<std::vector<int>*>::iterator it_place = place.begin() ;
			 		it_place < place.end() ;
					it_place ++	, index ++ )
		{
			std::cout << index << ":";
			for ( std::vector<int>::iterator it_pile = (*it_place) -> begin() ;
				 		it_pile < (*it_place) -> end () ;
						it_pile ++	)
			{
				std::cout << " " << (*it_pile) ;
			}
			std::cout << std::endl ;
		}
			std::cout << std::endl ;
		}

		int index = 0 ;
		for ( std::vector<std::vector<int>*>::iterator it_place = place.begin() ;
			 		it_place < place.end() ;
					it_place ++	, index ++ )
		{
			std::cout << index << ":";
			for ( std::vector<int>::iterator it_pile = (*it_place) -> begin() ;
				 		it_pile < (*it_place) -> end () ;
						it_pile ++	)
			{
				std::cout << " " << (*it_pile) ;
			}
			std::cout << std::endl ;
		}
	}
}
