#include <iostream>
#include <string>
#include <vector>

struct Vertex
{
    float x, y, z;

    Vertex(float x, float y, float z)
        : x(x), y(y), z(z) {
    }

    Vertex Add(const Vertex& other) const
    {
        return Vertex(x + other.x, y + other.y, z + other.z);
    }

    Vertex operator+(const Vertex& other) const
    {
        return Add(other);
    }

    Vertex Multiply(const Vertex& other) const
    {
        return Vertex(x * other.x, y * other.y, z * other.z);
    }

    Vertex operator*(const Vertex& other) const
    {
        return Multiply(other);
    }

    Vertex Divide(const Vertex& other) const
    {
        return Vertex(x / other.x, y / other.y, z / other.z);
    }

    Vertex operator/(const Vertex& other) const
    {
        return Divide(other);
    }

    bool operator==(const Vertex& other) const
    {
        return x == other.x && y == other.y && z == other.z;
    }

    bool operator!=(const Vertex& other) const
    {
        return x != other.x && y != other.y && z != other.z;
    }
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
    stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
    return stream;
}

class Example
{
public:
    Example()
    {
        std::cout << "Example constructor\n";
    }

    Example(int x)
    {
        std::cout << "Example constructor with : " << x << "!\n";
    }
};

class Entity
{
private:
    Example m_Example;
    std::string m_Name;
public:
    Entity()
    {
        m_Name = std::string("Unknown");
        m_Example = Example(8);
    }

    Entity(const std::string& name)
        : m_Name(name) { }

    const std::string GetName() const
    {
        return "unkown";
    }
};

class Player : public Entity
{
private:
    std::string m_Name;
    int m_Length;
public:
    Player(const std::string& name = "Unknown")
        :m_Name(name), m_Length(0) { }

    void SetLength(int length)
    {
        this->m_Length = length;
    }

    int GetLength() const
    {
        return m_Length;
    }

    const std::string GetName() const
    {
        return m_Name;
    }

    friend std::ostream& operator<<(std::ostream& stream, const Player& player);
    friend std::istream& operator>>(std::istream& input, Player& player);
};

std::ostream& operator<<(std::ostream& stream, const Player& player)
{
    stream << player.m_Name;
    return stream;
}

std::istream& operator>>(std::istream& input, Player& player)
{
    input >> player.m_Name;
    return input;
}

class ScopedPtr
{
private:
    Player* m_Obj;
public:
    int x;

    ScopedPtr(Player* obj)
        : m_Obj(obj) {
    }

    Player* operator->()
    {
        return m_Obj;
    }

    const Player* operator->() const
    {
        return m_Obj;
    }

    ~ScopedPtr()
    {
        delete m_Obj;
    }
};

bool searchWord(const std::string_view& word, char search)
{
    bool isTrue = false;
    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] == search)
        {
            std::cout << "column: " << i << '\n';
            isTrue = true;
            continue;
        }
    }
    if (isTrue)
        return true;
    return false;
}

int main()
{
    int x = 1025;
    int* y = &x;
    char* ptrY = (char*)y;
    //char* ptrY = (char*)&x;
    std::cout << "size y: " << sizeof(*y) << '\n';
    std::cout << "addres y: " << int(y) << ", value y: " << *y << '\n';
    std::cout << "addres y+1: " << int(y + 1) << ", value y+1: " << *(y + 1) << '\n';
    //*(y + 1) = 3;
    //std::cout << "value y+1: " << *(y + 1) << '\n';

    void* p0 = &x;
    std::cout << *static_cast<int*>(p0) << '\n';

    std::cout << "size ptrY: " << sizeof(*ptrY) << '\n';
    std::cout << "addres: " << int(ptrY) << ", value ptrY: " << int(*ptrY) << '\n';
    std::cout << "addres ptrY+1: " << int(ptrY + 1) << ", value ptrY+1: " << int(*(ptrY + 1)) << '\n';
    *(ptrY + 1) = 0x25;
    std::cout << "value y: " << *y << '\n';
    std::cout << "value ptrY + 1: " << int(*(ptrY + 1)) << '\n';

    char* arr[2] = { ptrY, ptrY + 1 };
    *arr[0] = 0x05;
    *arr[1] = 0x02;
    std::cout << "value ptrY: " << int(*(ptrY)) << '\n';
    std::cout << "value ptrY + 1: " << int(*(ptrY + 1)) << '\n';
    std::cout << "value y: " << *y << '\n';

#if 0
    char pilihan;
    char waktu;
    int orang;
    int total;
    char eksekutif;
    int bus;

    std::string waktuEksekutif = {
        "Waktu Keberangkatan Bus Eksekutif\n"
        "a.Pagi\n"
        "b.Malam\n"
        "Pilihan anda: "
    };

    std::string waktuPariwisata = {
    "Waktu Keberangkatan Bus Pariwisata\n"
    "a.Pagi\n"
    "b.Malam\n"
    "Pilihan anda: "
    };

    std::string menu = {
        "Jadwal dan harga tiket keberangkatan BUS\n"
        "1.Jakarta-Malang\n"
        "2.Jakarta-Solo\n"
        "Masukan pilihan anda (1-2): "
    };


    while (true)
    {
        std::cout << menu;
        std::cin >> pilihan;

        switch (pilihan)
        {
        case '1':
            std::cout << "anda mau memilih bus Eksekutif (y/n)? : ";
            std::cin >> eksekutif;

            switch (eksekutif)
            {
            case 'y':
                std::cout << waktuEksekutif;
                std::cin >> waktu;

                switch (waktu)
                {
                case 'a':
                    std::cout << "Harga perorang= Rp.50\n";
                    std::cout << "Input Banyak orang: ";
                    std::cin >> orang;
                    total = orang * 50;
                    std::cout << "Total Harga: " << total << '\n';
                    break;

                case 'b':
                    std::cout << "Harga perorang= Rp.75\n";
                    std::cout << "Input Banyak orang: ";
                    std::cin >> orang;
                    total = orang * 75;
                    std::cout << "Total Harga: " << total << '\n';
                    break;

                default:
                    std::cout << "kode tidak ada\n";
                    continue;
                }
                break;

            case 'n':
                std::cout << "Maaf Bus Ekonomi Jakarta-Malang untuk saat ini belum tersedia\n";
                continue;

            default:
                std::cout << "kode tidak ada\n";
                continue;
            }
            break;

        case '2':
            char pariwisata;
            std::cout << "Anda mau memilih bus Pariwisata (y/n) ? : ";
            std::cin >> pariwisata;

            switch (pariwisata)
            {
            case 'y':
                std::cout << waktuPariwisata;
                std::cin >> waktu;

                switch (waktu)
                {
                case 'a':
                    std::cout << "Harga paket = Rp.500\n";
                    std::cout << "Banyak bus: ";
                    std::cin >> bus;
                    total = bus * 500;
                    std::cout << "Total Harga: " << total << '\n';
                    break;

                case 'b':
                    std::cout << "Harga paket = Rp.750\n";
                    std::cout << "Banyak bus: ";
                    std::cin >> bus;
                    total = bus * 750;
                    std::cout << "Total Harga: " << total << '\n';
                    break;

                default:
                    std::cout << "kode tidak ada\n";
                    continue;
                }
                break;

            case 'n':
                std::cout << "Maaf Bus Ekonomi Yogyakarta_Solo untuk saat ini hanya melayani pariwisata\n";
                break;

            default:
                std::cout << "kode tidak ada\n";
                continue;
                break;
            }
            break;

        default:
            std::cout << "kode tidak ada\n";
            continue;
        }
        break;

    }

    int input = 4;

    for (int i = 1; i <= input; i++)
    {
        for (int j = 1; j <= i; j++)
            std::cout << j << " ";
        std::cout << '\n';
    }

    for (int i = input; i >= 0; i--)
    {
        for (int j = 1; j < i; j++)
            std::cout << j << " ";
        std::cout << '\n';
    }

    

    const char* hello = "Hello world";
    bool isTrue = searchWord(hello, 'o');

    std::cout << isTrue << '\n';
    std::cout << hello << ", " << *(hello + 1) << '\n';

    int arr[4] = { 2, 4, 3, 5 };
    int* arrPtr = arr;

    std::cout << arrPtr[0] << '\n';
    std::cout << *(arrPtr + 3) << '\n';
    *(arrPtr + 3) = 7;
    std::cout << *(arrPtr + 3) << '\n';

    arrPtr = nullptr;

    std::cout << "before" << char(0xa) << "after\n";

    char a = 'a';
    std::cout << a << ", " << char(a + 1) << '\n';

    for (char c = 'a'; c <= 'z'; c++)
        std::cout << c << '\n';

    int* x = new int[50];
    int* y = new(x) int;

    int* b = new int[50];
    Player* p1 = new(b) Player;

#endif

    std::cin.get();

    return 0;
}