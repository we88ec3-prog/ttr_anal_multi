
int FUN_008be600(undefined4 *param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte *in_EAX;
  int iVar4;
  undefined *local_8;
  
  if ((in_EAX != (byte *)0x0) && (bVar1 = *in_EAX, bVar1 != 0)) {
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
    if (bVar1 == 0x2d) {
      in_EAX = in_EAX + 1;
    }
    if ((*in_EAX == 0x30) && ((in_EAX[1] == 0x78 || (in_EAX[1] == 0x58)))) {
      param_2 = 0x10;
      local_8 = &DAT_00bd7ae8;
      in_EAX = in_EAX + 2;
    }
    bVar2 = *in_EAX;
    iVar4 = 0;
    bVar3 = local_8[bVar2 >> 3] & (byte)(1 << (bVar2 & 7));
    while (bVar3 != 0) {
      iVar4 = iVar4 * param_2 + (uint)(byte)(&DAT_00bd7a28)[(char)bVar2];
      bVar2 = in_EAX[1];
      in_EAX = in_EAX + 1;
      bVar3 = local_8[bVar2 >> 3] & (byte)(1 << (bVar2 & 7));
    }
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = in_EAX;
    }
    if (bVar1 == 0x2d) {
      iVar4 = -iVar4;
    }
    return iVar4;
  }
  return 0;
}

