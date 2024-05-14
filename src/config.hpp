#ifndef CONFIG_HPP
#define CONFIG_HPP

namespace cfg {
    namespace window {
        static constexpr unsigned int width = 1280;
        static constexpr unsigned int height = 720;
        static constexpr unsigned int fps = 60;
    };

    namespace cell {
        static constexpr float radius = 25.f;
        static constexpr float speed = 100.f;
        static constexpr float ai_cooldown = 2.f; /* in seconds */
    };

    namespace food {
        static constexpr float radius = 10.f;
        static constexpr float spawn_cooldown = 0.5f; /* in seconds */
    };
}

#endif /* CONFIG_HPP */
