
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004fe3b0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined2 local_1c;
  undefined2 uStack_1a;
  undefined2 uStack_18;
  undefined1 local_16;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar2 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093b01e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = *(undefined4 *)(param_1 + 2);
  iVar3 = FUN_0040f060(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  param_1 = uVar1;
  FUN_008438c0(&param_1);
  if ((local_14 != *(int *)(iVar3 + 0x1c)) && (*(int *)(local_14 + 0x10) != 0)) {
    iVar3 = CONCAT22(uStack_1a,local_1c);
    if (*(int *)(iVar3 + 0x5eac) == 0) {
      if ((DAT_00fb73b8 & 1) == 0) {
        DAT_00fb73b8 = DAT_00fb73b8 | 1;
        local_8 = 0;
        FUN_00560170();
        _atexit((_func_4879 *)&LAB_00bcd110);
        local_8 = 0xffffffff;
      }
      if (DAT_00fb73e8 == 0) {
        FUN_004054c0();
        FUN_0058ab80(0xf427a,*(undefined4 *)(iVar2 + 2));
      }
      else {
        uVar1 = *(undefined4 *)(iVar2 + 2);
        if ((_DAT_00fb1314 & 1) == 0) {
          _DAT_00fb1314 = _DAT_00fb1314 | 1;
          _atexit((_func_4879 *)&DAT_00bccf10);
        }
        local_1c = 0x4a;
        uStack_1a = (undefined2)uVar1;
        uStack_18 = (undefined2)((uint)uVar1 >> 0x10);
        local_16 = 2;
        if (DAT_00fba798 == 0) {
          (**(code **)(*DAT_00fba854 + 0x10))(0,&local_1c,7);
        }
        *(undefined4 *)(iVar3 + 0x5eac) = 0;
      }
    }
    else {
      if ((_DAT_00fb1314 & 1) == 0) {
        _DAT_00fb1314 = _DAT_00fb1314 | 1;
        _atexit((_func_4879 *)&DAT_00bccf10);
      }
      local_1c = 0x4a;
      uStack_1a = (undefined2)*(undefined4 *)(iVar2 + 2);
      uStack_18 = (undefined2)((uint)*(undefined4 *)(iVar2 + 2) >> 0x10);
      local_16 = 1;
      if (DAT_00fba798 == 0) {
        (**(code **)(*DAT_00fba854 + 0x10))(0,&local_1c,7);
      }
    }
    ExceptionList = local_10;
    return 0;
  }
  FUN_006edb60("ReqTradeFromUser: Received trade request from unknown user %d",
               *(undefined4 *)(iVar2 + 2));
  ExceptionList = local_10;
  return 0x80004005;
}

