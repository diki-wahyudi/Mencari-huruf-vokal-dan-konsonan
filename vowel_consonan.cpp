#include <iostream>
using namespace std;

int main()
{
    string kalimat;
    int vokal, konsonan;
    vokal = konsonan = 0;
    string hurufVokal[50],hurufKonsonan[50];
    cout << "Input: ";
    getline(cin, kalimat);

    cout << "Output: \n";
    for (int i = 0; i < kalimat.length(); ++i)
    {
        if (kalimat[i] == 'a' || kalimat[i] == 'e' || kalimat[i] == 'i' ||
            kalimat[i] == 'o' || kalimat[i] == 'u' || kalimat[i] == 'A' ||
            kalimat[i] == 'E' || kalimat[i] == 'I' || kalimat[i] == 'O' ||
            kalimat[i] == 'U')
        {
            // tambahkan nilai 1 ke variabel vokal, ketika ada huruf vokal
            ++vokal;
            // input huruf konsonan ke array hurufKonsonan
            hurufVokal[i] = kalimat[i];
        }
        else if ((kalimat[i] >= 'a' && kalimat[i] <= 'z') || (kalimat[i] >= 'A' && kalimat[i] <= 'Z'))
        {
            // tambahkan nilai 1 ke variabel vokal, ketika ada huruf konsonan
            ++konsonan;
            // input huruf konsonan ke array hurufKonsonan
            hurufKonsonan[i] = kalimat[i];
        }
    }
    cout << "Vokal: " << vokal << " : ";
    int panjangVokal = sizeof(hurufVokal) / sizeof(hurufVokal[0]);
    for (int v = 0; v < panjangVokal; v++)
    {
        cout << hurufVokal[v];
    }
    cout << endl;
    cout << "Konsonan: " << konsonan << " : ";
    int panjangKonsonan = sizeof(hurufKonsonan) / sizeof(hurufKonsonan[0]);
    for (int k = 0; k < panjangKonsonan; k++)
    {
        cout << hurufKonsonan[k];
    }
    cout << endl;

    //gabungkan data huruf Vokal dan huruf Konsonan menjadi satu array gabungan
    string gabungan[200];
    int x = 0, y = 0, z = 0;
    while (x < panjangVokal && y < panjangKonsonan)
    {
        if (hurufVokal[x] < hurufKonsonan[y])
        {
            gabungan[z++] = hurufVokal[x++];
        }
        else
        {
            gabungan[z++] = hurufKonsonan[y++];
        }
    }
    while (x < panjangVokal)
    {
        gabungan[z++] = hurufVokal[x++];
    }
    while (y < panjangKonsonan)
    {
        gabungan[z++] = hurufKonsonan[y++];
    }

    // pencarian data
    string cari;
    cout << "Masukkan data yang ingin di cari : ";
    cin >> cari;
    int sign = 0;
    int posisi;
    for (int total = 0; total < panjangVokal+panjangKonsonan; total++)
    {
        if (gabungan[total] == cari)
        {
            sign = 1;
        }
    }
    if (sign == 1)
    {
        cout << "data ada" << endl;
    }
    else
        cout << "data tidak ada" << endl;

    return 0;
}