/**
 * MinGW Distro 17.1 ：https://nuwen.net/mingw.html#install （using gcc 9.2.0）
 * C++17 reference ：https://en.cppreference.com/w/cpp/filesystem
 * StackOverflow ref ：https://stackoverflow.com/questions/612097/how-can-i-get-the-list-of-files-in-a-directory-using-c-or-c/612176#612176
 *
 * 目标：
 *      - 遍历指定路径rootpath
 *      - 取出所有文件/文件夹的filename与深度
 *      - 数据导出到output.md
 */

#include <windows.h>
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

std::string parseExt(const fs::path &p) {
    std::string res;
    for (wchar_t wch:p.wstring()) {
        if (wch == '.') {
            res.clear();
        } else {
            res += char(wch);
        }
    }
    return res;
}

void inputfile(const fs::path &p) {
    std::ifstream fin(p);
    std::string inputs;
    std::string ext = parseExt(p);

    if (ext == "ignore") {
        fin.close();
        return;
    }

    std::cout << "``` " << ext << std::endl;
    while (std::getline(fin, inputs))
        std::cout << inputs << std::endl;
    std::cout << "```" << std::endl;

    fin.close();
}

void display_file(const fs::directory_entry &e, const int &d) {
    std::cout << std::string(d, '#') << " ";
    std::cout << e.path().filename().string() << '\n';
    inputfile(e.path());
}

void display_dir(const fs::directory_entry &e, const int &d) {
    std::cout << std::string(d, '#') << " ";
    std::cout << e.path().filename().string() << std::endl;
}

void unexpected(const fs::path &p, const int &d) {
    std::cerr << "*** [warning]: unexpected file ***" << std::endl;
    std::cerr << p.string() << std::endl << std::endl;
}

void traverse(const fs::path &p, const int &d) {
    for (const auto &entry : fs::directory_iterator(p)) {
        if (fs::is_regular_file(entry)) {
            display_file(entry, d);
        } else if (fs::is_directory(entry)) {
            display_dir(entry, d);
            traverse(entry, d + 1);
        } else {
            unexpected(p, d);
        }
    }
}

int main() {
    system("chcp 65001 > nul");
    // https://blog.csdn.net/weixin_43851212/article/details/90485420
    // cout 控制台中文

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    freopen("output.md", "w+", stdout);
    fs::path root = "D:\\Twy59sGthb\\HappyACEveryday\\mycode";
    traverse(root, 1);
}