#ifndef PROCESSOR_HPP
#define PROCESSOR_HPP

#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

inline cv::Mat load(const std::string& path) {
    cv::Mat data = fetch(path);
    cv::Mat edges;
    cv::Canny(data, edges, 100, 200);

    return edges;
}

inline std::vector<std::vector<cv::Point3f>> forge(const cv::Mat& edges) {
    std::vector<std::vector<cv::Point3f>> ext;

    for (int i = 0; i < edges.rows; ++i) {
        for (int j = 0; j < edges.cols; ++j) {
            if (edges.at<uchar>(i, j) == 255) {
                cv::Point3f top(j, i, 0);
                cv::Point3f bottom(j, i, 1);
                ext.push_back({top, bottom});
            }
        }
    }

    return ext;
}

#endif