//#include <string>
//#include <vector>
//#include <fstream>
//#include <sstream>
//
//struct SourceFile
//{
//    std::string start;
//    std::string start2;
//};
//
//SourceFile readFile(const std::string& filepath)
//{
//    std::ifstream file(filepath);
//
//    enum class textType
//    {
//        NONE = -1, START = 0, START2 = 1
//    };
//
//    std::string line;
//    std::stringstream ss[2];
//    textType type = textType::NONE;
//
//    while (std::getline(file, line))
//    {
//        if (line.find("#start") != std::string::npos)
//        {
//            if (line.find("nol") != std::string::npos)
//                type = textType::START;
//            else if (line.find("satu") != std::string::npos)
//                type = textType::START2;
//        }
//        else
//        {
//            ss[(int)type] << line << '\n';
//        }
//    }
//    return { ss[0].str(), ss[1].str() };
//}