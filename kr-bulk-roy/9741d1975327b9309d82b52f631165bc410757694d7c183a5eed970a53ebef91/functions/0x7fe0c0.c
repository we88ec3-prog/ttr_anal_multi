
void FUN_007fe0c0(int param_1)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  char *_Str1;
  uint uVar4;
  uint uVar5;
  uint local_8;
  
  uVar5 = 0;
  local_8 = 0;
  iVar3 = (**(code **)(**(int **)(param_1 + 0x28) + 0x34))();
  if (iVar3 != 0) {
    do {
      iVar3 = (**(code **)(**(int **)(param_1 + 0x28) + 0x30))(uVar5);
      _Str1 = (char *)(iVar3 + 8);
      if (0xf < *(uint *)(iVar3 + 0x1c)) {
        _Str1 = *(char **)_Str1;
      }
      iVar3 = _strncmp(_Str1,"BB_",3);
      if (iVar3 == 0) {
        puVar1 = *(uint **)(param_1 + 0x4c);
        if (&local_8 < puVar1) {
          puVar2 = *(uint **)(param_1 + 0x48);
          if (&local_8 < puVar2) goto LAB_007fe14c;
          if (puVar1 == *(uint **)(param_1 + 0x50)) {
            FUN_006ddeb0();
          }
          if (*(undefined4 **)(param_1 + 0x4c) != (undefined4 *)0x0) {
            **(undefined4 **)(param_1 + 0x4c) =
                 *(undefined4 *)(*(uint *)(param_1 + 0x48) + ((int)&local_8 - (int)puVar2 >> 2) * 4)
            ;
          }
        }
        else {
LAB_007fe14c:
          if (puVar1 == *(uint **)(param_1 + 0x50)) {
            FUN_006ddeb0();
          }
          if (*(uint **)(param_1 + 0x4c) != (uint *)0x0) {
            **(uint **)(param_1 + 0x4c) = uVar5;
          }
        }
        *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 4;
      }
      uVar5 = uVar5 + 1;
      local_8 = uVar5;
      uVar4 = (**(code **)(**(int **)(param_1 + 0x28) + 0x34))();
    } while (uVar5 < uVar4);
  }
  return;
}

