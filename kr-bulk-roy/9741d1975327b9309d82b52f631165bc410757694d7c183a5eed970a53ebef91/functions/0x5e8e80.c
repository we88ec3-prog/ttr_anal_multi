
void FUN_005e8e80(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  int iVar5;
  void *unaff_EBX;
  int iVar6;
  undefined4 unaff_EDI;
  undefined4 uVar7;
  int local_40;
  undefined4 local_3c;
  uint local_38;
  int local_30;
  int local_2c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093ef4e;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffb0;
  iVar6 = 0;
  if (in_ECX[0x57] == 0) {
    return;
  }
  if (in_ECX[0x58] == 0) {
    return;
  }
  local_40 = 0;
  local_30 = 0;
  local_2c = 0;
  ExceptionList = &local_14;
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_c = 0;
    FUN_0051c120(uVar1);
    _atexit((_func_4879 *)&LAB_00bccc90);
  }
  local_c = 0xffffffff;
  iVar2 = FUN_0051d700(param_2);
  if (iVar2 == 0) {
    local_3c = param_1;
    iVar2 = FUN_004034e0();
    FUN_008438c0(&local_3c);
    if (local_38 == *(uint *)(iVar2 + 4)) {
      ExceptionList = local_14;
      return;
    }
    iVar2 = *(int *)(local_38 + 0x10);
    if (iVar2 == 0) {
      ExceptionList = local_14;
      return;
    }
  }
  if (*(int *)(iVar2 + 4) != 0) {
    iVar3 = FUN_00404ba0();
    if ((((*(int *)(iVar2 + 4) - 1U < 0xf) &&
         (*(int *)(iVar2 + 4) * 0x108 + *(int *)(iVar3 + 0x6920) != 0)) &&
        (piVar4 = (int *)FUN_00508be0(), piVar4 != (int *)0x0)) && (*piVar4 != 0)) {
      local_30 = piVar4[2];
      local_40 = piVar4[1];
      local_2c = piVar4[3];
      iVar6 = *piVar4;
    }
    goto LAB_005e9081;
  }
  iVar3 = *(int *)(iVar2 + 8);
  switch(iVar3) {
  case 1:
  case 2:
  case 3:
  case 4:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x1b:
  case 0x20:
  case 0x24:
  case 0x25:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
    FUN_0040f060();
    iVar2 = (**(code **)(*DAT_00fba7a4 + 0x20))();
    if (iVar2 == 0) goto LAB_005e9081;
    local_38 = (uint)*(ushort *)(iVar2 + 0x88);
    iVar2 = FUN_00404ba0();
    iVar2 = FUN_00509650(*(undefined4 *)(iVar2 + 0x6920));
    if (((iVar2 == 0) || (piVar4 = (int *)FUN_00508be0(), piVar4 == (int *)0x0)) || (piVar4[1] == 0)
       ) goto LAB_005e9081;
    iVar2 = *piVar4;
    local_40 = piVar4[1];
    break;
  default:
    if ((iVar3 != 0x10) && (iVar3 != 0x1c)) goto LAB_005e9081;
    uVar7 = *(undefined4 *)(iVar2 + 0x60);
    FUN_004034e0(uVar7);
    iVar2 = FUN_00523230(uVar7);
    if (*(int *)(iVar2 + 4) == 0) goto LAB_005e9081;
    iVar2 = FUN_00404ba0();
    iVar2 = FUN_00509650(*(undefined4 *)(iVar2 + 0x6920));
    if (iVar2 == 0) goto LAB_005e9081;
    piVar4 = (int *)FUN_00508be0();
    iVar2 = *piVar4;
    if (iVar2 == 0) goto LAB_005e9081;
    local_40 = piVar4[1];
  }
  local_2c = piVar4[3];
  local_30 = piVar4[2];
  iVar6 = iVar2;
LAB_005e9081:
  iVar2 = in_ECX[0x57];
  *(int *)(iVar2 + 0x1ac) = local_2c;
  *(undefined1 *)(iVar2 + 0x19c) = 1;
  *(int *)(iVar2 + 0x1a0) = iVar6;
  *(int *)(iVar2 + 0x1a4) = local_40;
  *(int *)(iVar2 + 0x1a8) = local_30;
  (**(code **)(*(int *)in_ECX[0x57] + 0x184))
            (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  if ((iVar6 == 0) && (local_40 == 0)) {
    (**(code **)(*(int *)in_ECX[0x58] + 0x94))(0);
    FUN_00749a00(0,0);
    iVar6 = in_ECX[0x57];
    (**(code **)(*in_ECX + 0xbc))
              (in_ECX[2],in_ECX[3],(*(int *)(iVar6 + 0x10) - *(int *)(iVar6 + 8)) + in_ECX[2],
               (*(int *)(iVar6 + 0x14) - *(int *)(iVar6 + 0xc)) + in_ECX[3]);
    ExceptionList = unaff_EBX;
    return;
  }
  (**(code **)(*(int *)in_ECX[0x58] + 0x94))(1);
  (**(code **)(*(int *)in_ECX[0x58] + 0x184))(iVar6,local_40,uVar1,unaff_EDI,0,0,0,0);
  iVar6 = in_ECX[0x57];
  iVar3 = *(int *)(iVar6 + 0x10) - *(int *)(iVar6 + 8);
  iVar2 = in_ECX[0x58];
  iVar5 = *(int *)(iVar2 + 0x10) - *(int *)(iVar2 + 8);
  iVar2 = *(int *)(iVar2 + 0x14) - *(int *)(iVar2 + 0xc);
  iVar6 = (*(int *)(iVar6 + 0x14) - *(int *)(iVar6 + 0xc)) + 0x1e;
  FUN_00749a00(0,0x1e);
  FUN_00749a00(iVar3,0);
  if (iVar2 < iVar6) {
    iVar2 = iVar6;
  }
  (**(code **)(*in_ECX + 0xbc))(in_ECX[2],in_ECX[3],in_ECX[2] + iVar5 + iVar3,iVar2 + in_ECX[3]);
  ExceptionList = local_14;
  return;
}

