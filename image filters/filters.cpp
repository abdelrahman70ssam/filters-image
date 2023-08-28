// FCI – Programming 1 – 2022 - Assignment 3 
// Program Name: filters.cpp
// Last Modification Date: 23/04/2022
// Author1 and ID and Group: Abdelrahman Hossam Eldin Ahmed  - 20210201 -  S7\S8  filters (1,4,7,a)
// Author2 and ID and Group: mohamed khaled abdelmonem - 20210556     - S7\S8      filters (2,5,8,b)
// Author3 and ID and Group:  amr hesham bayoumy   - 20210279 - S7\S8   filters (3,6,9,c)
// Teaching Assistant:  Eng. Abdulrahman Abdulmonem
// Purpose: train on 2D arrays and readymade libraries

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std ;
unsigned char image[SIZE][SIZE] , image2[SIZE][SIZE];

void loadimage();
void saveimage();
void saveimageEnlarge();

//Filter Functions
void blackandwhite (); // filter 1 black and white
void invert() ; // filter 2 invert image

void mergeimage(); // filter 3 merge images

void flipimagehorizontal();  // filter 4 (horizontal part)
void flipimagevertical() ;   // filter 4 (vertical part)

void rotate() ; // filter 5 (rotate image)


void darkenimage() ; //filter 6 (darken image)
void lightenimage() ; //filter 6 (lighten image)

void detectEdges() ; //filter 7 (detect iamge edges)

void enlarge() ; // filter 8 

void shrink() ; // filter 9 (shrink image)

void mirrorimageRight () ;  // filter (a) mirror image right
void mirrorimageLeft () ; // filter (a) mirror image left
void mirrorimageUpper () ; // filter (a) mirror image upper 
void mirrorimageDown () ; // filter (a) mirror image down





int main(){
  
  char filter ,flip , MirrorDirection , need  ; 
 

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
  
  while (true){
  
  cout << "enter the number of choice you want or 0 to end : " ;
  cin >> filter ;

  if( filter == '1')
  {
      loadimage();
      blackandwhite();
      saveimage();
  }
  else if (filter == '2'){
      loadimage();
      invert() ;
      saveimage();
  }
  else if (filter == '3')
  {
      loadimage();
      mergeimage();
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
  else if (filter == '5')
  {
      loadimage();
      rotate() ;
      saveimage();
      
  }
  
  else if ( filter == '6')
  {
      cout << "Do you want to (d)arken or (l)ighten?" << endl ;
      cout << "enter the letter between brackets to apply" << endl ;
      cin >> need  ;
      if(need == 'd' || need == 'D'){
        loadimage();
        darkenimage() ;
        saveimage();
      }
      else if (need == 'l' || need == 'L'){
        loadimage();
        lightenimage() ;
        saveimage(); 
      }
  }
  else if ( filter == '7' )
  {
      loadimage();
      detectEdges();
      saveimage();
  }
  else if (filter == '8')
  {
    loadimage();
    enlarge();
    saveimageEnlarge();
  }
  else if ( filter == '9')
  {
    loadimage();
    shrink();
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
        cout<<"thank you , BYE " << endl ; 
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
   readGSBMP(imagefilename, image);
}


void saveimage()
{
    char imagefilename[100];

    cout << "Please enter target file name: " << endl ;
    cin >> imagefilename ;
    
     strcat (imagefilename , ".bmp");
     writeGSBMP(imagefilename, image);
}

void saveimageEnlarge()
{
    char imagefilename[100];

    cout << "Please enter target file name: " << endl ;
    cin >> imagefilename ;
    
     strcat (imagefilename , ".bmp");
     writeGSBMP(imagefilename, image2);
}



// filter 1 --> black and white 
void blackandwhite ()
{
    long long avg = 0 ;
    for(int r=0 ; r<SIZE ; r++){
        for(int c=0 ; c<SIZE ; c++){
            avg += image[r][c];
        }
    }  
    avg /= (SIZE*SIZE) ;

    for(int r=0 ; r<SIZE ; r++){
        for(int c=0 ; c<SIZE ; c++){
           if(image[r][c] > avg){
               image[r][c] = 255;
           }
           else{
               image[r][c] = 0 ;
           }
        }
    }
}

// filter 2 --> invert image 
void invert()
{
  for(int r=0 ; r<SIZE ; r++){
        for(int c=0 ; c<SIZE ; c++){
          if(image[r][c]==0){
              image[r][c]=255 ;
          }
          else if (image[r][c]==255){
              image[r][c]=0 ;
          }
          else if (image[r][c]>0 && image[r][c]<=127 ){
             image[r][c]= ~image[r][c] + SIZE ;
          }
          else if (image[r][c]>=128 && image[r][c]<=255 ){
              image[r][c] = SIZE - image[r][c] - 1 ;
          }
        }
    }
}



// filter 3 --> merge images
void mergeimage()
{
   char imagefileName[100];
   unsigned char image2[SIZE][SIZE];
   //unsigned char image3[SIZE][SIZE];

   // Get gray scale image file name
   cout << "Please enter name of image file to merge with: "<< endl;
   cin >> imagefileName;

   // Add to it .bmp extension and load image
   strcat (imagefileName, ".bmp");
   readGSBMP(imagefileName, image2);

    for (int i = 0; i < SIZE; i++){
    for (int j = 0; j< SIZE; j++)
    {
         image[i][j] = (image[i][j] + image2[i][j]) / 2;
    }
 }
}

// Filter 4 --> flip image horizonatal 
void flipimagehorizontal()
{
   for(int r=0 ; r < SIZE ; r++){
        for(int c=0 ; c < SIZE/2 ; c++){
            swap(image[r][c] , image[r][SIZE - c - 1]);
        }
   }    

}
// Filter 4 --> flip image vertical
void flipimagevertical()
{
    flipimagehorizontal();

    for(int c=0 ; c < SIZE ; c++){
        for(int r=0 ; r < SIZE/2 ; r++){
            swap( image[r][c] , image[SIZE - r - 1][c]) ;
            
            }
        
   }

}
// filter 5 --> rotate image
void rotate()
{
    int deg ; 
    cout << "Rotate (90), (180) or (270) degrees?" << endl ;
    cin >> deg ;

   if(deg == 90)
   {
       for(int r = 0 ; r < SIZE ; r++){
        for(int c = r ; c < SIZE ; c++){
            
           swap(image[r][c] , image[c][r]);
        }
      }
      for(int r = 0 ; r < SIZE ; r++){
        for(int c = 0 ; c < SIZE/2 ; c++){
            
           swap(image[r][c] , image[r][SIZE - c - 1]);
        }
      }
   }
   else if (deg == 180 ) 
   { 
       int x = 2 ;
       while(x--){
           for(int r = 0 ; r < SIZE ; r++){
        for(int c = r ; c < SIZE ; c++){
            
           swap(image[r][c] , image[c][r]);
        }
      }
      for(int r = 0 ; r < SIZE ; r++){
        for(int c = 0 ; c < SIZE/2 ; c++){
            
           swap(image[r][c] , image[r][SIZE - c - 1]);
        }
      }

       }
   } 
   else if( deg == 270 )
   {
       int x = 3 ;
       while(x--)
       {
           for(int r = 0 ; r < SIZE ; r++){
        for(int c = r ; c < SIZE ; c++){
            
           swap(image[r][c] , image[c][r]);
        }
      }
      for(int r = 0 ; r < SIZE ; r++){
        for(int c = 0 ; c < SIZE/2 ; c++){
            
           swap(image[r][c] , image[r][SIZE - c - 1]);
        }
      }
    }
   }
}



// Filter 6 --> darken image
void darkenimage(){

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
		  if (image[i][j] < 127){
           		image[i][j] = 255/2;
      }	
      else{
        image[i][j]=0;
      }
    }
  }
}

 // Filter 6 --> lighten image
void lightenimage()
{
 for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
	  image[i][j] = image[i][j]/2+128;
  }   
 }
}
 
 // Filter 7 --> detect images
 void detectEdges()
{
    blackandwhite();

    for(int r=0 ; r < SIZE ; r++){
        for(int c=0 ; c < SIZE ; c++){
            if(image[r][c] == image[r][c+1] && image[r][c] == image[r+1][c] ){
                image[r][c] = 255 ;
                
            }
            else {
                 image[r][c] = 0 ;
                
            }
        }
   } 
       
}

// filter 8 
void enlarge()
{
    int quarter ;
    cout << "Which quarter to enlarge 1, 2, 3 or 4? " << endl ;
    cin >> quarter ;
    if(quarter == 1){
     for(int r = 0 ; r < SIZE/2 ; r++){
        for(int c = 0 ; c < SIZE/2 ; c++){
            image2[r][c] = image[r][c] ;
        }
      }
    }
    else if (quarter = 3 ){
       for(int r = 127 ; r < SIZE ; r++){
        for(int c = 0 ; c < SIZE/2 ; c++){
            image2[r][c] = image[r][c] ;
        }
      }
    }
     else if (quarter = 2 ){
       for(int r = 0 ; r < SIZE/2 ; r++){
        for(int c = 127 ; c < SIZE ; c++){
            image2[r][c] = image[r][c] ;
        }
      }
    }
     else if (quarter = 4 ){
       for(int r = 127 ; r < SIZE ; r++){
        for(int c = 127 ; c < SIZE ; c++){
            image2[r][c] = image[r][c] ;
        }
      }
    }
}




 // filter 9 -- > shrink image
 void shrink() 
 {
	int k = 0;
	int z = 0;
	int level ;
    unsigned char imageTemp[SIZE][SIZE];
	string s; //size of the shrinking
	cout <<"enter the shrinking size you need:half or third or quarter"<<endl;
	cin>> s;
	if (s=="half"){
	
	  for (int i = 0; i < SIZE; i+=2) {
    		for (int j = 0; j< SIZE; j+=2) {
				imageTemp [k][z]=image[i][j];

				z++;
    			}
    			z=0;
    			k++;
  }

  }
	if (s=="third"){
	
		  for (int i = 0; i < SIZE; i+=3) {
    		for (int j = 0; j< SIZE; j+=3) {
				imageTemp [k][z]=image[i][j];

				z++;
   		 }
    			z=0;
   			 k++;
  
  }
 
  }
		if (s=="fourth"){
		
			for (int i = 0; i < SIZE; i+=4) {
    			for (int j = 0; j< SIZE; j+=4) {
				imageTemp [k][z]=image[i][j];

				z++;
   			 }
    			z=0;
   			 k++;
  }

}
}
 // Filter a --> mirror image Right 
 void mirrorimageRight ()
{
     for(int r=0 ; r < SIZE ; r++){
        for(int c=0 ; c < SIZE/2 ; c++){
            image[r][c] = image[r][SIZE - c - 1];
        }
   }  
 }

 // Filter a--> mirror image Left
void mirrorimageLeft()
{
     for(int r=0 ; r < SIZE ; r++){
        for(int c=0 ; c < SIZE/2 ; c++){
            image[r][SIZE - c - 1] = image[r][c];
        }
   } 
  
}
// Filter a--> mirror image upper
void mirrorimageUpper ()
{
   for(int c=0 ; c < SIZE ; c++){
        for(int r=0 ; r < SIZE/2 ; r++){
            image[SIZE - r - 1][c] = image[r][c];
        }
   } 
  
} 
// Filter a--> mirror image Down
void mirrorimageDown () 
{
     for(int c=0 ; c < SIZE ; c++){
        for(int r=0 ; r < SIZE/2 ; r++){
            image[r][c] = image[SIZE - r - 1][c];
        }
   }
}

