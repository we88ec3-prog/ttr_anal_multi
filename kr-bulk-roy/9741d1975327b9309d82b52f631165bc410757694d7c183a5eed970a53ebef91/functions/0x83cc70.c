
undefined4
FUN_0083cc70(int *param_1,int *param_2,int *param_3,int *param_4,int *param_5,undefined4 param_6,
            double param_7)

{
  double dVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *in_ECX;
  undefined4 *puVar5;
  undefined4 local_94;
  undefined4 local_90 [14];
  int *local_58;
  double local_54;
  int local_4c;
  undefined4 local_48;
  int *local_44;
  int *local_40;
  int *local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  float local_1c;
  float local_18;
  float local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  piVar2 = param_2;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00906deb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_008392d0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  iVar3 = (**(code **)(*param_2 + 4))();
  if (*(int *)(iVar3 + 4) == -0x5ece0000) {
    param_2 = (int *)(**(code **)(*param_1 + 0xf0))(param_2);
  }
  else {
    iVar3 = (**(code **)(*param_2 + 4))();
    if (*(int *)(iVar3 + 4) == -0x5ecc0000) {
      param_2 = (int *)(**(code **)(*param_1 + 0xec))(param_2);
    }
    else {
      param_2 = (int *)0x0;
    }
  }
  dVar1 = param_7;
  if ((param_7 == 0.0) && ((param_2 == (int *)0x2 || (dVar1 = 0.0, param_2 == (int *)0x1)))) {
    local_1c = (float)in_ECX[9];
    local_18 = (float)in_ECX[10];
    local_14 = (float)in_ECX[0xb];
    dVar1 = -((double)(float)param_1[0x2e] * (double)local_14 +
              (double)(float)param_1[0x28] * (double)local_1c +
              (double)(float)param_1[0x2b] * (double)local_18 + (double)(float)param_1[0x31]);
  }
  local_48 = 4;
  local_94 = 0;
  puVar5 = local_90;
  for (iVar3 = 0xd; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *in_ECX;
    in_ECX = in_ECX + 1;
    puVar5 = puVar5 + 1;
  }
  local_4c = (int)param_2;
  local_58 = piVar2;
  local_40 = param_4;
  local_54 = dVar1;
  if (param_4 != (int *)0x0) {
    (**(code **)(*param_4 + 4))(param_4);
  }
  local_44 = param_3;
  if (param_3 != (int *)0x0) {
    (**(code **)(*param_3 + 4))(param_3);
  }
  local_3c = param_5;
  if (param_5 != (int *)0x0) {
    (**(code **)(*param_5 + 4))(param_5);
  }
  local_34 = param_6;
  local_30 = 1;
  local_2c = 0;
  local_38 = 0x18;
  if (param_2 == (int *)0x1) {
    FUN_00841880(&local_94);
    FUN_00841060(param_1 + 0xf4);
  }
  else if (param_2 == (int *)0x2) {
    FUN_00841880(&local_94);
    FUN_008410e0(param_1 + 0xf8);
  }
  else if (param_2 == (int *)0x3) {
    uVar4 = FUN_00841880(&local_94);
    FUN_00840fc0(param_1 + 0xf0,&param_7,uVar4);
  }
  else {
    FUN_0083ec20();
  }
  local_8 = 0xffffffff;
  FUN_00839400();
  ExceptionList = local_10;
  return 1;
}

