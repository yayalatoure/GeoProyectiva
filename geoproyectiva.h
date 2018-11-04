//
// Created by lalo on 11-10-18.
//

#ifndef GEOPROYECTIVA_GEOPROYECTIVA_H
#define GEOPROYECTIVA_GEOPROYECTIVA_H


#include <fstream>
#include <iostream>
#include <string>
#include <QLabel>
#include <QMessageBox>
#include <QFileDialog>

#include <opencv/cv.h>

using namespace std;
using namespace cv;


class geoproy {

    public:

        //// Constructor ////
        explicit geoproy(bool start);

        //// Read Calib File ////
        void readCalibFile();
        //// Generate Scene Calibpoints ////
        void genCalibPointsSuelo();
        void genCalibPointsImage();
        void genCalibPointsCorner();


        //// Add CalibPoints to CalibImage (QImage) ////
        void addCalibPoints(QImage &image);
        //// Transform Point from Image to Scene ////
        static cv::Point transformFloor2Image(Point2f p, cv::Mat &H);
        //// Draw Rectangle Round CalibPoints////
        void drawRectangleRed(QPainter &pnt, Point2f &p, cv::Mat &H);
        void drawRectangleBlue(QPainter &pnt, cv::Mat &H);

        void generateSequence(int seed);
        void playsToObjetives();

        void paintObjetive(int objetive);


    public:

        //// ATRIBUTES ////

        //// Bool Atributes ////
        bool start;
        //// Mat Atributes ////
        Mat homography;
        Mat homographyInv;

        //// Int Atributes ////

        static const int numPlays = 10;
        static const int tplays = 12;
        int plays[numPlays];
        int objetivesG2[numPlays];
        int objetivesG3[numPlays];

        //// Points Vector Atributes ////
        std::map<int, cv::Point2f> calibPointsFloor;
        std::map<int, cv::Point2f> calibPointsImage; // en el plano perspectivo
        std::map<int, cv::Point2f> calibPointsCornerFloor;
        std::map<int, cv::Point2f> calibPointsCornerImage;

        vector<Point> roiConvexPoly;




};















#endif //GEOPROYECTIVA_GEOPROYECTIVA_H
