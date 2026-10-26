
int FUN_00725170(void)

{
  ushort *puVar1;
  int iVar2;
  ushort uVar3;
  int in_ECX;
  uint uVar4;
  ushort *in_EDX;
  ushort *puVar5;
  
  puVar1 = in_EDX + in_ECX;
  iVar2 = 0;
  if (in_EDX < puVar1) {
    puVar5 = in_EDX + 1;
    do {
      uVar3 = *in_EDX << 8 | *in_EDX >> 8;
      uVar4 = (uint)uVar3;
      if ((uVar3 < 0xd800) || (uVar4 - 0xe000 < 0x2000)) {
        if (uVar4 < 0x80) {
          iVar2 = iVar2 + 1;
        }
        else if (uVar4 < 0x800) {
          iVar2 = iVar2 + 2;
        }
        else {
          iVar2 = iVar2 + 3;
        }
LAB_0072519d:
        in_EDX = in_EDX + 1;
        puVar5 = puVar5 + 1;
      }
      else {
        if (((0x3ff < uVar4 - 0xd800) || (puVar1 <= puVar5)) ||
           (0x3ff < (ushort)(*puVar5 << 8 | *puVar5 >> 8) - 0xdc00)) goto LAB_0072519d;
        iVar2 = iVar2 + 4;
        in_EDX = in_EDX + 2;
        puVar5 = puVar5 + 2;
      }
    } while (in_EDX < puVar1);
  }
  return iVar2;
}

