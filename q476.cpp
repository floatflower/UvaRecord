#include <iostream>
#include <vector>

class Square 
{
public :
	Square ( float leftTopX , float leftTopY , float rightDownX , float rightDownY , float squareNumber )
	: m_leftTopX ( leftTopX ) ,
	  m_leftTopY ( leftTopY ) ,
		m_rightDownX ( rightDownX ) ,
		m_rightDownY ( rightDownY ) ,
		m_squareNumber ( squareNumber )
	{
	}
	float m_leftTopX ;
	float m_leftTopY ;
	float m_rightDownX ;
	float m_rightDownY ;
	float m_squareNumber ;
};

int main ( )
{
	char firstChar ;
	float leftTopX ;
	float leftTopY ;
	float rightDownX ;
	float rightDownY ;
	int squareCount = 0;
	
	std::vector< Square * > squareVector ;
	
	for ( ; ; )
	{
		std::cin >> firstChar ;
  	if ( firstChar == '*' ) break ;
		squareCount ++ ;
		std::cin >> leftTopX >> leftTopY >> rightDownX >> rightDownY ;
		Square *temp_square = new Square ( leftTopX , leftTopY , rightDownX , rightDownY , squareCount );
		squareVector.push_back ( temp_square ) ;
	}

	float input1 ;
	float input2 ;

	int PointCount = 0 ;

	std::vector< Square * >::iterator it_squareVector ;

	while ( std::cin >> input1 >> input2 )
	{
		bool isIn = false ;
		//std::cout<<input1<<" "<<input2<<std::endl ;
		if ( input1 == ( float )9999.9 && input2 == ( float )9999.9 ) {
			break ;
		} 
		PointCount ++ ;
		for ( it_squareVector = squareVector.begin() ;
				  it_squareVector < squareVector.end() ;
					it_squareVector ++ )
		{
			if ( ( input1 > (*it_squareVector)->m_leftTopX && input1 < (*it_squareVector)->m_rightDownX ) &&
					 ( input2 < (*it_squareVector)->m_leftTopY && input2 > (*it_squareVector)->m_rightDownY ) )
			{
				isIn = true ;
				std::cout << "Point " << PointCount << " is contained in figure " << (*it_squareVector)->m_squareNumber<<std::endl ;
			}
		}
		if ( ! isIn )
		{
				std::cout << "Point " << PointCount << " is not contained in any figure" << std::endl;
		}
	}
}
