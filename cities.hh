/*
 * API file for Travelling-Salesperson Cities class and utilities
 */

#pragma once

#include <vector>
#include <istream>
#include <ostream>
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <cmath>
#include <fstream>
#include <assert.h>
#include <cstdlib>


// Representation of an ordering of cities
class Cities {
 public:
  // A pair of integral coordinates for each city
  using coord_t = std::pair<int, int>;

  // An ordering of cities. Each value represents a unique index
  // into the current city ordering in some container.
  using permutation_t = std::vector<unsigned int>;

  // Given a permutation, return a new Cities object where the order of the
  // cities reflects the original order of this class after reordering with
  // the given ordering. So for example, the ordering { 1, 0 } simply swaps
  // the first two elements (coordinates) in the new Cities object.
  Cities reorder(const permutation_t& ordering) const;

  // For a given permutation of the cities in this object,
  // compute how long (distance) it would take to traverse all the cities in the
  // order of the permutation, and then returning to the first city.
  // The distance between any two cities is computed as the Euclidean 
  // distance on a plane between their coordinates.
  double total_path_distance(const permutation_t& ordering) const;

  permutation_t random_permutation(unsigned len);

  Cities() = default;
  //Cities(const std::string& filename);

  ~Cities() = default;
 
  friend std::istream& operator>> (std::istream& iSCities, Cities& isCurCities);
  friend std::ostream& operator<< (std::ostream& oSCities, Cities& osCurCities);

  unsigned city_size();
 private:
  std::vector<coord_t> cities_lst;
  permutation_t cities_ord;
  int num_perm;
};
std::istream& operator>> (std::istream& iSCities, Cities& isCurCities);
std::ostream& operator<< (std::ostream& oSCities, Cities& osCurCities);
