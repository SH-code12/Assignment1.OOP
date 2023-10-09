#include <iostream>
#include <unistd.h>
#include "bmplib.h"
#include <fstream>
#include <cstring>
#include <cmath>
unsigned char image [SIZE][SIZE];
unsigned char image1 [SIZE][SIZE];
unsigned char newimage [SIZE][SIZE];


using namespace std;
void loadImage ();
void doSomethingForImage();
void DarkenLightenImage();
void BlurImage();
void saveImage ();
void mergeImage();
void ShrinkImage();
void SkewVertically();


int main() {
    string imgname , path = "\\imgs\\";
    cout<<"Enter Image Name: ";
    cin>>imgname;
    path += imgname;
    char cwd[PATH_MAX];
    readGSBMP(strcat(getcwd(cwd, sizeof(cwd)), path.c_str()),image);
    //doSomethingForImage();
    // loadImage();
    //mergeImage();
    // DarkenLightenImage();
    // ShrinkImage();
    //BlurImage();
    //SkewVertically();
    showGSBMP(image);
    //showGSBMP(newimage);
    saveImage();
    return 0;
}
//------------------------------------------
void loadImage () {
    char image1[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> image1;

    // Add to it .bmp extension and load image
    strcat (image1, ".bmp");
    readGSBMP(image1, image);
}
//--------------------------------------------
void saveImage () {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}
//-------------------------------------------------------
void doSomethingForImage() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            if (image[i][j] > 127){
                image[i][j] = 255;
            } else{
                image[i][j] = 0;}
        }
    }
}
//-------------------------------------------------------
void mergeImage(){
    unsigned char image [SIZE][SIZE];
    unsigned char image1 [SIZE][SIZE];
    // code for reed another image
    string imgname , path1 = "\\imgs\\";
    cout<<"Enter Image Name1: ";
    cin>>imgname;
    path1 += imgname;
    char cwd[PATH_MAX];
    readGSBMP(strcat(getcwd(cwd, sizeof(cwd)), path1.c_str()),image1);
    // code to merge two image
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image[i][j] = image[i][j] + image1[i][j]/2;
        }
    }
}
//-------------------------------------------------------
void DarkenLightenImage(){
    cout<<"If you want dark enter 0 else enter 1: ";
    int a;
    cin>>a;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (a==0){
                image[i][j] -=image[i][j]/2;
            }
            else{
                image[i][j] += (255-image[i][j])/2;
            }
        }

    }
}
//----------------------------------------------------------
void ShrinkImage(){
    cout<<"Enter  image dimensions{2 ,3,4}: ";
    int x;cin>>x;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            newimage[i/x][j/x] = (image[i][j] + image[i][j+1] + image[i+1][j]+ image[i+1][j+1])/4;
        }
    }
}
//---------------------------------------------------------
void BlurImage(){
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
           image[i][j] = image[2][200];
        }
    }

}
//------------------------------------------------------------
void SkewVertically(){
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image[i][j] = image[i][j]  ;



        }

    }
}
//---------------------------------------------------------------

