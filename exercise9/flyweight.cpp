#include <sstream>
#include <vector>

struct Sentence {
  struct WordToken {
    std::string word;
    bool capitalize;
    WordToken(const std::string& s, const bool& cap)
        : word{s}, capitalize{cap} {};
  };

  std::vector<WordToken> wordTokens;

  Sentence(const std::string& text) {
    WordToken wt{"", false};
    for (size_t i = 0; i < text.length(); i++) {
      if (!isalnum(text[i]) && !wt.word.empty()) {
        wordTokens.push_back(wt);
        wt = {"", false};
      } else if (isalnum(text[i])) 
        wt.word.push_back(text[i]);
    }
    if (!wt.word.empty()) wordTokens.push_back(wt);
  }

  WordToken& operator[](std::size_t index) {
    return wordTokens[index];
  }

  std::string str() const {
    std::stringstream ss;

    for (size_t i = 0; i < wordTokens.size() - 1; i++) {
      if (wordTokens[i].capitalize)
        for (auto&& c : wordTokens[i].word) ss << (char)toupper(c);
      else
        ss << wordTokens[i].word;
      ss << ' ';
    }

    if (wordTokens.back().capitalize)
      for (auto&& c : wordTokens.back().word) ss << (char)toupper(c);
    else
      ss << wordTokens.back().word;

    return ss.str();
  }
};