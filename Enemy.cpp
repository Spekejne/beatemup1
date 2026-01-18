void Enemy::update(float dt, const Player& player) {
    if (health <= 0) return;

    int dx = player.x - x;
    int dy = player.y - y;

    // prosty AI: typ 1 -> agresywny
    if (type == 1) {
        if (abs(dx) > 10) x += (dx > 0 ? 100 : -100) * dt;
    } 
    // typ 2 -> dystansowy, strzelanie/szarża
    else if (type == 2) {
        if (abs(dx) > 200) x += (dx > 0 ? 150 : -150) * dt; // zbliżenie
        else if (abs(dx) < 50) x -= (dx > 0 ? 150 : -150) * dt; // dystans
    }

    // można dodać atak jeśli blisko
    if (abs(dx) < 30 && abs(dy) < 30) {
        // uderzenie gracza
    }
}
