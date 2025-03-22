#ifndef LOADER_HPP
#define LOADER_HPP

#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

inline cv::Mat fetch(const std::string& path) {
    cv::Mat data = cv::imread(path, cv::IMREAD_GRAYSCALE);

    if (data.empty()) {
        std::cerr << "Unable to load sprite from " << path << std::endl;
        exit(1);
    }

    if (data.cols < 10 || data.rows < 10) {
        std::cerr << "Sprite is too small." << std::endl;
        exit(1);
    }

    return data;
}

#endif