#include "baseeffect.h"
#include <QColor>
#include <iostream>

BaseEffect::BaseEffect()
{
divisore=1;
    for(int i=0; i<3;i++){
        for(int j=0;j<3;j++){
            if(i!=1 && j!=1){
            matrixeffect[i][j]=0;}

        }
    }

matrixeffect[1][1]=1;

}
void BaseEffect::apply(QPixmap & originalmatrix){

    QImage img=originalmatrix.toImage();
    processing(img,img.height(),img.width());
    originalmatrix.convertFromImage(img);



}



void BaseEffect::processing(QImage & img,int width,int height){

    QColor result;
    QColor** matrix=new QColor*[height];
    for(int i=0;i<height;i++){
        matrix[i]=new QColor[width];}

    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            matrix[i][j].setRed(img.pixelColor(i,j).red());
            matrix[i][j].setGreen(img.pixelColor(i,j).green());
            matrix[i][j].setBlue(img.pixelColor(i,j).blue());
            matrix[i][j].setAlpha(img.pixelColor(i,j).alpha());
        }}
     float red,green,blue,alpha;

     for(int i=0;i<height;i++){
         for(int j=0;j<width;j++){

             red=0;
             blue=0;
             green=0;
             alpha=0;



         if(j!=0 && i!=0){
             red+=matrix[i-1][j-1].red()*matrixeffect[0][0];
             green+=matrix[i-1][j-1].green()*matrixeffect[0][0];
             blue+=matrix[i-1][j-1].blue()*matrixeffect[0][0];
             alpha+=matrix[i-1][j-1].alpha()*matrixeffect[0][0];
         }
         if(j!=0){
             red+=matrix[i][j-1].red()*matrixeffect[1][0];
             green+=matrix[i][j-1].green()*matrixeffect[1][0];
             blue+=matrix[i][j-1].blue()*matrixeffect[1][0];
             alpha+=matrix[i][j-1].alpha()*matrixeffect[1][0];
         }

         if(j!=0 && i!=height-1){
             red+=matrix[i+1][j-1].red()*matrixeffect[2][0];
             green+=matrix[i+1][j-1].green()*matrixeffect[2][0];
             blue+=matrix[i+1][j-1].blue()*matrixeffect[2][0];
             alpha+=matrix[i+1][j-1].alpha()*matrixeffect[2][0];
             }

         if(i!=0){

             red+=matrix[i-1][j].red()*matrixeffect[0][1];
            green+=matrix[i-1][j].green()*matrixeffect[0][1];
             blue+=matrix[i-1][j].blue()*matrixeffect[0][1];
             alpha+=matrix[i-1][j].alpha()*matrixeffect[0][1];
         }

             if(i!=0 && j!=width-1){
             red+=matrix[i-1][j+1].red()*matrixeffect[0][2];
             green+=matrix[i-1][j+1].green()*matrixeffect[0][2];
             blue+=matrix[i-1][j+1].blue()*matrixeffect[0][2];
             alpha+=matrix[i-1][j+1].alpha()*matrixeffect[0][2];
             }

         if(j!=width-1){

             red+=matrix[i][j+1].red()*matrixeffect[1][2];
              green+=matrix[i][j+1].green()*matrixeffect[1][2];
               blue+=matrix[i][j+1].blue()*matrixeffect[1][2];
               alpha+=matrix[i][j+1].alpha()*matrixeffect[1][2];

         }

         if(j!= width-1 && i!=height-1){
            red+=matrix[i+1][j+1].red()*matrixeffect[2][2];
             green+=matrix[i+1][j+1].green()*matrixeffect[2][2];
            blue+=matrix[i+1][j+1].blue()*matrixeffect[2][2];
            alpha+=matrix[i+1][j+1].alpha()*matrixeffect[2][2];
           }

         if(i!=height-1){

             red+=matrix[i+1][j].red()*matrixeffect[2][1];
              green+=matrix[i+1][j].green()*matrixeffect[2][1];
              blue+=matrix[i+1][j].blue()*matrixeffect[2][1];
              alpha+=matrix[i+1][j].alpha()*matrixeffect[2][1];
             }

         red+=matrix[i][j].red()*matrixeffect[1][1];
          green+=matrix[i][j].green()*matrixeffect[1][1];
           blue+=matrix[i][j].blue()*matrixeffect[1][1];
           alpha+=matrix[i][j].alpha()*matrixeffect[1][1];
   if(red<0){//controllo sulla correttezza dei valori valori negativi vengano settati 0
       red=0;}
   if(blue<0){
       blue=0;}
   if(green<0){
       green=0;}
   if(alpha<0){
       alpha=0;}

   if(red>255){//controllo sulla correttezza dei valori .. valori maggiori del range di colori vengano settati a 255
       red=255;}
   if(blue>255){
       blue=255;}
   if(green>255){
       green=255;}
   if(alpha>255){
       alpha=255;}
   result.setRed(red/divisore);
   result.setGreen(green/divisore);
   result.setBlue(blue/divisore);
   result.setAlpha(alpha/divisore);
   img.setPixelColor(i,j,result.rgba());
        }
     }
   }


     void BaseEffect::setBlur(){
         for(int i=0; i<3;i++){
             for(int j=0;j<3;j++){

                 matrixeffect[i][j]=1;
             }
         }
         divisore=9;
     }

     void BaseEffect::setEdgeDetection(){

         matrixeffect[0][0]=1;
         matrixeffect[0][1]=0;
         matrixeffect[0][2]=-1;

         matrixeffect[1][0]=0;
         matrixeffect[1][1]=0;
         matrixeffect[1][2]=0;

         matrixeffect[2][0]=-1;
         matrixeffect[2][1]=0;
         matrixeffect[2][2]=1;
         divisore=1;
     }

     void BaseEffect::setSharpening(){
         matrixeffect[0][0]=-1;
         matrixeffect[0][1]=0;
         matrixeffect[0][2]=-1;

         matrixeffect[1][0]=0;
         matrixeffect[1][1]=5;
         matrixeffect[1][2]=0;

         matrixeffect[2][0]=-1;
         matrixeffect[2][1]=0;
         matrixeffect[2][2]=-1;
         divisore=1;
     }

