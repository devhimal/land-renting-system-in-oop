# Land Renting System (C++ Project)

This project is a Land Renting System developed in C++ to manage rental transactions, including CRUD operations for land parcels, rentals, and invoices. The project is built and managed using CMake.


## Project Link

Hello @~Sushma ma'am, you can find our project on GitHub at the following link:  
[Land Renting System in OOP GitHub Repository](https://github.com/devhimal/land-renting-system-in-oop.git)

## Group Information

- **Group Name**: Padandash
- **Group Members**:
  - Sangam Mishra
  - Naman Marwadi
  - Himal Tamang

## Requirements

To successfully build and run this project, you will need:

- **CMake** (version 3.10 or higher)
- **C++ Compiler** (GCC, Clang, or MSVC)
- **Git** (optional, for version control)
- **VS Code or any C++ IDE** (optional, for coding)

### Install CMake

For Linux:

```bash
sudo apt-get install cmake
```

For macOS:

```bash
brew install cmake
```

For Windows:

Download from [CMake Official Website](https://cmake.org/download/).

## Project Structure

```bash
├── CMakeLists.txt          # CMake configuration file
├── src/                    # Source files
│   ├── main.cpp            # Main program
│   ├── land.cpp            # Implementation of land management
│   ├── rental.cpp          # Implementation of rental management
│   └── ...
├── include/                # Header files
│   ├── land.h              # Header file for land management
│   ├── rental.h            # Header file for rental management
│   └── ...
└── README.md               # This file
```

## How to Build

Follow these steps to build the project using CMake:

1. Clone the repository:

```bash
git clone https://github.com/devhimal/land-renting-system-in-oop.git
cd land-renting-system-in-oop
```

2. Create a `build` directory:

```bash
mkdir build
cd build
```

3. Run CMake to configure the project:

```bash
cmake ..
```

4. Build the project:

```bash
cmake --build .
```

## How to Run

Once the project is built, you can run the executable file generated in the `build` directory. Use the following command:

```bash
./land_renting_system
```
