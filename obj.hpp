#ifndef OBJ_HPP
#define OBJ_HPP

#include "Processor.hpp"
#include "Exporter.hpp"
#include "bin/Loader.hpp"

#include <iostream>

inline void run(const std::string& sprite, const std::string& output) {
    cv::Mat edges = load(sprite);
    std::vector<std::vector<cv::Point3f>> ext = forge(edges);
    save(output, ext);
}

#endif