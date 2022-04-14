#include "cities.hh"
std::istream& operator>> (std::istream& iSCities, Cities& isCurCities){

	isCurCities.cities_lst = std::vector<Cities::coord_t>();		
	std::string loc_x;
	std::string loc_y;

	while (iSCities >> loc_x) {
		iSCities >> loc_y;

		Cities::coord_t coord_pair(std::stoi(loc_x), std::stoi(loc_y));

		isCurCities.cities_lst.push_back(coord_pair);
	}

	return iSCities;
}
std::ostream& operator<< (std::ostream& oSCities, Cities& osCurCities){

	for (long unsigned int i = 0; i < osCurCities.cities_lst.size(); i++) {
		oSCities << osCurCities.cities_lst[i].first << "\t" << osCurCities.cities_lst[i].second << "\n";
	}
	return oSCities;

}

unsigned Cities::city_size() {
	return cities_lst.size();
}


double Cities::total_path_distance(const permutation_t& ordering) const{
	double all_distance = 0;
	//std::cout << "function called" << std::endl;
	for(long unsigned int j = 0; j < cities_lst.size()-1; j++){
	//	std::cout << j << std::endl;
	//	std::cout << "list size = " << cities_lst.size() << std::endl;
		coord_t c1 = cities_lst[ordering[j]];
		coord_t c2 = cities_lst[ordering[j+1]];
		double cur_hypot = std::hypot(c2.first - c1.first, c2.second - c1.second);
		all_distance += cur_hypot;
	//	std::cout << j << "second print" << std::endl;
	}
	coord_t c1 = cities_lst[ordering[cities_lst.size() - 1]];
	coord_t c2 = cities_lst[ordering[0]];
	double cur_hypot = std::hypot(c2.first - c1.first, c2.second - c1.second);
	all_distance += cur_hypot;
	return all_distance;
}
 Cities Cities::reorder(const permutation_t& ordering) const{
 	std::vector<coord_t> nu_ord;
 	for(long unsigned int k=0; k < ordering.size()-1; k++){
 		coord_t temp_city = cities_lst[ordering[k]];
 		nu_ord.push_back(temp_city);
 	}
 	Cities nu_city;
 	nu_city.cities_lst = nu_ord;
 	return nu_city;
 }
 Cities::permutation_t Cities::random_permutation(unsigned len){
	permutation_t nu_perm;
 	for (unsigned c=0; c< len; c++){
 		nu_perm.push_back(c);
 	}

 	std::random_shuffle(nu_perm.begin(), nu_perm.end());
 	return nu_perm;
 }



