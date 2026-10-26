
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005dd110(undefined4 param_1)

{
  int in_ECX;
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092e1ac;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fab0d8 & 1) == 0) {
    DAT_00fab0d8 = DAT_00fab0d8 | 1;
    local_8 = 0;
    FUN_004dd4a0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    DAT_00fab0ec = 0;
    _DAT_00fab0f0 = 0;
    _DAT_00fab0f4 = 0;
    _atexit((_func_4879 *)&LAB_00bccdb0);
  }
  local_8 = 0xffffffff;
  local_1c = *(undefined4 *)(in_ECX + 0x248);
  local_18 = *(int *)(in_ECX + 0x24c);
  FUN_004dd400(&DAT_00fab0dc,&local_14,&local_1c);
  if (local_14 == DAT_00fab0e0) {
    local_14 = 0;
  }
  else {
    local_14 = *(int *)(local_14 + 0x18);
  }
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_8 = 1;
    FUN_0051c120();
    _atexit((_func_4879 *)&LAB_00bccc90);
    local_8 = 0xffffffff;
  }
  FUN_008438c0(&param_1);
  if (local_18 == DAT_00f8d91c) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(local_18 + 0x10);
  }
  (**(code **)(**(int **)(in_ECX + 0x2c8) + 0x94))(0);
  (**(code **)(**(int **)(in_ECX + 0x2c0) + 0x94))(0);
  (**(code **)(**(int **)(in_ECX + 0x2c4) + 0x94))(0);
  if ((iVar2 != 0) && (iVar2 = *(int *)(iVar2 + 0x54), iVar2 != 0)) {
    switch(*(undefined4 *)(iVar2 + 8)) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 0x1b:
    case 0x28:
    case 0x29:
    case 0x2a:
    case 0x2b:
      if (local_14 == 0) {
        FUN_005dd5c0(in_ECX,1);
        piVar1 = *(int **)(in_ECX + 0x2c0);
        uVar3 = 1;
      }
      else {
        FUN_005dd5c0(in_ECX,*(int *)(local_14 + 0x10) + 1);
        piVar1 = *(int **)(in_ECX + 0x2c0);
        uVar3 = 1;
      }
      break;
    default:
      (**(code **)(**(int **)(in_ECX + 0x2c8) + 0x94))(0);
      (**(code **)(**(int **)(in_ECX + 0x2c0) + 0x94))(0);
      piVar1 = *(int **)(in_ECX + 0x2c4);
      uVar3 = 0;
      break;
    case 0xb:
      FUN_005dd690();
      piVar1 = *(int **)(in_ECX + 0x2c8);
      uVar3 = 1;
      break;
    case 0x10:
      FUN_005dd5c0(in_ECX,*(int *)(iVar2 + 0x68) + 1);
      (**(code **)(**(int **)(in_ECX + 0x2c0) + 0x94))(1);
      (**(code **)(**(int **)(in_ECX + 0x2c4) + 0x94))(1);
      ExceptionList = local_10;
      return;
    case 0x19:
      FUN_005dd690();
      (**(code **)(**(int **)(in_ECX + 0x2c8) + 0x94))(1);
      (**(code **)(**(int **)(in_ECX + 0x2c4) + 0x94))(1);
      ExceptionList = local_10;
      return;
    }
    (**(code **)(*piVar1 + 0x94))(uVar3);
  }
  ExceptionList = local_10;
  return;
}

