# Rotating Cube Algorithm using SFML in C++

This repository contains a C++ algorithm that prints a rotating cube using the SFML library. The SFML library is a simple and fast multimedia library used for game development in C++.

The algorithm utilizes the SFML/Graphics.hpp and SFML/System.hpp header files to handle the graphical and system aspects, respectively. The algorithm is implemented in C++ language.

!['A cube rotating'](https://i.ibb.co/vk4LxS8/out-6.gif)

## Prerequisites

To run this algorithm, you need to have the following prerequisites installed on your system:

- C++ compiler (e.g., g++, Visual Studio)
- SFML library

## Installation

1. Clone the repository to your local machine using the following command:

   ```
   git clone https://github.com/nervesscat/Rotating-Cube.git
   ```

2. Ensure that the SFML library is properly installed on your system.

3. Build the source code using the appropriate C++ compiler, and link it with the SFML library.

   - For g++ on Linux:

     ```
     g++ -o main main.cpp -lsfml-graphics -lsfml-window -lsfml-system
     ```

   - For Visual Studio on Windows:

     - Create a new project and add the source code files to it.
     
     - Configure the project to link with the SFML library.
     
     - Build the project to generate the executable.

4. Execute the compiled code to view the rotating cube.

## Usage

Once you have successfully built and executed the program, a window will open displaying a rotating cube. The cube will rotate continuously around its center point.

You can interact with the window using the following commands:

- **Close Window**: Click the close button (X) on the window to exit the program.

## Contributing

Contributions are welcome! If you find any bugs or have suggestions to enhance the algorithm, feel free to open an issue or submit a pull request.

## License

This repository is licensed under the [MIT License](LICENSE). You are free to use, modify, and distribute the code as per the terms of this license.
