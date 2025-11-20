#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
    public:
	vector<string> fullJustify(vector<string> &words, int maxWidth)
	{
		int i, j, n = words.size();
		int start = 0;
		int curr_words_size;
		int blank_space_num;
		int word_space;
		int line_word_num;
		int extra_space;
		vector<string> res;

		while (start < n) {
			// 计算当前行容下几个单词, 从start开始
			curr_words_size = 0;
			for (i = 0; start + i < n; i++) {
				if (curr_words_size + words[start + i].size() + i <= maxWidth) { //加上空格
					curr_words_size += words[start + i].size();
				} else {
					break;
				}
			}
			// start .. start+i 一共i个单词
			line_word_num = i;
			// 空格数量
			blank_space_num = maxWidth - curr_words_size;

			string curr;
			if (start + line_word_num >= n) { //最后一行
				for (i = 0; i < line_word_num; i++) {
					curr += words[start + i];
					curr += ' ';
				}
				if (curr.size() != 0) { //去掉最后一个单词的空格
					curr.pop_back();
				}
				// 剩下多少空格加到末尾
				for (i = 0; i < blank_space_num - line_word_num + 1; i++) {
					curr += ' ';
				}
				res.push_back(curr);
				break;
			}

			if (line_word_num == 0) {
				break;
			} else if (line_word_num == 1) {
				//只有一个单词
				curr += words[start];
				for (i = 0; i < blank_space_num; i++) {
					curr += ' ';
				}
			} else if (line_word_num > 1) {
				// 最后一个字母不需要空格,前面字母至少word_space个空格
				word_space = blank_space_num / (line_word_num - 1);
				extra_space = blank_space_num % (line_word_num - 1);
				if (extra_space == 0) {
					for (i = 0; i < line_word_num - 1; i++) {
						curr += words[start + i];
						for (j = 0; j < word_space; j++) {
							curr += ' ';
						}
					}
				} else {
					for (i = 0; i < line_word_num - 1; i++) {
						curr += words[start + i];
						if (i < extra_space) {
							curr += ' ';
						}
						for (j = 0; j < word_space; j++) {
							curr += ' ';
						}
					}
				}
				//最后一个单词
				curr += words[start + i];
			}

			res.push_back(curr);

			start = start + line_word_num;
		}

		return res;
	}
};

#include <stdio.h>
int main()
{
	vector<string> words = { "Science", "is", "what",	"we",	"understand", "well",
				 "enough",  "to", "explain",	"to",	"a",	      "computer.",
				 "Art",	    "is", "everything", "else", "we",	      "do" };
	int maxWidth = 20;
	Solution S;
	vector<string> res = S.fullJustify(words, maxWidth);
	vector<string> err;
	for (string s : res) {
		printf("%s\n", s.c_str());
		if (s.size() != maxWidth) {
			err.push_back(s);
		}
	}
	if (err.size() != 0) {
		printf("err line: \n");
	}
	for (string s : err) {
		printf("line size: %d line: %s\n", s.size(), s.c_str());
	}
}
