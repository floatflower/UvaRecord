#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>

class card
{
public:
	bool match ( card* com_card )
	{
		return com_card -> m_num == this->m_num || com_card -> m_icon == this->m_icon ;
	}
	char m_num ;
	char m_icon ;
};
class cardStack : public std::stack < card * >
{
};

int main()
{
	std::string eachLine ;
	while ( true )
	{
		std::vector < card * > cardVec ;
		for ( int i = 0 ; i < 2 ; i ++ )
		{
			getline ( std::cin , eachLine ) ;
			if ( eachLine == "#" ) exit( 0 ) ;
			for ( std::string::iterator it_eachLine = eachLine.begin() ;
				 		it_eachLine < eachLine.end() ;
						it_eachLine ++ )
			{
				if ( *it_eachLine == ' ' ) continue ;
				card *temp_card = new card ;
				temp_card -> m_num = *it_eachLine ;
				it_eachLine++ ;
				temp_card -> m_icon = *it_eachLine ;
				cardVec.push_back ( temp_card ) ;
			}
		}
		std::vector< cardStack * > stackVec ;
		for ( std::vector< card * >::iterator it_cardVec = cardVec.begin() ;
			 		it_cardVec < cardVec.end() ;
					it_cardVec ++	)
		{
			int size_stackVec = stackVec.size () ;
			std::cout << size_stackVec << std::endl ;
			if ( size_stackVec >= 3 )
			{
					card* temp_card = stackVec.at( size_stackVec - 3 ) -> top() ;
					if ( ( * ( it_cardVec ) ) -> match ( temp_card ) )
					{
						stackVec.at ( size_stackVec - 3  ) -> push ( temp_card ) ;
						continue ;	
					}
			}	
			if ( size_stackVec >= 1)
			{
					card* temp_card = stackVec.at( size_stackVec - 1 ) -> top() ;
					if ( ( * ( it_cardVec ) ) -> match ( temp_card ) )
					{
						stackVec.at ( size_stackVec - 1  ) -> push ( temp_card ) ;
						continue ;
					}
			}
			cardStack *newStack = new cardStack ;
			newStack -> push ( *(it_cardVec) )	;
			stackVec.push_back ( newStack ) ;
		}	

		std::cout << stackVec.size() << " piles remaining: " ;
		for ( std::vector< cardStack * >::iterator it_stackVec = stackVec.begin() ;
					it_stackVec < stackVec.end()-1 ;
					it_stackVec ++ )
		{
			std::cout << ( *it_stackVec ) -> size () << " " ;
		}
		std::cout << (*( stackVec.end() - 1 )) -> size () << std::endl ;
		
	}
}
