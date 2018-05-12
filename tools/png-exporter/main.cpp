#include <iostream>
#include <QImage>
#include <tinycolormap.hpp>

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " SAVE_DIRECTORY_PATH" << std::endl;
        return 1;
    }

    const std::string save_directory_path = argv[1];

    constexpr int width  = 300;
    constexpr int height = 30;
    
    const std::vector<std::pair<tinycolormap::ColormapType, std::string>> colormap_types
    {
        { tinycolormap::ColormapType::Heat,    "Heat"    },
        { tinycolormap::ColormapType::Jet,     "Jet"     },
        { tinycolormap::ColormapType::Hot,     "Hot"     },
        { tinycolormap::ColormapType::Gray,    "Gray"    },
        { tinycolormap::ColormapType::Magma,   "Magma"   },
        { tinycolormap::ColormapType::Inferno, "Inferno" },
        { tinycolormap::ColormapType::Plasma,  "Plasma"  },
        { tinycolormap::ColormapType::Viridis, "Viridis" },
        { tinycolormap::ColormapType::Github,  "Github"  },
    };

    for (const auto& colormap_type : colormap_types)
    {
        QImage image(width, height, QImage::Format_ARGB32);
        
        for (int x = 0; x < width; ++ x)
        {
            const double          value = static_cast<double>(x) / static_cast<double>(width - 1);
            const Eigen::Vector3d color = tinycolormap::GetColor(value, colormap_type.first);
            
            for (int y = 0; y < height; ++ y)
            {
                image.setPixel(x, y, qRgba(color(0) * 255.0, color(1) * 255.0, color(2) * 255.0, 255));
            }
        }
        
        image.save(QString::fromStdString(save_directory_path + "/" + colormap_type.second + ".png"));
    }
    
    return 0;
}
