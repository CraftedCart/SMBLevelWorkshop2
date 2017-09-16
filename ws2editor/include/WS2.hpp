/**
 * @file
 * @brief Header for global WS2 members
 */

#ifndef SMBLEVELWORKSHOP2_WS2_HPP
#define SMBLEVELWORKSHOP2_WS2_HPP

#include "task/TaskManager.hpp"
#include <QApplication>
#include <random>

/**
 * @brief Namespace where all SMB Level Workshop 2 Editor code resides in
 *
 * WS2 is short for Workshop 2
 */
namespace WS2Editor {
    extern Task::TaskManager *ws2TaskManager;
    extern QApplication *ws2App;
    extern bool qAppRunning;
    extern std::mt19937 *randGen;

    //Prefixed with ws2 to avoid confusion with other functions that are within the WS2Editor namespace
    void ws2Init(int &argc, char *argv[]);
    void ws2Destroy();
}

#endif

