
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b4680(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined4 uVar4;
  undefined1 auStack_2c [4];
  undefined2 local_28;
  undefined1 local_26;
  undefined2 local_24;
  undefined1 local_22;
  undefined2 local_21;
  undefined1 local_1f;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0094390c;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_2c;
  ExceptionList = &local_14;
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    local_c = 0;
    FUN_00539c20(DAT_00d61f20 ^ (uint)&stack0xffffffc8);
    _atexit((_func_4879 *)&LAB_00bccfb0);
  }
  local_c = 0xffffffff;
  if (DAT_00fb7258 == 0) goto LAB_005b4802;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 1;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  iVar2 = FUN_00539aa0(DAT_00f93930);
  if (iVar2 == 0) {
LAB_005b47bc:
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    local_28 = 6;
    if (DAT_00fba798 != 0) goto LAB_005b4802;
    uVar4 = 2;
    puVar3 = &local_28;
  }
  else {
    if (*(char *)(iVar2 + 6) == '\0') {
      if (*(char *)(iVar2 + 8) == '\0') {
        FUN_005972e0(param_1);
      }
      goto LAB_005b47bc;
    }
    FUN_00423240();
    FUN_00516fa0();
    iVar2 = *(int *)(param_1 + 0x2e4);
    local_28 = *(undefined2 *)(iVar2 + 0x131);
    uVar1 = *(undefined1 *)(iVar2 + 0x130);
    local_26 = *(undefined1 *)(iVar2 + 0x133);
    FUN_00414680();
    local_24 = 0x84;
    local_21 = local_28;
    local_1f = local_26;
    local_22 = uVar1;
    if (DAT_00fba798 != 0) goto LAB_005b4802;
    uVar4 = 6;
    puVar3 = &local_24;
  }
  (**(code **)(*DAT_00fba854 + 0x10))(0,puVar3,uVar4);
LAB_005b4802:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_2c);
  return;
}

