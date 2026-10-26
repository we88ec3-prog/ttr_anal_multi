
int FUN_008f34f0(int param_1,uint param_2,int *param_3)

{
  undefined4 uVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int local_8;
  
  iVar3 = param_1;
  uVar1 = *(undefined4 *)(param_1 + 100);
  local_8 = 0;
  *(undefined1 *)(param_1 + 0x2a0) = 0;
  if ((*(int *)(param_1 + 0x2a4) != 0) || (local_8 = FUN_008f0bb0(param_1,0), local_8 == 0)) {
    puVar2 = *(uint **)(param_1 + 0x2a4);
    if (param_2 != *(uint *)puVar2[2]) {
      return 6;
    }
    uVar4 = 0;
    if (param_2 != 0) {
      do {
        if (param_3[uVar4] < -0x10000) {
          return 6;
        }
        if (0x10000 < param_3[uVar4]) {
          return 6;
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < param_2);
    }
    if ((puVar2[9] != 0) || (local_8 = FUN_008f0870(param_1), local_8 == 0)) {
      uVar4 = 0;
      if (puVar2[1] == 0) {
        uVar4 = FUN_008bc7d0(uVar1,4,0,param_2,0,&local_8);
        puVar2[1] = uVar4;
        if (local_8 != 0) {
          return local_8;
        }
        param_1 = 1;
      }
      else {
        param_1 = 0;
        if (param_2 != 0) {
          piVar5 = param_3;
          do {
            if (*(int *)((puVar2[1] - (int)param_3) + (int)piVar5) != *piVar5) {
              param_1 = 2;
              break;
            }
            uVar4 = uVar4 + 1;
            piVar5 = piVar5 + 1;
          } while (uVar4 < param_2);
        }
      }
      *puVar2 = param_2;
      FID_conflict__memcpy((void *)puVar2[1],param_3,param_2 * 4);
      *(undefined1 *)(iVar3 + 0x2a0) = 1;
      if (*(int *)(iVar3 + 0x288) != 0) {
        if (param_1 == 1) {
          FUN_008f0fe0(iVar3);
        }
        else if (param_1 == 2) {
          FUN_008b9f80(uVar1,*(int *)(iVar3 + 0x288));
          *(undefined4 *)(iVar3 + 0x288) = 0;
          FUN_008f1a40();
          return local_8;
        }
      }
    }
  }
  return local_8;
}

