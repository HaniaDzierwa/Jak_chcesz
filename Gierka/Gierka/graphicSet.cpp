#include "graphicSet.h"


GraphicSet::GraphicSet(std::string nameFile)
{

	std::fstream file;
	std::string line;


	file.open((nameFile), std::ios::in);
	if (file.good() == true)
	{

		while (!file.eof()) // eof end of file
		{
			getline(file, line);
			std::stringstream ss(line);
			int windowHeight = 0;
			int windowWidth=0;
			std::string style;
			std::string name;
			
			int FramerateLimit =0;
			std::string verticalSync;



			ss >> windowHeight;
			ss >> windowWidth;
			ss >> name;
			ss >> style;
			ss >> FramerateLimit;
			ss >> verticalSync;

			
			
				this->videoMode.height = windowHeight;
				this->videoMode.width = windowWidth;

				this->name= name;

				if (style == "Fullscreen")
				{

					this->style = "true" ;
				}
				
				this->FramerateLimit = FramerateLimit;
				
				this->verticalSync = verticalSync;
				

			

		}
	}
	else
	{
		std::cout << "File didnt open";
		return;
	}


	

}




GraphicSet::GraphicSet(int windowHeight, int windowWidth, sf::RenderWindow style, int FramerateLimit, bool verticalSync)
{
}

GraphicSet::~GraphicSet()
{
}




