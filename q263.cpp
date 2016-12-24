#include <iostream>

std::string reverse ( std::string raw )
{
	std::string backup = raw ;
	std::string rev ;
	bool start = false ;
	for ( int i = raw.size()-1 ; i >= 0 ; i -- )
	{
		char append = (char)backup.at(i);
		if ( append == (char)'0' && ( ! start ) )
		{
			continue ;
		}
		rev.append ( &append , sizeof(char) ) ;
		// std::cout << (char) raw.at(i) ;
		start = true ; 
	} 
	return rev ;
}

std::string processNumber ( std::string raw )
{
	std::string backup = raw ;
	std::string rev ;
	bool start = false ;
	for ( int i = 0 ; i < raw.size() ; i ++ )
	{
		char append = (char)backup.at(i);
		if ( append == (char)'0' && ( ! start ) )
		{
			continue ;
		}
		rev.append ( &append , sizeof(char) ) ;
		// std::cout << (char) raw.at(i) ;
		start = true ; 
	} 
	if ( ! start ) return "0" ;
	return rev ;
}

std::string descSort ( std::string value ) 
{
	std::string duplicate = value ;
	for ( size_t i = 0 ; i < duplicate.size ( ) ; i ++ )
	{
		char biggerIndex = i ;
		for ( size_t j = i ;  j < duplicate.size ( ) ; j ++ )
		{
			if ( duplicate [ j ] > duplicate [ biggerIndex ] ) biggerIndex = j ;
		}
		char temp = duplicate [ biggerIndex ] ;
		duplicate [ biggerIndex ] = duplicate [ i ] ;
		duplicate [ i ] = temp ;
	}
	return duplicate ;
}
std::string ascSort ( std::string value ) 
{
	std::string duplicate = value ;
	for ( size_t i = 0 ; i < duplicate.size ( ) ; i ++ )
	{
		char smallIndex = i ;
		for ( size_t j = i ;  j < duplicate.size ( ) ; j ++ )
		{
			if ( duplicate [ j ] < duplicate [ smallIndex ] ) smallIndex = j ;
		}
		char temp = duplicate [ smallIndex ] ;
		duplicate [ smallIndex ] = duplicate [ i ] ;
		duplicate [ i ] = temp ;
	}
	return duplicate ;
}

std::string minus ( std::string desc , std::string asc )
{
	std::string result ;
	std::string::reverse_iterator it_desc ;
	std::string::reverse_iterator it_asc ;
	int borrow = 0 ;
	for ( it_desc = desc.rbegin ( ) , it_asc = asc.rbegin ( ) ;
				it_desc != desc.rend ( ) ;
				it_desc ++ , it_asc ++ )
	{
/*		if ( it_asc + 1 < asc.rend ( ) ) it_asc ++ ;
		else {
			*it_asc = '0' ;
		}
*/
		int asc_real = *it_asc - 48 ;
		int desc_real = *it_desc - 48 ;
		int result_real = desc_real - asc_real - borrow ;
		if ( result_real >= 0 )
		{
			char append = (char)(result_real + 48) ;
			result.append(&append,sizeof(char)) ;
			borrow = 0 ;
		}
		else
		{
			char append = (char)(result_real + 58) ;
			result.append(&append,sizeof(char) ) ;
			borrow = 1 ;
		}		
	}
	return result ;
}

int main()
{
	std::string input ;
	while ( std::cin >> input )
	{
		if ( input == "0" ) break ;
		std::string inputAsc = ascSort ( input ) ;
		std::string inputDesc = descSort ( input ) ;
		std::string beginValue = minus ( inputDesc , inputAsc) ;
		std::string previous = processNumber( beginValue ) ;
		std::string afterCalc = previous ;
		int chainLength = 1 ;
		std::cout << "Original number was " << input << std::endl ;
		std::cout << processNumber ( inputDesc ) << " - " << processNumber ( inputAsc ) << " = " ;
		std::cout << processNumber ( reverse ( previous ) ) << std::endl ;
		while ( true )
		{
			afterCalc = minus ( descSort ( previous ) , ascSort ( previous ) )  ;
			chainLength ++ ;			
			
			std::string previousDesc = descSort ( previous ) ;
			std::string previousAsc = ascSort ( previous ) ;

			std::cout << processNumber(previousDesc) << " - " <<  processNumber(previousAsc)  << " = ";
			std::cout << processNumber ( reverse ( afterCalc ) ) << std::endl ;

			if ( afterCalc == previous ) break ;
			previous = processNumber ( afterCalc ) ;	
		}
		std::cout << "Chain length " << chainLength << std::endl ;
		std::cout << std::endl ;
	}
}
