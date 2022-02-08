#ifndef BEZ_HPP
#define BEZ_HPP

#include "alien_consts.hpp"
#include "consts.hpp"



plot_type* set_reper_points(const plot_type& start_p);


void make_path_bezje(plot_type* path_, plot_type* reper_points);


double get_t(int power, const double t_bezje);


#endif