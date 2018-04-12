#include <iostream>
#include <QImage>
#include <tinycolormap.h>

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
    
    const std::vector<std::pair<tinycolormap::ColorMapType, std::string>> color_map_types
    {
        { tinycolormap::ColorMapType::Heat,    "Heat"    },
        { tinycolormap::ColorMapType::Jet,     "Jet"     },
        { tinycolormap::ColorMapType::Hot,     "Hot"     },
        { tinycolormap::ColorMapType::Gray,    "Gray"    },
        { tinycolormap::ColorMapType::Magma,   "Magma"   },
        { tinycolormap::ColorMapType::Inferno, "Inferno" },
        { tinycolormap::ColorMapType::Plasma,  "Plasma"  },
        { tinycolormap::ColorMapType::Viridis, "Viridis" },
        { tinycolormap::ColorMapType::Github,  "Github"  },
    };

    for (const auto& color_map_type : color_map_types)
    {
        QImage image(width, height, QImage::Format_ARGB32);
        
        for (int x = 0; x < width; ++ x)
        {
            const double          value = static_cast<double>(x) / static_cast<double>(width - 1);
            const Eigen::Vector3d color = tinycolormap::GetColor(value, color_map_type.first);
            
            for (int y = 0; y < height; ++ y)
            {
                image.setPixel(x, y, qRgba(color(0) * 255.0, color(1) * 255.0, color(2) * 255.0, 255));
            }
        }
        
        image.save(QString::fromStdString(save_directory_path + "/" + color_map_type.second + ".png"));
    }
    
    return 0;
}
