
/* WARNING: Removing unreachable block (ram,0x00840648) */

int FUN_00840590(int *param_1,undefined2 *param_2)

{
  uint uVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090bd68;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_1[8] == param_1[9]) {
    DAT_00fe34e0 = DAT_00fe34e0 + 1;
    iVar2 = param_1[5] - param_1[4] >> 2;
    if (0xffff < DAT_00fe34e0) {
      DAT_00fe34e0 = 1;
    }
    uVar1 = DAT_00fe34e0;
    *param_2 = (short)iVar2;
    param_2[1] = (short)uVar1;
    local_8 = 0;
    FUN_00840e50(param_1);
    local_8 = 0xffffffff;
    FUN_006de9c0();
  }
  else {
    iVar2 = *(int *)(param_1[9] + -4);
    DAT_00fe34e0 = DAT_00fe34e0 + 1;
    if (0xffff < DAT_00fe34e0) {
      DAT_00fe34e0 = 1;
    }
    uVar1 = DAT_00fe34e0;
    *param_2 = (short)iVar2;
    param_2[1] = (short)uVar1;
    if (param_1[8] != param_1[9]) {
      param_1[9] = param_1[9] + -4;
    }
    *(uint *)(param_1[4] + iVar2 * 4) = (uint)(ushort)param_2[1];
  }
  ExceptionList = local_10;
  return iVar2 * 0x34 + *param_1;
}

