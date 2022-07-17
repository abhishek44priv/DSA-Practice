#include"stdafx.h"
namespace ak
{
	namespace file {
		std::string ReadAllText(std::string path)
		{
			std::ifstream t(path);
			std::stringstream buffer;
			buffer << t.rdbuf();

			return buffer.str();
		}
		std::vector<std::string> GetAllWords(std::string text)
		{
			enum State { WHITE_SPACE, CHAR, UNKNOWN };
			size_t a = 0;
			State state = State::UNKNOWN;
			std::vector<std::string> words;

			for (size_t i = 0; i < text.size(); i++)
			{
				auto c = text[i];

				if (state == State::UNKNOWN) {
					if (std::isspace(c)) {
						state = State::WHITE_SPACE;
					}
					else {
						state = State::CHAR;
					}
					continue;
				}

				if (state == State::WHITE_SPACE) {
					if (std::isspace(c))
					{

					}
					else
					{
						//text begin
						state = State::CHAR;
						a = i;
					}
				}
				else
				{
					//end
					if (std::isspace(c) || i == text.size() - 1)
					{
						state = State::WHITE_SPACE;
						words.push_back(text.substr(a, i - a));
					}
					else
					{


					}
				}


			}
			return words;
		}
		size_t GetLineCount(std::string text) {
			size_t count = 0;
			for (size_t i = 0; i < text.size(); i++)
			{
				auto c = text[i];
				if (c == '\r' && i != text.size() - 1)
				{
					if (text[i + 1] == '\n')
					{
						count++;
						continue;
					}
				}
				if (c == '\n')
				{
					count++;
				}

			}

			return count;
		}
	}
}


int main()
{
	auto text = ak::file::ReadAllText("text.txt");
	auto words = ak::file::GetAllWords(text);
	print("no of lines {}\n", ak::file::GetLineCount(text));
	
	return 0;
}
