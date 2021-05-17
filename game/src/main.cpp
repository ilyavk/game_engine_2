#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>

#include "engine.h"


int main(int argc, char **argv)
{
  /*** cmd line args input ***/

  // shaders inputs
  std::string vertFilePath, fragFilePath;
	// Get command line arguments and pass into the engine
	// ./Tutorial -v shaderv.txt -f shaderf.txt
  /*std::string vertFilePath, fragFilePath;
	for (int i = 1; i < argc; ++i)
	{
		if (std::strcmp(argv[i], "-v") == 0)
			vertFilePath = argv[i+1]; 
		if (std::strcmp(argv[i], "-f") == 0)
			fragFilePath = argv[i+1];			
	}*/
  // read in shader files, use hard coding for pathing rn cause it aint assignment and its kinda pointless rn w/ an easy change if i need to tbh
  std::ifstream v("../shaders/vert.txt");
	std::string vertF((std::istreambuf_iterator<char>(v)), std::istreambuf_iterator<char>());
	v.close();
	std::ifstream f("../shaders/frag.txt");
	std::string fragF((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
	f.close();

  // Start an engine and run it then cleanup after
  Engine *engine = new Engine("Game", 1200, 980, vertF, fragF);
  if(!engine->Initialize())
  {
    printf("The engine failed to start.\n");
    delete engine;
    engine = NULL;
    return 1;
  }
  engine->Run();
  delete engine;
  engine = NULL;
  return 0;
}
