
void FUN_00449a10(int param_1)

{
  void *_Dst;
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *local_28;
  int local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00945266;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fb93cc & 1) == 0) {
    DAT_00fb93cc = DAT_00fb93cc | 1;
    local_c = 0;
    FUN_00445460(DAT_00d61f20 ^ (uint)&stack0xffffffc8);
    _atexit((_func_4879 *)&LAB_00bcd620);
  }
  local_c = 0xffffffff;
  FUN_004462a0();
  piVar5 = (int *)(param_1 + 0x108);
  local_c = 1;
  _Dst = (void *)*piVar5;
  if (_Dst != *(void **)(param_1 + 0x10c)) {
    FID_conflict__memcpy(_Dst,*(void **)(param_1 + 0x10c),0);
    *(void **)(param_1 + 0x10c) = _Dst;
  }
  piVar4 = local_28;
  for (iVar3 = local_24 - (int)local_28 >> 2; iVar3 != 0; iVar3 = iVar3 + -1) {
    if (*(char *)(*piVar4 + 9) == '\0') {
      piVar1 = *(int **)(param_1 + 0x10c);
      if ((piVar4 < piVar1) && (piVar2 = (int *)*piVar5, piVar2 <= piVar4)) {
        if (piVar1 == *(int **)(param_1 + 0x110)) {
          FUN_004deab0();
        }
        if (*(undefined4 **)(param_1 + 0x10c) != (undefined4 *)0x0) {
          **(undefined4 **)(param_1 + 0x10c) =
               *(undefined4 *)(*piVar5 + ((int)piVar4 - (int)piVar2 >> 2) * 4);
        }
      }
      else {
        if (piVar1 == *(int **)(param_1 + 0x110)) {
          FUN_004deab0();
        }
        if (*(int **)(param_1 + 0x10c) != (int *)0x0) {
          **(int **)(param_1 + 0x10c) = *piVar4;
        }
      }
      *(int *)(param_1 + 0x10c) = *(int *)(param_1 + 0x10c) + 4;
    }
    else {
      FUN_0044a480(piVar5,*piVar5);
    }
    piVar4 = piVar4 + 1;
  }
  FUN_00449b90(param_1);
  FUN_004738a0(piVar5);
  FUN_00446b30(**(undefined4 **)*piVar5);
  if (local_28 != (int *)0x0) {
    FUN_0089120c(local_28);
  }
  ExceptionList = local_14;
  return;
}

