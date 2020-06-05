#include <iostream>
#include <vector>
#include <tinycolormap.hpp>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STBI_MSC_SECURE_CRT
#include "stb_image_write.h"

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
        { tinycolormap::ColormapType::Parula,  "Parula"  },
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
        std::vector<uint8_t> image_data;
        image_data.resize(width * height * 3);
        
        for (int x = 0; x < width; ++x)
        {
            const double value = static_cast<double>(x) / static_cast<double>(width - 1);
            const auto color = tinycolormap::GetColor(value, colormap_type.first);

            for (int y = 0; y < height; ++ y)
            {
                int index = 3 * (y * width + x);
                image_data[index + 0] = uint8_t(color.r() * 255.0);
                image_data[index + 1] = uint8_t(color.g() * 255.0);
                image_data[index + 2] = uint8_t(color.b() * 255.0);
            }
        }

        stbi_write_png((save_directory_path + "/" + colormap_type.second + ".png").c_str(), width, height, 3 /* num_components */, image_data.data(), 0);
    }

    return 0;
}
