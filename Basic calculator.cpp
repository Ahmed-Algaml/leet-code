class Solution {
public:

	int eval(string &s, int &pos, int n) {
		int res = 0;
		char op = '+';
		for (; pos < n; ++pos) {
			if (s[pos] == ' ')
				;
			else if (isdigit(s[pos])) {
				int num = 0;
				while (pos < n && isdigit(s[pos]))
					num = num * 10 + s[pos++] - '0';

				res += op == '+' ? num : -1 * num;
				--pos;
			} else if (s[pos] == '-' || s[pos] == '+')
				op = s[pos];
			else if (s[pos] == '(') {
				++pos;
				int num = eval(s, pos, n);
				res += op == '+' ? num : -1 * num;
			} else
				return res;

		}
		return res;
	}
	int calculate(string s) {
		int pos = 0;
		return eval(s, pos, s.length());
	}
};
