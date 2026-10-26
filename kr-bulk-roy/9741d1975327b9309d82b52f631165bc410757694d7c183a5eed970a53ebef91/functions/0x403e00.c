
undefined4 FUN_00403e00(int *param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  ushort *in_EDX;
  int iVar3;
  ushort *puVar4;
  ushort *local_8;
  
  iVar1 = param_3 - (int)in_EDX >> 1;
  iVar2 = 0;
  puVar4 = in_EDX;
  if (0 < iVar1) {
    do {
      if (*puVar4 == 0x3d) {
        iVar1 = (int)puVar4 - (int)in_EDX >> 1;
        iVar2 = iVar1 + -1;
        if (iVar1 == 1) goto LAB_00403e99;
        iVar1 = 0;
        iVar3 = 0;
        if (iVar2 < 1) goto LAB_00403e9c;
        goto LAB_00403e73;
      }
      iVar2 = iVar2 + 1;
      puVar4 = puVar4 + 1;
    } while (iVar2 < iVar1);
  }
  if (iVar1 == 1) {
LAB_00403eb7:
    iVar2 = -1;
  }
  else {
    iVar2 = 0;
    iVar3 = 0;
    if (0 < iVar1 + -1) {
      do {
        in_EDX = in_EDX + 1;
        if (9 < *in_EDX - 0x30) goto LAB_00403eb7;
        iVar3 = iVar3 + 1;
        iVar2 = (*in_EDX - 0x30) + iVar2 * 10;
      } while (iVar3 < iVar1 + -1);
    }
  }
  *param_1 = iVar2;
  *param_2 = 0;
  return 0;
LAB_00403e99:
  iVar1 = -1;
  goto LAB_00403e9c;
  while( true ) {
    iVar3 = iVar3 + 1;
    iVar1 = (*local_8 - 0x30) + iVar1 * 10;
    in_EDX = local_8;
    if (iVar2 <= iVar3) break;
LAB_00403e73:
    local_8 = in_EDX + 1;
    if (9 < *local_8 - 0x30) goto LAB_00403e99;
  }
LAB_00403e9c:
  *param_1 = iVar1;
  *param_2 = (param_3 - (int)puVar4 >> 1) + -1;
  return 1;
}

