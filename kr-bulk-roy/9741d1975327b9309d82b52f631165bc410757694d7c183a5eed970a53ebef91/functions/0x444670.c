
undefined4 FUN_00444670(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0094532e;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar5 = 0;
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  ExceptionList = &local_10;
  *(undefined4 *)(*(int *)(in_ECX + 0xc) + 0x374) = 1;
  *(undefined4 *)(*(int *)(in_ECX + 0x18) + 0x374) = 0;
  *(undefined4 *)(*(int *)(in_ECX + 0x24) + 0x374) = 0;
  uVar3 = FUN_005452c0(uVar2);
  iVar1 = *(int *)(in_ECX + 0xc);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 0x158) != 0) {
      iVar5 = *(int *)(*(int *)(iVar1 + 0x158) + 0x30);
    }
    iVar4 = FUN_004c9ed0();
    if ((iVar5 != 0) && (iVar4 == 0)) {
      iVar5 = *(int *)(*(int *)(iVar1 + 0x158) + 8);
      if ((iVar5 == 1) || (iVar5 == 2)) {
        FUN_0049c5c0(iVar1);
      }
      else {
        *(undefined4 *)(in_ECX + 0xac) = 0;
        *(undefined4 *)(in_ECX + 0xa4) = 0;
      }
      goto LAB_00444740;
    }
  }
  *(undefined4 *)(in_ECX + 0xac) = 0;
  *(undefined4 *)(in_ECX + 0xa4) = 0;
LAB_00444740:
  if ((DAT_00fb7c14 & 1) == 0) {
    DAT_00fb7c14 = DAT_00fb7c14 | 1;
    local_8 = 0;
    FUN_006d0750();
    _atexit((_func_4879 *)&LAB_00bcd530);
    local_8 = 0xffffffff;
  }
  uVar2 = (uint)(DAT_00fb9011 == '\x01');
  FUN_00434250(uVar2);
  FUN_00544a00(uVar2);
  ExceptionList = local_10;
  return uVar3;
}

