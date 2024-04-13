#ifndef CONFIG_HPP
#define CONFIG_HPP

namespace cfg {
    class Ball {
    public:
        static constexpr float RADIUS = 25.f;
        static constexpr float SPEED = 100.f;
    };

    class Food {
    public:
        static constexpr float RADIUS = 10.f;
        static constexpr float SPAWN_COOLDOWN = 0.5f; /* in seconds */
    };

    class Window {
    public:
        static constexpr unsigned int WIDTH = 1280;
        static constexpr unsigned int HEIGHT = 720;
        static constexpr unsigned int FPS = 60;
    };
}

#endif /* CONFIG_HPP */
