
int FUN_008be520(undefined4 *param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  byte *in_EAX;
  int iVar3;
  int iVar4;
  undefined *local_8;
  
  if ((in_EAX != (byte *)0x0) && (*in_EAX != 0)) {
    if (param_2 == 8) {
      local_8 = &DAT_00bd7aa8;
    }
    else if (param_2 == 0x10) {
      local_8 = &DAT_00bd7ae8;
    }
    else {
      param_2 = 10;
      local_8 = &DAT_00bd7ac8;
    }
    if ((*in_EAX == 0x30) && ((in_EAX[1] == 0x78 || (in_EAX[1] == 0x58)))) {
      param_2 = 0x10;
      local_8 = &DAT_00bd7ae8;
      in_EAX = in_EAX + 2;
    }
    bVar1 = *in_EAX;
    iVar4 = 0;
    bVar2 = local_8[bVar1 >> 3] & (byte)(1 << (bVar1 & 7));
    while (bVar2 != 0) {
      iVar3 = (int)(char)bVar1;
      bVar1 = in_EAX[1];
      in_EAX = in_EAX + 1;
      iVar4 = iVar4 * param_2 + (uint)(byte)(&DAT_00bd7a28)[iVar3];
      bVar2 = local_8[bVar1 >> 3] & (byte)(1 << (bVar1 & 7));
    }
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = in_EAX;
    }
    return iVar4;
  }
  return 0;
}

