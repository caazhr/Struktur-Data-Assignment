#ifndef MAHASISWA H INCLUDED
#define MAHASISWA_H_INCLUDED
struct mahasiswa{
char nim[10];
int nilail, nilai2;
};
void inputMhs (mahasiswa &m);
float rata2(mahasiswa m);
#endif // MAHASISWA_H_INCLUDED