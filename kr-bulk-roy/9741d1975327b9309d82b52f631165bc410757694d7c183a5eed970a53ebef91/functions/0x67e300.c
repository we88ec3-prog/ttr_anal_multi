
/* WARNING: Removing unreachable block (ram,0x0067e4a0) */
/* WARNING: Removing unreachable block (ram,0x0067e3e1) */

void FUN_0067e300(int param_1)

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
  puStack_c = &LAB_00932dbc;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_1 == 0) {
    iVar1 = *(int *)(in_ECX + 0xf4);
    *(undefined4 *)(iVar1 + 0x98) = *(undefined4 *)(iVar1 + 0xa0);
    *(undefined4 *)(iVar1 + 0x94) = 2;
    *(undefined4 *)(iVar1 + 0xa8) = 0;
    *(undefined4 *)(iVar1 + 0xb0) = 0;
    *(undefined4 *)(iVar1 + 0x90) = 0;
    FUN_0068a590();
    FUN_0040b310("EQUIP_REINFORCE_SUCCESS");
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
    goto LAB_0067e50e;
  }
  if (param_1 == 1) {
    iVar1 = *(int *)(in_ECX + 0xf4);
    *(undefined4 *)(iVar1 + 0x98) = *(undefined4 *)(iVar1 + 0xa0);
    *(undefined4 *)(iVar1 + 0x94) = 2;
    *(undefined4 *)(iVar1 + 0xa8) = 1;
    *(undefined4 *)(iVar1 + 0xb0) = 0;
    *(undefined4 *)(iVar1 + 0x90) = 0;
    FUN_0068a540();
    FUN_0040b310("EQUIP_REINFORCE_FAILED");
    local_8 = 2;
    if ((DAT_00fab0d4 & 1) == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      local_8._0_1_ = 3;
      local_8._1_3_ = 0;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
      local_8 = CONCAT31(local_8._1_3_,2);
    }
    piVar3 = (int *)FUN_0080ab00(&DAT_00fab028);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x14))();
    }
    goto LAB_0067e50e;
  }
  if (param_1 == 5) {
    uVar5 = 0x196;
    FUN_005854b0(0x196,0,0,uVar2);
    uVar5 = FUN_00585330(uVar5);
    uVar4 = 0xb;
LAB_0067e4e9:
    FUN_005854b0(uVar4,uVar5);
    uVar5 = FUN_00585330(uVar4);
    FUN_00404b10(0xca,uVar5);
  }
  else if (param_1 == 0x12) {
    uVar5 = 0x196;
    FUN_005854b0(0x196,0,0,uVar2);
    uVar5 = FUN_00585330(uVar5);
    uVar4 = 0xe8;
    goto LAB_0067e4e9;
  }
  FUN_0068a350();
LAB_0067e50e:
  ExceptionList = local_10;
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}

