/*
 * Created by Gabe H and Daniel K
 * Cities.cc (i.e. the implementation of methods in cities.hh 
 */
#include "cities.hh"
std::istream& operator>> (std::istream& iSCities, Cities& isCurCities){ // Overwriting operator for pulling from the stream

	isCurCities.cities_lst = std::vector<Cities::coord_t>();	// Set up our vector of cities_lst as a vector of coords
	std::string loc_x; 						// Set up x and y inputs
	std::string loc_y;

	while (iSCities >> loc_x) { 					// Loop while we can read into x & record first value into x
		iSCities >> loc_y; 					// record value after x into y

		Cities::coord_t coord_pair(std::stoi(loc_x), std::stoi(loc_y)); // create the chord pair and converts the strings of x&y into ints

		isCurCities.cities_lst.push_back(coord_pair); 			// Add to vector
	}

	return iSCities; 							// Return the istream out
}

std::ostream& operator<< (std::ostream& oSCities, Cities& osCurCities){ // Overwriting the operator for pushing into the stream

	for (long unsigned int i = 0; i < osCurCities.cities_lst.size(); i++) { 				// Loop through the vector of cities_lst
		oSCities << osCurCities.cities_lst[i].first << "\t" << osCurCities.cities_lst[i].second << "\n";// Push to stream the first of the pair, then a tab, then the second of the pair
	}
	return oSCities; 			// Return the stream

}

/*
 * Now we move to the actual member functions.
 */

unsigned Cities::city_size() { 	  // Public function to return the size of the vector cities_lst
	return cities_lst.size(); // which is a private member
}


double Cities::total_path_distance(const permutation_t& ordering) const{      	// Calculates the distance when given the ordering of a list
	double all_distance = 0;
	//std::cout << "function called" << std::endl; 				// A few debug lines
	
	for(long unsigned int j = 1; j < cities_lst.size()-1; j++){		// Loop through entire cities_lst
	
	//	std::cout << j << std::endl;
	//	std::cout << "list size = " << cities_lst.size() << std::endl;
	
		coord_t c1 = cities_lst[ordering[j]];						// Take the first city
		coord_t c2 = cities_lst[ordering[j+1]]; 					// Take the next city/destination
		double cur_hypot = std::hypot(c2.first - c1.first, c2.second - c1.second); 	// Use hypot function to get the distance between the two
		all_distance += cur_hypot; 							// Add to the full travel distance
	//	std::cout << j << "second print" << std::endl;
	}
	
	coord_t c1 = cities_lst[ordering[cities_lst.size() - 1]]; 				// Then get the final city...
	coord_t c2 = cities_lst[ordering[0]]; 							// ...and the first city
	
	double cur_hypot = std::hypot(c2.first - c1.first, c2.second - c1.second); 		// Find the distance between the two (as the TSP must return home)
	
	all_distance += cur_hypot; 								// Add it!!
	
	return all_distance; 					// Return and rejoice
}


 Cities Cities::reorder(const permutation_t& ordering) const{  	// Take permutation, reorder the cities list as the ordering demands
 	
	 std::vector<coord_t> nu_ord; 				// Create a vector

 	for(long unsigned int k=0; k < ordering.size(); k++){ 	// Loop through the permutations vector

 		coord_t temp_city = cities_lst[ordering[k]]; 	// Take the city requested by the permutations vector...
 		nu_ord.push_back(temp_city); 			// ...add it to the newly created vector.
 	}

 	Cities nu_city; 					// Create a new cities object...
 	nu_city.cities_lst = nu_ord; 				// ...set the cities_list of that object to our new setup...
 	return nu_city; 					// ...return and rejoice
 }


 Cities::permutation_t Cities::random_permutation(unsigned len){  			// Function for making a new permutation
	
	 permutation_t nu_perm; 							// create a new permutation vector (with a maybe similar naming convention
 	
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); 	// Create a RNG seed from the system clock

	std::mt19937 rng(seed); 							// Create RNG with said seed
	
	for (unsigned c=0; c< len; c++){ 						// Fill the permutation vector with numbers 1,2,...,len
 		nu_perm.push_back(c);
 	}

 	std::shuffle(nu_perm.begin(), nu_perm.end(), rng); 				// Shuffle the permutation vector with the rng
 	return nu_perm; 					// return and rejoice that you no longer must read these comments
 }


