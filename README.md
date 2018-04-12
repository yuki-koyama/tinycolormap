# tinycolormap
A tiny header-only library for color maps written in C++11

## Dependencies

- Eigen http://eigen.tuxfamily.org/

## Sample Code

```
#include <iostream>
#include <tinycolormap.h>

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

## Available Colormaps

### Matlab

| Name     | Sample                         |
|:--------:|:------------------------------:|
| Heat     | ![](docs/samples/Heat.png)     |
| Hot      | ![](docs/samples/Hot.png)      |
| Jet      | ![](docs/samples/Jet.png)      |
| Gray     | ![](docs/samples/Gray.png)     |

Reference: https://www.mathworks.com/help/matlab/ref/colormap.html

### mpl colormaps (Matplotlib)

| Name     | Sample                         |
|:--------:|:------------------------------:|
| Magma    | ![](docs/samples/Magma.png)    |
| Inferno  | ![](docs/samples/Inferno.png)  |
| Plasma   | ![](docs/samples/Plasma.png)   |
| Viridis  | ![](docs/samples/Viridis.png)  |

These colormaps are designed to be perceptually uniform (even in black-and-white printing) and friendly to colorblindness.

The original colormaps are released under CC0 by Nathaniel J. Smith, Stefan van der Walt, and (in the case of viridis) Eric Firing: https://github.com/BIDS/colormap/blob/master/colormaps.py . Their python code is adapted for the use in C++11.

Reference: https://bids.github.io/colormap/

### GitHub

| Name     | Sample                         |
|:--------:|:------------------------------:|
| Github   | ![](docs/samples/Github.png)   |

This colormap is designed to mimic the color scheme used in GitHub contributions visualization.

## Projects using tinycolormap

- sequential_line_search (SIGGRAPH 2017) https://github.com/yuki-koyama/sequential-line-search
- selph (CHI 2016) https://github.com/yuki-koyama/selph
