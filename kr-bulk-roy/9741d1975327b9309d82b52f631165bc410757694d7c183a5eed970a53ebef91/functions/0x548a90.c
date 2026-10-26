
undefined4 FUN_00548a90(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  uint uVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0094532e;
  local_10 = ExceptionList;
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  ExceptionList = &local_10;
  uVar2 = FUN_005452c0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  iVar1 = *(int *)(in_ECX + 0xc);
  if (iVar1 != 0) {
    iVar4 = 0;
    if (*(int *)(iVar1 + 0x158) != 0) {
      iVar4 = *(int *)(*(int *)(iVar1 + 0x158) + 0x30);
    }
    iVar3 = FUN_004c9ed0();
    if (((iVar4 != 0) && (iVar3 == 0)) &&
       ((iVar4 = *(int *)(*(int *)(iVar1 + 0x158) + 8), iVar4 == 1 || (iVar4 == 2)))) {
      FUN_0049c5c0(iVar1);
      goto LAB_00548b2e;
    }
  }
  *(undefined4 *)(in_ECX + 0xa4) = 0;
  *(undefined4 *)(in_ECX + 0xac) = 0;
LAB_00548b2e:
  if ((DAT_00fb7c14 & 1) == 0) {
    DAT_00fb7c14 = DAT_00fb7c14 | 1;
    local_8 = 0;
    FUN_006d0750();
    _atexit((_func_4879 *)&LAB_00bcd530);
    local_8 = 0xffffffff;
  }
  uVar5 = (uint)(DAT_00fb9011 == '\x01');
  FUN_00434250(uVar5);
  FUN_00544a00(uVar5);
  ExceptionList = local_10;
  return uVar2;
}

