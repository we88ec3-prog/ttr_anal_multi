
void FUN_005c5830(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *******pppppppuVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *******pppppppuVar10;
  undefined4 *******pppppppuVar11;
  undefined4 *****pppppuVar12;
  wchar_t *******_Str1;
  undefined4 ******ppppppuVar13;
  undefined4 ******local_460;
  undefined4 ******local_45c;
  undefined4 ******local_458;
  undefined4 ******local_454;
  undefined4 ******local_450 [4];
  undefined4 local_440;
  uint local_43c;
  wchar_t ******local_434 [4];
  undefined4 ******local_424;
  uint local_420;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091299e;
  local_10 = ExceptionList;
  local_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar7 = FUN_005c7190();
  *(undefined4 *)(param_1 + 0x50) = uVar7;
  uVar7 = FUN_005c7190();
  *(undefined4 *)(param_1 + 0x54) = uVar7;
  uVar7 = FUN_005c7190();
  *(undefined4 *)(param_1 + 0x58) = uVar7;
  uVar7 = FUN_005c7190();
  *(undefined4 *)(param_1 + 0x4c) = uVar7;
  uVar7 = FUN_005c7190();
  *(undefined4 *)(param_1 + 0x48) = uVar7;
  uVar7 = FUN_005c7190();
  *(undefined4 *)(param_1 + 0x1d0) = uVar7;
  uVar7 = FUN_005c7190();
  *(undefined4 *)(param_1 + 0x1d4) = uVar7;
  uVar7 = FUN_005c7190();
  *(undefined4 *)(param_1 + 0x464) = uVar7;
  puVar9 = *(undefined4 **)(*(int *)(param_1 + 0x4c) + 0xc);
  puVar2 = (undefined4 *)*puVar9;
  while (puVar2 != puVar9) {
    piVar3 = (int *)puVar2[4];
    piVar3[0x27] = piVar3[0x27] + 1;
    if (piVar3[0x27] == 1) {
      (**(code **)(*piVar3 + 0x24))();
    }
    if (*(char *)((int)puVar2 + 0x15) == '\0') {
      puVar4 = (undefined4 *)puVar2[2];
      if (*(char *)((int)puVar4 + 0x15) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x15);
        puVar2 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x15);
          puVar2 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar2[1] + 0x15);
        puVar6 = (undefined4 *)puVar2[1];
        puVar4 = puVar2;
        while ((puVar2 = puVar6, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar2[2]))) {
          cVar1 = *(char *)((int)puVar2[1] + 0x15);
          puVar6 = (undefined4 *)puVar2[1];
          puVar4 = puVar2;
        }
      }
    }
  }
  iVar8 = *(int *)(param_1 + 0x14);
  local_458 = (undefined4 ******)0x0;
  FUN_0082ef00();
  if (local_45c == *(undefined4 *******)(iVar8 + 8)) {
    local_45c = (undefined4 ******)0x0;
  }
  else {
    local_45c = (undefined4 ******)local_45c[4];
  }
  iVar8 = 0;
  puVar9 = (undefined4 *)(param_1 + 0x5c);
  do {
    iVar8 = iVar8 + 1;
    FUN_0040aeb0();
    uVar7 = FUN_00763360();
    *puVar9 = uVar7;
    puVar9 = puVar9 + 1;
  } while (iVar8 < 9);
  iVar8 = *(int *)(param_1 + 0x14);
  local_458 = (undefined4 ******)0xb;
  FUN_0082ef00();
  if (local_45c == *(undefined4 *******)(iVar8 + 8)) {
    local_45c = (undefined4 ******)0x0;
  }
  else {
    local_45c = (undefined4 ******)local_45c[4];
  }
  iVar8 = 0;
  puVar9 = (undefined4 *)(param_1 + 0x80);
  do {
    iVar8 = iVar8 + 1;
    FUN_0040aeb0();
    uVar7 = FUN_00763360();
    *puVar9 = uVar7;
    puVar9 = puVar9 + 1;
  } while (iVar8 < 9);
  iVar8 = *(int *)(param_1 + 0x14);
  pppppppuVar11 = (undefined4 *******)(*(undefined4 ********)(iVar8 + 8))[1];
  cVar1 = *(char *)((int)pppppppuVar11 + 0x15);
  local_458 = *(undefined4 ********)(iVar8 + 8);
  while (cVar1 == '\0') {
    if (pppppppuVar11[3] < (undefined4 ******)0x4c) {
      pppppppuVar10 = (undefined4 *******)pppppppuVar11[2];
      pppppppuVar11 = (undefined4 *******)local_458;
    }
    else {
      pppppppuVar10 = (undefined4 *******)*pppppppuVar11;
    }
    local_458 = pppppppuVar11;
    pppppppuVar11 = pppppppuVar10;
    cVar1 = *(char *)((int)pppppppuVar10 + 0x15);
  }
  if (((undefined4 *******)local_458 == *(undefined4 ********)(iVar8 + 8)) ||
     ((undefined4 ******)0x4c < local_458[3])) {
    local_45c = *(undefined4 ********)(iVar8 + 8);
    pppppppuVar11 = &local_45c;
  }
  else {
    pppppppuVar11 = &local_458;
  }
  if (*pppppppuVar11 == *(undefined4 *******)(iVar8 + 8)) {
    ppppppuVar13 = (undefined4 ******)0x0;
  }
  else {
    local_45c = (undefined4 ******)(*pppppppuVar11)[4];
    ppppppuVar13 = local_45c;
    if (local_45c != (undefined4 ******)0x0) {
      FUN_0051ab00();
      local_8 = 0;
      pppppppuVar11 = (undefined4 *******)*local_424;
      local_454 = local_424;
      if (pppppppuVar11 != (undefined4 *******)local_424) {
        do {
          local_460 = pppppppuVar11[3];
          FUN_005c7fe0();
          local_8._0_1_ = 1;
          if (local_43c < 8) {
            local_458 = local_450;
          }
          else {
            local_458 = local_450[0];
          }
          puVar9 = (undefined4 *)FUN_00831f50();
          uVar7 = FUN_00763360();
          *puVar9 = uVar7;
          if (*(char *)((int)pppppppuVar11 + 0x15) == '\0') {
            pppppppuVar10 = (undefined4 *******)pppppppuVar11[2];
            if (*(char *)((int)pppppppuVar10 + 0x15) == '\0') {
              cVar1 = *(char *)((int)*pppppppuVar10 + 0x15);
              pppppppuVar11 = pppppppuVar10;
              pppppppuVar10 = (undefined4 *******)*pppppppuVar10;
              while (cVar1 == '\0') {
                cVar1 = *(char *)((int)*pppppppuVar10 + 0x15);
                pppppppuVar11 = pppppppuVar10;
                pppppppuVar10 = (undefined4 *******)*pppppppuVar10;
              }
            }
            else {
              cVar1 = *(char *)((int)pppppppuVar11[1] + 0x15);
              pppppppuVar5 = (undefined4 *******)pppppppuVar11[1];
              pppppppuVar10 = pppppppuVar11;
              while ((pppppppuVar11 = pppppppuVar5, cVar1 == '\0' &&
                     (pppppppuVar10 == (undefined4 *******)pppppppuVar11[2]))) {
                cVar1 = *(char *)((int)pppppppuVar11[1] + 0x15);
                pppppppuVar5 = (undefined4 *******)pppppppuVar11[1];
                pppppppuVar10 = pppppppuVar11;
              }
            }
          }
          local_8 = (uint)local_8._1_3_ << 8;
          if (7 < local_43c) {
            FUN_0089120c();
          }
        } while (pppppppuVar11 != (undefined4 *******)local_454);
      }
      local_8 = 2;
      FUN_005540c0();
      local_8 = 0xffffffff;
      FUN_0089120c();
      ppppppuVar13 = local_45c;
    }
  }
  iVar8 = *(int *)(param_1 + 0x14);
  pppppppuVar11 = (undefined4 *******)(*(undefined4 ********)(iVar8 + 8))[1];
  cVar1 = *(char *)((int)pppppppuVar11 + 0x15);
  local_454 = *(undefined4 ********)(iVar8 + 8);
  while (cVar1 == '\0') {
    if (pppppppuVar11[3] < (undefined4 ******)0x4d) {
      pppppppuVar10 = (undefined4 *******)pppppppuVar11[2];
      pppppppuVar11 = (undefined4 *******)local_454;
    }
    else {
      pppppppuVar10 = (undefined4 *******)*pppppppuVar11;
    }
    local_454 = pppppppuVar11;
    pppppppuVar11 = pppppppuVar10;
    cVar1 = *(char *)((int)pppppppuVar10 + 0x15);
  }
  if (((undefined4 *******)local_454 == *(undefined4 ********)(iVar8 + 8)) ||
     ((undefined4 ******)0x4d < local_454[3])) {
    local_460 = *(undefined4 ********)(iVar8 + 8);
    pppppppuVar11 = &local_460;
  }
  else {
    pppppppuVar11 = &local_454;
  }
  if (*pppppppuVar11 == *(undefined4 *******)(iVar8 + 8)) {
    local_45c = (undefined4 ******)0x0;
  }
  else {
    local_45c = (undefined4 ******)(*pppppppuVar11)[4];
  }
  if (ppppppuVar13 != (undefined4 ******)0x0) {
    FUN_0051ab00();
    local_8 = 3;
    pppppppuVar11 = (undefined4 *******)*local_424;
    local_460 = local_424;
    if (pppppppuVar11 != (undefined4 *******)local_424) {
      do {
        local_454 = pppppppuVar11[3];
        FUN_005c7fe0();
        local_8._0_1_ = 4;
        if (local_43c < 8) {
          local_458 = local_450;
        }
        else {
          local_458 = local_450[0];
        }
        puVar9 = (undefined4 *)FUN_00831f50();
        uVar7 = FUN_00763360();
        *puVar9 = uVar7;
        if (*(char *)((int)pppppppuVar11 + 0x15) == '\0') {
          pppppppuVar10 = (undefined4 *******)pppppppuVar11[2];
          if (*(char *)((int)pppppppuVar10 + 0x15) == '\0') {
            cVar1 = *(char *)((int)*pppppppuVar10 + 0x15);
            pppppppuVar11 = pppppppuVar10;
            pppppppuVar10 = (undefined4 *******)*pppppppuVar10;
            while (cVar1 == '\0') {
              cVar1 = *(char *)((int)*pppppppuVar10 + 0x15);
              pppppppuVar11 = pppppppuVar10;
              pppppppuVar10 = (undefined4 *******)*pppppppuVar10;
            }
          }
          else {
            cVar1 = *(char *)((int)pppppppuVar11[1] + 0x15);
            pppppppuVar5 = (undefined4 *******)pppppppuVar11[1];
            pppppppuVar10 = pppppppuVar11;
            while ((pppppppuVar11 = pppppppuVar5, cVar1 == '\0' &&
                   (pppppppuVar10 == (undefined4 *******)pppppppuVar11[2]))) {
              cVar1 = *(char *)((int)pppppppuVar11[1] + 0x15);
              pppppppuVar5 = (undefined4 *******)pppppppuVar11[1];
              pppppppuVar10 = pppppppuVar11;
            }
          }
        }
        local_8 = CONCAT31(local_8._1_3_,3);
        if (7 < local_43c) {
          FUN_0089120c();
        }
      } while (pppppppuVar11 != (undefined4 *******)local_460);
    }
    local_8 = 5;
    FUN_005540c0();
    local_8 = 0xffffffff;
    FUN_0089120c();
  }
  local_454 = *(undefined4 *******)(*(int *)(param_1 + 0x14) + 8);
  pppppppuVar11 = (undefined4 *******)local_454[1];
  cVar1 = *(char *)((int)pppppppuVar11 + 0x15);
  while (cVar1 == '\0') {
    if (pppppppuVar11[3] < (undefined4 ******)0xc) {
      pppppppuVar10 = (undefined4 *******)pppppppuVar11[2];
      pppppppuVar11 = (undefined4 *******)local_454;
    }
    else {
      pppppppuVar10 = (undefined4 *******)*pppppppuVar11;
    }
    local_454 = pppppppuVar11;
    pppppppuVar11 = pppppppuVar10;
    cVar1 = *(char *)((int)pppppppuVar10 + 0x15);
  }
  pppppppuVar11 = *(undefined4 ********)(*(int *)(param_1 + 0x14) + 8);
  if (((undefined4 *******)local_454 == pppppppuVar11) || ((undefined4 ******)0xc < local_454[3])) {
    local_460 = pppppppuVar11;
  }
  uVar7 = FUN_00763360();
  *(undefined4 *)(param_1 + 0x1b8) = uVar7;
  uVar7 = FUN_00763360();
  *(undefined4 *)(param_1 + 0x1bc) = uVar7;
  local_454 = *(undefined4 *******)(*(int *)(param_1 + 0x14) + 8);
  pppppppuVar11 = (undefined4 *******)local_454[1];
  cVar1 = *(char *)((int)pppppppuVar11 + 0x15);
  while (cVar1 == '\0') {
    if (pppppppuVar11[3] == (undefined4 ******)0x0) {
      pppppppuVar10 = (undefined4 *******)pppppppuVar11[2];
      pppppppuVar11 = (undefined4 *******)local_454;
    }
    else {
      pppppppuVar10 = (undefined4 *******)*pppppppuVar11;
    }
    local_454 = pppppppuVar11;
    pppppppuVar11 = pppppppuVar10;
    cVar1 = *(char *)((int)pppppppuVar10 + 0x15);
  }
  pppppppuVar11 = *(undefined4 ********)(*(int *)(param_1 + 0x14) + 8);
  if (((undefined4 *******)local_454 == pppppppuVar11) || ((undefined4 ******)0x1 < local_454[3])) {
    local_460 = pppppppuVar11;
  }
  uVar7 = FUN_00763360();
  *(undefined4 *)(param_1 + 0x1c0) = uVar7;
  uVar7 = FUN_00763360();
  *(undefined4 *)(param_1 + 0x1c4) = uVar7;
  uVar7 = FUN_00763360();
  *(undefined4 *)(param_1 + 0x1c8) = uVar7;
  uVar7 = FUN_00763360();
  *(undefined4 *)(param_1 + 0x1cc) = uVar7;
  local_454 = *(undefined4 *******)(*(int *)(param_1 + 0x14) + 8);
  pppppppuVar11 = (undefined4 *******)local_454[1];
  cVar1 = *(char *)((int)pppppppuVar11 + 0x15);
  while (cVar1 == '\0') {
    if (pppppppuVar11[3] < (undefined4 ******)0x47) {
      pppppppuVar10 = (undefined4 *******)pppppppuVar11[2];
      pppppppuVar11 = (undefined4 *******)local_454;
    }
    else {
      pppppppuVar10 = (undefined4 *******)*pppppppuVar11;
    }
    local_454 = pppppppuVar11;
    pppppppuVar11 = pppppppuVar10;
    cVar1 = *(char *)((int)pppppppuVar10 + 0x15);
  }
  pppppppuVar11 = *(undefined4 ********)(*(int *)(param_1 + 0x14) + 8);
  if (((undefined4 *******)local_454 == pppppppuVar11) || ((undefined4 ******)0x47 < local_454[3]))
  {
    local_460 = pppppppuVar11;
  }
  uVar7 = FUN_00763360();
  *(undefined4 *)(param_1 + 0x44c) = uVar7;
  uVar7 = FUN_00763360();
  *(undefined4 *)(param_1 + 0x450) = uVar7;
  local_454 = *(undefined4 *******)(*(int *)(param_1 + 0x14) + 8);
  pppppppuVar11 = (undefined4 *******)local_454[1];
  cVar1 = *(char *)((int)pppppppuVar11 + 0x15);
  while (cVar1 == '\0') {
    if (pppppppuVar11[3] < (undefined4 ******)0xf) {
      pppppppuVar10 = (undefined4 *******)pppppppuVar11[2];
      pppppppuVar11 = (undefined4 *******)local_454;
    }
    else {
      pppppppuVar10 = (undefined4 *******)*pppppppuVar11;
    }
    local_454 = pppppppuVar11;
    pppppppuVar11 = pppppppuVar10;
    cVar1 = *(char *)((int)pppppppuVar10 + 0x15);
  }
  pppppppuVar11 = *(undefined4 ********)(*(int *)(param_1 + 0x14) + 8);
  if (((undefined4 *******)local_454 == pppppppuVar11) || ((undefined4 ******)0xf < local_454[3])) {
    local_460 = pppppppuVar11;
  }
  uVar7 = FUN_00763360();
  *(undefined4 *)(param_1 + 0xa4) = uVar7;
  local_454 = *(undefined4 *******)(*(int *)(param_1 + 0x14) + 8);
  pppppppuVar11 = (undefined4 *******)local_454[1];
  cVar1 = *(char *)((int)pppppppuVar11 + 0x15);
  while (cVar1 == '\0') {
    if (pppppppuVar11[3] < (undefined4 ******)0xf) {
      pppppppuVar10 = (undefined4 *******)pppppppuVar11[2];
      pppppppuVar11 = (undefined4 *******)local_454;
    }
    else {
      pppppppuVar10 = (undefined4 *******)*pppppppuVar11;
    }
    local_454 = pppppppuVar11;
    pppppppuVar11 = pppppppuVar10;
    cVar1 = *(char *)((int)pppppppuVar10 + 0x15);
  }
  pppppppuVar11 = *(undefined4 ********)(*(int *)(param_1 + 0x14) + 8);
  if (((undefined4 *******)local_454 == pppppppuVar11) || ((undefined4 ******)0xf < local_454[3])) {
    local_460 = pppppppuVar11;
  }
  uVar7 = FUN_00763360();
  *(undefined4 *)(param_1 + 0xa8) = uVar7;
  local_454 = *(undefined4 *******)(*(int *)(param_1 + 0x14) + 8);
  pppppppuVar11 = (undefined4 *******)local_454[1];
  cVar1 = *(char *)((int)pppppppuVar11 + 0x15);
  while (cVar1 == '\0') {
    if (pppppppuVar11[3] < (undefined4 ******)0xf) {
      pppppppuVar10 = (undefined4 *******)pppppppuVar11[2];
      pppppppuVar11 = (undefined4 *******)local_454;
    }
    else {
      pppppppuVar10 = (undefined4 *******)*pppppppuVar11;
    }
    local_454 = pppppppuVar11;
    pppppppuVar11 = pppppppuVar10;
    cVar1 = *(char *)((int)pppppppuVar10 + 0x15);
  }
  pppppppuVar11 = *(undefined4 ********)(*(int *)(param_1 + 0x14) + 8);
  if (((undefined4 *******)local_454 == pppppppuVar11) || ((undefined4 ******)0xf < local_454[3])) {
    local_460 = pppppppuVar11;
  }
  uVar7 = FUN_00763360();
  iVar8 = *(int *)(param_1 + 0x14);
  *(undefined4 *)(param_1 + 0xac) = uVar7;
  pppppppuVar11 = (undefined4 *******)(*(undefined4 ********)(iVar8 + 8))[1];
  cVar1 = *(char *)((int)pppppppuVar11 + 0x15);
  local_454 = *(undefined4 ********)(iVar8 + 8);
  while (cVar1 == '\0') {
    if (pppppppuVar11[3] < (undefined4 ******)0x38) {
      pppppppuVar10 = (undefined4 *******)pppppppuVar11[2];
      pppppppuVar11 = (undefined4 *******)local_454;
    }
    else {
      pppppppuVar10 = (undefined4 *******)*pppppppuVar11;
    }
    local_454 = pppppppuVar11;
    pppppppuVar11 = pppppppuVar10;
    cVar1 = *(char *)((int)pppppppuVar10 + 0x15);
  }
  if (((undefined4 *******)local_454 == *(undefined4 ********)(iVar8 + 8)) ||
     ((undefined4 ******)0x38 < local_454[3])) {
    local_460 = *(undefined4 ********)(iVar8 + 8);
    pppppppuVar11 = &local_460;
  }
  else {
    pppppppuVar11 = &local_454;
  }
  if (*pppppppuVar11 == *(undefined4 *******)(iVar8 + 8)) {
    local_45c = (undefined4 *******)0x0;
  }
  else {
    local_45c = (undefined4 ******)(*pppppppuVar11)[4];
  }
  iVar8 = 0;
  puVar9 = (undefined4 *)(param_1 + 0xb0);
  do {
    iVar8 = iVar8 + 1;
    FUN_0040aeb0();
    uVar7 = FUN_00763360();
    *puVar9 = uVar7;
    puVar9 = puVar9 + 1;
  } while (iVar8 < 0x1a);
  iVar8 = 0;
  puVar9 = (undefined4 *)(param_1 + 0x118);
  do {
    iVar8 = iVar8 + 1;
    FUN_0040aeb0();
    uVar7 = FUN_00763360();
    *puVar9 = uVar7;
    puVar9 = puVar9 + 1;
  } while (iVar8 < 4);
  local_420 = 7;
  local_424 = (undefined4 ******)0x0;
  local_434[0] = (wchar_t ******)((uint)local_434[0] & 0xffff0000);
  FUN_00402160();
  local_454 = (undefined4 ******)FUN_005c7610();
  if (local_454 != *(undefined4 *******)(param_1 + 8)) {
    ppppppuVar13 = local_454 + 3;
    if ((undefined4 *****)0x7 < local_454[8]) {
      ppppppuVar13 = (undefined4 ******)*ppppppuVar13;
    }
    _Str1 = (wchar_t *******)local_434[0];
    if (local_420 < 8) {
      _Str1 = local_434;
    }
    iVar8 = __wcsicmp((wchar_t *)_Str1,(wchar_t *)ppppppuVar13);
    if (iVar8 < 1) {
      pppppppuVar11 = &local_454;
      goto LAB_005c6215;
    }
  }
  local_460 = *(undefined4 ********)(param_1 + 8);
  pppppppuVar11 = &local_460;
LAB_005c6215:
  ppppppuVar13 = *pppppppuVar11;
  if (7 < local_420) {
    FUN_0089120c();
  }
  pppppuVar12 = (undefined4 *****)0x0;
  local_420 = 7;
  local_424 = (undefined4 ******)0x0;
  local_434[0] = (wchar_t ******)((uint)local_434[0] & 0xffff0000);
  if (ppppppuVar13 != *(undefined4 *******)(param_1 + 8)) {
    pppppuVar12 = ppppppuVar13[10];
  }
  *(undefined4 ******)(param_1 + 0x188) = pppppuVar12;
  local_454 = (undefined4 *******)0x9;
  FUN_0082ef00();
  iVar8 = 0;
  puVar9 = (undefined4 *)(param_1 + 0x18c);
  do {
    FUN_0040aeb0();
    uVar7 = FUN_00763360();
    *puVar9 = uVar7;
    iVar8 = iVar8 + 1;
    puVar9 = puVar9 + 1;
  } while (iVar8 < 3);
  iVar8 = 0;
  puVar9 = (undefined4 *)(param_1 + 0x1a8);
  do {
    FUN_0040aeb0();
    uVar7 = FUN_00763360();
    puVar9[-4] = uVar7;
    FUN_0040aeb0();
    uVar7 = FUN_00763360();
    *puVar9 = uVar7;
    iVar8 = iVar8 + 1;
    puVar9 = puVar9 + 1;
  } while (iVar8 < 4);
  FUN_00823850();
  iVar8 = FUN_005c8db0();
  if (iVar8 != 0) {
    pppppppuVar11 = *(undefined4 ********)(iVar8 + 0x20);
    pppppppuVar10 = (undefined4 *******)*pppppppuVar11;
    while (local_45c = pppppppuVar10, pppppppuVar10 != pppppppuVar11) {
      iVar8 = FUN_00774c30();
      if (iVar8 != 0) {
        local_460 = pppppppuVar10[0x19];
        local_458 = (undefined4 ******)*local_460;
        if (local_458 != local_460) {
          do {
            local_454 = (undefined4 ******)local_458[3];
            local_434[0] = (wchar_t ******)((uint)local_434[0] & 0xffff0000);
            local_420 = 7;
            local_424 = (undefined4 ******)0x0;
            FUN_004026e0();
            local_8 = 6;
            puVar9 = (undefined4 *)FUN_00831f50();
            uVar7 = FUN_00763360();
            *puVar9 = uVar7;
            FUN_00717a50();
            local_8 = 0xffffffff;
            if (7 < local_420) {
              FUN_0089120c();
            }
          } while (local_458 != local_460);
        }
      }
      FUN_00527e20();
      pppppppuVar10 = (undefined4 *******)local_45c;
    }
  }
  FUN_00823850();
  iVar8 = FUN_005c8db0();
  if (iVar8 != 0) {
    local_460 = *(undefined4 *******)(iVar8 + 0x20);
    local_45c = (undefined4 ******)*local_460;
    if (local_45c != local_460) {
      do {
        ppppppuVar13 = local_45c;
        iVar8 = FUN_00774c30();
        if (iVar8 != 0) {
          local_454 = (undefined4 ******)ppppppuVar13[0x19];
          local_458 = (undefined4 ******)*local_454;
          if (local_458 != local_454) {
            do {
              local_420 = 7;
              local_424 = (undefined4 ******)0x0;
              local_434[0] = (wchar_t ******)((uint)local_434[0] & 0xffff0000);
              FUN_004026e0();
              local_8 = 7;
              puVar9 = (undefined4 *)FUN_00831f50();
              uVar7 = FUN_00763360();
              *puVar9 = uVar7;
              FUN_00717a50();
              local_8 = 0xffffffff;
              if (7 < local_420) {
                FUN_0089120c();
              }
            } while (local_458 != local_454);
          }
        }
        FUN_00527e20();
      } while (local_45c != local_460);
    }
  }
  iVar8 = FUN_005c8db0();
  if (iVar8 != 0) {
    FUN_00402160(L"39196389",8);
    iVar8 = FUN_005c3d40();
    if (iVar8 != 0) {
      FUN_00774c30();
      local_454 = *(undefined4 *******)(iVar8 + 0x3c);
      local_458 = (undefined4 ******)*local_454;
      if (local_458 != local_454) {
        do {
          local_420 = 7;
          local_424 = (undefined4 ******)0x0;
          local_434[0] = (wchar_t ******)((uint)local_434[0] & 0xffff0000);
          FUN_004026e0();
          local_8 = 8;
          puVar9 = (undefined4 *)FUN_00831f50();
          uVar7 = FUN_00763360();
          *puVar9 = uVar7;
          FUN_00717a50();
          local_8 = 0xffffffff;
          if (7 < local_420) {
            FUN_0089120c();
          }
        } while (local_458 != local_454);
      }
    }
  }
  local_45c = (undefined4 ******)FUN_005c8db0();
  if ((undefined4 *******)local_45c != (undefined4 *******)0x0) {
    FUN_00402160(L"116405291",9);
    iVar8 = FUN_005c3d40();
    if (iVar8 != 0) {
      FUN_00774c30();
      local_454 = *(undefined4 *******)(iVar8 + 0x3c);
      local_458 = (undefined4 ******)*local_454;
      if (local_458 != local_454) {
        do {
          local_420 = 7;
          local_424 = (undefined4 ******)0x0;
          local_434[0] = (wchar_t ******)((uint)local_434[0] & 0xffff0000);
          FUN_004026e0();
          local_8 = 9;
          puVar9 = (undefined4 *)FUN_00831f50();
          uVar7 = FUN_00763360();
          *puVar9 = uVar7;
          FUN_00717a50();
          local_8 = 0xffffffff;
          if (7 < local_420) {
            FUN_0089120c();
          }
        } while (local_458 != local_454);
      }
    }
  }
  FUN_005c8db0();
  if ((undefined4 *******)local_45c != (undefined4 *******)0x0) {
    FUN_00402160(L"8495921",7);
    iVar8 = FUN_005c3d40();
    if (iVar8 != 0) {
      local_454 = (undefined4 ******)FUN_00774c30();
      local_460 = *(undefined4 *******)(iVar8 + 0x3c);
      local_458 = (undefined4 ******)*local_460;
      if (local_458 != local_460) {
        do {
          local_420 = 7;
          local_424 = (undefined4 ******)0x0;
          local_434[0] = (wchar_t ******)((uint)local_434[0] & 0xffff0000);
          FUN_004026e0();
          local_8 = 10;
          puVar9 = (undefined4 *)FUN_00831f50();
          uVar7 = FUN_00763360();
          *puVar9 = uVar7;
          FUN_00717a50();
          local_8 = 0xffffffff;
          if (7 < local_420) {
            FUN_0089120c();
          }
        } while (local_458 != local_460);
      }
    }
  }
  FUN_005c8db0();
  if ((undefined4 *******)local_45c != (undefined4 *******)0x0) {
    FUN_00402160(L"13310519",8);
    iVar8 = FUN_005c3d40();
    if (iVar8 != 0) {
      FUN_00774c30();
      local_454 = *(undefined4 *******)(iVar8 + 0x3c);
      local_458 = (undefined4 ******)*local_454;
      if (local_458 != local_454) {
        do {
          local_420 = 7;
          local_424 = (undefined4 ******)0x0;
          local_434[0] = (wchar_t ******)((uint)local_434[0] & 0xffff0000);
          FUN_004026e0();
          local_8 = 0xb;
          puVar9 = (undefined4 *)FUN_00831f50();
          uVar7 = FUN_00763360();
          *puVar9 = uVar7;
          FUN_00717a50();
          local_8 = 0xffffffff;
          if (7 < local_420) {
            FUN_0089120c();
          }
        } while (local_458 != local_454);
      }
    }
  }
  FUN_005c8db0();
  if ((undefined4 *******)local_45c != (undefined4 *******)0x0) {
    FUN_00402160(L"7160233",7);
    iVar8 = FUN_005c3d40();
    if (iVar8 != 0) {
      FUN_00774c30();
      local_454 = *(undefined4 *******)(iVar8 + 0x3c);
      local_458 = (undefined4 ******)*local_454;
      if (local_458 != local_454) {
        do {
          local_420 = 7;
          local_424 = (undefined4 ******)0x0;
          local_434[0] = (wchar_t ******)((uint)local_434[0] & 0xffff0000);
          FUN_004026e0();
          local_8 = 0xc;
          puVar9 = (undefined4 *)FUN_00831f50();
          uVar7 = FUN_00763360();
          *puVar9 = uVar7;
          FUN_00717a50();
          local_8 = 0xffffffff;
          if (7 < local_420) {
            FUN_0089120c();
          }
        } while (local_458 != local_454);
      }
    }
  }
  iVar8 = FUN_005c8db0();
  if (iVar8 != 0) {
    FUN_00402160(L"643339773",9);
    iVar8 = FUN_005c3d40();
    if (iVar8 != 0) {
      local_460 = (undefined4 ******)FUN_00774c30();
      local_45c = *(undefined4 *******)(iVar8 + 0x3c);
      local_458 = (undefined4 ******)*local_45c;
      if (local_458 != local_45c) {
        local_454 = (undefined4 ******)(param_1 + 0x468);
        do {
          local_43c = 7;
          local_440 = 0;
          local_450[0] = (undefined4 ******)((uint)local_450[0] & 0xffff0000);
          FUN_004026e0();
          local_8 = 0xd;
          puVar9 = (undefined4 *)FUN_00831f50();
          uVar7 = FUN_00763360();
          *puVar9 = uVar7;
          FUN_00717a50();
          local_8 = 0xffffffff;
          if (7 < local_43c) {
            FUN_0089120c();
          }
        } while (local_458 != local_45c);
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

