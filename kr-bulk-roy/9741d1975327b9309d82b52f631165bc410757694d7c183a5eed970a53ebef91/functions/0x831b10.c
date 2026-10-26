
/* WARNING: Removing unreachable block (ram,0x00831c40) */

void FUN_00831b10(int *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  undefined **local_38 [3];
  undefined **local_2c;
  uint local_28;
  int local_24;
  char *local_20;
  char *local_1c;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00909364;
  local_10 = ExceptionList;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar12 = 0;
  local_18 = 0;
  puVar7 = (undefined4 *)FUN_00891268(0x18,uVar6);
  if (puVar7 == (undefined4 *)0x0) {
    local_1c = (char *)0x0;
    std::exception::exception((exception *)&local_2c,&local_1c);
    local_2c = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(&local_2c,&DAT_00c857a8);
  }
  *puVar7 = puVar7;
  puVar7[1] = puVar7;
  puVar7[2] = puVar7;
  *(undefined1 *)(puVar7 + 5) = 1;
  *(undefined1 *)((int)puVar7 + 0x15) = 1;
  local_8 = 0;
  puVar8 = (undefined4 *)FUN_00891268(0x18,uVar6);
  if (puVar8 != (undefined4 *)0x0) {
    *puVar8 = puVar8;
    puVar8[1] = puVar8;
    puVar8[2] = puVar8;
    *(undefined1 *)(puVar8 + 5) = 1;
    *(undefined1 *)((int)puVar8 + 0x15) = 1;
    local_8 = CONCAT31(local_8._1_3_,1);
    iVar10 = param_1[1] - *param_1 >> 0x1f;
    if ((param_1[1] - *param_1) / 0xc + iVar10 != iVar10) {
      iVar10 = 0;
      do {
        iVar2 = *(int *)(*param_1 + iVar10);
        iVar11 = *param_1 + iVar10;
        if (iVar2 == 0) {
          local_18 = local_18 + *(int *)(iVar11 + 8);
        }
        else if (iVar2 == 1) {
          local_1c = (char *)(uint)*(ushort *)(iVar11 + 4);
          piVar9 = (int *)FUN_00831ed0();
          *piVar9 = *piVar9 + *(int *)(iVar11 + 8);
        }
        else if (iVar2 == 2) {
          piVar9 = (int *)FUN_00831f50();
          *piVar9 = *piVar9 + *(int *)(iVar11 + 8);
        }
        uVar12 = uVar12 + 1;
        iVar10 = iVar10 + 0xc;
      } while (uVar12 < (uint)((param_1[1] - *param_1) / 0xc));
    }
    if (*param_1 != param_1[1]) {
      param_1[1] = *param_1;
    }
    local_2c = (undefined **)0x0;
    local_28 = 0;
    local_24 = local_18;
    FUN_0052ef90();
    puVar3 = (undefined4 *)*puVar7;
    while (puVar3 != puVar7) {
      local_24 = puVar3[4];
      local_28 = (uint)*(ushort *)(puVar3 + 3);
      local_2c = (undefined **)0x1;
      FUN_0052ef90();
      if (*(char *)((int)puVar3 + 0x15) == '\0') {
        puVar4 = (undefined4 *)puVar3[2];
        if (*(char *)((int)puVar4 + 0x15) == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x15);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((int)*puVar4 + 0x15);
            puVar3 = puVar4;
            puVar4 = (undefined4 *)*puVar4;
          }
        }
        else {
          cVar1 = *(char *)((int)puVar3[1] + 0x15);
          puVar5 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
          while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
            cVar1 = *(char *)((int)puVar3[1] + 0x15);
            puVar5 = (undefined4 *)puVar3[1];
            puVar4 = puVar3;
          }
        }
      }
    }
    puVar3 = (undefined4 *)*puVar8;
    while (puVar3 != puVar8) {
      local_28 = puVar3[3];
      local_24 = puVar3[4];
      local_2c = (undefined **)0x2;
      FUN_0052ef90();
      if (*(char *)((int)puVar3 + 0x15) == '\0') {
        puVar4 = (undefined4 *)puVar3[2];
        if (*(char *)((int)puVar4 + 0x15) == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x15);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((int)*puVar4 + 0x15);
            puVar3 = puVar4;
            puVar4 = (undefined4 *)*puVar4;
          }
        }
        else {
          cVar1 = *(char *)((int)puVar3[1] + 0x15);
          puVar5 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
          while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
            cVar1 = *(char *)((int)puVar3[1] + 0x15);
            puVar5 = (undefined4 *)puVar3[1];
            puVar4 = puVar3;
          }
        }
      }
    }
    local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_005540c0(*puVar8,puVar8);
    FUN_0089120c(puVar8);
    local_8 = 3;
    FUN_005540c0(*puVar7,puVar7);
    FUN_0089120c(puVar7);
    ExceptionList = local_10;
    return;
  }
  local_20 = (char *)0x0;
  std::exception::exception((exception *)local_38,&local_20);
  local_38[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_38,&DAT_00c857a8);
}

