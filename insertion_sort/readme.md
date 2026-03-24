# Insertion Sort

Decrease and conquer (azalt ve fethet) mnatığını kullanır. Problemi her adımda sadece bir birim küçültür.

- In-Place (Yerinde): Algoritma çalışırken orijinal dizinin dışında ekstra devasa bir belleğe ihtiyaç duymaz. Sadece "key" dediğimiz o anki elemanı tutmak için tek bir değişkenlik yer kullanır. Uzay karmaşıklığının O(1) olmasının sebebi budur.

- Stable (Kararlı): Eğer dizide iki tane aynı değer varsa (örneğin iki tane "5" sayısı), algoritma bittiğinde bu iki "5"in orijinal sırası bozulmaz. Insertion Sort'ta A[j] > key kontrolü yaptığımız için, değerler eşitse kaydırma yapmaz ve sırayı korur.

Örnek:

Elimizde [5,2,4,6,1,3] 6 elemanlı bir dizi olsun.

- 5 sıralı kabul edilir, 2 elemanına bakılır. 2<5 olduğu için 5 sağa kaydırılır ve 2 başa gelir.

    [2,5,4,6,1,3]

- 4 elemanına bakılır, 4<5'tir ama 2'den büyüktür. 5 sağa kayar, 4 ortaya yerleşir.

    [2,4,5,6,1,3]

- 6'ya bakılır. 6 5'ten büyüktür yerinde kalır.

    [2,4,5,6,1,3]

- 1'e bakılır. Kendinden önceki tüm elemanlardan küçük olduğundan tek tek sağa kaydırılır.

    [1,2,4,5,6,3]

- 3'e bakılır. 6'dan küçük kaydırılır, 5'ten küçük kaydırılır. 5'ten küçük kaydırılır, 4'ten küçük kaydırılır. 2'den büyük olduğu yerde durur.

    [1,2,3,4,5,6]

## Algoritma Analizi

6 elemanlı diziyi sıralamak için:

- Önce 5 elemanlı sıraladık (n-1)
- Sonra 1 elemanlı (n) bu sıralı yapıya entegre ettik
- `T(n) = T(n-1)+ C(n)`

T(n) : Toplam süre, bir önceki T(n-1) boyut sıralama süresi ile bağlantılıdır.
C(n): son elemanı doğu yere yerleştirme maliyeti. En kötü durumda her seferinde n kadar olduğu için `n(n-1) / 2` olur.

Bu formül ile karmaşıklık `O(n^2)` çıkar.

En iyi durumda ise dizi zaten sıralıysa sadece karşılaştırma yapılır ve `O(n)` çıkar.

Ortalama olarak `O(n^2)` çıkar.

Alan karmaşıklığı ise O(1)'dir. Orjinal dizi üzerinden sıralama yapılır. (in-place)


Pseudocode: 
```bash
InsertionSort(A):
  for i = 1 to length(A) - 1:
    key = A[i]
    j = i - 1
    while j >= 0 and A[j] > key:
      A[j + 1] = A[j]
      j = j - 1
    A[j + 1] = key
```

# Sonuç:

- her defasında bir eleman azaltır
- ekstra bellek gerektirmez O(1)
- en iyi durum O(n)
- en kötü durum O(n^2)

---

> İnsertion Sort C kodu için [bu](./insertion_sort.c) dosyaya bakabilirsiniz. (çalıştırmak için dizine gidip make run yazınız)