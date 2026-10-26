
void FUN_005506b0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091df3e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fe1770 & 1) == 0) {
    DAT_00fe1770 = DAT_00fe1770 | 1;
    local_8 = 0;
    FUN_007b7da0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bce790);
  }
  local_8 = 0xffffffff;
  iVar3 = FUN_007b8230(&DAT_00fe173c,unaff_ESI + 0xb);
  if (iVar3 != 0) {
    uVar1 = unaff_ESI[3];
    uVar2 = unaff_ESI[6];
    *(undefined4 *)(iVar3 + 0x44) = *unaff_ESI;
    *(undefined4 *)(iVar3 + 0x48) = unaff_ESI[1];
    *(undefined4 *)(iVar3 + 0x4c) = unaff_ESI[2];
    *(undefined4 *)(iVar3 + 0x28) = *unaff_ESI;
    *(undefined4 *)(iVar3 + 0x2c) = unaff_ESI[1];
    *(undefined4 *)(iVar3 + 0x30) = unaff_ESI[2];
    *(undefined4 *)(iVar3 + 0x58) = uVar1;
    *(undefined4 *)(iVar3 + 0x3c) = uVar1;
    *(undefined4 *)(iVar3 + 0x40) = uVar2;
    *(undefined4 *)(iVar3 + 0x18) = uVar2;
    *(undefined4 *)(iVar3 + 0x70) = 1;
    *(undefined4 *)(iVar3 + 0x6c) = 0;
    unaff_ESI[9] = iVar3;
  }
  ExceptionList = local_10;
  return;
}

