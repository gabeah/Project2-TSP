#include "cities.hh"

std::istream& operator>> (std::istream& iSCities, Cities& isCurCities){

	isCurCities.cities_list = std::vector<coord_t>();		
	std::string loc_x;
	std::string loc_y;

	while (iSCities >> loc_x) {
		iSCities >> loc_y;

		coord_t coord_pair(loc_x, loc_y);

		isCurCities.cities_list.pushback(coord_pair);
	}

	return iSCities;
}
std::ostream& operator<< (std::ostream& oSCities, Cities& osCurCities){

	for (i = 0; i < osCurCities.cities_list.size(); i++;) {
		oSCities << cities_list[i].first() << "\t" << cities_list[i].second() << "\n";
	}
	return oSCities;

}
Cities::Cities() {
	num_perm = 0;
	

}

