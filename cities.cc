#include "cities.hh"

std::istream& operator>> (std::istream& iSCities, Cities& isCurCities){

	isCurCities.cities_lst = std::vector<coord_t>();		
	std::string loc_x;
	std::string loc_y;

	while (iSCities >> loc_x) {
		iSCities >> loc_y;

		coord_t coord_pair(loc_x, loc_y);

		isCurCities.cities_lst.pushback(coord_pair);
	}

	return iSCities;
}
std::ostream& operator<< (std::ostream& oSCities, Cities& osCurCities){

	for (i = 0; i < osCurCities.cities_lst.size(); i++;) {
		oSCities << cities_lst[i].first() << "\t" << cities_lst[i].second() << "\n";
	}
	return oSCities;

}
double Cities::total_path_distance(const permutation_t& ordering) const{
	double all_distance = 0;
	for(j = 0; j < cities_lst.size()-1; j++){
		coord_t c1 = cities_lst[ordering[j]];
		coord_t c2 = cities_lst[ordering[j+1]];
		double cur_hypot = std::hypot(c2.first() - c1.first(), c2.second() - s1.second());
		all_distance += cur_hypot;
	}
	coord_t c1 = cities_lst[ordering[cities_lst.size() - 1]];
	coord_t c2 = cities_lst[ordering[0]];
	double cur_hypot = std::hypot(c2.first() - c1.first(), c2.second() - s1.second());
	all_distance += cur_hypot;
	return all_distance;
}
 Cities Cities::reorder(const permutation_t& ordering) const{
 	std::vector<coord_t> nu_ord;
 	for(k=0; k < ordering.size()-1; k++){
 		coord_t temp_city = cities_lst[ordering[k]];
 		nu_ord.push_back(temp_city);
 	}
 	return nu_ord;
 }
 permutation_t Cities::random_permutation(unsigned len){
 	unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count;
 	std::default_random_engine generator (gen_seed);

 	std::uniform_int_distribution<int> distro(0,len-1);

 	permutation_t perm_nu;
 	if (cities_ord.size() == 0) {
 		for (c=0; c< len-1< c++){
 			cities_ord.push_back(c);
 		}
 		return cities_ord;
 	}


 	for (d = 0; d<len-1, d++) {
 		int r = distro(gen_seed);

 		perm_nu.push_back(cities_ord[r]);

 		cities_ord.erase(r);

 		std::uniform_int_distribution<int> distro(0,len-d);
 	}
 	cities_ord = perm_nu;
 	return cities_ord;
 }

Cities::Cities() {
	num_perm = 0;
	

}

