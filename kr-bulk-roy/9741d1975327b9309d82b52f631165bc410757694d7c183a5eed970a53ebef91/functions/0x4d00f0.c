
void FUN_004d00f0(void)

{
  undefined4 uVar1;
  char cVar2;
  byte bVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  int *in_ECX;
  char *pcVar7;
  undefined4 ***pppuVar8;
  undefined4 **local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00929dc2;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_8 = 0;
    FUN_004f3d80(local_14);
    _atexit((_func_4879 *)&LAB_00bcd1e0);
  }
  local_8 = 0xffffffff;
  iVar5 = FUN_004f7a70();
  if (*(uint *)(iVar5 + 0x4c) < 0x10) {
    pcVar7 = (char *)(iVar5 + 0x38);
  }
  else {
    pcVar7 = *(char **)(iVar5 + 0x38);
  }
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (undefined4 **)((uint)local_30[0] & 0xffffff00);
  pcVar6 = pcVar7;
  do {
    cVar2 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar2 != '\0');
  FUN_00402a70(pcVar7,(int)pcVar6 - (int)(pcVar7 + 1));
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_00401fc0(&DAT_00c07bfc,4);
  pppuVar8 = (undefined4 ***)local_30[0];
  if (local_1c < 0x10) {
    pppuVar8 = local_30;
  }
  if ((DAT_00fe1770 & 1) == 0) {
    DAT_00fe1770 = DAT_00fe1770 | 1;
    local_8._0_1_ = 2;
    FUN_007b7da0();
    _atexit((_func_4879 *)&LAB_00bce790);
    local_8._0_1_ = 1;
  }
  iVar5 = FUN_007b8230(&DAT_00fe173c,pppuVar8);
  in_ECX[0x3c] = iVar5;
  if (iVar5 != 0) {
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_8._0_1_ = 3;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_8._0_1_ = 1;
    }
    uVar4 = DAT_00fb90bc;
    bVar3 = *(byte *)(in_ECX + 0x2c);
    if ((DAT_00fb7c18 & 1) == 0) {
      DAT_00fb7c18 = DAT_00fb7c18 | 1;
      FUN_004449d0();
    }
    iVar5 = in_ECX[0x3c];
    uVar1 = (&DAT_00fb7c20)[bVar3];
    *(int *)(iVar5 + 0x44) = in_ECX[0x28];
    *(int *)(iVar5 + 0x48) = in_ECX[0x29];
    *(int *)(iVar5 + 0x4c) = in_ECX[0x2a];
    *(int *)(iVar5 + 0x28) = in_ECX[0x28];
    *(int *)(iVar5 + 0x2c) = in_ECX[0x29];
    *(int *)(iVar5 + 0x30) = in_ECX[0x2a];
    *(undefined4 *)(iVar5 + 0x58) = uVar1;
    *(undefined4 *)(iVar5 + 0x3c) = uVar1;
    *(undefined4 *)(iVar5 + 0x40) = uVar4;
    *(undefined4 *)(iVar5 + 0x18) = uVar4;
    *(undefined4 *)(iVar5 + 0x70) = 1;
    *(undefined4 *)(iVar5 + 0x6c) = 0;
  }
  *(ushort *)((int)in_ECX + 0xe2) = *(ushort *)((int)in_ECX + 0xe2) | 0x8000;
  *(char *)(in_ECX + 0x39) = (char)in_ECX[0x2c];
  (**(code **)(*in_ECX + 0x58))((char)in_ECX[0x2c]);
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

