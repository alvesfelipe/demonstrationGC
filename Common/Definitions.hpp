#ifndef _Definitions_hpp
#define _Definitions_hpp

class Definitions{
	private:
		unsigned int screen_width;
		unsigned int screen_height;

	public:
		//Default width and height is 800 x 600
		Definitions();
		Definitions(unsigned int width, unsigned int height);
		unsigned int getWidthScreen();
		void setWidthScreen(unsigned int width);
		unsigned int getHeightScreen();
		void setHeightScreen(unsigned int height);

};


#endif