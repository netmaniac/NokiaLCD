# Biblioteka obsługi Arduino LCD Shield ARD Graph 123

Biblioteka dotyzy produktu: https://nettigo.pl/products/54
Wywodzi się z projektu: https://github.com/netmaniac/NokiaLCD

Postanowiłem ja ulepszyć, ponieważ nie lubię kiedy API robią specjaliści od radzieckiej satelity.

### Interfejs:
Interfejs oparłem luźno na stosie PDF wzorowanym na interfejsie Canvas z HTML5. Jestem do takiego interfejsu przyzwyczajony i uważam, że jest wygodny.

- Automatycznie zadeklarowany globalny obiekt Display
- Display.begin() - inicjuje wyświetlacz
- Display.backlight(light) - 1 włącza podświetlanie, 0 wyłącza
- Display.clear() - czyści zawartość wyświetlacza
- Display.moveTo(x, y) - przesuwa kursor na zadaną pozycję
- Display.setColor(color) - ustawia kolor kolejnego elementu
- Display.setBackground(color) - ustawia kolor tła następnego elementu
- Display.setFont(font) - ustawia krój pisma dla kolejnego elemetu
- Display.pixel() - rysuje pixel w punkcie wyznaczonym przez moveTo
- Display.lineTo(x, y) - rysuje linie od punktu wyznaczonego przez moveTo. Po narysowaniu linii, jej koniec wyznacza nowe współrzędne dla kolejnego elementu
- Display.fillRect(x, y, width, height) - rysuje protokąt
- Display.circle(x, y, radius) - rysuje koło
- Display.bitmap(x, y, data) - rysuje obrazek z pamięci

#### Interfejs Print z Arduino
Dodatkowo obiekt ma też funkcje pisania tekstu z Arduino oparte o znane metody [print](http://arduino.cc/en/Serial/Print) i [println](http://arduino.cc/en/Serial/Println). Funkcje te działaja jak w obiekcie Serial i przyjmują wszystkie typy danych jak w Serial.

Display.print(F("Ala ma kota"));
Display.print(123, BIN);
Display.print(2.384, 2);

Przykład użycia biblioteki w przykładzie o nazwie "nokia_test".

*Uwaga:* Gdy napis dojdzie do końca wyświetlacza nie wyświetla dalszych znaków.

Uwagi i propozycje rozszerzeń mile widziane :-)

sprae