
void FUN_00449ea0(int param_1)

{
  int *piVar1;
  void *_Dst;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *local_28;
  int local_24;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00948016;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb93cc & 1) == 0) {
    DAT_00fb93cc = DAT_00fb93cc | 1;
    local_8 = 0;
    FUN_00445460(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd620);
  }
  local_8 = 0xffffffff;
  FUN_004462a0();
  local_8 = 1;
  iVar4 = *(int *)(*(int *)(param_1 + 0xf0) + 0x24c);
  if (iVar4 != 0) {
    iVar4 = *(int *)(iVar4 + 0xcc);
    if (iVar4 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(iVar4 + 0xdc);
    }
    if (iVar4 != 0) {
      local_18 = *(int *)(iVar4 + 0x20);
      goto LAB_00449f41;
    }
  }
  local_18 = -1;
LAB_00449f41:
  _Dst = *(void **)(param_1 + 0x108);
  piVar1 = (int *)(param_1 + 0x108);
  if (_Dst != *(void **)(param_1 + 0x10c)) {
    FID_conflict__memcpy(_Dst,*(void **)(param_1 + 0x10c),0);
    *(void **)(param_1 + 0x10c) = _Dst;
  }
  if (local_18 == 0) {
    piVar5 = local_28;
    for (iVar4 = local_24 - (int)local_28 >> 2; iVar4 != 0; iVar4 = iVar4 + -1) {
      if (*(char *)(*piVar5 + 9) == '\0') {
        piVar2 = *(int **)(param_1 + 0x10c);
        if ((piVar5 < piVar2) && (piVar3 = (int *)*piVar1, piVar3 <= piVar5)) {
          if (piVar2 == *(int **)(param_1 + 0x110)) {
            FUN_004deab0();
          }
          if (*(undefined4 **)(param_1 + 0x10c) != (undefined4 *)0x0) {
            **(undefined4 **)(param_1 + 0x10c) =
                 *(undefined4 *)(*piVar1 + ((int)piVar5 - (int)piVar3 >> 2) * 4);
          }
        }
        else {
          if (piVar2 == *(int **)(param_1 + 0x110)) {
            FUN_004deab0();
          }
          if (*(int **)(param_1 + 0x10c) != (int *)0x0) {
            **(int **)(param_1 + 0x10c) = *piVar5;
          }
        }
        *(int *)(param_1 + 0x10c) = *(int *)(param_1 + 0x10c) + 4;
      }
      else {
        FUN_0044a480(piVar1,*piVar1);
      }
      piVar5 = piVar5 + 1;
    }
  }
  else {
    piVar5 = local_28;
    for (iVar4 = local_24 - (int)local_28 >> 2; iVar4 != 0; iVar4 = iVar4 + -1) {
      if (local_18 == *(int *)(*piVar5 + 4)) {
        if (*(char *)(*piVar5 + 9) == '\0') {
          FUN_00443d10();
        }
        else {
          FUN_0044a480(piVar1,*piVar1);
        }
      }
      piVar5 = piVar5 + 1;
    }
  }
  FUN_00449b90(param_1);
  FUN_004738a0(piVar1);
  if (local_28 != (int *)0x0) {
    FUN_0089120c(local_28);
  }
  ExceptionList = local_10;
  return;
}

