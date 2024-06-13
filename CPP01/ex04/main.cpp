#include <iostream>
#include <fstream>
#include <string>

static void	replace_s1_with_s2(std::string s1_find, std::string s2_replace, std::ifstream &infile, std::ofstream &outfile)
{
	size_t	i;
	std::string	line;
	std::string	line_tmp;
	while(std::getline(infile, line))
	{
		i = 0;
		line_tmp = "";
		while((i = line.find(s1_find, i)) != std::string::npos)
		{
			line_tmp = line.substr(0, i);
			line_tmp = line_tmp + s2_replace + line.substr(i + s1_find.length());
			line = line_tmp;
			i = i + s2_replace.length();
		}
		outfile << line << std::endl;
	}
	infile.close();
	outfile.close();
}

static void err_msg(std::string msg)
{
	std::cerr << msg << std::endl;
}

int main(int argc, char **argv)
{
	if (argc != 4)
		return(err_msg("incorrect input: ./replace [filename] [find_str] [replace_str]"), 1);
	std::string filename = (std::string)argv[1];
	std::string s1_find = (std::string)argv[2];
	std::string s2_replace = (std::string)argv[3];
	if (s1_find.empty() || s2_replace.empty())
		return(err_msg("incorrect [str]"), 1);
	std::ifstream	infile;
	infile.open(filename.c_str(), std::ios::in);
	if(!infile.is_open())
		return(err_msg("incorrect infile"), 1);
	std::ofstream	outfile;
	std::string	outname = filename + ".replace";
	outfile.open(outname.c_str(), std::ios::out | std::ios::trunc);
	if(!outfile.is_open())
		return(infile.close(), err_msg("open outfile failed"), 1);
	replace_s1_with_s2(s1_find, s2_replace, infile, outfile);
}

// static std::string	outname_create(std::string filename)
// {
// 	size_t	dot_index = filename.find_last_of('.');
// 	std::string	outname = filename.substr(0, dot_index);
// 	std::string	extension = filename.substr(dot_index);
// 	outname.append(".replace" + extension);
// 	return (outname);
// }