
/* WARNING: Removing unreachable block (ram,0x00539a4f) */

void FUN_005398e0(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  int *_Dst;
  int *piVar5;
  int iVar6;
  int *local_30;
  int *local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00904a58;
  local_14 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffffc0;
  ExceptionList = &local_14;
  piVar5 = (int *)0x0;
  local_24 = (int *)0x0;
  local_c = 0;
  _Dst = *(int **)(param_1 + 0x28);
  if (_Dst != *(int **)(param_1 + 0x2c)) {
    local_30 = _Dst + 1;
    do {
      if (*(char *)(*_Dst + 10) == '\0') {
        if (_Dst < piVar5) {
          if (piVar5 == (int *)0x0) {
            FUN_004deab0(uVar3);
            piVar5 = local_24;
          }
          if (piVar5 != (int *)0x0) {
            *piVar5 = *(int *)(((int)_Dst >> 2) * 4);
          }
        }
        else {
          if (piVar5 == (int *)0x0) {
            FUN_004deab0(uVar3);
            piVar5 = local_24;
          }
          if (piVar5 != (int *)0x0) {
            *piVar5 = *_Dst;
          }
        }
        piVar5 = piVar5 + 1;
        FID_conflict__memcpy(_Dst,local_30,(*(int *)(param_1 + 0x2c) - (int)local_30 >> 2) * 4);
        *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + -4;
        local_24 = piVar5;
      }
      else {
        _Dst = _Dst + 1;
        local_30 = local_30 + 1;
      }
    } while (_Dst != *(int **)(param_1 + 0x2c));
  }
  puVar4 = (undefined4 *)0x0;
  for (iVar6 = (int)piVar5 >> 2; iVar6 != 0; iVar6 = iVar6 + -1) {
    puVar1 = *(undefined4 **)(param_1 + 0x2c);
    if ((puVar4 < puVar1) && (puVar2 = *(undefined4 **)(param_1 + 0x28), puVar2 <= puVar4)) {
      if (puVar1 == *(undefined4 **)(param_1 + 0x30)) {
        FUN_004deab0(uVar3);
      }
      if (*(undefined4 **)(param_1 + 0x2c) != (undefined4 *)0x0) {
        **(undefined4 **)(param_1 + 0x2c) =
             *(undefined4 *)(*(uint *)(param_1 + 0x28) + ((int)puVar4 - (int)puVar2 >> 2) * 4);
      }
    }
    else {
      if (puVar1 == *(undefined4 **)(param_1 + 0x30)) {
        FUN_004deab0(uVar3);
      }
      if (*(undefined4 **)(param_1 + 0x2c) != (undefined4 *)0x0) {
        **(undefined4 **)(param_1 + 0x2c) = *puVar4;
      }
    }
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 4;
    puVar4 = puVar4 + 1;
  }
  ExceptionList = local_14;
  return;
}

