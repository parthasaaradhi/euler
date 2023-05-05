#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct point { int x; int y; long long dst;};

class cmpr {
	public:
		bool operator() (struct point &a, struct point &b) {
			return a.dst >= b.dst;
		}
};

int main() {
	long long matrix[80][80];
	bool visited[80][80];
	long long min_no = 9999;
	struct point p,cur;
	priority_queue<struct point, vector<struct point>, cmpr> q;
	for(int i=0;i<80;i++)
		for(int j=0;j<80;j++) {
			cin>> matrix[i][j];
			visited[i][j] = false;
			min_no = min(matrix[i][j], min_no);
		}
	p.x = 0; p.y = 0; p.dst = matrix[0][0] + min_no*(79-0) + min_no*(79-0);
	visited[0][0] = true;
	q.push(p);
	while(!q.empty()) {
		cur = q.top();
		q.pop();
		if(cur.x == 79 && cur.y == 79) {
			cout << cur.dst << endl;
			return 0;
		}
		if(cur.x>0) {
			p.x = cur.x-1; p.y = cur.y;
			if(!visited[p.x][p.y]) {
				visited[p.x][p.y] = true;
				p.dst = cur.dst - min_no*(79-cur.x) - min_no*(79-cur.y)
					+ matrix[p.x][p.y] + min_no*(79-p.x) + min_no*(79-p.y);
				q.push(p);
			}
		}
		if(cur.y>0) {
			p.x = cur.x; p.y = cur.y-1;
			if(!visited[p.x][p.y]) {
				visited[p.x][p.y] = true;
				p.dst = cur.dst - min_no*(79-cur.x) - min_no*(79-cur.y)
					+ matrix[p.x][p.y] + min_no*(79-p.x) + min_no*(79-p.y);
				q.push(p);
			}
		}
		if(cur.x<79) {
			p.x = cur.x+1; p.y = cur.y;
			if(!visited[p.x][p.y]) {
				visited[p.x][p.y] = true;
				p.dst = cur.dst - min_no*(79-cur.x) - min_no*(79-cur.y)
					+ matrix[p.x][p.y] + min_no*(79-p.x) + min_no*(79-p.y);
				q.push(p);
			}
		}
		if(cur.y<79) {
			p.x = cur.x; p.y = cur.y+1;
			if(!visited[p.x][p.y]) {
				visited[p.x][p.y] = true;
				p.dst = cur.dst - min_no*(79-cur.x) - min_no*(79-cur.y)
					+ matrix[p.x][p.y] + min_no*(79-p.x) + min_no*(79-p.y);
				q.push(p);
			}
		}
	}
	return 0;
}
