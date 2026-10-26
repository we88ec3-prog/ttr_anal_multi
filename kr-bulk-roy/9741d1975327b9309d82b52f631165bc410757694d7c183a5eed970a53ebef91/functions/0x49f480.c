
undefined4 * FUN_0049f480(void)

{
  int iVar1;
  int *in_EAX;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int in_EDX;
  int *piVar5;
  
  iVar1 = *in_EAX;
  uVar2 = in_EAX[1] - iVar1 >> 6;
  uVar3 = 0;
  if (uVar2 != 0) {
    piVar5 = (int *)(iVar1 + 0x3c);
    do {
      if (in_EDX + 1 == *piVar5) {
        puVar4 = (undefined4 *)(uVar3 * 0x40 + iVar1);
        if (7 < (uint)puVar4[5]) {
          return (undefined4 *)*puVar4;
        }
        return puVar4;
      }
      uVar3 = uVar3 + 1;
      piVar5 = piVar5 + 0x10;
    } while (uVar3 < uVar2);
  }
  return (undefined4 *)&DAT_00bed1fc;
}

