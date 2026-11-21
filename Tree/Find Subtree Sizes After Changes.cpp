class Solution {
private:
	struct AdjustArray {
		vector<int> dhead;
		vector<int> dto;
		vector<int> dnext;
		uint32_t edgeCount;

		AdjustArray(size_t n) {
			dhead = vector<int>(n, -1);
			dto = vector<int>(n*2);
			dnext = vector<int>(n*2);
			edgeCount = 0;
		}

		void link(int from, int to) {
			dto[edgeCount] = to;
			dnext[edgeCount] = dhead[from];
			dhead[from] = edgeCount;
			++edgeCount;
		}
	};

	string groupMap;
	void rebuild(AdjustArray &src, AdjustArray &nw, int curr, int parent, vector<int> &closest) {
		int group = groupMap[curr] - 'a';

		int ancestor = closest[group];
		if (ancestor >= 0) {
			nw.link(ancestor, curr);
		} else if (parent >= 0) {
			nw.link(parent, curr);
		}
		closest[group] = curr;

		int nxt = src.dhead[curr];
		while (nxt >= 0) {
			int trg = src.dto[nxt];
			nxt = src.dnext[nxt];

			rebuild(src, nw, trg, curr, closest);
		}

		closest[group] = ancestor;
	}

	vector<int> res;
	int subsize(AdjustArray &a, int curr) {
		int sum = 1;
		int nxt = a.dhead[curr];
		while (nxt >= 0) {
			int trg = a.dto[nxt];
			nxt = a.dnext[nxt];

			sum += subsize(a, trg);
		}

		res[curr] = sum;
		return sum;
	}
public:
	vector<int> findSubtreeSizes(vector<int> parent, string s) {
		size_t size = parent.size();

		AdjustArray src = AdjustArray(size);
		AdjustArray nw = AdjustArray(size);

		for (int i = 1; i < size; ++i) {
			src.link(parent[i], i);
		}

		vector<int> closest(26, -1);
		groupMap = s;

		rebuild(src, nw, 0, -1, closest);

		res = vector<int>(size);
		subsize(nw, 0);

		return res;
	}
};
