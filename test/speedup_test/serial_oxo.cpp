#include "monte_carlo_search_tree.hpp"
#include "oxo.hpp"

#include <fstream>
#include <ctime>

struct seed_generator {
  unsigned state = 0;
  int operator () (void);
};

int main(int argc, char** argv) {

// Namespaces
using Oxo = game::Oxo::OxoGame<>;
using Move = game::Oxo::OxoAction;

// Output
std::ofstream data_set;
data_set.open ("speedup_oxo.csv", std::ios::app);
// Format:
// | SIZE | SIMULATIONS | ELAPSED TIME |

int outer_it = 10, inner_it;
int n_sample = 20;
seed_generator gen_seed;

for (inner_it = 50; inner_it <= 1000; inner_it += 50) {

  for (int n = 0; n < n_sample; ++n) {

    Oxo oxo_board;
    oxo_board.set_seed(gen_seed());
    Move current_player_move;
    MonteCarloSearchTree<Oxo, Move> mcst_player_1(outer_it, inner_it);
    MonteCarloSearchTree<Oxo, Move> mcst_player_2(outer_it, inner_it);

    std::clock_t c_start = std::clock();

    while( !oxo_board.get_terminal_status() ) {
      if ( oxo_board.get_agent_id() == 1 ) {
        current_player_move = mcst_player_1.uct_search();
        mcst_player_2.change_current_status(current_player_move);
      }
      else {
        current_player_move = mcst_player_2.uct_search();
        mcst_player_1.change_current_status(current_player_move);
      }
      oxo_board.apply_action(current_player_move);
    }

    std::clock_t c_end = std::clock();
    double time_elapsed_ms = 1000.0 * (c_end-c_start) / CLOCKS_PER_SEC;

    data_set << 0 << "," << inner_it << "," << time_elapsed_ms << std::endl;

  }

}

data_set.close();

return 0;

}

int seed_generator::operator () () {
  time_t rawtime;
  struct tm * ptm;
  time ( &rawtime );
  ptm = gmtime ( &rawtime );
  state = (state+1);
  return state + 10*ptm->tm_sec + 100*(ptm->tm_min) + 1000;
}
