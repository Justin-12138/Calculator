# RESTful Calculator

A modern calculator application with RESTful API backend and responsive web frontend.

## Features

- **RESTful API**: Backend provides clean API endpoints
- **Responsive UI**: Modern, mobile-friendly interface
- **Calculation History**: Keeps track of previous calculations
- **Unit Tests**: Comprehensive test coverage
- **Cross-platform**: Runs on Linux, Windows, and macOS

## Tech Stack

- **Backend**: C++ with httplib
- **Frontend**: HTML5, CSS3, JavaScript
- **Testing**: Google Test
- **Build System**: CMake

## Installation

### Prerequisites
- CMake >= 3.10
- C++17 compiler
- Git

### Build Instructions

```bash
git clone https://github.com/Justin-12138/Calculator.git
cd Calculator
mkdir build
cd build
cmake ..
make
```

## Running the Application

```bash
./Calculator
```

Then open your browser and navigate to `http://localhost:8080`

## Running Tests

```bash
./CalculatorTest
```

## API Documentation

### POST /api/calculate

**Request Body:**
```json
{
    "expression": "2+3*4"
}
```

**Response:**
```json
{
    "result": 14
}
```

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License

[MIT](https://choosealicense.com/licenses/mit/)