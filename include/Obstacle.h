#include <iostream>
#include <array>

#include "MathTypes.h"
#include "Object.h"

namespace Joguinho
{
    class Obstacle : public DynamicObject {
        public:
            Obstacle(Vector position,
                Vector velocity,
                Vector size,
                SDL_Texture* texture);
            ~Obstacle();
        
            void render(SDL_Renderer* renderer) override;
            void update(float deltaTime) override;
    };
}
