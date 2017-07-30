#include "Component.h"

Component::Component() {}

Component::~Component() {}

bool Component::Input(SDL_Event* event) { return false; }

void Component::Update(int dt) {}

void Component::Draw() {}
