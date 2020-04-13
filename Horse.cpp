#include <iostream>
#include <vector>

using namespace std;

const int coord_step[][2] = { {1, -2}, {2, -1} };

//bool in_square(int x, int y, int size_x, int size_y) {
//	return ((x > -1) && (x < size_x) && (y > -1) && (y < size_y));
//}
//
//struct stp {
//	int x{};
//	int y{};
//
//	bool operator==(stp rhs)const{
//		return x == rhs.x && y == rhs.y;
//	}
//};
//
//vector<stp> move(vector<stp> way, int outsize, int insize) {
//	vector<stp> new_steps;
//	int quantity_of_variants = sizeof(coord_step) / sizeof(coord_step[0]);
//	int way_size = (int)way.size();
//	for (int i = 0; i < quantity_of_variants; ++i) {
//		int new_x = way[way_size - 1].x + coord_step[i][0];
//		int new_y = way[way_size - 1].y + coord_step[i][1];
//		if (in_square(new_x, new_y, outsize, insize)) {
//			stp step;
//			step.x = new_x;
//			step.y = new_y;
//			new_steps.push_back(step);
//
//		}
//	}
//	return new_steps;
//}
//
//vector< vector<stp> > Fnew_ways(vector<stp> way, vector<stp> new_steps) {
//	vector< vector<stp> > list_of_result;
//	int quant_steps = (int)new_steps.size();
//	for (int i = 0; i < quant_steps; ++i) {
//		vector<stp> new_way = way;
//		new_way.push_back(new_steps[i]);
//		list_of_result.push_back(new_way);
//	}
//	return list_of_result;
//}
//
//vector< vector<stp> > update_list_of_ways(vector< vector<stp> > ways, int* results, int outsize, int insize, stp purpose) {
//	vector< vector<stp> > new_ways;
//	int quantity_of_ways = (int)ways.size();
//	for (int i = 0; i < quantity_of_ways; ++i) {
//		vector<stp> list_of_new_steps = move(ways[i], outsize, insize);
//		if ((int)list_of_new_steps.size() > 0) {
//			vector< vector<stp> > variants = Fnew_ways(ways[i], list_of_new_steps);
//			int size_variants = (int)variants.size();
//			for (int j = 0; j < size_variants; ++j) {
//				stp last_step = variants[j][(int)variants[j].size() - 1];
//				if (last_step == purpose) {
//					++* results;
//				}
//				else
//					new_ways.push_back(variants[j]);
//			}
//		}
//	}
//	return new_ways;
//}

//int main() {
//	vector< vector<stp> > ways;
//	int results{};
//	int n, m;
//	cin >> n >> m;
//	stp purpose;
//	purpose.x = m - 1;
//	purpose.y = 0;
//	{
//		stp start;
//		start.x = 0;
//		start.y = n - 1;
//		vector<stp> vstart = { {start} };
//		ways.push_back(vstart);
//	}
//	while (ways.size()) {
//		int* mention_results = &results;
//		ways = update_list_of_ways(ways, mention_results, m, n, purpose);
//		cout << (int)ways.size() << ' ' << results << endl;
//	}
//	cout << results;
//}

bool in_square(int x, int y, int size_x, int size_y) {
	return ((x > -1) && (x < size_x) && (y > -1) && (y < size_y));
}

int main() {
	int n, m;
	cin >> n >> m;
	vector< vector<int> > square(m, vector<int>(n, 0));
	square[0][n - 1] = 1;
	for (int i = 1; i < m; ++i)
		for (int j = n - 2; j > -1; --j) {
			int x1 = i - coord_step[0][0];
			int y1 = j - coord_step[0][1];
			int x2 = i - coord_step[1][0];
			int y2 = j - coord_step[1][1];
			if (in_square(x1, y1, m, n))
				square[i][j] += square[x1][y1];
			if (in_square(x2, y2, m, n))
				square[i][j] += square[x2][y2];
		}
	cout << square[m - 1][0];
}