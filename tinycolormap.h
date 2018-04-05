/*
 MIT License
 
 Copyright (c) 2018 Yuki Koyama
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 */

#ifndef TINYCOLORMAP_H_
#define TINYCOLORMAP_H_

#include <cmath>
#include <Eigen/Core>

namespace tinycolormap
{
    //////////////////////////////////////////////////////////////////////////////////
    // API Definitions
    //////////////////////////////////////////////////////////////////////////////////
    
    enum class ColorMapType
    {
        Heat
    };
    
    inline Eigen::Vector3d GetColor(double x, ColorMapType type = ColorMapType::Heat);
    inline Eigen::Vector3d GetHeatColor(double x);
    
    //////////////////////////////////////////////////////////////////////////////////
    // Implementation
    //////////////////////////////////////////////////////////////////////////////////
    
    inline Eigen::Vector3d GetColor(double x, ColorMapType type)
    {
        switch (type)
        {
            case ColorMapType::Heat:
                return GetHeatColor(x);
            default:
                break;
        }
    }
    
    inline Eigen::Vector3d GetHeatColor(double x)
    {
        x = std::max(0.0, std::min(1.0, x));
        
        static const Eigen::Vector3d r(1.0, 0.0, 0.0);
        static const Eigen::Vector3d y(1.0, 1.0, 0.0);
        static const Eigen::Vector3d g(0.0, 1.0, 0.0);
        static const Eigen::Vector3d c(0.0, 1.0, 1.0);
        static const Eigen::Vector3d b(0.0, 0.0, 1.0);
        
        if (x < 0.25)
        {
            const double t = x * 4.0;
            return t * c + (1.0 - t) * b;
        }
        else if (x < 0.50)
        {
            const double t = (x - 0.25) * 4.0;
            return t * g + (1.0 - t) * c;
        }
        else if (x < 0.75)
        {
            const double t = (x - 0.50) * 4.0;
            return t * y + (1.0 - t) * g;
        }
        else
        {
            const double t = (x - 0.75) * 4.0;
            return t * r + (1.0 - t) * y;
        }
    }
}

#endif
