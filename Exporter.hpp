#ifndef EXPORTER_HPP
#define EXPORTER_HPP

#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <vector

inline void save(const std::string& path, const std::vector<std::vector<cv::Point3f>>& ext) {
    std::ofstream location(path);

    for (const auto& face : ext) {
        for (const auto& vertex : face) {
            location << "v " << vertex.x << " " << vertex.y << " " << vertex.z << "\n";
        }
    }

    for (size_t i = 0; i < ext.size(); ++i) {
        location << "f " << i + 1 << " " << i + 2 << " " << i + 3 << " " << i + 4 << "\n";
    }

    location.close();
    std::cout << "Saved to " << path << std::endl;
}

#endif