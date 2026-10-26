
void FUN_0041cb90(int param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093446e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb725c & 1) == 0) {
    DAT_00fb725c = DAT_00fb725c | 1;
    local_8 = 0;
    FUN_004a79a0();
    _atexit((_func_4879 *)&DAT_00bccf80);
  }
  local_8 = 0xffffffff;
  FUN_0041ccf0();
  uVar2 = DAT_00fb7284 - DAT_00fb7280 >> 2;
  uVar3 = 0;
  if (uVar2 != 0) {
    while ((piVar1 = *(int **)(DAT_00fb7280 + uVar3 * 4), (char)piVar1[2] == '\0' ||
           (*piVar1 != param_2))) {
      uVar3 = uVar3 + 1;
      if (uVar2 <= uVar3) {
        ExceptionList = local_10;
        return;
      }
    }
    (**(code **)(**(int **)(*(int *)(param_1 + 0xe0) + uVar3 * 4) + 0x94))();
    (**(code **)(**(int **)(param_1 + 0xdc) + 0x94))();
    FUN_004026e0(*(int *)(DAT_00fb7280 + uVar3 * 4) + 0xc,0,0xffffffff);
    FUN_0041c3e0();
    (**(code **)(**(int **)(param_1 + 0xdc) + 200))();
  }
  ExceptionList = local_10;
  return;
}

