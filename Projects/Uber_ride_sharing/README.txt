# Ride Sharing App

## Overview

This project is a ride-sharing application that simulates the interaction between riders and drivers. The application allows riders to request rides and drivers to accept or cancel these requests. The main components of the project are implemented in the following files:
- `driver.cpp` and `driver.h`
- `rider.cpp` and `rider.h`
- `main.cpp`

## Data Structures Used

### Driver and Rider Classes
The `Driver` and `Rider` classes are defined in `driver.h` and `rider.h`, respectively. These classes encapsulate the properties and behaviors of drivers and riders.

### Vectors
The primary data structure used in this project is the `std::vector`. Vectors are used to store lists of drivers and riders. This allows for dynamic resizing and easy access to elements.

### Example Usage
- **Driver Management**: A vector of `Driver` objects is used to keep track of all drivers in the system.
- **Rider Management**: Similarly, a vector of `Rider` objects is used to manage all riders.

## Implementation Details

### Main Components
- **Driver Class**: Manages driver information such as availability and ride status.
- **Rider Class**: Manages rider information and ride requests.
- **Main Program**: Handles the interaction between riders and drivers, processes ride requests, and updates the status of drivers and riders.

### Key Functions
- **Request Ride**: Allows a rider to request a ride.
- **Accept Ride**: Allows a driver to accept a ride request.
- **Cancel Ride**: Allows a driver or rider to cancel a ride.

## Development and Testing

### Challenges
- **Header File Integration**: Initially faced issues with accessing header files and integrating CPP files. Solved by ensuring proper use of `#endif` in header files.
- **Segmentation Faults**: Encountered segmentation errors, resolved with the help of GDB to set breakpoints and identify the source of the error.
- **Vector Management**: Faced issues with accessing and initializing vectors. Ensured vectors were properly initialized and managed.
- **Variable Management**: Had issues with setting variables to null in the cancel function and updating driver status correctly.

### Reflection
This assignment involved overcoming several challenges, including debugging segmentation faults and managing vectors. Through this process, I gained a deeper understanding of C++ programming, especially in terms of memory management and debugging techniques.

## Conclusion

This ride-sharing app project provided valuable experience in managing complex interactions between objects and handling dynamic data structures. The use of vectors allowed for efficient management of drivers and riders, and the debugging process helped solidify my understanding of C++.

