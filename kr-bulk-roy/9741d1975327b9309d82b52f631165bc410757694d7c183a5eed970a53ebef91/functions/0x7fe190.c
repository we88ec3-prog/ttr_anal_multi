
void FUN_007fe190(int param_1)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  uint local_8;
  
  uVar7 = 0;
  local_8 = 0;
  iVar3 = (**(code **)(**(int **)(param_1 + 0x28) + 0x34))();
  if (iVar3 != 0) {
    do {
      iVar3 = (**(code **)(**(int **)(param_1 + 0x28) + 0x30))(uVar7);
      pcVar5 = (char *)(iVar3 + 8);
      pcVar4 = pcVar5;
      if (0xf < *(uint *)(iVar3 + 0x1c)) {
        pcVar4 = *(char **)pcVar5;
      }
      pcVar4 = _strstr(pcVar4,"_CB");
      if (pcVar4 == (char *)0x0) {
        if (0xf < *(uint *)(iVar3 + 0x1c)) {
          pcVar5 = *(char **)pcVar5;
        }
        pcVar5 = _strstr(pcVar5,"_CM");
        if (pcVar5 != (char *)0x0) goto LAB_007fe1f7;
      }
      else {
LAB_007fe1f7:
        puVar1 = *(uint **)(param_1 + 0x5c);
        if (&local_8 < puVar1) {
          puVar2 = *(uint **)(param_1 + 0x58);
          if (&local_8 < puVar2) goto LAB_007fe238;
          if (puVar1 == *(uint **)(param_1 + 0x60)) {
            FUN_006ddeb0();
          }
          if (*(undefined4 **)(param_1 + 0x5c) != (undefined4 *)0x0) {
            **(undefined4 **)(param_1 + 0x5c) =
                 *(undefined4 *)(*(uint *)(param_1 + 0x58) + ((int)&local_8 - (int)puVar2 >> 2) * 4)
            ;
          }
        }
        else {
LAB_007fe238:
          if (puVar1 == *(uint **)(param_1 + 0x60)) {
            FUN_006ddeb0();
          }
          if (*(uint **)(param_1 + 0x5c) != (uint *)0x0) {
            **(uint **)(param_1 + 0x5c) = uVar7;
          }
        }
        *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + 4;
      }
      uVar7 = uVar7 + 1;
      local_8 = uVar7;
      uVar6 = (**(code **)(**(int **)(param_1 + 0x28) + 0x34))();
    } while (uVar7 < uVar6);
  }
  return;
}

