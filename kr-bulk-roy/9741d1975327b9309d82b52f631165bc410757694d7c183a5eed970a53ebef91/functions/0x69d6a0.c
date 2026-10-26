
void FUN_0069d6a0(void)

{
  int iVar1;
  double dVar2;
  int in_EAX;
  DWORD DVar3;
  
  if (*(char *)(in_EAX + 0x114) != '\0') {
    iVar1 = *(int *)(in_EAX + 0x100);
    if (*(double *)(iVar1 + 0x120) < *(double *)(iVar1 + 0x118)) {
      FUN_0069ec20();
      return;
    }
    DVar3 = timeGetTime();
    dVar2 = (double)(int)DVar3;
    if ((int)DVar3 < 0) {
      dVar2 = dVar2 + 4294967296.0;
    }
    *(double *)(iVar1 + 0x118) = dVar2;
  }
  return;
}

