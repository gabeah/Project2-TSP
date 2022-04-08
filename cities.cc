#include "cities.hh"

std::istream& operator>> (std::istream& iSCities, Cities& isCurCities){
	
	iSCities >> x >> y;
}
std::ostream& operator<< (std::ostream& oSCities, Cities& osCurCities){
	
	output << x << y; 
	return output;
}

Cities::Cities() {
	num_perm = 0;
	
}
