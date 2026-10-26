
int * FUN_0071efc0(int *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  char *in_ECX;
  undefined4 uVar3;
  int local_58 [2];
  undefined4 *local_50;
  undefined4 local_4c;
  undefined4 *local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  undefined1 local_28 [4];
  undefined4 local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0090f1e8;
  local_14 = ExceptionList;
  switch(*in_ECX) {
  case '\x0e':
    local_50 = (undefined4 *)param_3[1];
    local_44 = *local_50;
    local_40 = local_50[1];
    local_c = 0;
    local_4c = *param_3;
    ExceptionList = &local_14;
    local_48 = local_50;
    FUN_0071efc0(local_28,param_2,&local_50);
    FUN_0071efc0(&local_38,param_2,param_3);
    local_38 = 0;
    FUN_0071cfe0(local_24,*param_3);
    FUN_0071d060();
    *param_1 = local_38;
    param_1[1] = local_34;
    param_1[2] = local_30;
    param_1[3] = local_2c;
    local_c = 0xffffffff;
    FUN_0071beb0();
    ExceptionList = local_14;
    return param_1;
  case '\x10':
  case '\x11':
    ExceptionList = &local_14;
    FUN_0071efc0(&local_48,param_2,param_3);
    if (*in_ECX == '\x10') {
      local_48 = (undefined4 *)FUN_0071ceb0(local_44);
    }
    FUN_0071d4e0(&local_48,0,*(undefined4 *)(in_ECX + 8),param_3);
    *param_1 = (int)local_48;
    param_1[1] = local_44;
    param_1[2] = local_40;
    param_1[3] = local_3c;
    ExceptionList = local_14;
    return param_1;
  case '\x14':
    if (in_ECX[1] == '\x01') {
      piVar2 = *(int **)(in_ECX + 0x10) + 2;
      if (**(int **)(in_ECX + 0x10) != 1) {
        piVar2 = &DAT_00f7ad18;
      }
      local_48 = (undefined4 *)*piVar2;
      local_44 = 0;
      local_40 = 0;
      local_3c = 0;
      ExceptionList = &local_14;
      FUN_0071cfe0(piVar2[3],*param_3);
      *param_1 = (int)local_48;
      param_1[1] = local_44;
      param_1[2] = local_40;
      param_1[3] = local_3c;
      ExceptionList = local_14;
      return param_1;
    }
  default:
switchD_0071f004_caseD_f:
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    return param_1;
  case '8':
    break;
  case '9':
    goto switchD_0071f004_caseD_39;
  }
  switch(in_ECX[2]) {
  case '\0':
    local_58[0] = (uint)local_58[0]._1_3_ << 8;
    ExceptionList = &local_14;
    FUN_00723f50(in_ECX,param_3,local_58[0]);
    ExceptionList = local_14;
    return param_1;
  case '\x01':
    local_58[0] = (uint)local_58[0]._1_3_ << 8;
    ExceptionList = &local_14;
    FUN_007240f0(in_ECX,param_3,local_58[0]);
    ExceptionList = local_14;
    return param_1;
  case '\x02':
    local_58[0] = (uint)local_58[0]._1_3_ << 8;
    ExceptionList = &local_14;
    FUN_007242a0(in_ECX,param_3,local_58[0]);
    ExceptionList = local_14;
    return param_1;
  case '\x03':
    local_58[0] = (uint)local_58[0]._1_3_ << 8;
    ExceptionList = &local_14;
    FUN_007243b0(in_ECX,param_3,local_58[0]);
    ExceptionList = local_14;
    return param_1;
  case '\x04':
    local_58[0] = (uint)local_58[0]._1_3_ << 8;
    ExceptionList = &local_14;
    FUN_007244c0(in_ECX,param_3,local_58[0]);
    ExceptionList = local_14;
    return param_1;
  case '\x05':
    local_58[0] = (uint)local_58[0]._1_3_ << 8;
    ExceptionList = &local_14;
    FUN_007245f0(param_3,local_58[0]);
    ExceptionList = local_14;
    return param_1;
  case '\x06':
    local_58[0] = (uint)local_58[0]._1_3_ << 8;
    ExceptionList = &local_14;
    FUN_007247a0(in_ECX,param_3,local_58[0]);
    ExceptionList = local_14;
    return param_1;
  case '\a':
    local_58[0] = (uint)local_58[0]._1_3_ << 8;
    ExceptionList = &local_14;
    FUN_00724940(in_ECX,param_3,local_58[0]);
    ExceptionList = local_14;
    return param_1;
  case '\b':
    goto switchD_0071f004_caseD_f;
  case '\t':
    local_58[0] = (uint)local_58[0]._1_3_ << 8;
    ExceptionList = &local_14;
    FUN_00724a70(in_ECX,param_3,local_58[0]);
    ExceptionList = local_14;
    return param_1;
  case '\n':
    local_58[0] = (uint)local_58[0]._1_3_ << 8;
    ExceptionList = &local_14;
    FUN_00724c00(in_ECX,param_3,local_58[0]);
    ExceptionList = local_14;
    return param_1;
  case '\v':
    local_58[0] = (uint)local_58[0]._1_3_ << 8;
    ExceptionList = &local_14;
    FUN_00724da0(in_ECX,param_3,local_58[0]);
    ExceptionList = local_14;
    return param_1;
  case '\f':
    local_58[0] = (uint)local_58[0]._1_3_ << 8;
    ExceptionList = &local_14;
    FUN_00724ed0(param_1,param_2,param_3,local_58[0]);
    ExceptionList = local_14;
    return param_1;
  }
switchD_0071f004_caseD_39:
  iVar1 = param_2[1];
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_48 = (undefined4 *)0x1;
  piVar2 = param_2;
  if (iVar1 != 0) {
    local_58[0] = 0;
    piVar2 = local_58;
  }
  if (*piVar2 == 0) {
    if (iVar1 == 0) goto LAB_0071f443;
    ExceptionList = &local_14;
    FUN_00721400(DAT_00d61f20 ^ (uint)&stack0xffffff98);
    piVar2 = (int *)FUN_0071bb90();
    local_50 = (undefined4 *)*piVar2;
    uVar3 = *param_3;
  }
  else {
    if (iVar1 != 0) {
      local_58[0] = 0;
      param_2 = local_58;
    }
    if (((uint *)*param_2 == (uint *)0x0) ||
       (iVar1 = *(int *)(*(uint *)*param_2 & 0xffffffe0), iVar1 == 0)) {
      local_50 = (undefined4 *)0x0;
      uVar3 = *param_3;
      ExceptionList = &local_14;
    }
    else {
      local_50 = (undefined4 *)(iVar1 + -0x20);
      uVar3 = *param_3;
      ExceptionList = &local_14;
    }
  }
  local_4c = 0;
  FUN_0071cf80(&local_50,uVar3);
LAB_0071f443:
  *param_1 = (int)local_48;
  param_1[1] = local_44;
  param_1[2] = local_40;
  param_1[3] = local_3c;
  ExceptionList = local_14;
  return param_1;
}

