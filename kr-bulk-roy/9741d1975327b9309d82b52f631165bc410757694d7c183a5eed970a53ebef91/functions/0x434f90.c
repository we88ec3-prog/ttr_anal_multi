
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00434f90(void)

{
  char cVar1;
  int *piVar2;
  int **ppiVar3;
  undefined4 *puVar4;
  code *pcVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int **ppiVar11;
  undefined4 *puVar12;
  int iVar13;
  int *in_ECX;
  int *piVar14;
  undefined ***pppuVar15;
  undefined **local_74 [3];
  int *local_68;
  int *local_64;
  int *local_60;
  undefined **local_5c [3];
  int *local_50;
  undefined **local_4c [3];
  int *local_40;
  int *local_3c;
  int *local_38 [2];
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00931d1f;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_40 = in_ECX;
  FUN_00755e50(local_14);
  local_60 = in_ECX + 0x3e;
  FUN_00458240(1000);
  FUN_00436530();
  local_64 = in_ECX + 0x3f;
  FUN_00458240(5000);
  local_68 = in_ECX + 0x40;
  FUN_00436620();
  iVar8 = *(int *)(in_ECX[0x3e] + 0xcc);
  if (iVar8 != 0) {
    FUN_006438f0(iVar8);
  }
  local_3c = in_ECX + 0x42;
  local_38[1] = (int *)0x1;
  do {
    piVar14 = local_38[1];
    piVar10 = *(int **)(*local_60 + 0xcc);
    if ((piVar10 == (int *)0x0) || (piVar2 = (int *)piVar10[0x29], piVar2 == (int *)0x0)) {
LAB_00435166:
      piVar14 = (int *)0x0;
    }
    else {
      if (piVar10[0x2e] == piVar10[0x2f]) {
        piVar6 = (int *)(**(code **)(*piVar2 + 0x28))();
        local_50 = piVar6;
      }
      else {
        piVar6 = *(int **)(piVar10[0x2f] + -4);
        local_50 = piVar6;
        (**(code **)(*piVar2 + 0x2c))(piVar6);
        if (piVar10[0x2e] != piVar10[0x2f]) {
          piVar10[0x2f] = piVar10[0x2f] + -4;
        }
      }
      piVar6[8] = (int)piVar14;
      local_38[0] = piVar6;
      (**(code **)(*piVar10 + 0x70))(piVar6);
      ppiVar11 = (int **)piVar10[0x2b];
      if (local_38 < ppiVar11) {
        ppiVar3 = (int **)piVar10[0x2a];
        if (local_38 < ppiVar3) goto LAB_004350f9;
        if (ppiVar11 == (int **)piVar10[0x2c]) {
          FUN_004deab0();
        }
        if ((undefined4 *)piVar10[0x2b] != (undefined4 *)0x0) {
          *(undefined4 *)piVar10[0x2b] =
               *(undefined4 *)(piVar10[0x2a] + ((int)local_38 - (int)ppiVar3 >> 2) * 4);
        }
      }
      else {
LAB_004350f9:
        if (ppiVar11 == (int **)piVar10[0x2c]) {
          FUN_004deab0();
        }
        if ((undefined4 *)piVar10[0x2b] != (undefined4 *)0x0) {
          *(undefined4 *)piVar10[0x2b] = piVar6;
        }
      }
      piVar14 = local_50;
      piVar10[0x2b] = piVar10[0x2b] + 4;
      uVar7 = piVar10[0x39];
      if ((uint)piVar10[0x39] < (int)local_38[1] + 1U) {
        uVar7 = (int)local_38[1] + 1U;
      }
      piVar10[0x39] = uVar7;
      iVar8 = (**(code **)(*local_50 + 4))();
      if (iVar8 != 0x12d) {
        MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
        goto LAB_00435166;
      }
    }
    piVar2 = local_38[1];
    piVar10 = local_3c;
    *local_3c = (int)piVar14;
    (**(code **)(*piVar14 + 0x1a4))(0x3eb);
    (**(code **)(*(int *)*piVar10 + 0x198))(piVar2);
    local_38[1] = (int *)((int)piVar2 + 1);
    local_3c = piVar10 + 1;
  } while (local_38[1] < (int *)0xa);
  if (*(int *)(*local_64 + 0xcc) != 0) {
    FUN_00408920(*(int *)(*local_64 + 0xcc),3);
  }
  iVar8 = 0;
  local_3c = (int *)(-300 - (int)local_40);
  piVar10 = local_40 + 0x4b;
  do {
    iVar9 = *(int *)(*local_64 + 0xcc);
    if ((((iVar9 == 0) || (iVar8 < 0)) ||
        (*(int *)(iVar9 + 0xac) - *(int *)(iVar9 + 0xa8) >> 2 <= iVar8)) ||
       (piVar14 = *(int **)((int)local_3c + (int)piVar10 + *(int *)(iVar9 + 0xa8)),
       piVar14 == (int *)0x0)) {
LAB_00435231:
      piVar14 = (int *)0x0;
    }
    else {
      iVar9 = (**(code **)(*piVar14 + 4))();
      if (iVar9 != 0x12d) {
        MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
        goto LAB_00435231;
      }
    }
    *piVar10 = (int)piVar14;
    (**(code **)(*piVar14 + 0x1a0))(0x138b);
    (**(code **)(*(int *)*piVar10 + 0x19c))();
    iVar8 = iVar8 + 1;
    piVar10 = piVar10 + 1;
  } while (iVar8 < 3);
  if ((DAT_00fe5ae4 & 1) != 0) {
LAB_0043530f:
    cVar1 = *(char *)(DAT_00fe5ac8[1] + 0x2d);
    piVar10 = (int *)DAT_00fe5ac8[1];
    local_3c = DAT_00fe5ac8;
    while (piVar14 = piVar10, cVar1 == '\0') {
      if (piVar14[3] < 0x296) {
        piVar10 = (int *)piVar14[2];
        piVar14 = local_3c;
      }
      else {
        piVar10 = (int *)*piVar14;
      }
      cVar1 = *(char *)((int)piVar10 + 0x2d);
      local_3c = piVar14;
    }
    if ((local_3c == DAT_00fe5ac8) || (0x296 < local_3c[3])) {
      local_50 = DAT_00fe5ac8;
      ppiVar11 = &local_50;
    }
    else {
      ppiVar11 = &local_3c;
    }
    if (*ppiVar11 == DAT_00fe5ac8) {
      pcVar5 = (code *)swi(3);
      (*pcVar5)();
      return;
    }
    FUN_00757710();
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 2;
      _DAT_00fe5acc = 0;
      piVar10 = (int *)FUN_00891268(0x30);
      if (piVar10 == (int *)0x0) {
        local_38[0] = (int *)0x0;
        std::exception::exception((exception *)local_4c,(char **)local_38);
        pppuVar15 = local_4c;
        local_4c[0] = std::bad_alloc::vftable;
        goto LAB_00435374;
      }
      DAT_00fe5ac8 = piVar10;
      *piVar10 = (int)piVar10;
      DAT_00fe5ac8[1] = (int)DAT_00fe5ac8;
      DAT_00fe5ac8[2] = (int)DAT_00fe5ac8;
      *(undefined1 *)(DAT_00fe5ac8 + 0xb) = 1;
      *(undefined1 *)((int)DAT_00fe5ac8 + 0x2d) = 1;
      local_8 = CONCAT31(local_8._1_3_,3);
      _DAT_00fe5adc = 0;
      iVar8 = FUN_00891268(0x30);
      if (iVar8 == 0) {
        local_38[1] = (int *)0x0;
        ppiVar11 = (int **)((int)local_38 + 4);
        goto LAB_0043535b;
      }
      DAT_00fe5ad8 = iVar8;
      *(int *)iVar8 = iVar8;
      *(int *)(DAT_00fe5ad8 + 4) = DAT_00fe5ad8;
      *(int *)(DAT_00fe5ad8 + 8) = DAT_00fe5ad8;
      *(undefined1 *)(DAT_00fe5ad8 + 0x2c) = 1;
      *(undefined1 *)(DAT_00fe5ad8 + 0x2d) = 1;
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 0xffffffff;
    }
    cVar1 = *(char *)(DAT_00fe5ac8[1] + 0x2d);
    piVar10 = (int *)DAT_00fe5ac8[1];
    local_40 = DAT_00fe5ac8;
    while (piVar14 = piVar10, cVar1 == '\0') {
      if (piVar14[3] < 0x297) {
        piVar10 = (int *)piVar14[2];
        piVar14 = local_40;
      }
      else {
        piVar10 = (int *)*piVar14;
      }
      cVar1 = *(char *)((int)piVar10 + 0x2d);
      local_40 = piVar14;
    }
    if ((local_40 == DAT_00fe5ac8) || (0x297 < local_40[3])) {
      local_3c = DAT_00fe5ac8;
      ppiVar11 = &local_3c;
    }
    else {
      ppiVar11 = &local_40;
    }
    if (*ppiVar11 == DAT_00fe5ac8) {
      pcVar5 = (code *)swi(3);
      (*pcVar5)();
      return;
    }
    FUN_00757710();
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 4;
      _DAT_00fe5acc = 0;
      piVar10 = (int *)FUN_00891268(0x30);
      if (piVar10 == (int *)0x0) {
        local_38[0] = (int *)0x0;
        ppiVar11 = local_38;
        goto LAB_00435337;
      }
      DAT_00fe5ac8 = piVar10;
      *piVar10 = (int)piVar10;
      DAT_00fe5ac8[1] = (int)DAT_00fe5ac8;
      DAT_00fe5ac8[2] = (int)DAT_00fe5ac8;
      *(undefined1 *)(DAT_00fe5ac8 + 0xb) = 1;
      *(undefined1 *)((int)DAT_00fe5ac8 + 0x2d) = 1;
      local_8 = CONCAT31(local_8._1_3_,5);
      _DAT_00fe5adc = 0;
      iVar8 = FUN_00891268(0x30);
      if (iVar8 == 0) {
        local_38[1] = (int *)0x0;
        std::exception::exception((exception *)local_5c,(char **)((int)local_38 + 4));
        pppuVar15 = local_5c;
        local_5c[0] = std::bad_alloc::vftable;
        goto LAB_00435374;
      }
      DAT_00fe5ad8 = iVar8;
      *(int *)iVar8 = iVar8;
      *(int *)(DAT_00fe5ad8 + 4) = DAT_00fe5ad8;
      *(int *)(DAT_00fe5ad8 + 8) = DAT_00fe5ad8;
      *(undefined1 *)(DAT_00fe5ad8 + 0x2c) = 1;
      *(undefined1 *)(DAT_00fe5ad8 + 0x2d) = 1;
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 0xffffffff;
    }
    cVar1 = *(char *)(DAT_00fe5ac8[1] + 0x2d);
    piVar10 = (int *)DAT_00fe5ac8[1];
    local_40 = DAT_00fe5ac8;
    while (piVar14 = piVar10, cVar1 == '\0') {
      if (piVar14[3] < 0x298) {
        piVar10 = (int *)piVar14[2];
        piVar14 = local_40;
      }
      else {
        piVar10 = (int *)*piVar14;
      }
      cVar1 = *(char *)((int)piVar10 + 0x2d);
      local_40 = piVar14;
    }
    if ((local_40 == DAT_00fe5ac8) || (0x298 < local_40[3])) {
      local_3c = DAT_00fe5ac8;
      ppiVar11 = &local_3c;
    }
    else {
      ppiVar11 = &local_40;
    }
    if (*ppiVar11 == DAT_00fe5ac8) {
      pcVar5 = (code *)swi(3);
      (*pcVar5)();
      return;
    }
    FUN_00757710();
    piVar10 = (int *)*local_60;
    puVar12 = (undefined4 *)piVar10[0x19];
    for (puVar4 = (undefined4 *)*puVar12; puVar4 != puVar12; puVar4 = (undefined4 *)*puVar4) {
      iVar8 = puVar4[2];
      if ((*(int *)(iVar8 + 0x60) != 0) && ((*(int **)(iVar8 + 0x1c))[2] != 6)) {
        (**(code **)(**(int **)(iVar8 + 0x1c) + 0x30))(iVar8);
      }
    }
    (**(code **)(*piVar10 + 0x128))();
    piVar10 = (int *)*local_64;
    puVar12 = (undefined4 *)piVar10[0x19];
    for (puVar4 = (undefined4 *)*puVar12; puVar4 != puVar12; puVar4 = (undefined4 *)*puVar4) {
      iVar8 = puVar4[2];
      if ((*(int *)(iVar8 + 0x60) != 0) && ((*(int **)(iVar8 + 0x1c))[2] != 6)) {
        (**(code **)(**(int **)(iVar8 + 0x1c) + 0x30))(iVar8);
      }
    }
    (**(code **)(*piVar10 + 0x128))();
    if ((DAT_00f94394 & 1) == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_8 = 6;
      FUN_005c3de0();
      _atexit((_func_4879 *)&LAB_00bccc30);
      local_8 = 0xffffffff;
    }
    piVar2 = local_68;
    piVar10 = *(int **)(DAT_00f943ac + 8);
    cVar1 = *(char *)(piVar10[1] + 0x15);
    local_60 = piVar10;
    piVar14 = (int *)piVar10[1];
    while (cVar1 == '\0') {
      if ((uint)piVar14[3] < 0x5d) {
        piVar6 = (int *)piVar14[2];
        piVar14 = local_60;
      }
      else {
        piVar6 = (int *)*piVar14;
      }
      local_60 = piVar14;
      piVar14 = piVar6;
      cVar1 = *(char *)((int)piVar6 + 0x15);
    }
    if ((local_60 == piVar10) || (0x5d < (uint)local_60[3])) {
      local_40 = piVar10;
      ppiVar11 = &local_40;
    }
    else {
      ppiVar11 = &local_60;
    }
    if ((*ppiVar11 != piVar10) && ((*ppiVar11)[4] != 0)) {
      iVar8 = *local_68;
      FUN_007444b0(0xbf6b);
      *(undefined1 *)(iVar8 + 0xa4) = 1;
      iVar8 = *piVar2;
      if ((*(char *)(iVar8 + 0xa4) != '\0') &&
         ((*(int **)(iVar8 + 0x94) != (int *)0x0 &&
          (iVar9 = (**(code **)(**(int **)(iVar8 + 0x94) + 4))(), iVar9 == 0xbf6b)))) {
        *(undefined1 *)(*(int *)(iVar8 + 0x94) + 0x4c) = 1;
      }
      if ((DAT_00fb7a08 & 1) == 0) {
        DAT_00fb7a08 = DAT_00fb7a08 | 1;
        local_8 = 7;
        DAT_00fb7a14 = 0;
        iVar8 = FUN_00891268(0x3c);
        if (iVar8 == 0) {
          local_3c = (int *)0x0;
          std::exception::exception((exception *)local_74,(char **)&local_3c);
          pppuVar15 = local_74;
          local_74[0] = std::bad_alloc::vftable;
          goto LAB_00435350;
        }
        DAT_00fb7a10 = iVar8;
        *(int *)iVar8 = iVar8;
        *(int *)(DAT_00fb7a10 + 4) = DAT_00fb7a10;
        *(int *)(DAT_00fb7a10 + 8) = DAT_00fb7a10;
        *(undefined1 *)(DAT_00fb7a10 + 0x38) = 1;
        *(undefined1 *)(DAT_00fb7a10 + 0x39) = 1;
        _atexit(FUN_00bcd310);
        local_8 = 0xffffffff;
      }
      puVar12 = (undefined4 *)FUN_00426ec0();
      local_8 = 8;
      if (7 < (uint)puVar12[5]) {
        puVar12 = (undefined4 *)*puVar12;
      }
      iVar9 = FUN_00763360(puVar12);
      iVar8 = *piVar2;
      if ((((*(char *)(iVar8 + 0xa4) != '\0') && (*(int **)(iVar8 + 0x94) != (int *)0x0)) &&
          (iVar13 = (**(code **)(**(int **)(iVar8 + 0x94) + 4))(), iVar13 == 0xbf6b)) &&
         (iVar8 = *(int *)(iVar8 + 0x94), *(int *)(iVar8 + 0x10) != iVar9)) {
        if (((iVar9 != 0) && (piVar10 = *(int **)(iVar9 + 8), piVar10 != (int *)0x0)) &&
           (piVar10[0x27] = piVar10[0x27] + 1, piVar10[0x27] == 1)) {
          (**(code **)(*piVar10 + 0x24))();
        }
        if ((*(int *)(iVar8 + 0x10) != 0) &&
           (piVar10 = *(int **)(*(int *)(iVar8 + 0x10) + 8), piVar10 != (int *)0x0)) {
          piVar14 = piVar10 + 0x27;
          *piVar14 = *piVar14 + -1;
          if (*piVar14 == 0) {
            (**(code **)(*piVar10 + 0x28))();
          }
        }
        *(int *)(iVar8 + 0x10) = iVar9;
      }
      local_8 = 0xffffffff;
      if (7 < local_1c) {
        FUN_0089120c(local_30);
      }
      local_30 = local_30 & 0xffff0000;
      local_1c = 7;
      local_20 = 0;
      (**(code **)(*(int *)*piVar2 + 200))();
    }
    ExceptionList = local_10;
    __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
    return;
  }
  DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
  local_8 = 0;
  _DAT_00fe5acc = 0;
  piVar10 = (int *)FUN_00891268(0x30);
  if (piVar10 == (int *)0x0) {
    local_38[0] = (int *)0x0;
    ppiVar11 = local_38;
LAB_0043535b:
    std::exception::exception((exception *)local_5c,(char **)ppiVar11);
    pppuVar15 = local_5c;
    local_5c[0] = std::bad_alloc::vftable;
LAB_00435374:
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(pppuVar15,&DAT_00c857a8);
  }
  DAT_00fe5ac8 = piVar10;
  *piVar10 = (int)piVar10;
  DAT_00fe5ac8[1] = (int)DAT_00fe5ac8;
  DAT_00fe5ac8[2] = (int)DAT_00fe5ac8;
  *(undefined1 *)(DAT_00fe5ac8 + 0xb) = 1;
  *(undefined1 *)((int)DAT_00fe5ac8 + 0x2d) = 1;
  local_8 = CONCAT31(local_8._1_3_,1);
  _DAT_00fe5adc = 0;
  iVar8 = FUN_00891268(0x30);
  if (iVar8 != 0) {
    DAT_00fe5ad8 = iVar8;
    *(int *)iVar8 = iVar8;
    *(int *)(DAT_00fe5ad8 + 4) = DAT_00fe5ad8;
    *(int *)(DAT_00fe5ad8 + 8) = DAT_00fe5ad8;
    *(undefined1 *)(DAT_00fe5ad8 + 0x2c) = 1;
    *(undefined1 *)(DAT_00fe5ad8 + 0x2d) = 1;
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
    goto LAB_0043530f;
  }
  local_38[1] = (int *)0x0;
  ppiVar11 = (int **)((int)local_38 + 4);
LAB_00435337:
  std::exception::exception((exception *)local_4c,(char **)ppiVar11);
  pppuVar15 = local_4c;
  local_4c[0] = std::bad_alloc::vftable;
LAB_00435350:
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(pppuVar15,&DAT_00c857a8);
}

