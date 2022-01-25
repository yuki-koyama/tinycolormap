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

    constexpr int width          = 300;
    constexpr int height         = 30;
    constexpr int num_components = 3;

    const std::vector<std::pair<tinycolormap::ColormapType, std::string>> colormap_types
    {
        { tinycolormap::ColormapType::Parula,    "Parula"    },
        { tinycolormap::ColormapType::Heat,      "Heat"      },
        { tinycolormap::ColormapType::Jet,       "Jet"       },
        { tinycolormap::ColormapType::Turbo,     "Turbo"     },
        { tinycolormap::ColormapType::Hot,       "Hot"       },
        { tinycolormap::ColormapType::Gray,      "Gray"      },
        { tinycolormap::ColormapType::Magma,     "Magma"     },
        { tinycolormap::ColormapType::Inferno,   "Inferno"   },
        { tinycolormap::ColormapType::Plasma,    "Plasma"    },
        { tinycolormap::ColormapType::Viridis,   "Viridis"   },
        { tinycolormap::ColormapType::Cividis,   "Cividis"   },
        { tinycolormap::ColormapType::Github,    "Github"    },
        { tinycolormap::ColormapType::Cubehelix, "Cubehelix" },
    };

    for (const auto& colormap_type : colormap_types)
    {
        std::vector<uint8_t> image_data(width * height * num_components);

        for (int x = 0; x < width; ++x)
        {
            const double value = static_cast<double>(x) / static_cast<double>(width - 1);
            const auto   color = tinycolormap::GetColor(value, colormap_type.first);

            for (int y = 0; y < height; ++ y)
            {
                const int index = num_components * (y * width + x);

                image_data[index + 0] = color.ri();
                image_data[index + 1] = color.gi();
                image_data[index + 2] = color.bi();
            }
        }

        const std::string save_file_path = save_directory_path + "/" + colormap_type.second + ".png";

        stbi_write_png(save_file_path.c_str(), width, height, num_components, image_data.data(), 0);
    }

    return 0;
}
