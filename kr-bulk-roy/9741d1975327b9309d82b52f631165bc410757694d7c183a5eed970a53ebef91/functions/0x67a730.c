
/* WARNING: Removing unreachable block (ram,0x0067a813) */

void FUN_0067a730(int param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int in_ECX;
  undefined4 uVar4;
  undefined4 uVar5;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = -1;
  puStack_c = &LAB_00932c16;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_1 == 0) {
    iVar1 = *(int *)(in_ECX + 0x11c);
    *(undefined4 *)(iVar1 + 0x98) = *(undefined4 *)(iVar1 + 0xa0);
    *(undefined4 *)(iVar1 + 0x94) = 2;
    *(undefined4 *)(iVar1 + 0xa8) = 0;
    *(undefined4 *)(iVar1 + 0xb0) = 0;
    *(undefined4 *)(iVar1 + 0x90) = 0;
    FUN_0068a590();
    FUN_0040b310("ITEM_ADDSLOT_SUCCESS");
    local_8 = 0;
    if ((DAT_00fab0d4 & 1) == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      local_8._0_1_ = 1;
      local_8._1_3_ = 0;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
      local_8 = (uint)local_8._1_3_ << 8;
    }
    piVar3 = (int *)FUN_0080ab00(&DAT_00fab028);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x14))();
    }
  }
  else if (param_1 == 1) {
    iVar1 = *(int *)(in_ECX + 0x11c);
    *(undefined4 *)(iVar1 + 0x98) = *(undefined4 *)(iVar1 + 0xa0);
    *(undefined4 *)(iVar1 + 0x94) = 2;
    *(undefined4 *)(iVar1 + 0xa8) = 1;
    *(undefined4 *)(iVar1 + 0xb0) = 0;
    *(undefined4 *)(iVar1 + 0x90) = 0;
    FUN_0068a540();
  }
  else {
    if (param_1 == 5) {
      uVar5 = 0x196;
      FUN_005854b0(0x196,0,0,uVar2);
      uVar5 = FUN_00585330(uVar5);
      uVar4 = 0xb;
      FUN_005854b0(0xb,uVar5);
      uVar5 = FUN_00585330(uVar4);
      FUN_00404b10(0xca,uVar5);
    }
    FUN_0068a350();
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}

