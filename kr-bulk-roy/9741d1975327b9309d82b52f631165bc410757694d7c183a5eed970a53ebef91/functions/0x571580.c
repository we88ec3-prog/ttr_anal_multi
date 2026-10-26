
void FUN_00571580(int param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int unaff_EDI;
  int local_20;
  int local_1c [2];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093fa8c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  switch(DAT_00f9392c) {
  case 3:
  case 5:
  case 7:
  case 8:
  case 0x15:
  case 0x17:
  case 0x18:
  case 0x1b:
    if ((DAT_00f8d9a4 & 1) == 0) {
      DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
      local_c = 1;
      FUN_0051c120();
      _atexit((_func_4879 *)&LAB_00bccc90);
    }
    local_c = 0xffffffff;
    local_20 = param_1;
    FUN_008438c0(&local_20);
    if ((local_1c[0] != DAT_00f8d91c) && (*(int *)(local_1c[0] + 0x10) != 0)) {
      local_1c[0] = *(int *)(*(int *)(local_1c[0] + 0x10) + 0x20);
      puVar2 = (undefined4 *)FUN_00570e50();
      FUN_008438c0(local_1c);
      if ((local_20 != puVar2[2]) &&
         ((*puVar2 = *(undefined4 *)(*(int *)(local_20 + 0x10) + 4),
          *(int *)(*(int *)(local_20 + 0x10) + 4) == 2 &&
          (piVar1 = *(int **)(unaff_EDI + 8), piVar1 != (int *)0x0)))) {
        (**(code **)(*piVar1 + 0x30))(param_1,param_2);
        *(int **)(unaff_EDI + 0xc) = piVar1;
        *(undefined4 *)(unaff_EDI + 0x10) = 1;
      }
    }
  }
  ExceptionList = local_14;
  return;
}

