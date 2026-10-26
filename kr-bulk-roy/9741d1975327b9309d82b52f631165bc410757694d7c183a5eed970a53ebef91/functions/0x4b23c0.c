
undefined4 FUN_004b23c0(int param_1,uint param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009454de;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar5 = 2;
  param_1 = param_1 + 2;
  iVar3 = FUN_0040f060(uVar2);
  piVar1 = *(int **)(iVar3 + 4);
  if (*piVar1 != piVar1[1]) {
    iVar3 = FUN_004fa270(*piVar1);
    piVar1[1] = iVar3;
  }
  while (uVar5 < param_2) {
    switch(*(undefined1 *)(param_1 + 1)) {
    case 1:
    case 3:
      iVar3 = param_1 + 0xf;
      uVar5 = uVar5 + 0xf;
      break;
    case 2:
    case 5:
      iVar3 = param_1 + 0xb;
      uVar5 = uVar5 + 0xb;
      break;
    case 4:
    case 6:
      iVar3 = param_1 + 0xd;
      uVar5 = uVar5 + 0xd;
      break;
    case 7:
    case 8:
      iVar3 = param_1 + 10;
      uVar5 = uVar5 + 10;
      break;
    default:
      goto switchD_004b242a_default;
    }
    if (param_2 < uVar5) {
      FUN_006edb60(&DAT_00bf6cbc);
    }
    iVar4 = FUN_0040f060(uVar2);
    FUN_0053d5e0(*(undefined4 *)(iVar4 + 4),param_1);
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 0;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_8 = 0xffffffff;
    }
    FUN_0058aad0(0xf4266);
    param_1 = iVar3;
  }
switchD_004b242a_default:
  ExceptionList = local_10;
  return 0;
}

