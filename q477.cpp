#include <iostream>
#include <cmath>
#include <vector>

class Shape 
{
public :
		Shape ( float shapeNumber ) 
			: m_shapeNumber ( shapeNumber ) 
		{} 
		virtual bool in ( float inputX , float inputY ){}
		float m_shapeNumber ;
} ; 

class Rectangle : public Shape 
{
public :
	Rectangle ( float leftTopX , float leftTopY , float rightDownX , float rightDownY , int shapeNumber )
		: m_leftTopX ( leftTopX ) ,
			m_leftTopY ( leftTopY ) ,
			m_rightDownX ( rightDownX ) ,
			m_rightDownY ( rightDownY ) ,
			Shape ( shapeNumber ){}
	virtual bool in ( float inputX , float inputY )
	{
		return ( inputX > m_leftTopX && inputX < m_rightDownX ) && ( inputY < m_leftTopY && inputY > m_rightDownY ) ;
	}
	float m_leftTopX ;
	float m_leftTopY ;
	float m_rightDownX ;
	float m_rightDownY ;
} ;

class Circle : public Shape 
{
public :
	Circle ( float centerX , float centerY , float radius , int shapeNumber )
		: Shape ( shapeNumber ) ,
			m_centerX ( centerX ) ,
			m_centerY ( centerY ) ,
			m_radius ( radius ){}
	virtual bool in ( float inputX , float inputY )
	{
		float distanceX ;
		float distanceY ;
		float distanceRadius ;
		distanceX = inputX - m_centerX ;
		distanceY = inputY - m_centerY ;
		distanceRadius = sqrt ( pow ( distanceX , 2 ) + pow ( distanceY , 2 ) ) ; 
		return distanceRadius < m_radius ;
	}
	float m_centerX ;
	float m_centerY ;
	float m_radius ;
};

int main ()
{
	std::vector< Shape * > shapeVector ;
	int shapeCount = 0 ;
	char firstChar ;
	while ( std::cin>>firstChar )
	{
		shapeCount ++ ;
		if ( firstChar == (char) '*' ) break ;
		if ( firstChar == (char) 'r' ) 
		{
		  float leftTopX ;
			float leftTopY ;
			float rightDownX ;
			float rightDownY ;
			std::cin >> leftTopX >> leftTopY >> rightDownX >> rightDownY ;
			Shape *temp_shape = new Rectangle ( leftTopX , leftTopY , rightDownX , rightDownY , shapeCount ) ;
			shapeVector.push_back ( temp_shape ) ;
		}
		if ( firstChar == (char)'c' )
		{
			float centerX ;
			float centerY ;
			float radius ;

			std::cin >> centerX >> centerY >> radius ;
			Shape *temp_shape = new Circle ( centerX , centerY , radius , shapeCount ) ;
			shapeVector.push_back ( temp_shape ) ;
		}
	}	
	float inputX ;
	float inputY ;
	float pointCount = 0 ; 
	while ( std::cin >> inputX >> inputY )
	{
		bool isIn = false ;
		pointCount ++ ;
		if ( inputX == (float) 9999.9 && inputY == (float) 9999.9 ) break ;
		for ( std::vector< Shape * >::iterator it_shapeVector = shapeVector.begin() ;
			    it_shapeVector < shapeVector.end () ;
			    it_shapeVector ++	)
		{
				if ( ( *it_shapeVector ) -> in ( inputX , inputY ) )
				{
					isIn = true ;
					std::cout<<"Point "<<pointCount<<" is contained in figure "<< ( *it_shapeVector ) -> m_shapeNumber <<std::endl ;
				}
		}
		if ( ! isIn )
		{
			std::cout << "Point "<<pointCount<<" is not contained in any figure"<<std::endl ;
		}
	}
}
