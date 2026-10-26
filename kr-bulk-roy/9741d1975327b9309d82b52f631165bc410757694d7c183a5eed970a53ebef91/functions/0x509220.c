
void FUN_00509220(void)

{
  undefined4 *puVar1;
  int iVar2;
  void *unaff_ESI;
  
  iVar2 = 0x1e0;
  puVar1 = (undefined4 *)((int)unaff_ESI + 8);
  do {
    puVar1[-2] = 0;
    puVar1[-1] = 0;
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1 = puVar1 + 6;
    iVar2 = iVar2 + -1;
  } while (-1 < iVar2);
  *(undefined4 *)((int)unaff_ESI + 0x2d18) = 0;
  _memset(unaff_ESI,0,0x2d18);
  return;
}

