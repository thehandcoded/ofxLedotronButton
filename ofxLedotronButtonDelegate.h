/*
 *  ofxLedotronButtonDelegate.h
 *  THIS_Editor
 *
 *  Created by Jim on 9/23/10.
 *  Copyright 2010 FlightPhase. All rights reserved.
 *
 */

#pragma once


#include "ofMain.h"
#include "ofxLedotronButton.h"

class ofxLedotronButtonDelegate 
{
  public:
 	virtual void objectDidRollOver(ofxLedotronButton* object, int x, int y) = 0;
    virtual void objectDidRollOut(ofxLedotronButton* object, int x, int y) = 0;
	virtual void objectDidPress(ofxLedotronButton* object, int x, int y, int button) = 0;	
	virtual void objectDidRelease(ofxLedotronButton* object, int x, int y, int button) = 0;
    virtual void objectDidReleaseOutside(ofxLedotronButton* object, int x, int y, int button) = 0;
    virtual void objectDidMouseMove(ofxLedotronButton* object, int x, int y) = 0;
    virtual void objectDidDragOver(ofxLedotronButton* object, int x, int y) = 0;
    virtual void objectDidDragOutside(ofxLedotronButton* object, int x, int y) = 0;
};


class ofxLedotronButtonWithDelegate : public ofxLedotronButton {

  public:
	
    ofTrueTypeFont* fontReference;
	ofxLedotronButtonWithDelegate(){
		delegate = NULL;
        fontReference = NULL;
		idleColor.setHex(0xFFFFFF);
		hoverColor.setHex(0x00FF00);
		downColor.setHex(0x00FF00);		
	}
	
	void setup() {
		enableMouseEvents();
		enableKeyEvents();
	}	
	
	void setDelegate(ofxLedotronButtonDelegate* _delegate){
		delegate = _delegate;
	}
	
	void setIdleColor(ofColor c){
		idleColor = c;
	}
	
	void setHoverColor(ofColor c){
		hoverColor = c;
	}
	
	void setDownColor(ofColor c){
		downColor = c;
	}

	void setTextColor(ofColor c){
		textColor = c;
	}
	
	void setLabel(string l){
		label = l;
	}

	string getLabel(){
		return label;
	}
	
	void update() {
	
	}
	
	void draw() {
        ofPushStyle();
        
		if(isMouseDown()){
			ofSetColor(downColor);
			ofFill();
		}
		else if(isMouseOver()){
			ofSetColor(hoverColor);
			ofFill();
		}
		else{
			ofSetColor(idleColor);
			//ofNoFill();
		}
		
		ofRect(*this);
        
		ofSetColor(textColor);
		if(label != ""){
            if(fontReference != NULL){
                
                fontReference->drawString(label, x+10, y+fontReference->getLineHeight()-2);
            }
            else {
                
                ofDrawBitmapString(label, x+10, y+15);
            }
		}
        ofPopStyle();
	}
	
	virtual void onRollOver(int x, int y) {
		if(delegate != NULL){
			delegate->objectDidRollOver(this, x, y);
		}

	}
	
	virtual void onRollOut() {
        if(delegate != NULL){
			delegate->objectDidRollOut(this, x, y);
		}
	}
	
	virtual void onMouseMove(int x, int y){
		if(delegate != NULL){
			delegate->objectDidMouseMove(this, x, y);
		}
	}
	
	virtual void onDragOver(int x, int y, int button) {
        if(delegate != NULL){
            delegate->objectDidDragOver(this, x, y);
        }
		//printf("MyTestObject::onDragOver(x: %i, y: %i, button: %i)\n", x, y, button);
	}
	
	virtual void onDragOutside(int x, int y, int button) {
        if(delegate != NULL){
            delegate->objectDidDragOutside(this, x, y);
        }

		//printf("MyTestObject::onDragOutside(x: %i, y: %i, button: %i)\n", x, y, button);
	}
	
	virtual void onPress(int x, int y, int button) {
		if(delegate != NULL){
			delegate->objectDidPress(this, x, y, button);
		}
		//printf("MyTestObject::onPress(x: %i, y: %i, button: %i)\n", x, y, button);
	}
	
	virtual void onRelease(int x, int y, int button) {
		if(delegate != NULL){
			delegate->objectDidRelease(this, x, y, button);
		}
		
		//printf("MyTestObject::onRelease(x: %i, y: %i, button: %i)\n", x, y, button);
	}
	
	virtual void onReleaseOutside(int x, int y, int button) {
        if(delegate != NULL){
            delegate->objectDidReleaseOutside(this, x, y, button);
        }
		//printf("MyTestObject::onReleaseOutside(x: %i, y: %i, button: %i)\n", x, y, button);
	}
	
	virtual void keyPressed(int key) {
		//printf("MyTestObject::keyPressed(key: %i)\n", key);
	}
	
	virtual void keyReleased(int key) {
		//printf("MyTestObject::keyReleased(key: %i)\n", key);
	}
	
  private:
	ofxLedotronButtonDelegate* delegate;
	ofColor idleColor;
	ofColor hoverColor;
	ofColor downColor;
	
	ofColor textColor;
	
	string label;
	
};