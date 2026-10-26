
void FUN_006b9df0(void)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int in_ECX;
  undefined4 *******pppppppuVar7;
  int iVar8;
  int *piVar9;
  undefined4 *puVar10;
  int local_58;
  uint local_50;
  undefined4 local_4c;
  uint local_3c;
  uint local_38;
  undefined4 ******local_30 [4];
  uint local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00935750;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_006ba0d0(local_14);
  FUN_006ba160();
  local_8 = 0;
  FUN_006ba160();
  local_8 = CONCAT31(local_8._1_3_,1);
  if ((local_3c == 0) || (local_20 == 0)) {
    if (0xf < local_1c) {
      FUN_0089120c(local_30[0]);
    }
  }
  else {
    iVar8 = 4;
    puVar10 = (undefined4 *)(in_ECX + 0xb0);
    do {
      (**(code **)(*(int *)puVar10[-5] + 0x94))(0);
      (**(code **)(*(int *)*puVar10 + 0x94))(0);
      puVar10 = puVar10 + -1;
      iVar8 = iVar8 + -1;
    } while (-1 < iVar8);
    local_58 = 4;
    piVar9 = (int *)(in_ECX + 0x9c);
    uVar5 = local_3c;
    do {
      uVar5 = uVar5 - 1;
      if ((int)uVar5 < 0) break;
      if (local_3c <= uVar5) goto LAB_006b9f58;
      (**(code **)(*(int *)*piVar9 + 0x94))(1);
      iVar8 = *piVar9;
      if (((*(char *)(iVar8 + 0xa4) != '\0') && (*(int *)(iVar8 + 0x94) != 0)) &&
         (iVar8 = (**(code **)(**(int **)(iVar8 + 0x94) + 4))(), iVar8 == 0xbf6b)) {
        FUN_0077b200();
      }
      (**(code **)(*(int *)*piVar9 + 200))();
      local_58 = local_58 + -1;
      piVar9 = piVar9 + -1;
    } while (-1 < local_58);
    local_50 = 0;
    piVar9 = (int *)(in_ECX + 0xa0);
    do {
      if (local_20 - 1 < local_50) break;
      if (local_20 <= local_50) {
LAB_006b9f58:
                    /* WARNING: Subroutine does not return */
        FUN_0087db7d("invalid string position");
      }
      pppppppuVar7 = (undefined4 *******)local_30[0];
      if (local_1c < 0x10) {
        pppppppuVar7 = local_30;
      }
      cVar2 = *(char *)((int)pppppppuVar7 + local_50);
      (**(code **)(*(int *)*piVar9 + 0x94))(1);
      iVar8 = *piVar9;
      iVar3 = *(int *)(in_ECX + 0xbc + (short)(cVar2 + -0x30) * 4);
      if (((*(char *)(iVar8 + 0xa4) != '\0') && (*(int *)(iVar8 + 0x94) != 0)) &&
         ((iVar6 = (**(code **)(**(int **)(iVar8 + 0x94) + 4))(), iVar6 == 0xbf6b &&
          (iVar8 = *(int *)(iVar8 + 0x94), *(int *)(iVar8 + 0x10) != iVar3)))) {
        if (((iVar3 != 0) && (piVar4 = *(int **)(iVar3 + 8), piVar4 != (int *)0x0)) &&
           (piVar4[0x27] = piVar4[0x27] + 1, piVar4[0x27] == 1)) {
          (**(code **)(*piVar4 + 0x24))();
        }
        if ((*(int *)(iVar8 + 0x10) != 0) &&
           (piVar4 = *(int **)(*(int *)(iVar8 + 0x10) + 8), piVar4 != (int *)0x0)) {
          piVar1 = piVar4 + 0x27;
          *piVar1 = *piVar1 + -1;
          if (*piVar1 == 0) {
            (**(code **)(*piVar4 + 0x28))();
          }
        }
        *(int *)(iVar8 + 0x10) = iVar3;
      }
      (**(code **)(*(int *)*piVar9 + 200))();
      local_50 = local_50 + 1;
      piVar9 = piVar9 + 1;
    } while ((int)local_50 < 5);
    if (0xf < local_1c) {
      FUN_0089120c(local_30[0]);
    }
  }
  local_30[0] = (undefined4 ******)((uint)local_30[0] & 0xffffff00);
  local_20 = 0;
  local_1c = 0xf;
  if (0xf < local_38) {
    local_1c = 0xf;
    local_20 = 0;
    FUN_0089120c(local_4c);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

