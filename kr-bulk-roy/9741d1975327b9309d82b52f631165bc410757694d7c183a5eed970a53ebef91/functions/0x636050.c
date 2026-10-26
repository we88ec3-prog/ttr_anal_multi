
void FUN_00636050(int param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  short sVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  code *pcVar8;
  char *pcVar9;
  char *pcVar10;
  undefined4 uVar11;
  int *local_50;
  uint local_4c;
  undefined4 local_3c;
  uint local_38;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0094646c;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(uint *)(param_1 + 0xac) < 2) {
    iVar5 = *(int *)(param_1 + 0x90);
    if (iVar5 == 0) {
      (**(code **)(**(int **)(param_1 + 0xbc) + 4))();
      pcVar8 = *(code **)(**(int **)(param_1 + 0xbc) + 0xc);
      if (*(int *)(param_1 + 0x98) + 1 <
          *(int *)(*(int *)(param_1 + 0x94) + 0x18) - *(int *)(*(int *)(param_1 + 0x94) + 0x14) >> 2
         ) {
        (*pcVar8)(1,1);
      }
      else {
        (*pcVar8)(0,1);
      }
    }
    else if (iVar5 == 1) {
      (**(code **)(**(int **)(param_1 + 0xbc) + 8))();
    }
    else {
      if (iVar5 != 2) {
        if (iVar5 != 3) {
          (**(code **)(**(int **)(param_1 + 0xbc) + 4))(local_14);
          (**(code **)(**(int **)(param_1 + 0xbc) + 0xc))(1,1);
          goto LAB_0063616b;
        }
        if (*(undefined4 **)(param_1 + 0x88) != (undefined4 *)0x0) {
          uVar11 = **(undefined4 **)(param_1 + 0x88);
          FUN_0040f930();
          sVar4 = FUN_005007d0(uVar11);
          if (sVar4 != 0) {
            (**(code **)(**(int **)(param_1 + 0xbc) + 8))();
            goto LAB_0063616b;
          }
        }
      }
      FUN_006390e0();
    }
  }
  else {
    (**(code **)(**(int **)(param_1 + 0xbc) + 8))();
  }
LAB_0063616b:
  if (*(int *)(param_1 + 0xb8) != 0) {
    if ((DAT_00f94394 & 1) == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_8 = 0;
      FUN_005c3de0();
      _atexit((_func_4879 *)&LAB_00bccc30);
      local_8 = 0xffffffff;
    }
    piVar6 = (int *)**(int **)(param_1 + 0xb8);
    iVar5 = FUN_005c7190();
    if (iVar5 != 0) {
      local_50 = piVar6;
      FUN_0082ef00(&local_50);
    }
    FUN_00745060();
    (**(code **)(**(int **)(param_1 + 0xd0) + 200))();
    FUN_00757710();
    (**(code **)(**(int **)(param_1 + 0xc4) + 200))();
  }
  if (*(int *)(param_1 + 0xac) == 0) {
    FUN_00757710();
    (**(code **)(**(int **)(param_1 + 200) + 200))();
    (**(code **)(**(int **)(param_1 + 0xd4) + 0xd4))();
  }
  else {
    FUN_00542210();
    FUN_00405300(*(int *)(param_1 + 200) + 0xe8);
    (**(code **)(**(int **)(param_1 + 200) + 200))();
    piVar6 = (int *)FUN_00542210();
    if ((int *)*piVar6 == (int *)0x0) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)*piVar6;
    }
    uVar7 = (uint)piVar6[2] >> 2;
    if (*(uint *)(iVar5 + 8) <= uVar7) {
      uVar7 = uVar7 - *(uint *)(iVar5 + 8);
    }
    iVar2 = *(int *)(param_1 + 0xb8);
    iVar5 = *(int *)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + uVar7 * 4) + (piVar6[2] & 3U) * 4) +
                    0x24);
    if (((iVar2 != 0) && (iVar5 != 0)) &&
       (piVar6 = *(int **)(iVar2 + 0x6c), piVar6 != *(int **)(iVar2 + 0x70))) {
LAB_00636330:
      if (*piVar6 != iVar5) goto code_r0x00636334;
      if (*(uint *)(iVar2 + 100) < 0x10) {
        pcVar10 = (char *)(iVar2 + 0x50);
      }
      else {
        pcVar10 = *(char **)(iVar2 + 0x50);
      }
      local_1c = 0xf;
      local_20 = 0;
      local_30[0] = local_30[0] & 0xffffff00;
      pcVar9 = pcVar10;
      do {
        cVar1 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar1 != '\0');
      FUN_00402a70(pcVar10,(int)pcVar9 - (int)(pcVar10 + 1));
      local_8 = 1;
      local_50 = (int *)FUN_004028b0(local_30);
      if (7 < (uint)local_50[5]) {
        local_50 = (int *)*local_50;
      }
      if ((DAT_00f94394 & 1) == 0) {
        DAT_00f94394 = DAT_00f94394 | 1;
        local_8._0_1_ = 3;
        FUN_005c3de0();
        _atexit((_func_4879 *)&LAB_00bccc30);
      }
      local_8 = CONCAT31(local_8._1_3_,2);
      piVar3 = (int *)piVar6[3];
      iVar5 = FUN_005c7190();
      if (iVar5 != 0) {
        local_50 = piVar3;
        FUN_0082ef00(&local_50);
      }
      FUN_00745060();
      if (7 < local_38) {
        FUN_0089120c(local_4c);
      }
      local_8 = 0xffffffff;
      local_38 = 7;
      local_3c = 0;
      local_4c = local_4c & 0xffff0000;
      if (0xf < local_1c) {
        FUN_0089120c(local_30[0]);
      }
      local_20 = 0;
      local_1c = 0xf;
      local_30[0] = local_30[0] & 0xffffff00;
      FUN_00749a00(*(int *)(*(int *)(param_1 + 0xd0) + 8) + piVar6[1],
                   *(int *)(*(int *)(param_1 + 0xd0) + 0xc) + piVar6[2]);
      FUN_00749c50();
      FUN_00749d00();
      (**(code **)(**(int **)(param_1 + 0xd4) + 0xd0))();
      pcVar8 = *(code **)(**(int **)(param_1 + 0xd4) + 200);
      goto LAB_00636349;
    }
LAB_0063633b:
    pcVar8 = *(code **)(**(int **)(param_1 + 0xd4) + 0xd4);
LAB_00636349:
    (*pcVar8)();
  }
  (**(code **)(**(int **)(param_1 + 0xd8) + 0x94))(1 < *(uint *)(param_1 + 0xac));
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
code_r0x00636334:
  piVar6 = piVar6 + 4;
  if (piVar6 == *(int **)(iVar2 + 0x70)) goto LAB_0063633b;
  goto LAB_00636330;
}

