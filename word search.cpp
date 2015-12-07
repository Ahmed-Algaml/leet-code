class Solution {
public:

	int dx[4] { 0, 0, 1, -1 };
	int dy[4] { 1, -1, 0, 0 };
	int n, m;
	bool valid(int i, int j) {
		return i >= 0 && i < n && j >= 0 && j < m;
	}
	bool search(int i, int j, int idx, vector<vector<char>>& board,
			string &word) {
		if (idx == (int) word.length())
			return 1;

		if (!valid(i, j))
			return 0;

		int ret = 0;

		if (board[i][j] == word[idx]) {
			char tmp = board[i][j];
			board[i][j] = '#';
			for (int t = 0; t < 4 && !ret; ++t)
				ret |= search(i + dx[t], j + dy[t], idx + 1, board, word);
			board[i][j] = tmp;
		}
		return ret;
	}
	bool exist(vector<vector<char>>& board, string word) {
		n = board.size();
		m = board[0].size();

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (search(i, j, 0, board, word))
					return 1;
		return 0;
	}

};
