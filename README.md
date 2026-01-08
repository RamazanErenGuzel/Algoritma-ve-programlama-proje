# Uzay Simülasyonu – Algoritmalar ve Programlama Projesi

Bu proje, Algoritmalar ve Programlama dersi kapsamında **C programlama dili** kullanılarak
geliştirilmiş **konsol tabanlı** bir uzay simülasyonu uygulamasıdır.

## Projenin Amacı
Bu çalışmanın amacı, Güneş Sistemi’nde yer alan gezegenlerin farklı yerçekimi ivmeleri altında
çeşitli fizik deneylerini simüle etmek ve temel fizik formüllerinin yazılım ortamında
uygulanmasını sağlamaktır.

Program, bir bilim insanının uzayda yaptığı deneyleri simüle eden bir senaryo üzerine
kurgulanmıştır.

## Programın Genel Çalışma Mantığı
1. Program başlatıldığında kullanıcıdan bilim insanının adı alınır.
2. Kullanıcıya deney menüsü sunulur.
3. Seçilen deney için gerekli fiziksel büyüklükler kullanıcıdan alınır.
4. Sonuçlar, Güneş Sistemi’ndeki tüm gezegenler için ayrı ayrı hesaplanır.
5. Hesaplanan sonuçlar birimleri ile birlikte konsola yazdırılır.
6. Kullanıcı `-1` değerini girene kadar program çalışmaya devam eder.

## İçerilen Deneyler
1. Serbest Düşme Deneyi  
2. Yukarı Atış Deneyi  
3. Ağırlık Deneyi  
4. Kütleçekimsel Potansiyel Enerji Deneyi  
5. Hidrostatik Basınç Deneyi  
6. Arşimet Kaldırma Kuvveti Deneyi  
7. Basit Sarkaç Periyodu Deneyi  
8. Sabit İp Gerilmesi Deneyi  
9. Asansör Deneyi  

## Teknik Özellikler
- Program **C dili** ile yazılmıştır.
- Konsol tabanlıdır, grafiksel arayüz içermez.
- Gezegenlerin yerçekimi ivmeleri bir **dizi** içerisinde tutulmuştur.
- Dizilere **yalnızca pointer kullanılarak** erişilmiştir.
- Tüm deneyler **ayrı fonksiyonlar** halinde yazılmıştır.
- Negatif girilen değerler **ternary operatörü** kullanılarak mutlak değere çevrilmiştir.
- Deney çıktıları birimleri ile birlikte gösterilmiştir.

## Kullanılan Gezegenler
- Merkür
- Venüs
- Dünya
- Mars
- Jüpiter
- Satürn
- Uranüs
- Neptün

## Derleme ve Çalıştırma
Aşağıdaki komutlar kullanılarak program derlenip çalıştırılabilir:

```bash
gcc main.c -o uzay_simulasyonu -lm
./uzay_simulasyonu

