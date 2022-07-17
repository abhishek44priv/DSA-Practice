#include"stdafx.h"
namespace ak
{
	std::string ReadAllText(std::string path)
	{
		std::ifstream t(path);
		std::stringstream buffer;
		buffer << t.rdbuf();

		return buffer.str();
	}
}
std::vector<std::string> GetAllWords(std::string text)
{
	enum State{WHITE_SPACE,CHAR,UNKNOWN};
	int a=0,b=0;
	State state=State::UNKNOWN;
	std::vector<std::string> words;

	for (size_t i = 0; i < text.size(); i++)
	{
		auto c = text[i];

		
		if (std::isspace(c)) {
			words.push_back(text.substr(a, i - a));
			a = i;

		}
		if (i == text.size() - 1) {
			words.push_back(text.substr(a, i - a));
		}
		
	}

	return words;
}
int main()
{
	auto text = ak::ReadAllText("text.txt");
	for (auto e : GetAllWords(text)) {
		print(" {}\n",e );

	}
	return 0;
}
