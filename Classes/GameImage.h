//
//  GameImage.h
//  igame
//
//  Created by Johan Ekholm on 2010-04-11.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import "TextureMap.h"
#import <OpenGLES/ES1/gl.h>

class TextureMap;

class GameImage {
	GLfloat x, y;
	GLfloat width, height;
	TextureMap *texture;
	int texIndex;

public:
	GameImage(GLfloat aWidth, GLfloat aHeight, TextureMap* tex, int index);
	//~GameImageCPP();
	void draw();
	void setPosition(GLfloat aX, GLfloat aY);
};

/*@interface GameImage : NSObject {
	CGPoint position;
	CGSize size;
	TextureMap *texture;
	int texIndex;
}

@property (nonatomic, readwrite) CGPoint position;

- (id) initWithTextureMap: (TextureMap*)texMap withIndex: (int)index;
- (id) initWithSize: (CGSize)newSize andTexture: (TextureMap*)texMap withIndex: (int)index;
- (void) draw;

@end
*/