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
        { tinycolormap::ColormapType::Cividis, "Cividis" },
        { tinycolormap::ColormapType::Github,  "Github"  },
    };

    for (const auto& colormap_type : colormap_types)
    {
        QImage image(width, height, QImage::Format_ARGB32);

        for (int x = 0; x < width; ++ x)
        {
            const double value = static_cast<double>(x) / static_cast<double>(width - 1);
            const QColor color = tinycolormap::GetColor(value, colormap_type.first).ConvertToQColor();

            for (int y = 0; y < height; ++ y)
            {
                image.setPixel(x, y, color.rgb());
            }
        }

        image.save(QString::fromStdString(save_directory_path + "/" + colormap_type.second + ".png"));
    }

    return 0;
}
