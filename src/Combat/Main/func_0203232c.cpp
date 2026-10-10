// usa: 0203232c
// jpn: 02031e64
extern "C" int rand();
extern "C" void func_0203232c(int* entries, int count) {
 for(int i=0;i<count/2;i++) {
  int index=rand()%count;
  int temp=entries[i];
  entries[i]=entries[index];
  entries[index]=temp;
 }
}
