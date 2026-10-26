
int FUN_008406d0(int *param_1,undefined2 *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined1 local_ac [156];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090e44d;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_1[8] == param_1[9]) {
    DAT_00fe34e4 = DAT_00fe34e4 + 1;
    iVar3 = param_1[5] - param_1[4] >> 2;
    if (0xffff < DAT_00fe34e4) {
      DAT_00fe34e4 = 1;
    }
    uVar1 = DAT_00fe34e4;
    *param_2 = (short)iVar3;
    param_2[1] = (short)uVar1;
    FUN_008598b0(local_ac);
    local_8 = 0;
    FUN_00840f10(uVar2);
    local_8 = 0xffffffff;
    FUN_0085a2f0(local_ac);
    FUN_006de9c0();
  }
  else {
    iVar3 = *(int *)(param_1[9] + -4);
    DAT_00fe34e4 = DAT_00fe34e4 + 1;
    if (0xffff < DAT_00fe34e4) {
      DAT_00fe34e4 = 1;
    }
    uVar2 = DAT_00fe34e4;
    *param_2 = (short)iVar3;
    param_2[1] = (short)uVar2;
    if (param_1[8] != param_1[9]) {
      param_1[9] = param_1[9] + -4;
    }
    *(uint *)(param_1[4] + iVar3 * 4) = (uint)(ushort)param_2[1];
  }
  ExceptionList = local_10;
  return iVar3 * 0x9c + *param_1;
}

