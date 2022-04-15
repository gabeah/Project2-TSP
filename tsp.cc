/*
 * Created by Daniel K and Gabe H
 */

#include "cities.hh"

int main(int argc, char *argv[]){ 							// Start function with ability to read from flags
	if(argc < 2){

		std::cout << "ERROR: NO FILE TO OPTIMIZE, try again pls <3 :) \n";  	// be mad if you don't give a file
		return 0;
	}

	else {


		std::ofstream os_file ("shortest.tsv", std::ofstream::out); 		// create the oStream file of 'shortest.tsv'

		Cities input_city; 							// create a cities object

		std::ifstream is_file(argv[1], std::ifstream::in); 			// setup iStream

		is_file >> input_city; 							// using our super overwritten operator, read from iStream to our city object

		unsigned city_amt = input_city.city_size(); 				// set city_amt to the size of our cities_lst vector

		Cities::permutation_t cur_perm = input_city.random_permutation(city_amt); // Create a starting permutaion

		double best_route = input_city.total_path_distance(cur_perm); 		// find that distance and go from there

		Cities best_city; 							// create a new temp cities object

		for(int i = 0; i < 1000000; i++){ 					// do a million iterations (cause eitan said so apparently)

			cur_perm = input_city.random_permutation(city_amt); 		// new permutation!!

			double path_temp = input_city.total_path_distance(cur_perm); 	// see how long it is
			
			if(path_temp < best_route){ 					// if it beats the high score for shortest route...
				best_route = path_temp;					// ...set new high score...
				best_city = input_city.reorder(cur_perm);		// ...overwrite the order of our temp cities object...
				std::cout << i << "\t" << best_route << std::endl; 	// ...report the new high score along with the iteration number.
			}

		}
		os_file << best_city; 							// After a million iterations, output the best one to the oStream
		return 0; 			// RETURN AND REJOICE!!!!!!
	}
}

