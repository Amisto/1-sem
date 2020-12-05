#include <SFML/Graphics.hpp>
#include <iostream>
#include "map.h"


using namespace sf;

int main()
{
	RenderWindow window(sf::VideoMode(1200, 675), "SFML works!");// ��� ���� ��������: Style::Fullscreen

	//! MAP!

	Image map_image;//������ ����������� ��� �����
	map_image.loadFromFile("images/map.png");//��������� ���� ��� �����
	Texture map;//�������� �����
	map.loadFromImage(map_image);//�������� �������� ���������
	Sprite s_map;//������ ������ ��� �����
	s_map.setTexture(map);//�������� �������� ��������

	//! SIMBA!

	Image simbaimg; //������� ������ Image (�����������)
	simbaimg.loadFromFile("images/simba.png");//��������� � ���� ����

	Texture simbatexture;//������� ������ Texture (��������)
	simbatexture.loadFromImage(simbaimg);//�������� � ���� ������ Image (�����������)

	Sprite simbasprite;//������� ������ Sprite(������)
	simbasprite.setTexture(simbatexture);//������� � ���� ������ Texture (��������)
	simbasprite.setTextureRect(IntRect(0, 180, 38, 38));//�������� ������ ��� ������������� � �����
	simbasprite.setPosition(250, 250);//������ ��������� ���������� ��������� �������

	//! KOVU!

	Image kovuimg; //������� ������ Image (�����������)
	kovuimg.loadFromFile("images/kovu.png");//��������� � ���� ����

	Texture kovutexture;//������� ������ Texture (��������)
	kovutexture.loadFromImage(kovuimg);//�������� � ���� ������ Image (�����������)

	Sprite kovusprite;//������� ������ Sprite(������)
	kovusprite.setTexture(kovutexture);//������� � ���� ������ Texture (��������)
	kovusprite.setTextureRect(IntRect(0, 0, 38, 38));//�������� ������ ��� ������������� � �����
	kovusprite.setPosition(200, 200);//������ ��������� ���������� ��������� �������


	float CurrentFrame = 0;
	Clock clock;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds(); //���� ��������� ����� � �������������
		clock.restart(); //������������� �����
		time = time / 800; //�������� ����
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//! MOVING SIMBA!

		if ((Keyboard::isKeyPressed(Keyboard::Right)))
		{
			CurrentFrame += 0.005 * time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
			if (CurrentFrame > 7) CurrentFrame -= 7; // ���� ������ � �������� ����� - ������������ �����.
			simbasprite.setTextureRect(IntRect(38 * int(CurrentFrame), 180, 38, 38)); //���������� �� ����������� �. ���������� �������� ��������� � ���������� � ������ 0,96,96*2, � ����� 0
			simbasprite.move(0.1 * time, 0);//���������� ���� �������� ��������� ������

		}

		if ((Keyboard::isKeyPressed(Keyboard::Left)))
		{
			CurrentFrame += 0.005 * time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
			if (CurrentFrame > 7) CurrentFrame -= 7; // ���� ������ � �������� ����� - ������������ �����.
			simbasprite.setTextureRect(IntRect(38 * int(CurrentFrame+1), 180, -38, 38)); //���������� �� ����������� �. ���������� �������� ��������� � ���������� � ������ 0,96,96*2, � ����� 0
			simbasprite.move(-0.1 * time, 0);//���������� ���� �������� ��������� �����
		
		}

		if ((Keyboard::isKeyPressed(Keyboard::Up)))
		{	
			CurrentFrame += 0.005 * time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
			if (CurrentFrame > 2) CurrentFrame -= 2; // ���� ������ � �������� ����� - ������������ �����.
			simbasprite.setTextureRect(IntRect(30 * int(CurrentFrame), 240, 30, 30)); //���������� �� ����������� �. ���������� 0,96,96*2, � ����� 0
			simbasprite.move(0, -0.1 * time);//���������� ���� �������� ��������� �����
		}

		if ((Keyboard::isKeyPressed(Keyboard::Down)))
		{
			CurrentFrame += 0.005 * time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
			if (CurrentFrame > 2) CurrentFrame -= 2; //���� ������ � �������� ����� - ������������ �����.
			simbasprite.setTextureRect(IntRect(30 * int(CurrentFrame), 240, 30, 30)); //���������� �� ����������� �. ���������� 0,96,96*2,� ����� 0
			simbasprite.move(0, 0.1 * time);//���������� ���� �������� ��������� ����
		}

		//! MOVING KOVU!

		if ((Keyboard::isKeyPressed(Keyboard::D)))
		{
			CurrentFrame += 0.005 * time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
			if (CurrentFrame > 4) CurrentFrame -= 4; // ���� ������ � �������� ����� - ������������ �����.
			kovusprite.setTextureRect(IntRect(41 * int(CurrentFrame), 100, 41, 27)); //���������� �� ����������� �. ���������� �������� ��������� � ���������� � ������ 0,96,96*2, � ����� 0
			kovusprite.move(0.1 * time, 0);//���������� ���� �������� ��������� ������

		}

		if ((Keyboard::isKeyPressed(Keyboard::A)))
		{
			CurrentFrame += 0.005 * time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
			if (CurrentFrame > 4) CurrentFrame -= 4; // ���� ������ � �������� ����� - ������������ �����.
			kovusprite.setTextureRect(IntRect(41 * int(CurrentFrame + 1), 100, -41, 27)); //���������� �� ����������� �. ���������� �������� ��������� � ���������� � ������ 0,96,96*2, � ����� 0
			kovusprite.move(-0.1 * time, 0);//���������� ���� �������� ��������� �����

		}

		if ((Keyboard::isKeyPressed(Keyboard::W)))
		{
			CurrentFrame += 0.005 * time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
			if (CurrentFrame > 2) CurrentFrame -= 2; // ���� ������ � �������� ����� - ������������ �����.
			kovusprite.setTextureRect(IntRect(37 * int(CurrentFrame), 36, 37, 26)); //���������� �� ����������� �. ���������� 0,96,96*2, � ����� 0
			kovusprite.move(0, -0.1 * time);//���������� ���� �������� ��������� �����
		}

		if ((Keyboard::isKeyPressed(Keyboard::S)))
		{
			CurrentFrame += 0.005 * time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
			if (CurrentFrame > 2) CurrentFrame -= 2; //���� ������ � �������� ����� - ������������ �����.
			kovusprite.setTextureRect(IntRect(37 * int(CurrentFrame), 36, 37, 26)); //���������� �� ����������� �. ���������� 0,96,96*2,� ����� 0
			kovusprite.move(0, 0.1 * time);//���������� ���� �������� ��������� ����
		}




		window.clear();

		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap[i][j] == 's') s_map.setTextureRect(IntRect(255, 0, 334, 70)); //���� ��������� ������ ������, �� ������ 1� ���������
				if (TileMap[i][j] == ' ') s_map.setTextureRect(IntRect(334, 0, 400, 70));//���� ��������� ������ s, �� ������ 2� ���������
				if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(0, 0, 70, 70));//���� ��������� ������ 0, �� ������ 3� ���������



				s_map.setPosition(j * 32, i * 32);//�� ���� ����������� ����������, ��������� � �����. �� ���� ������ ������� �� ��� �������. ���� ������, �� ��� ����� ���������� � ����� �������� 32*32 � �� ������ ���� �������

				window.draw(s_map);
			}

		window.draw(simbasprite);
		window.draw(kovusprite);
		window.display();
	}


	
	return 0;
}
