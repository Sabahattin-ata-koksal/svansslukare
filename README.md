# Svansslukare Cosmic Voyager Oyunu

Svansslukare Proje Ekibi:
- Kuzey TORÇUK 231201043
- Sabahattin Ata KÖKSAL 231201024
- Alper ACAR 231201076

GİRİŞ VE KODUN AMACI:
TOBB ETÜ BİL142 dersi kapsamında dönem sonu projesi için C++ dilinde yazılan yazı tabanlı uzay yolculuğu temalı bir bilgisayar oyunu yapımı istenmiştir. Bu dokümanlarda oyunun dosyalarının tamamı bulunmaktadır.

OYUNUN YAPISI VE OYNANIŞI:
Oyunda 3 adet olay (asteroid kuşağı, terk edilmiş gezegen, uzay korsanları) ve 3 adet gemi türü (hızlı, güçlü, normal) bulunmaktadır. Gemiler MainShip klasından inherite edilmiştir, olaylar ise fonksiyonlardan oluşmaktadır. Oyunda olaylar rastgele çağrılacağı için ve her olayda bazı olasılık hesapları yapılması gerektiğ içi bu olasılık hesaplarının hepsini yapan bir olasılık üretici klas, MainShip klasının parent klasıdır. Olayların istenilen adette çağrılmasını ve olay örgüsünün kontrolünü sağlaması için ek bir oyun fonksiyonu oluşturulmuştur. Oyun fonksiyonu, 5 adet olay döndürdükten sonra (olayların daha rahat görülebilmesi için olaylar arasında birkaç saniyelik gecikme konulmuştur) ya da oyuncunun seçtiği geminin yakıtı/canı sıfırlanıyorsa oyunu bitirmektedir.

 NOT: Kodun en başında olaylar için klas kullanımı denenmiştir ancak koddaki bağlantı hataları ve diğer envai çeşit hatalar, kodda değişikliğe gidilmesine sebep olmuştur. Aynı şekilde kod düzenlenirken de smart pointer kullanımı amaçlanmış fakat çözülemeyen sorunlar nedeniyle raw pointerlarda karar kılınmıştır. 
