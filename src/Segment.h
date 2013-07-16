#ifndef CPPJIEBA_SEGMENT_H
#define CPPJIEBA_SEGMENT_H

#include <algorithm>
#include <set>
#include "Trie.h"
#include "globals.h"

namespace CppJieba
{
	class Segment
	{
		private:
			Trie _trie;
		public:
			Segment();
			~Segment();
		public:
			bool init(const char* const dictFilePath);
			bool destroy();
		public:
			bool cutDAG(const string& chStr, vector<string>& res);
			double getUtf8WordWeight(const string& word);
			double getUniWordWeight(const string& word);

		private:
			string _utf8ToUni(const string& chStr);
			bool _calcDAG(const string& uniStr, vector<vector<uint> >& dag);
			bool _calcDP(const string& uniStr, const vector<vector<uint> >& dag, vector<pair<int, double> >& res);
			bool _cutDAG(const string& uniStr, const vector<pair<int, double> >& dp, vector<string>& res);

		private:
			enum {bufSize = 1024};
			
	};
}

#endif