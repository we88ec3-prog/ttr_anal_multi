
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0066aca0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int unaff_EDI;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar1 = param_1;
  puStack_c = &LAB_0091d14c;
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
  iVar2 = 0;
  local_14 = param_3 >> 0x1f;
  local_18 = param_3;
  FUN_004dd400(&DAT_00fab0dc,&param_1,&local_18);
  if (param_1 == DAT_00fab0e0) {
    param_1 = 0;
  }
  else {
    param_1 = *(int *)(param_1 + 0x18);
  }
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_8 = 1;
    FUN_0051c120();
    _atexit((_func_4879 *)&LAB_00bccc90);
    local_8 = 0xffffffff;
  }
  param_3 = param_2;
  FUN_008438c0(&param_3);
  if (param_2 != DAT_00f8d91c) {
    iVar2 = *(int *)(param_2 + 0x10);
  }
  (**(code **)(**(int **)(iVar1 + 0x160 + unaff_EDI * 4) + 0x94))(0);
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
      if (param_1 == 0) {
        iVar2 = 1;
      }
      else {
        iVar2 = *(int *)(param_1 + 0x10) + 1;
      }
      break;
    default:
      goto switchD_0066adc3_caseD_5;
    case 0x10:
      iVar2 = *(int *)(iVar2 + 0x68) + 1;
    }
    FUN_0066ae40(iVar1,iVar2,unaff_EDI);
  }
switchD_0066adc3_caseD_5:
  ExceptionList = local_10;
  return;
}

