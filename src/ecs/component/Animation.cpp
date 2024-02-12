#include "../../../include/ecs/component/Animation.hpp"


th::Animation::Animation(
    const std::string& name,
    const std::filesystem::path& source,
    const bool repeat_ = true,
    const double animationSpeed_ = th::ANIMATION_SPEED
) : th::Component(name),
    repeat(repeat_),
    animationSpeed(animationSpeed_) {
    for (const auto& p : std::filesystem::directory_iterator(source)) {
        sprites.push_back(
            std::make_unique<th::Sprite>(p.path())
        );
    }
    std::sort(
        sprites.begin(), sprites.end(),
        [](std::unique_ptr<th::Sprite>& s1, std::unique_ptr<th::Sprite>& s2) {
            return s1->name < s2->name;
        }
    );
}


void th::Animation::setRepeat(const bool repeatOn) {
    repeat = repeatOn;
}


void th::Animation::update(const float dt) {
    currentIndex += dt * animationSpeed;
    if (repeat) {
        currentIndex = std::fmod(
            currentIndex, 
            sprites.size()
        );
    } else if (currentIndex > sprites.size() - 1) {
        currentIndex = sprites.size() - 1;
    }
}


void th::Animation::draw(sf::RenderWindow& window) {
    sprites[(int) currentIndex]->draw(window);
}


void th::Animation::setGameObj(th::GameObj* gameObj) {
    for (std::unique_ptr<th::Sprite>& sprite : sprites) {
        sprite->setGameObj(gameObj);
    }
}


void th::Animation::reset() {
    currentIndex = 0;
}


th::AnimationPool::AnimationPool(
    const std::filesystem::path& source
) : th::Component("AnimationPool") {
    for (const auto& p : std::filesystem::directory_iterator(source)) {
        std::filesystem::path path = p.path();
        animationName = path.stem().string();
        animationMap.insert({animationName, th::Animation(animationName, path)});
    }
}


void th::AnimationPool::changeAnimation(const std::string& newAnimationName) {
    if (newAnimationName != animationName) {
        animationName = newAnimationName;
        animationMap.at(newAnimationName).reset();
    }
}


void th::AnimationPool::update(const float dt) {
    animationMap.at(animationName).update(dt);
}


void th::AnimationPool::draw(sf::RenderWindow& window) {
    animationMap.at(animationName).draw(window);
}


void th::AnimationPool::setGameObj(th::GameObj* gameObj) {
    for (auto& [name, animation] : animationMap) {
        animation.setGameObj(gameObj);
    }
}


std::map<std::string, th::Animation>* th::AnimationPool::getAnimationMap() {
    return &animationMap;
}
