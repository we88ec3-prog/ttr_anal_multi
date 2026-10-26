
void FUN_0071e420(char *param_1,int *param_2)

{
  uint uVar1;
  char cVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined1 **ppuVar9;
  int *piVar10;
  char *pcVar11;
  int *piVar12;
  int in_ECX;
  uint uVar13;
  char *in_EDX;
  char *pcVar14;
  uint uVar15;
  int local_64;
  int local_60;
  undefined1 local_5c [4];
  int local_58;
  undefined **local_54;
  undefined1 local_50 [8];
  int *local_48;
  uint local_44;
  char *local_40;
  undefined1 **local_3c;
  char *local_38;
  undefined1 *local_34;
  undefined1 local_30;
  undefined1 *local_2c;
  undefined1 local_28;
  undefined1 *local_24;
  undefined1 local_20;
  undefined1 *local_1c;
  undefined1 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00905978;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar3 = (int *)param_2[1];
  local_38 = param_1;
  puVar4 = (undefined4 *)*piVar3;
  iVar5 = piVar3[1];
  local_48 = param_2;
  local_8 = 0;
  uVar15 = 1;
  for (iVar6 = *(int *)(in_ECX + 8); iVar6 != 0; iVar6 = *(int *)(iVar6 + 0xc)) {
    uVar15 = uVar15 + 1;
  }
  local_3c = &local_34;
  local_34 = &DAT_00bf2375;
  local_30 = 0;
  local_2c = &DAT_00bf2375;
  local_28 = 0;
  local_24 = &DAT_00bf2375;
  local_20 = 0;
  local_1c = &DAT_00bf2375;
  local_18 = 0;
  ppuVar9 = local_3c;
  local_58 = in_ECX;
  local_44 = uVar15;
  local_40 = in_EDX;
  if (4 < uVar15) {
    uVar1 = uVar15 * 8;
    uVar13 = piVar3[1] + uVar1;
    if (uVar13 < 0x1001) {
      ppuVar9 = (undefined1 **)(piVar3[1] + 4 + *piVar3);
      piVar3[1] = uVar13;
    }
    else {
      uVar13 = uVar1;
      if (uVar1 < 0x1001) {
        uVar13 = 0x1000;
      }
      piVar10 = (int *)(*(code *)PTR_FUN_00d63d48)(uVar13 + 4,local_14);
      if (piVar10 == (int *)0x0) goto LAB_0071e515;
      *piVar10 = *piVar3;
      *piVar3 = (int)piVar10;
      piVar3[1] = uVar1;
      ppuVar9 = (undefined1 **)(piVar10 + 1);
    }
    if (ppuVar9 == (undefined1 **)0x0) goto LAB_0071e515;
  }
  local_64 = local_48[1];
  local_60 = *local_48;
  local_3c = ppuVar9;
  piVar10 = (int *)FUN_0071e6b0(local_50,local_40,&local_64);
  *ppuVar9 = (undefined1 *)*piVar10;
  ppuVar9[1] = (undefined1 *)piVar10[1];
  ppuVar9 = local_3c;
  for (iVar6 = *(int *)(local_58 + 8); iVar6 != 0; iVar6 = *(int *)(iVar6 + 0xc)) {
    piVar10 = (int *)FUN_0071e6b0(local_5c,local_40,&local_64);
    ppuVar9[2] = (undefined1 *)*piVar10;
    ppuVar9[3] = (undefined1 *)piVar10[1];
    uVar15 = local_44;
    ppuVar9 = ppuVar9 + 2;
  }
  pcVar14 = (char *)0x0;
  uVar13 = 0;
  if (uVar15 != 0) {
    do {
      pcVar11 = local_3c[uVar13 * 2];
      local_40 = pcVar11 + 1;
      do {
        cVar2 = *pcVar11;
        pcVar11 = pcVar11 + 1;
      } while (cVar2 != '\0');
      uVar13 = uVar13 + 1;
      pcVar14 = pcVar11 + ((int)pcVar14 - (int)local_40);
    } while (uVar13 < uVar15);
  }
  piVar10 = (int *)*local_48;
  uVar13 = (uint)(pcVar14 + 4) & 0xfffffffc;
  uVar15 = piVar10[1] + uVar13;
  if (uVar15 < 0x1001) {
    piVar12 = (int *)(*piVar10 + 4 + piVar10[1]);
    piVar10[1] = uVar15;
  }
  else {
    uVar15 = uVar13;
    if (uVar13 < 0x1001) {
      uVar15 = 0x1000;
    }
    piVar12 = (int *)(*(code *)PTR_FUN_00d63d48)(uVar15 + 4);
    if (piVar12 == (int *)0x0) goto LAB_0071e515;
    *piVar12 = *piVar10;
    *piVar10 = (int)piVar12;
    piVar10[1] = uVar13;
    piVar12 = piVar12 + 1;
  }
  if (piVar12 != (int *)0x0) {
    uVar15 = 0;
    piVar10 = piVar12;
    if (local_44 != 0) {
      do {
        pcVar14 = local_3c[uVar15 * 2];
        cVar2 = *pcVar14;
        while (cVar2 != '\0') {
          pcVar14 = pcVar14 + 1;
          *(char *)piVar10 = cVar2;
          piVar10 = (int *)((int)piVar10 + 1);
          cVar2 = *pcVar14;
        }
        uVar15 = uVar15 + 1;
      } while (uVar15 < local_44);
    }
    *(undefined1 *)piVar10 = 0;
    *(int **)local_38 = piVar12;
    local_8 = 0xffffffff;
    local_38[4] = '\x01';
    puVar8 = (undefined4 *)*piVar3;
    while (puVar8 != puVar4) {
      puVar7 = (undefined4 *)*puVar8;
      (*(code *)PTR_FUN_00d63d4c)(puVar8);
      puVar8 = puVar7;
    }
    *piVar3 = (int)puVar4;
    piVar3[1] = iVar5;
    ExceptionList = local_10;
    __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
    return;
  }
LAB_0071e515:
  local_38 = "bad allocation";
  std::exception::exception((exception *)&local_54,&local_38,1);
  local_54 = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(&local_54,&DAT_00c857a8);
}

