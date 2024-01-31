#include <filesystem>
#include <json.hpp>
#include "opensplat.hpp"
#include "point_io.hpp"

namespace fs = std::filesystem;

int main(int argc, char *argv[]){
    fs::path nfProjectRoot("banana");
    ns::Transforms t = ns::readTransforms((nfProjectRoot / "transforms.json").string());
    if (t.plyFilePath.empty()) throw std::runtime_error("ply_file_path is empty");

    PointSet *pSet = readPointSet((nfProjectRoot / t.plyFilePath).string());

    // std::cout << pSet->pointsTensor() << std::endl;
    // std::cout << pSet->colorsTensor() << std::endl;
    auto p = ns::posesFromTransforms(t);
    std::cout << p << std::endl;
}