
void FUN_006d8da0(void)

{
  int iVar1;
  DWORD DVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 8);
  do {
    if (iVar1 == 0) {
      return;
    }
    DVar2 = WaitForSingleObject(*(HANDLE *)(in_ECX + 0xc),1000);
    if (DVar2 == 0) {
      if (*(int *)(in_ECX + 8) == 0) {
        return;
      }
      while (*(int *)(in_ECX + 0x10) != 0) {
        (**(code **)(**(int **)(in_ECX + 0x14) + 8))();
        if (*(int *)(in_ECX + 8) == 0) {
          return;
        }
      }
    }
    iVar1 = *(int *)(in_ECX + 8);
  } while( true );
}

