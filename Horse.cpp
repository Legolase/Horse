#include <iostream>
#include <vector>

using namespace std;

const int coord_step[][2] = { {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1} };

bool in_square(int x, int y, int size_x, int size_y) {
	return ((x > -1) && (x < size_x) && (y > -1) && (y < size_y));
}

vector< vector<int> > move(vector< vector<int> > way, int outsize, int insize) {
	vector< vector<int> > new_steps;
	int quantity_of_variants = sizeof(coord_step) / sizeof(coord_step[0]);
	int way_size = (int)way.size();
	for (int i = 0; i < quantity_of_variants; ++i) {
		int new_x = way[way_size - 1][0] + coord_step[i][0]; 
		int new_y = way[way_size - 1][1] + coord_step[i][1];
		if (in_square(new_x, new_y, outsize, insize)) {
			bool unic = true;
			for (int j = 0; j < way_size; ++j)
				if ((new_x == way[j][0]) && (new_y == way[j][1])) {
					unic = false;
					break;
				}
			if (unic == true) {
				vector<int> step;
				step.push_back(new_x);
				step.push_back(new_y);
				new_steps.push_back(step);
			}
		}
	}
	return new_steps;
}

vector< vector< vector<int> > > Fnew_ways(vector< vector<int> > way, vector< vector<int> > new_steps) {
	vector< vector< vector<int> > > list_of_result;
	int quant_steps = (int)new_steps.size();
	for (int i = 0; i < quant_steps; ++i) {
		vector< vector<int> > new_way = way;
		new_way.push_back(new_steps[i]);
		list_of_result.push_back(new_way);
	}
	return list_of_result;
}

vector< vector< vector<int> > > update_list_of_ways(vector< vector< vector<int> > > ways, vector< vector< vector<int> > > *results ,int outsize, int insize, int end_x, int end_y) {
	vector< vector< vector<int> > > new_ways;
	int quantity_of_ways = (int)ways.size();
	for (int i = 0; i < quantity_of_ways; ++i) {
		vector< vector<int> > list_of_new_steps = move(ways[i], outsize, insize);
		if ((int)list_of_new_steps.size() > 0) {
			vector< vector< vector<int> > > variants = Fnew_ways(ways[i], list_of_new_steps);
			int size_variants = (int)variants.size();
			for (int j = 0; j < size_variants; ++j) {
				int last_x = variants[j][(int)variants[j].size() - 1][0];
				int last_y = variants[j][(int)variants[j].size() - 1][1];
				if ((last_x == end_x) && (last_y == end_y)) {
					(*results).push_back(variants[j]);
				}
				else
					new_ways.push_back(variants[j]);
			}
		}
	}
	return new_ways;
}

int main() {
	vector< vector< vector<int> > > ways;
	vector< vector< vector<int> > > results;
	int n, m;
	cin >> n >> m;
	{
		vector< vector<int> > start = { { 0, n-1 } };
		ways.push_back(start);
	}
	while (true) {
		vector< vector< vector<int> > > *mention_results = &results;
		vector< vector< vector<int> > > new_ways = update_list_of_ways(ways, mention_results, m, n, m-1, 0);
		if (new_ways == ways)
			break;
		else
			ways = new_ways;
	}
	cout << (int)results.size();
}