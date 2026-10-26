
void FUN_006665b0(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  uint local_40;
  int *local_3c;
  int aiStack_38 [5];
  uint local_24;
  
  aiStack_38[2] = FUN_004adcd0();
  iVar5 = *(int *)(*(int *)(param_1 + 0xec) + 0xcc);
  if (iVar5 == 0) {
    local_3c = (int *)0x0;
  }
  else {
    local_3c = (int *)(iVar5 + 0xa8);
  }
  local_24 = *(uint *)(aiStack_38[2] + 0x10);
  aiStack_38[1] = local_3c[1] - *local_3c >> 2;
  local_40 = 0;
  if (local_24 != 0) {
    do {
      uVar6 = 0;
      if (aiStack_38[1] != 0) {
        piVar7 = (int *)*local_3c;
        do {
          iVar5 = *piVar7;
          puVar4 = (undefined4 *)FUN_005cfc30();
          if ((*(int *)(iVar5 + 0x260) == *(int *)*puVar4) &&
             (*(int *)(iVar5 + 0x264) == ((int *)*puVar4)[1])) goto LAB_00666763;
          uVar6 = uVar6 + 1;
          piVar7 = piVar7 + 1;
        } while (uVar6 < (uint)aiStack_38[1]);
      }
      piVar7 = *(int **)(*(int *)(param_1 + 0xec) + 0xcc);
      if (piVar7 == (int *)0x0) {
        iVar5 = 0;
      }
      else {
        piVar1 = (int *)piVar7[0x29];
        iVar2 = piVar7[0x39];
        if (piVar1 == (int *)0x0) {
          iVar5 = 0;
        }
        else {
          if (piVar7[0x2e] == piVar7[0x2f]) {
            iVar5 = (**(code **)(*piVar1 + 0x28))();
          }
          else {
            iVar5 = *(int *)(piVar7[0x2f] + -4);
            (**(code **)(*piVar1 + 0x2c))(iVar5);
            if (piVar7[0x2e] != piVar7[0x2f]) {
              piVar7[0x2f] = piVar7[0x2f] + -4;
            }
          }
          *(int *)(iVar5 + 0x20) = iVar2;
          aiStack_38[0] = iVar5;
          (**(code **)(*piVar7 + 0x70))(iVar5);
          piVar1 = (int *)piVar7[0x2b];
          if ((aiStack_38 < piVar1) && ((int *)piVar7[0x2a] <= aiStack_38)) {
            aiStack_38[3] = (int)aiStack_38 - piVar7[0x2a] >> 2;
            if (piVar1 == (int *)piVar7[0x2c]) {
              FUN_004deab0();
            }
            if ((undefined4 *)piVar7[0x2b] != (undefined4 *)0x0) {
              *(undefined4 *)piVar7[0x2b] = *(undefined4 *)(piVar7[0x2a] + aiStack_38[3] * 4);
            }
          }
          else {
            if (piVar1 == (int *)piVar7[0x2c]) {
              FUN_004deab0();
            }
            if ((int *)piVar7[0x2b] != (int *)0x0) {
              *(int *)piVar7[0x2b] = iVar5;
            }
          }
          piVar7[0x2b] = piVar7[0x2b] + 4;
          uVar6 = iVar2 + 1;
          if (uVar6 <= (uint)piVar7[0x39]) {
            uVar6 = piVar7[0x39];
          }
          piVar7[0x39] = uVar6;
        }
      }
LAB_00666763:
      uVar6 = local_40;
      FUN_00542210(local_40);
      FUN_0050b4b0(uVar6);
      FUN_00666440(iVar5);
      local_40 = local_40 + 1;
    } while (local_40 < local_24);
  }
  FUN_00666d10(*local_3c,local_3c[1],local_3c[1] - *local_3c >> 2,FUN_006662f0);
  piVar7 = *(int **)(param_1 + 0xec);
  puVar4 = (undefined4 *)piVar7[0x19];
  for (puVar3 = (undefined4 *)*puVar4; puVar3 != puVar4; puVar3 = (undefined4 *)*puVar3) {
    iVar5 = puVar3[2];
    if ((*(int *)(iVar5 + 0x60) != 0) && ((*(int **)(iVar5 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar5 + 0x1c) + 0x30))(iVar5);
    }
  }
  (**(code **)(*piVar7 + 0x128))();
  (**(code **)(**(int **)(param_1 + 0xec) + 200))();
  return;
}

