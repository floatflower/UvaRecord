#include <iostream>
#include <iomanip>
class TimeUsage 
{
public :
	TimeUsage ( int startHour , int startMinute , int endHour , int endMinute )
	{
		totalStart = startHour * 60 + startMinute ;
		totalEnd = endHour * 60 + endMinute ;
		_10P8A = 0 ;
		_8A6P = 0 ;
		_6P10P = 0 ;
	}	
	float getTotalFee ( void )
	{
		float allFee = 600 * _10P8AFee + 240 * _6P10PFee + 600 * _8A6PFee ; 

		float startFee = calcFee ( totalStart ) ;

		float endFee = calcFee ( totalEnd ) ;

		totalFee = endFee - startFee < 0 ? endFee - startFee + allFee : endFee - startFee ;	
	
	}
	float calcFee ( int time )
	{
		float totalFee = 0 ;
		if ( time > 1320 )
		{
			totalFee = 480 * _10P8AFee + 600 * _8A6PFee + 240 * _6P10PFee + ( time - 1320 ) * _10P8AFee ;
			_10P8A += 480 ;
			_8A6P += 600 ;
			_6P10P += 240 ;
			_10P8A += ( time - 1320 ) ;
		}
		else if ( time > 1080 )
		{
			totalFee = 480 * _10P8AFee + 600 * _8A6PFee + ( time - 1080 ) * _6P10PFee ;
			_10P8A += 480 ;
			_8A6P += 600 ;
			_6P10P += ( time - 1080 ) ;
		}
		else if ( time > 480 )
		{
			totalFee = 480 * _10P8AFee + ( time - 480 ) * _8A6PFee ;
			_10P8A += 480 ;
			_8A6P += ( time - 480 ) ;
		}
		else 
		{
			totalFee = time * _10P8AFee ;
			_10P8A += time ;
		}
		return totalFee ;
	}
	void setChargingStep ( char mode ) 
	{
		switch ( mode )
		{
			case 'A' : 
				_8A6PFee = 0.1 ;
				_6P10PFee = 0.06 ;
				_10P8AFee = 0.02 ;
				break ;
			case 'B' :
				_8A6PFee = 0.25 ;
				_6P10PFee = 0.15 ;
				_10P8AFee = 0.05 ;
				break ;
			case 'C' :
				_8A6PFee = 0.53 ;
				_6P10PFee = 0.33 ;
				_10P8AFee = 0.13 ;
				break ;
			case 'D' :
				_8A6PFee = 0.87 ;
				_6P10PFee = 0.47 ;
				_10P8AFee = 0.17 ;
				break ;
			case 'E' :
				_8A6PFee = 1.44 ;
				_6P10PFee = 0.8 ;
				_10P8AFee = 0.3 ;
				break ;
		}
	}
	int totalFee ;
	int totalStart ;
	int totalEnd ;
	int _8A6P ;
	int _6P10P ; 
	int _10P8A ;
	float _8A6PFee ;
	float _6P10PFee ;
	float _10P8AFee ;
};

int main () 
{
	char chargingStep ;
	std::string phoneNumber ;
	int startHour ;
	int startMinute ;
	int endHour ;
	int endMinute ;
	while ( std::cin >> chargingStep )
	{
		if ( chargingStep == '#' ) break ;
		std::cin >> phoneNumber >> startHour >> startMinute >> endHour >> endMinute ;

		TimeUsage *time = new TimeUsage ( startHour , startMinute , endHour , endMinute ) ;
		time -> setChargingStep(chargingStep) ;
		std::cout << std::setw(10) << phoneNumber 
		 					<< std::setw(6)  << time -> _8A6P 
						 	<< std::setw(6)  << time -> _6P10P 
							<< std::setw(6)  << time -> _10P8A
							<< std::setw(3)  << time -> getTotalFee () ;
	}
}
