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
        Heat, Jet, Hot
    };
    
    inline Eigen::Vector3d GetColor(double x, ColorMapType type = ColorMapType::Heat);
    inline Eigen::Vector3d GetHeatColor(double x);
    inline Eigen::Vector3d GetJetColor(double x);
    inline Eigen::Vector3d GetHotColor(double x);

    //////////////////////////////////////////////////////////////////////////////////
    // Implementation
    //////////////////////////////////////////////////////////////////////////////////
    
    inline Eigen::Vector3d GetColor(double x, ColorMapType type)
    {
        switch (type)
        {
            case ColorMapType::Heat:
                return GetHeatColor(x);
            case ColorMapType::Jet:
                return GetJetColor(x);
            case ColorMapType::Hot:
                return GetHotColor(x);
            default:
                break;
        }
    }
    
    inline Eigen::Vector3d GetHeatColor(double x)
    {
        x = std::max(0.0, std::min(1.0, x));
        
        const Eigen::Vector3d r(1.0, 0.0, 0.0);
        const Eigen::Vector3d y(1.0, 1.0, 0.0);
        const Eigen::Vector3d g(0.0, 1.0, 0.0);
        const Eigen::Vector3d c(0.0, 1.0, 1.0);
        const Eigen::Vector3d b(0.0, 0.0, 1.0);
        
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
    
    inline Eigen::Vector3d GetJetColor(double x)
    {
        x = std::max(0.0, std::min(1.0, x));
        
        double r, g, b;
        
        constexpr double r_max = 0.8;
        constexpr double g_max = 1.0;
        constexpr double b_max = 1.0;
        
        constexpr double t = 0.125;
        
        if (x < t)
        {
            r = 0;
            g = 0;
            b = b_max * (0.5 + x / t * 0.5);
        }
        else if (x < 3.0 * t)
        {
            r = 0;
            g = g_max * (x - t) / (3.0 * t - t);
            b = b_max;
        }
        else if (x < 5.0 * t)
        {
            r = r_max * (x - 3.0 * t) / (5.0 * t - 3.0 * t);
            g = g_max;
            b = (b_max - (x - 3.0 * t) / (5.0 * t - 3.0 * t));
        }
        else if (x < 7.0 * t)
        {
            r = r_max;
            g = (g_max - (x - 5.0 * t) / (7.0 * t - 5.0 * t));
            b = 0;
        }
        else
        {
            r = (r_max - (x - 7.0 * t) / (1.0 - 7.0 * t) * 0.5);
            g = 0;
            b = 0;
        }
        return Eigen::Vector3d(r, g, b);
    }
    
    inline Eigen::Vector3d GetHotColor(double x)
    {
        x = std::max(0.0, std::min(1.0, x));
        
        const Eigen::Vector3d r(1.0, 0.0, 0.0);
        const Eigen::Vector3d g(0.0, 1.0, 0.0);
        const Eigen::Vector3d b(0.0, 0.0, 1.0);

        if (x < 0.4)
        {
            const double t = x / 0.4;
            return t * r;
        }
        else if (x < 0.8)
        {
            const double t = (x - 0.4) / (0.8 - 0.4);
            return r + t * g;
        }
        else
        {
            const double t = (x - 0.8) * (1.0 - 0.8);
            return r + g + t * b;
        }
    }
}

#endif
