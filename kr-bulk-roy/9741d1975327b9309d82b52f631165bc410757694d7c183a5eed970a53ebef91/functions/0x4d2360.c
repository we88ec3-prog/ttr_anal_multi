
void FUN_004d2360(int *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0094790e;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_1[0xdb] != 0) goto switchD_004d2430_default;
  (**(code **)(*param_1 + 0x4c))(uVar1);
  if ((param_1[0x57] != 0) && (param_1[0xdc] != 0)) {
    FUN_007a7100();
  }
  iVar3 = param_1[0x22];
  if ((DAT_00fab29c & 1) == 0) {
    DAT_00fab29c = DAT_00fab29c | 1;
    local_8 = 0;
    FUN_004ffe60();
    _atexit((_func_4879 *)&LAB_00bccf00);
    local_8 = 0xffffffff;
  }
  uVar2 = FUN_00500a80(&DAT_00fab2a0,(short)iVar3);
  switch(uVar2) {
  case 0:
    if (param_1[0x108] != 0) {
      if (*(int *)(param_1[0x108] + 0x24) != 0) {
        FUN_007be5f0();
      }
      if (param_1[0x108] != 0) {
        FUN_004c7db0();
        param_1[0x108] = 0;
      }
    }
    param_1[0x109] = -1;
    goto switchD_004d2430_default;
  case 1:
    if (param_1[0x109] == 0) goto switchD_004d2430_default;
    if (param_1[0x108] != 0) {
      if (*(int *)(param_1[0x108] + 0x24) != 0) {
        FUN_007be5f0();
      }
      if (param_1[0x108] != 0) {
        FUN_004c7db0();
        param_1[0x108] = 0;
      }
    }
    uVar4 = (uint)*(ushort *)(param_1 + 1);
    uVar5 = 0x3f800000;
    uVar2 = 0;
    FUN_0049b140(uVar4,0,0x3f800000);
    iVar3 = FUN_00551f90(uVar4,uVar2,uVar5);
    param_1[0x109] = 0;
    break;
  case 2:
    if (param_1[0x109] == 3) goto switchD_004d2430_default;
    if (param_1[0x108] != 0) {
      if (*(int *)(param_1[0x108] + 0x24) != 0) {
        FUN_007be5f0();
      }
      if (param_1[0x108] != 0) {
        FUN_004c7db0();
        param_1[0x108] = 0;
      }
    }
    uVar4 = (uint)*(ushort *)(param_1 + 1);
    uVar5 = 0x3f800000;
    uVar2 = 0;
    FUN_0049b140(uVar4,0,0x3f800000);
    iVar3 = FUN_00551f90(uVar4,uVar2,uVar5);
    param_1[0x109] = 3;
    break;
  case 3:
    if (param_1[0x109] == 1) goto switchD_004d2430_default;
    if (param_1[0x108] != 0) {
      if (*(int *)(param_1[0x108] + 0x24) != 0) {
        FUN_007be5f0();
      }
      if (param_1[0x108] != 0) {
        FUN_004c7db0();
        param_1[0x108] = 0;
      }
    }
    uVar4 = (uint)*(ushort *)(param_1 + 1);
    uVar5 = 0x3f800000;
    uVar2 = 0;
    FUN_0049b140(uVar4,0,0x3f800000);
    iVar3 = FUN_00551f90(uVar4,uVar2,uVar5);
    param_1[0x109] = 1;
    break;
  case 4:
    if (param_1[0x109] == 4) goto switchD_004d2430_default;
    if (param_1[0x108] != 0) {
      if (*(int *)(param_1[0x108] + 0x24) != 0) {
        FUN_007be5f0();
      }
      if (param_1[0x108] != 0) {
        FUN_004c7db0();
        param_1[0x108] = 0;
      }
    }
    uVar4 = (uint)*(ushort *)(param_1 + 1);
    uVar5 = 0x3f800000;
    uVar2 = 0;
    FUN_0049b140(uVar4,0,0x3f800000);
    iVar3 = FUN_00551f90(uVar4,uVar2,uVar5);
    param_1[0x109] = 4;
    break;
  case 5:
    iVar3 = FUN_00404ba0();
    iVar3 = *(int *)(iVar3 + 0x5f4c);
    if ((param_1[0x109] == 2) ||
       ((((iVar3 != 3 && (iVar3 != 1)) && (iVar3 != 7)) && ((iVar3 != 0x17 && (iVar3 != 0x18))))))
    goto switchD_004d2430_default;
    if (param_1[0x108] != 0) {
      if (*(int *)(param_1[0x108] + 0x24) != 0) {
        FUN_007be5f0();
      }
      if (param_1[0x108] != 0) {
        FUN_004c7db0();
        param_1[0x108] = 0;
      }
    }
    uVar4 = (uint)*(ushort *)(param_1 + 1);
    uVar5 = 0x3f800000;
    uVar2 = 0;
    FUN_0049b140(uVar4,0,0x3f800000);
    iVar3 = FUN_00551f90(uVar4,uVar2,uVar5);
    param_1[0x109] = 2;
    break;
  case 6:
    if (param_1[0x109] == 6) goto switchD_004d2430_default;
    if (param_1[0x108] != 0) {
      if (*(int *)(param_1[0x108] + 0x24) != 0) {
        FUN_007be5f0();
      }
      if (param_1[0x108] != 0) {
        FUN_004c7db0();
        param_1[0x108] = 0;
      }
    }
    uVar4 = (uint)*(ushort *)(param_1 + 1);
    uVar5 = 0x3f800000;
    uVar2 = 0;
    FUN_0049b140(uVar4,0,0x3f800000);
    iVar3 = FUN_00551f90(uVar4,uVar2,uVar5);
    param_1[0x109] = 6;
    break;
  default:
    goto switchD_004d2430_default;
  }
  param_1[0x108] = iVar3;
switchD_004d2430_default:
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}

