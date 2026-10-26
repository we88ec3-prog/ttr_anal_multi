
int FUN_00721aa0(void)

{
  ushort *puVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  ushort *in_EDX;
  ushort *puVar4;
  
  puVar1 = in_EDX + in_ECX;
  iVar2 = 0;
  if (in_EDX < puVar1) {
    puVar4 = in_EDX + 1;
    do {
      uVar3 = (uint)*in_EDX;
      if ((*in_EDX < 0xd800) || (uVar3 - 0xe000 < 0x2000)) {
        if (uVar3 < 0x80) {
          iVar2 = iVar2 + 1;
        }
        else if (uVar3 < 0x800) {
          iVar2 = iVar2 + 2;
        }
        else {
          iVar2 = iVar2 + 3;
        }
LAB_00721ac6:
        in_EDX = in_EDX + 1;
        puVar4 = puVar4 + 1;
      }
      else {
        if (((0x3ff < uVar3 - 0xd800) || (puVar1 <= puVar4)) || (0x3ff < *puVar4 - 0xdc00))
        goto LAB_00721ac6;
        iVar2 = iVar2 + 4;
        in_EDX = in_EDX + 2;
        puVar4 = puVar4 + 2;
      }
    } while (in_EDX < puVar1);
  }
  return iVar2;
}

