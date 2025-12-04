#include <SFML/Graphics.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Pong Game");
	window.setFramerateLimit(60);

	sf::RectangleShape leftPaddle(sf::Vector2f(20, 100));
	leftPaddle.setPosition(50, 250);
	leftPaddle.setFillColor(sf::Color::White);

	sf::RectangleShape rightPaddle(sf::Vector2f(20, 100));
	rightPaddle.setPosition(730, 250);
	rightPaddle.setFillColor(sf::Color::White);

	sf::CircleShape ball(10);
	ball.setPosition(400, 300);
	ball.setFillColor(sf::Color::Red);

	float ballSpeedX = 5.0f;
	float ballSpeedY = 3.0f;

	float paddleSpeed = 8.0f;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && leftPaddle.getPosition().y > 0) {
			leftPaddle.move(0, -paddleSpeed);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && leftPaddle.getPosition().y < 500) {
			leftPaddle.move(0, paddleSpeed);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && rightPaddle.getPosition().y > 0) {
			rightPaddle.move(0, -paddleSpeed);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && rightPaddle.getPosition().y < 500) {
			rightPaddle.move(0, paddleSpeed);
		}

		ball.move(ballSpeedX, ballSpeedY);

		if (ball.getPosition().y <= 0 || ball.getPosition().y >= 580) {
			ballSpeedY = -ballSpeedY;
		}

		if (ball.getGlobalBounds().intersects(leftPaddle.getGlobalBounds()) ||
			ball.getGlobalBounds().intersects(rightPaddle.getGlobalBounds())) {
			ballSpeedX = -ballSpeedX;
		}

		if (ball.getPosition().x <= 0 || ball.getPosition().x >= 800) {
			ball.setPosition(400, 300);
		}

		window.clear(sf::Color::Black);
		window.draw(leftPaddle);
		window.draw(rightPaddle);
		window.draw(ball);
		window.display();
	}

	return 0;
}