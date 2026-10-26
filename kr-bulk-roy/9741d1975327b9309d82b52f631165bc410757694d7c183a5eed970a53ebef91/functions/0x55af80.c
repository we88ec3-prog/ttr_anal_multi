
/* WARNING: Removing unreachable block (ram,0x0055afe5) */

void FUN_0055af80(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  int *local_10;
  int *local_8;
  
  local_10 = (int *)*param_1;
  local_8 = (int *)*local_10;
  if (local_8 != local_10) {
    do {
      iVar1 = local_8[2];
      FUN_0055a350();
      FUN_0055a260(iVar1);
      if (*(int *)(iVar1 + 8) == 0) {
        *(undefined4 *)(iVar1 + 0xe8) = 1;
        FUN_0046fba0();
        puVar2 = *(undefined4 **)(iVar1 + 0x28);
        if (puVar2 != *(undefined4 **)(iVar1 + 0x2c)) {
          puVar3 = *(undefined4 **)(iVar1 + 0x2c);
          for (puVar5 = puVar2; puVar5 != puVar3; puVar5 = puVar5 + 7) {
            if (7 < (uint)puVar5[5]) {
              FUN_0089120c(*puVar5);
            }
            puVar5[5] = 7;
            puVar5[4] = 0;
            *(undefined2 *)puVar5 = 0;
          }
          *(undefined4 **)(iVar1 + 0x2c) = puVar2;
        }
      }
      else {
        *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + -1;
      }
      iVar1 = local_8[2];
      if ((*(int *)(iVar1 + 8) == 0) && (*(int *)(iVar1 + 0xe8) == 0)) {
        if (iVar1 != 0) {
          FUN_00559d10();
          FUN_0089120c(iVar1);
          local_8[2] = 0;
        }
        piVar4 = (int *)*local_8;
        if (local_8 != (int *)*param_1) {
          *(int **)local_8[1] = piVar4;
          *(int *)(*local_8 + 4) = local_8[1];
          FUN_0089120c(local_8);
          param_1[1] = param_1[1] + -1;
        }
        local_10 = (int *)*param_1;
        local_8 = piVar4;
      }
      else {
        local_8 = (int *)*local_8;
      }
    } while (local_8 != local_10);
  }
  return;
}

