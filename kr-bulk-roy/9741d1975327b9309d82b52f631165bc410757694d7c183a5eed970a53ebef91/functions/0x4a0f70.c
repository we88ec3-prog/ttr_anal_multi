
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a0f70(uint param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
                 int param_6)

{
  code *pcVar1;
  uint uVar2;
  void *pvVar3;
  int iVar4;
  int *piVar5;
  int local_28;
  undefined4 local_24;
  undefined4 uStack_1c;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00939f6b;
  local_14 = ExceptionList;
  pvVar3 = (void *)(DAT_00d61f20 ^ (uint)&stack0xffffffc8);
  ExceptionList = &local_14;
  piVar5 = (int *)0x0;
  iVar4 = 0;
  if (((int)param_1 < 10) || (iVar4 = (((int)param_1 < 0x2711) - 1 & 5) + 1, iVar4 == 0)) {
    local_28 = FUN_00891268(0x444);
    local_c = 0;
    if (local_28 == 0) {
LAB_004a1043:
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = (int *)FUN_004cd6f0(local_28,0);
    }
  }
  else {
    if (iVar4 == 1) {
      local_28 = FUN_00891268(0x434);
      if (local_28 == 0) {
        piVar5 = (int *)0x0;
      }
      else {
        local_c = iVar4;
        piVar5 = (int *)FUN_004d1710(local_28);
      }
      local_c = 0xffffffff;
      FUN_004a0dd0(param_1);
      goto LAB_004a104f;
    }
    if (iVar4 != 6) goto LAB_004a104f;
    local_28 = FUN_00891268(0x42c);
    local_c = 2;
    if (local_28 == 0) goto LAB_004a1043;
    piVar5 = (int *)FUN_004d2120(local_28);
  }
  local_c = 0xffffffff;
LAB_004a104f:
  pcVar1 = *(code **)(*piVar5 + 0x44);
  *(undefined2 *)(piVar5 + 1) = DAT_00f7de04;
  local_28 = param_2;
  local_24 = param_3;
  (*pcVar1)(&local_28,1);
  (**(code **)(*piVar5 + 0x58))(param_5);
  (**(code **)(*piVar5 + 0x3c))(iVar4 << 0x18 | param_1 & 0xffff);
  if ((int)param_1 < 10) {
    *(undefined2 *)(piVar5 + 0xe2) = 1;
    if ((piVar5[0x57] != 0) && (piVar5[0xdc] != 0)) {
      FUN_007a6ea0(piVar5[0x57],1,1);
    }
  }
  (**(code **)(*piVar5 + 0x30))();
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    uStack_1c = 3;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    uStack_1c = 0xffffffff;
  }
  (**(code **)(*piVar5 + 0x5c))((float)param_4 * DAT_00fb90bc);
  (**(code **)(*piVar5 + 0x44))(&stack0xffffffcc,1);
  (**(code **)(piVar5[0x3c] + 8))(1);
  (**(code **)(*piVar5 + 0x68))(1,0x3f800000);
  uVar2 = DAT_00fab22c & 1;
  piVar5[0x33] = 0x42700000;
  if (uVar2 == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  FUN_004dff30(&DAT_00fab130);
  _DAT_00f7de04 = _DAT_00f7de04 + 1;
  if (param_6 != 0) {
    pcVar1 = *(code **)(*DAT_00fba7a4 + 4);
    DAT_00fba7a4[1] = 1;
    (*pcVar1)(piVar5);
    (**(code **)(*DAT_00fba7a4 + 0x10))();
    if ((DAT_00fb7c14 & 1) == 0) {
      DAT_00fb7c14 = DAT_00fb7c14 | 1;
      FUN_006d0750();
      _atexit((_func_4879 *)&LAB_00bcd530);
    }
    DAT_00fb8830 = 0;
  }
  ExceptionList = pvVar3;
  return;
}

