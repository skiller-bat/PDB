#include <iostream>

#include <errhandlingapi.h>
#include <processthreadsapi.h>
#include <handleapi.h>
#include <psapi.h>

#include "game.h"


const Game *Game::instance = nullptr;

Game::Game(HANDLE handle, void *base) : PROC_HANDLE(handle), BASE_ADDRESS(base)
    {}

const Game *Game::get_instance() {

    if (instance != nullptr) {
        return instance;
    }

    // Get the list of process identifiers.
    DWORD processes[1024], bytes_processes;
    if (!EnumProcesses(processes, sizeof(processes), &bytes_processes)) {
        win_api_error();
    }

    // Calculate how many process identifiers were returned.
    DWORD num_processes = bytes_processes / sizeof(DWORD);

    // Find the desired process.
    DWORD proc_id;
    HANDLE proc_handle;
    const unsigned base_name_size = 64;
    char base_name[base_name_size];
    bool process_running = false;
    HMODULE modules;

    for (unsigned i = 0; i < num_processes; i++) {
        if (processes[i] == 0) {
            continue;
        }
        proc_id = processes[i];
        if ((proc_handle = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, false, proc_id)) == NULL) {
//            win_api_error(); // ERROR_ACCESS_DENIED on some processes
            continue;
        }
        DWORD bytes_modules;
        if (!EnumProcessModules(proc_handle, &modules, sizeof(modules), &bytes_modules)) {
            win_api_error();
            continue;
        }
        if (GetModuleBaseName(proc_handle, modules, base_name, sizeof(base_name)) == 0) {
            win_api_error();
            continue;
        }
        if (strncmp(EXECUTABLE_NAME, base_name, base_name_size) == 0) {
            process_running = true;
            break;
        }
    }

    if (!process_running) {
        throw std::system_error();
        // https://nexwebsites.com/blog/cpp_exceptions/
    }

    MODULEINFO mod_info;
    if (!GetModuleInformation(proc_handle, modules, &mod_info, sizeof(mod_info))) {
        win_api_error();
    }

    return instance = new Game(proc_handle, mod_info.lpBaseOfDll);
}

Game::~Game() {
    if (!CloseHandle(PROC_HANDLE)) {
        win_api_error();
    }
}

// TODO: add parameter to allow the caller to specify which error occurred or where
void Game::win_api_error() {
    std::cout << "ERROR: " << GetLastError() << std::endl;
}
