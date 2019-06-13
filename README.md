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

### Matplotlib

| Name     | Sample                         |
|:--------:|:------------------------------:|
| Magma    | ![](docs/samples/Magma.png)    |
| Inferno  | ![](docs/samples/Inferno.png)  |
| Plasma   | ![](docs/samples/Plasma.png)   |
| Viridis  | ![](docs/samples/Viridis.png)  |
| Cividis  | ![](docs/samples/Cividis.png)  |

These colormaps are designed to be perceptually uniform (even in black-and-white printing) and friendly to colorblindness. Cividis is specially designed such that it enables as identical interpretation to both those without a CVD and those with red-green colorblindness as possible.

Magma, Inferno, Plasma, Viridis are released under CC0 by Nathaniel J. Smith, Stefan van der Walt, and (in the case of Viridis) Eric Firing: <https://github.com/BIDS/colormap/blob/master/colormaps.py>. Their python code is adapted for the use in C++11.

Cividis is released under CC0 by the authors of PLOS ONE paper (Jamie R. Nuñez, Christopher R. Anderton, Ryan S. Renslow): <https://doi.org/10.1371/journal.pone.0199239>. We incorporated the LUT into C++11.

### GitHub

| Name     | Sample                         |
|:--------:|:------------------------------:|
| Github   | ![](docs/samples/Github.png)   |

This colormap is designed to mimic the color scheme used in GitHub contributions visualization.

## Dependency

tinycolormap does not have any dependencies except for C++11 standard library.

## Installation

tinycolormap is a header-only library, so you do not need to compile it. You can use it by

- Adding the path to the `include` directory in the cloned tinycolormap repository to your project's include paths, or
- Copying the file `tinycolormap.hpp` to your project (note that tinycolormap consists of only that single file).

If your project is managed by Cmake <https://cmake.org/>, `add_subdirectory` or `ExternalProject_Add` commands are useful as tinycolormap provides `CMakeLists.txt` for this purpose.

## Usage

The core function of this library is
```cpp
inline Color GetColor(double x, ColormapType type);
```
where `x` should be between `0.0` and `1.0` (otherwise, it will be cropped), and `type` is the target colormap type like `Viridis` (default) and `Heat`.

Here is a working code:
```cpp
#include <iostream>
#include <tinycolormap.hpp>

int main()
{
  // Define a target value. This value should be in [0, 1]; otherwise, it will be cropped to 0 or 1.
  const double value = 0.5;

  // Get the mapped color. Here, Viridis is specified as the colormap.
  const tinycolormap::Color color = tinycolormap::GetColor(value, tinycolormap::ColormapType::Viridis);

  // Print the RGB values. Each value is in [0, 1].
  std::cout << "r = " << color.r() << ", g = " << color.g() << ", b = " << color.b() << std::endl;

  return 0;
}
```

## Options for External Libraries Integration

### Qt5 Support

When `TINYCOLORMAP_WITH_QT5` is defined before including `tinycolormap.hpp`, for example,
```cpp
#define TINYCOLORMAP_WITH_QT5
#include <tinycolormap.hpp>
```
(or `TINYCOLORMAP_WITH_QT5` CMake option is `ON`), this library offers an additional utility function:
```cpp
const QColor color = tinycolormap::GetColor(x).ConvertToQColor();
```

### Eigen Support

When `TINYCOLORMAP_WITH_EIGEN` is defined before including `tinycolormap.hpp`, for example,
```cpp
#define TINYCOLORMAP_WITH_EIGEN
#include <tinycolormap.hpp>
```
(or `TINYCOLORMAP_WITH_EIGEN` CMake option is `ON`), this library offers an additional utility function:
```cpp
const Eigen::Vector3d color = tinycolormap::GetColor(x).ConvertToEigen();
```

###  Qt5 and Eigen Support

When both Qt5 and Eigen are available, this library offers additional utility functions:
```cpp
inline QImage CreateMatrixVisualization(const Eigen::MatrixXd& matrix);
inline void ExportMatrixVisualization(const Eigen::MatrixXd& matrix, const std::string& path);
```

## Tools (Optional)

This repository includes the following optional tools:

- PNG Exporter: This tool exports all the available colormaps as PNG images. (Requirement: `TINYCOLORMAP_WITH_QT5 = ON`)

### Tools Build Instruction

The optional tools are managed by CMake <https://cmake.org/>. They can be built by, for example,
```bash
mkdir build
cd build
cmake [PATH_TO_TINYCOLORMAP] -DTINYCOLORMAP_BUILD_TOOLS=ON
make
```

## Projects using tinycolormap

- Unblending (Pacific Graphics 2018) <https://github.com/yuki-koyama/unblending>
- OptiMo (CHI 2018) <https://github.com/yuki-koyama/optimo>
- Sequential Line Search (SIGGRAPH 2017) <https://github.com/yuki-koyama/sequential-line-search>
- SelPh (CHI 2016) <https://github.com/yuki-koyama/selph>
- VisOpt Slider (UIST 2014) <https://github.com/yuki-koyama/visoptslider>

## Contribute

Pull requests are welcome.
