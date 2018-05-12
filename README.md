# tinycolormap

A header-only, single-file library for colormaps written in C++11.

## Available Colormaps

### Matlab

| Name     | Sample                         |
|:--------:|:------------------------------:|
| Heat     | ![](docs/samples/Heat.png)     |
| Hot      | ![](docs/samples/Hot.png)      |
| Jet      | ![](docs/samples/Jet.png)      |
| Gray     | ![](docs/samples/Gray.png)     |

Reference: <https://www.mathworks.com/help/matlab/ref/colormap.html>

### mpl colormaps (Matplotlib)

| Name     | Sample                         |
|:--------:|:------------------------------:|
| Magma    | ![](docs/samples/Magma.png)    |
| Inferno  | ![](docs/samples/Inferno.png)  |
| Plasma   | ![](docs/samples/Plasma.png)   |
| Viridis  | ![](docs/samples/Viridis.png)  |

These colormaps are designed to be perceptually uniform (even in black-and-white printing) and friendly to colorblindness.

The original colormaps are released under CC0 by Nathaniel J. Smith, Stefan van der Walt, and (in the case of viridis) Eric Firing: <https://github.com/BIDS/colormap/blob/master/colormaps.py>. Their python code is adapted for the use in C++11.

Reference: <https://bids.github.io/colormap/>

### GitHub

| Name     | Sample                         |
|:--------:|:------------------------------:|
| Github   | ![](docs/samples/Github.png)   |

This colormap is designed to mimic the color scheme used in GitHub contributions visualization.

## Dependency

- Eigen <http://eigen.tuxfamily.org/>

## Installation

tinycolormap is a header-only library, so you do not need to compile it. You can use it by 
- Adding the path to the `include` directory of tinycolormap to your project's include paths, or
- Copying the file `tinycolormap.hpp` to your project (note that tinycolormap consists of only that single file).

If your project is managed by Cmake <https://cmake.org/>, then the `ExternalProject_Add` is useful as tinycolormap provides `CMakeLists.txt` for this purpose.

## Tools (Optional)

This repository includes the following optional tools: 
- PNG Exporter: This tool exports all the available colormaps as PNG images. 

### Additional Dependency

- Qt5 <http://doc.qt.io/qt-5/>

### Tools Build Instruction

The optional tools are managed by CMake <https://cmake.org/>. They can be built by, for example, 
```
mkdir build
cd build
cmake [PATH_TO_TINYCOLORMAP] -DTINYCOLORMAP_BUILD_TOOLS=ON
make
```

Tips: if CMake could not find Qt5, it needs to specify the path to Qt5 explicitly by adding an option: `-DCMAKE_PREFIX_PATH=[PATH_TO_Qt5]`.

## Sample Code

```
#include <iostream>
#include <tinycolormap.hpp>

int main()
{
  // Define a target value. This value should be in [0, 1]; otherwise, it will be cropped to 0 or 1.
  const double value = 0.5;
  
  // Get the color as a 3-dimensional double-valued vector. Here, Viridis is specified as a colormap.
  const Eigen::Vector3d color = tinycolormap::GetColor(value, tinycolormap::ColorMapType::Viridis);
  
  // Print the RGB values. Each value is in [0, 1].
  std::cout << "r = " << color(0) << ", g = " << color(1) << ", b = " << color(2) << std::endl;
  
  return 0;
}
```

## Projects using tinycolormap

- OptiMo (CHI 2018)
- Sequential Line Search (SIGGRAPH 2017) <https://github.com/yuki-koyama/sequential-line-search>
- SelPh (CHI 2016) <https://github.com/yuki-koyama/selph>
- VisOpt Slider (UIST 2014)

## Contribute

Pull requests are welcome.


