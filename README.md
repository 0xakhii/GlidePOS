### GlidePOS
GlidePOS is a cross-platform point-of-sale (POS) application developed using C++ and wxWidgets. It provides a simple yet functional interface for managing products, suitable for small businesses or personal use.

## Features
- Add new products
- List all products
- Search products by name
### Requirements
## Dependencies
- C++ Compiler: g++ or equivalent
- wxWidgets: For GUI development. Ensure that you have libwxgtk3.0-dev installed.
- CMake: For building the project
## Installing Dependencies
**On Ubuntu/Debian**:
Run the following commands to install the necessary dependencies:
```bash
sudo apt-get update
sudo apt-get install -y build-essential libwxgtk3.0-dev cmake x11-apps
```
**On macOS**:
- Install Homebrew if you haven’t already.
- Use Homebrew to install wxWidgets and CMake:
```bash
brew install wxwidgets cmake
```
**On Windows**:
- Download and install wxWidgets from the official website.
- Install CMake from the official website.

### Building and Running GlidePOS
# Clone the Repository:
```bash
git clone https://github.com/0xakhi/GlidePOS.git
cd glidepos
```
Build the Project:

Create a build directory and run Make:
``` bash
make
./GlidePOS
```
### Contributing
Contributions are welcome! Feel free to fork the repository, make changes, and submit pull requests.
### Contact
For any questions or feedback, please contact ojamal710@gmail.com
