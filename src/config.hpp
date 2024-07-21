#ifndef CONFIG_HPP
#define CONFIG_HPP

namespace cfg {
    namespace window {
        inline constexpr unsigned int width  = 1280;
        inline constexpr unsigned int height = 720;
        inline constexpr unsigned int fps    = 60;
    };

    namespace ai {
        inline constexpr unsigned int num      = 9;
        inline constexpr float        cooldown = 2.f; // in seconds
    }

    namespace cell {
        inline constexpr float radius = 25.f;
        inline constexpr float speed  = 100.f;
    };

    namespace food {
        inline constexpr float radius         = 10.f;
        inline constexpr float spawn_cooldown = 0.5f; // in seconds
    };

    namespace text {
        inline constexpr unsigned int size = 48;
    }
}

#endif // CONFIG_HPP
