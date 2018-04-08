# tinycolormap
A tiny header-only library for colormaps written in C++11

## Dependencies

- Eigen http://eigen.tuxfamily.org/

## Colormaps

### Matlab
- Heat
- Jet
- Hot
- Gray

Reference: https://www.mathworks.com/help/matlab/ref/colormap.html

### mpl colormaps (Matplotlib)
- Magma
- Inferno
- Plasma
- Viridis

These colormaps are designed to be perceptually uniform (even in black-and-white printing) and friendly to colorblindness.

The original colormaps are released under CC0 by Nathaniel J. Smith, Stefan van der Walt, and (in the case of viridis) Eric Firing: https://github.com/BIDS/colormap/blob/master/colormaps.py . Their python code is adapted for the use in C++11.

Reference: https://bids.github.io/colormap/

## Projects using tinycolormap

- sequential_line_search (SIGGRAPH 2017) https://github.com/yuki-koyama/sequential-line-search
- selph (CHI 2016) https://github.com/yuki-koyama/selph
