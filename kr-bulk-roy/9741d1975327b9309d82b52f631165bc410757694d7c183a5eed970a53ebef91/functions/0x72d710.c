
void FUN_0072d710(void)

{
  int iVar1;
  int *piVar2;
  int *in_EDX;
  
  iVar1 = 0;
  piVar2 = in_EDX + 0x25;
  do {
    if ((short)*piVar2 != 0) break;
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar1 < 9);
  if (iVar1 == 9) {
    iVar1 = 0xe;
    piVar2 = in_EDX + 0x34;
    while ((short)piVar2[-1] == 0) {
      if ((short)*piVar2 != 0) {
        *(uint *)(*in_EDX + 0x2c) = (uint)(iVar1 == 0x1f);
        return;
      }
      if ((short)piVar2[1] != 0) {
        *(uint *)(*in_EDX + 0x2c) = (uint)(iVar1 == 0x1e);
        return;
      }
      if ((short)piVar2[2] != 0) {
        *(uint *)(*in_EDX + 0x2c) = (uint)(iVar1 == 0x1d);
        return;
      }
      if ((short)piVar2[3] != 0) {
        *(uint *)(*in_EDX + 0x2c) = (uint)(iVar1 == 0x1c);
        return;
      }
      if ((short)piVar2[4] != 0) {
        iVar1 = iVar1 + 5;
        break;
      }
      iVar1 = iVar1 + 6;
      piVar2 = piVar2 + 6;
      if (0x1f < iVar1) {
        *(uint *)(*in_EDX + 0x2c) = (uint)(iVar1 == 0x20);
        return;
      }
    }
  }
  *(uint *)(*in_EDX + 0x2c) = (uint)(iVar1 == 0x20);
  return;
}

