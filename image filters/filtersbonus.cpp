// FCI – Programming 1 – 2022 - Assignment 3 
// Program Name: filters
// Last Modification Date: 23/04/2022
// Author1 and ID and Group: Abdelrahman Hossam Eldin Ahmed  / 20210201 / S7\S8 
// Author2 and ID and Group: xxxxx xxxxx
// Author3 and ID and Group: xxxxx xxxxx
// Teaching Assistant: Eng. Abdulrahman Abdulmonem
// Purpose:..........

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std ;
unsigned char image[SIZE][SIZE][RGB],  image2[SIZE][SIZE][RGB];


void loadimage();
void saveimage();


//Filter Functions
void blackandwhite (); // filter 1 black and white
void invert() ; // filter 2 invert image

void merge() ; //filter 3 merge 

void flipimagehorizontal();  // filter 4 (horizontal part)
void flipimagevertical() ;   // filter 4 (vertical part)

void detectEdges() ; //filter 7 (detect image edges)

void mirrorimageRight () ;  // filter (a) mirror image right
void mirrorimageLeft () ; // filter (a) mirror image left
void mirrorimageUpper () ; // filter (a) mirror image upper 
void mirrorimageDown () ; // filter (a) mirror image down

int main ()
{

   char filter , flip , MirrorDirection  ;
   bool x =true ; 

  
  cout << "Ahlan ya user ya habibi " << endl;
  
  
  cout << "Please select the number or alphabet of filter to apply or 0 to exit: " << endl ;
  cout << "1- Black & White Filter" << endl ;
  cout << "2- invert image " << endl ;
  cout << "3- Merge Filter" << endl ;
  cout << "4- Flip Image" << endl ;
  cout << "5- rotate image" << endl;
  cout << "6- Darken and Lighten Image" << endl ;
  cout << "7- Detect Image Edges" << endl ;
  cout << "8- Enlarge image " << endl ; 
  cout << "9- Shrink Image" << endl ;
  cout << "a- Mirror 1/2 Image" << endl ;
  cout << endl ;
  
  while(x=true){
   cout << "enter the number of choice you want or 0 to end : " ;
   cin >> filter ;
   
  if( filter == '1')
  {
      loadimage();
      blackandwhite();
      saveimage();
  }
  else if (filter == '2')
  {
      loadimage();
      invert();
      saveimage();
  }
  else if (filter == '3')
  {
      loadimage();
      merge();
      saveimage();
  }
  
  else if( filter == '4'){
      cout << "flip horizontal enter h or vertical enter v : " <<endl;
      cin >> flip ;
      if(flip == 'h' || flip == 'H' ){
          loadimage();
          flipimagehorizontal();
          saveimage();
      }
      else if(flip == 'v' || flip == 'V'){
          loadimage();
          flipimagevertical();
          saveimage();
      }
  }
  else if ( filter == '7' )
  {
      loadimage();
      detectEdges();
      saveimage();
  }
   else if (filter == 'a' || filter == 'A' )
  {
      cout << "Mirror (l)eft, (r)ight, (u)pper, (d)own side?" << endl ;
      cout << "enter the letter between brackets to apply" << endl ;
      cin >> MirrorDirection ;
    if (MirrorDirection == 'l' || MirrorDirection == 'L'){
        loadimage();
        mirrorimageLeft();
        saveimage();
    }
    else if (MirrorDirection == 'R' || MirrorDirection == 'r'){
        loadimage();
        mirrorimageRight();
        saveimage();
    }
    else if (MirrorDirection == 'u' || MirrorDirection == 'U' ){
        loadimage();
        mirrorimageUpper() ;
        saveimage();
    }
     else if (MirrorDirection == 'd' || MirrorDirection == 'D'){
         loadimage();
         mirrorimageDown() ; 
         saveimage();
    }
  } 
    else if (filter == '0'){
        x = false ;
        cout<<" thank you , BYE " << endl ; 
        return 0 ;
    }
  
  
  }
  
 
  
  
  

    return 0 ;
}

void loadimage()
{
    char imagefilename[100];

    cout << "Please enter file name of the image to process: " << endl;
    cin >> imagefilename ;

   strcat (imagefilename, ".bmp");
   readRGBBMP(imagefilename, image);
}


void saveimage()
{
    char imagefilename[100];

    cout << "Please enter target file name: " << endl ;
    cin >> imagefilename ;
    
     strcat (imagefilename, ".bmp");
     writeRGBBMP(imagefilename, image);
}

// filter 1 --> black and white 
void blackandwhite()
{
    int r = 0 ;
    for( ; r<SIZE ; r++){
        int c=0 ;
        for( ; c<SIZE ; c++){
            long long avg =0 ;
            int k =0 ;
            for(  ; k<RGB ; k++){
            avg += image[r][c][k];
            }
            avg /= 3 ;
            if(avg>127){
                for(int k = 0  ;k<RGB ;k++){
                image[r][c][k]=255 ;
                }
            }
            else{
               for(int k = 0  ;k<RGB ;k++){
                image[r][c][k]=0 ;
                }  
            }
        }
    }  
}

//filter 2 -> Invert Function

void invert()
{
    for (int i = 0; i < SIZE; i++)
{
    for (int j = 0; j < SIZE; j++)
    {
        for (int k = 0; k < RGB; k++){

            image[i][j][k] = 255 - image[i][j][k];
        }
    }
}
}


//filter3 -> Merge Function

void merge()
{
    char imagefileName[100];
   //unsigned char image3[SIZE][SIZE];

   // Get gray scale image file name
   cout << "Please enter name of image file to merge with: "<< endl;
   cin >> imagefileName;

   // Add to it .bmp extension and load image
   strcat (imagefileName, ".bmp");
   readRGBBMP(imagefileName, image2);


    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                image[i][j][k] = (image2[i][j][k] + image[i][j][k]) / 2;
            }
        }
    }
}

// Filter 4 --> flip image horizonatal 
void flipimagehorizontal()
{


     int k = 0;
    while(k<RGB)
    {
        for(int r = 0 ; r<SIZE ; r++){
            for(int c=0 ; c<SIZE/2 ; c++){
           swap (image[r][c][k] , image[r][SIZE-c-1][k]);
        }
      }
        k++;
    } 
  
}        

// Filter 4 --> flip image vertical
void flipimagevertical()
{
    flipimagehorizontal();

     int k = 0;
    while(k<RGB)
    {
        for(int r = 0 ; r<SIZE/2 ; r++){
            for(int c=0 ; c<SIZE ; c++){
           swap (image[r][c][k] , image[SIZE-r-1][c][k]);
        }
      }
        k++;
    } 
}

// Filter 7 --> detect images
void detectEdges()
{
    blackandwhite();
     int k = 0;
    while(k<RGB)
    {
        for(int r = 0 ; r<SIZE ; r++){
            for(int c=0 ; c<SIZE ; c++){
           if(image[r][c][k] == image[r][c+1][k] && image[r][c][k] == image[r+1][c][k] ){
                image[r][c][k] = 255 ;
           }
           else{
               image[r][c][k] = 0 ;
           }
        }
      }
        k++;
    } 
}

void mirrorimageLeft () 
{
    int k =0 ;
    while(k<RGB){
    for(int r=0 ; r < SIZE ; r++){
        for(int c=0 ; c < SIZE/2 ; c++){
            image[r][SIZE - c - 1][k] = image[r][c][k];
        }
    }
    k++ ;
  }
}

void mirrorimageRight () 
{
    int k =0 ;
    while(k<RGB){
    for(int r=0 ; r < SIZE ; r++){
        for(int c=0 ; c < SIZE/2 ; c++){
            image[r][c][k] = image[r][SIZE - c - 1][k];
        }
    }
    k++ ;
  }
}

void mirrorimageUpper ()
{
     int k =0 ;
    while(k<RGB){
    for(int r=0 ; r < SIZE/2 ; r++){
        for(int c=0 ; c < SIZE ; c++){
            image[SIZE - r - 1][c][k] = image[r][c][k];
        }
    }
    k++ ;
  }
}

void mirrorimageDown ()
{
     int k =0 ;
    while(k<RGB){
    for(int r=0 ; r < SIZE/2 ; r++){
        for(int c=0 ; c < SIZE ; c++){
            image[r][c][k] = image[SIZE - r - 1][c][k];
        }
    }
    k++ ;
  }
}