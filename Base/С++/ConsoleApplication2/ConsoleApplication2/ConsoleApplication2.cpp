#include <iostream>
#include <vector>
#include <cassert>
#include <queue>

struct Pos {
	int i;
	int j;
	Pos(const int i, const int j)
		:i(i)
	    ,j(j)
	{}
};
bool operator == (const Pos& left, const Pos& right) {
	return left.i == right.i && left.j == right.j;
}
int main()
{
	const int UNDEF = -1;
	int n;
	int i;
	scanf("%d", &n);
	std::vector<std::vector<char>> a(n, std::vector<char>(n));
	std::vector<std::vector<Pos>> from(n, std::vector<Pos>(n, Pos(UNDEF, UNDEF)));
	std::queue<Pos>q;
	Pos start(UNDEF, UNDEF);
	Pos finish(UNDEF, UNDEF);
	for (int j = 0; j < n; j++) {
		scanf("%c", &a [i][j]);
		if (a[i][j] == '@') {
			if (start.i == UNDEF) {
				assert(start.j == UNDEF);
				start = Pos(i, j);
				q.push(start);
			}
			else {
				assert(finish.i == UNDEF);
				assert(finish.i == UNDEF);
				finish = Pos(i, j);
				a[i][j] = '.';
			}
		}
	}
	assert(finish.i != UNDEF);
	assert(finish.j != UNDEF);
	std::queue <Pos> q;
	q.push(start);
	while (!q.empty()) {
		Pos cur = q.front();
		q.pop();
		for (int di = -2; di <= 2; di++) {
			for (int dj = -2; dj <= 2; dj++) {
				if (di * di + dj * dj == 5) {
					int ni = cur.i + di;
					int nj = cur.j + dj;
					if (0 <= ni && ni < n && 0 <= nj && nj < n &&
						a[ni][nj] == '.' && from[ni][nj].i == UNDEF)
					{
						q.push(Pos(ni, nj));
						from[ni][nj] = cur;
					}
				}
			}

		}
	}
	return 0;

}


