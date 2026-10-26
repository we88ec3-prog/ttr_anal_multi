
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006bb5d0(void)

{
  char cVar1;
  int *piVar2;
  int **ppiVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  code *pcVar6;
  uint uVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  int **ppiVar13;
  int in_ECX;
  int *piVar14;
  undefined ***pppuVar15;
  undefined **local_58 [3];
  undefined **local_4c [3];
  undefined **local_40 [3];
  undefined **local_34 [3];
  int *local_28;
  int *local_24;
  char *local_20;
  int *local_1c [2];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092bfed;
  local_10 = ExceptionList;
  uVar7 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar10 = *(int *)(*(int *)(in_ECX + 0x90) + 0xcc);
  local_14 = in_ECX;
  if (iVar10 != 0) {
    FUN_006438f0(iVar10);
  }
  local_24 = (int *)(in_ECX + 0x98);
  local_1c[1] = (int *)0x1;
  do {
    piVar14 = local_1c[1];
    piVar12 = *(int **)(*(int *)(in_ECX + 0x90) + 0xcc);
    if ((piVar12 == (int *)0x0) || (piVar2 = (int *)piVar12[0x29], piVar2 == (int *)0x0)) {
LAB_006bb769:
      piVar14 = (int *)0x0;
    }
    else {
      if (piVar12[0x2e] == piVar12[0x2f]) {
        piVar8 = (int *)(**(code **)(*piVar2 + 0x28))();
        local_28 = piVar8;
      }
      else {
        piVar8 = *(int **)(piVar12[0x2f] + -4);
        local_28 = piVar8;
        (**(code **)(*piVar2 + 0x2c))(piVar8,uVar7);
        if (piVar12[0x2e] != piVar12[0x2f]) {
          piVar12[0x2f] = piVar12[0x2f] + -4;
        }
      }
      piVar8[8] = (int)piVar14;
      local_1c[0] = piVar8;
      (**(code **)(*piVar12 + 0x70))(piVar8);
      ppiVar13 = (int **)piVar12[0x2b];
      if (local_1c < ppiVar13) {
        ppiVar3 = (int **)piVar12[0x2a];
        if (local_1c < ppiVar3) goto LAB_006bb6f6;
        if (ppiVar13 == (int **)piVar12[0x2c]) {
          FUN_004deab0();
        }
        if ((undefined4 *)piVar12[0x2b] != (undefined4 *)0x0) {
          *(undefined4 *)piVar12[0x2b] =
               *(undefined4 *)(piVar12[0x2a] + ((int)local_1c - (int)ppiVar3 >> 2) * 4);
        }
      }
      else {
LAB_006bb6f6:
        if (ppiVar13 == (int **)piVar12[0x2c]) {
          FUN_004deab0();
        }
        if ((undefined4 *)piVar12[0x2b] != (undefined4 *)0x0) {
          *(undefined4 *)piVar12[0x2b] = piVar8;
        }
      }
      piVar14 = local_28;
      piVar12[0x2b] = piVar12[0x2b] + 4;
      uVar9 = piVar12[0x39];
      if ((uint)piVar12[0x39] < (int)local_1c[1] + 1U) {
        uVar9 = (int)local_1c[1] + 1U;
      }
      piVar12[0x39] = uVar9;
      iVar10 = (**(code **)(*local_28 + 4))();
      in_ECX = local_14;
      if (iVar10 != 0x12d) {
        MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
        in_ECX = local_14;
        goto LAB_006bb769;
      }
    }
    piVar2 = local_1c[1];
    piVar12 = local_24;
    *local_24 = (int)piVar14;
    (**(code **)(*piVar14 + 0x1a4))(0x323);
    (**(code **)(*(int *)*piVar12 + 0x198))(piVar2);
    local_1c[1] = (int *)((int)piVar2 + 1);
    local_24 = piVar12 + 1;
  } while (local_1c[1] < (int *)0xa);
  iVar10 = *(int *)(*(int *)(in_ECX + 0xbc) + 0xcc);
  if (iVar10 != 0) {
    FUN_00408920(iVar10,5);
  }
  iVar10 = 0;
  local_28 = (int *)(-0xc0 - local_14);
  piVar12 = (int *)(local_14 + 0xc0);
  do {
    iVar11 = *(int *)(*(int *)(local_14 + 0xbc) + 0xcc);
    if ((((iVar11 == 0) || (iVar10 < 0)) ||
        (*(int *)(iVar11 + 0xac) - *(int *)(iVar11 + 0xa8) >> 2 <= iVar10)) ||
       (piVar14 = *(int **)(*(int *)(iVar11 + 0xa8) + (int)local_28 + (int)piVar12),
       piVar14 == (int *)0x0)) {
LAB_006bb833:
      piVar14 = (int *)0x0;
    }
    else {
      iVar11 = (**(code **)(*piVar14 + 4))();
      if (iVar11 != 0x12d) {
        MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
        goto LAB_006bb833;
      }
    }
    *piVar12 = (int)piVar14;
    (**(code **)(*piVar14 + 0x1a4))(0x57b);
    (**(code **)(*(int *)*piVar12 + 0x1a0))();
    iVar10 = iVar10 + 1;
    piVar12 = piVar12 + 1;
  } while (iVar10 < 5);
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0;
    _DAT_00fe5acc = 0;
    piVar12 = (int *)FUN_00891268(0x30);
    if (piVar12 == (int *)0x0) {
      local_1c[0] = (int *)0x0;
      ppiVar13 = local_1c;
LAB_006bb95b:
      std::exception::exception((exception *)local_40,(char **)ppiVar13);
      pppuVar15 = local_40;
      local_40[0] = std::bad_alloc::vftable;
LAB_006bb974:
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(pppuVar15,&DAT_00c857a8);
    }
    DAT_00fe5ac8 = piVar12;
    *piVar12 = (int)piVar12;
    DAT_00fe5ac8[1] = (int)DAT_00fe5ac8;
    DAT_00fe5ac8[2] = (int)DAT_00fe5ac8;
    *(undefined1 *)(DAT_00fe5ac8 + 0xb) = 1;
    *(undefined1 *)((int)DAT_00fe5ac8 + 0x2d) = 1;
    local_8 = CONCAT31(local_8._1_3_,1);
    _DAT_00fe5adc = 0;
    iVar10 = FUN_00891268(0x30);
    if (iVar10 != 0) {
      DAT_00fe5ad8 = iVar10;
      *(int *)iVar10 = iVar10;
      *(int *)(DAT_00fe5ad8 + 4) = DAT_00fe5ad8;
      *(int *)(DAT_00fe5ad8 + 8) = DAT_00fe5ad8;
      *(undefined1 *)(DAT_00fe5ad8 + 0x2c) = 1;
      *(undefined1 *)(DAT_00fe5ad8 + 0x2d) = 1;
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 0xffffffff;
      goto LAB_006bb910;
    }
    local_1c[1] = (int *)0x0;
    ppiVar13 = (int **)((int)local_1c + 4);
LAB_006bb937:
    std::exception::exception((exception *)local_34,(char **)ppiVar13);
    local_34[0] = std::bad_alloc::vftable;
    pppuVar15 = local_34;
    goto LAB_006bb950;
  }
LAB_006bb910:
  cVar1 = *(char *)(DAT_00fe5ac8[1] + 0x2d);
  piVar12 = (int *)DAT_00fe5ac8[1];
  local_28 = DAT_00fe5ac8;
  while (piVar14 = piVar12, cVar1 == '\0') {
    if (piVar14[3] < 0x291) {
      piVar12 = (int *)piVar14[2];
      piVar14 = local_28;
    }
    else {
      piVar12 = (int *)*piVar14;
    }
    cVar1 = *(char *)((int)piVar12 + 0x2d);
    local_28 = piVar14;
  }
  if ((local_28 == DAT_00fe5ac8) || (0x291 < local_28[3])) {
    local_24 = DAT_00fe5ac8;
    ppiVar13 = &local_24;
  }
  else {
    ppiVar13 = &local_28;
  }
  if (*ppiVar13 == DAT_00fe5ac8) {
    pcVar6 = (code *)swi(3);
    (*pcVar6)();
    return;
  }
  FUN_00757710();
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 2;
    _DAT_00fe5acc = 0;
    piVar12 = (int *)FUN_00891268(0x30);
    if (piVar12 == (int *)0x0) {
      local_1c[0] = (int *)0x0;
      std::exception::exception((exception *)local_34,(char **)local_1c);
      pppuVar15 = local_34;
      local_34[0] = std::bad_alloc::vftable;
      goto LAB_006bb974;
    }
    DAT_00fe5ac8 = piVar12;
    *piVar12 = (int)piVar12;
    DAT_00fe5ac8[1] = (int)DAT_00fe5ac8;
    DAT_00fe5ac8[2] = (int)DAT_00fe5ac8;
    *(undefined1 *)(DAT_00fe5ac8 + 0xb) = 1;
    *(undefined1 *)((int)DAT_00fe5ac8 + 0x2d) = 1;
    local_8 = CONCAT31(local_8._1_3_,3);
    _DAT_00fe5adc = 0;
    iVar10 = FUN_00891268(0x30);
    if (iVar10 == 0) {
      local_1c[1] = (int *)0x0;
      ppiVar13 = (int **)((int)local_1c + 4);
      goto LAB_006bb95b;
    }
    DAT_00fe5ad8 = iVar10;
    *(int *)iVar10 = iVar10;
    *(int *)(DAT_00fe5ad8 + 4) = DAT_00fe5ad8;
    *(int *)(DAT_00fe5ad8 + 8) = DAT_00fe5ad8;
    *(undefined1 *)(DAT_00fe5ad8 + 0x2c) = 1;
    *(undefined1 *)(DAT_00fe5ad8 + 0x2d) = 1;
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  cVar1 = *(char *)(DAT_00fe5ac8[1] + 0x2d);
  piVar12 = (int *)DAT_00fe5ac8[1];
  local_28 = DAT_00fe5ac8;
  while (piVar14 = piVar12, cVar1 == '\0') {
    if (piVar14[3] < 0x292) {
      piVar12 = (int *)piVar14[2];
      piVar14 = local_28;
    }
    else {
      piVar12 = (int *)*piVar14;
    }
    cVar1 = *(char *)((int)piVar12 + 0x2d);
    local_28 = piVar14;
  }
  if ((local_28 == DAT_00fe5ac8) || (0x292 < local_28[3])) {
    local_24 = DAT_00fe5ac8;
    ppiVar13 = &local_24;
  }
  else {
    ppiVar13 = &local_28;
  }
  if (*ppiVar13 == DAT_00fe5ac8) {
    pcVar6 = (code *)swi(3);
    (*pcVar6)();
    return;
  }
  FUN_00757710();
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 4;
    _DAT_00fe5acc = 0;
    piVar12 = (int *)FUN_00891268(0x30);
    if (piVar12 == (int *)0x0) {
      local_1c[0] = (int *)0x0;
      ppiVar13 = local_1c;
      goto LAB_006bb937;
    }
    DAT_00fe5ac8 = piVar12;
    *piVar12 = (int)piVar12;
    DAT_00fe5ac8[1] = (int)DAT_00fe5ac8;
    DAT_00fe5ac8[2] = (int)DAT_00fe5ac8;
    *(undefined1 *)(DAT_00fe5ac8 + 0xb) = 1;
    *(undefined1 *)((int)DAT_00fe5ac8 + 0x2d) = 1;
    local_8 = CONCAT31(local_8._1_3_,5);
    _DAT_00fe5adc = 0;
    iVar10 = FUN_00891268(0x30);
    if (iVar10 == 0) {
      local_1c[1] = (int *)0x0;
      std::exception::exception((exception *)local_40,(char **)((int)local_1c + 4));
      pppuVar15 = local_40;
      local_40[0] = std::bad_alloc::vftable;
      goto LAB_006bb974;
    }
    DAT_00fe5ad8 = iVar10;
    *(int *)iVar10 = iVar10;
    *(int *)(DAT_00fe5ad8 + 4) = DAT_00fe5ad8;
    *(int *)(DAT_00fe5ad8 + 8) = DAT_00fe5ad8;
    *(undefined1 *)(DAT_00fe5ad8 + 0x2c) = 1;
    *(undefined1 *)(DAT_00fe5ad8 + 0x2d) = 1;
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  cVar1 = *(char *)(DAT_00fe5ac8[1] + 0x2d);
  piVar12 = (int *)DAT_00fe5ac8[1];
  local_28 = DAT_00fe5ac8;
  while (piVar14 = piVar12, cVar1 == '\0') {
    if (piVar14[3] < 0x293) {
      piVar12 = (int *)piVar14[2];
      piVar14 = local_28;
    }
    else {
      piVar12 = (int *)*piVar14;
    }
    cVar1 = *(char *)((int)piVar12 + 0x2d);
    local_28 = piVar14;
  }
  if ((local_28 == DAT_00fe5ac8) || (0x293 < local_28[3])) {
    local_24 = DAT_00fe5ac8;
    ppiVar13 = &local_24;
  }
  else {
    ppiVar13 = &local_28;
  }
  if (*ppiVar13 == DAT_00fe5ac8) {
    pcVar6 = (code *)swi(3);
    (*pcVar6)();
    return;
  }
  FUN_00757710();
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 6;
    _DAT_00fe5acc = 0;
    piVar12 = (int *)FUN_00891268(0x30);
    if (piVar12 == (int *)0x0) {
      local_1c[0] = (int *)0x0;
      std::exception::exception((exception *)local_34,(char **)local_1c);
      pppuVar15 = local_34;
      local_34[0] = std::bad_alloc::vftable;
      goto LAB_006bb950;
    }
    DAT_00fe5ac8 = piVar12;
    *piVar12 = (int)piVar12;
    DAT_00fe5ac8[1] = (int)DAT_00fe5ac8;
    DAT_00fe5ac8[2] = (int)DAT_00fe5ac8;
    *(undefined1 *)(DAT_00fe5ac8 + 0xb) = 1;
    *(undefined1 *)((int)DAT_00fe5ac8 + 0x2d) = 1;
    local_8 = CONCAT31(local_8._1_3_,7);
    _DAT_00fe5adc = 0;
    iVar10 = FUN_00891268(0x30);
    if (iVar10 == 0) {
      local_1c[1] = (int *)0x0;
      std::exception::exception((exception *)local_40,(char **)((int)local_1c + 4));
      local_40[0] = std::bad_alloc::vftable;
      pppuVar15 = local_40;
      goto LAB_006bb950;
    }
    DAT_00fe5ad8 = iVar10;
    *(int *)iVar10 = iVar10;
    *(int *)(DAT_00fe5ad8 + 4) = DAT_00fe5ad8;
    *(int *)(DAT_00fe5ad8 + 8) = DAT_00fe5ad8;
    *(undefined1 *)(DAT_00fe5ad8 + 0x2c) = 1;
    *(undefined1 *)(DAT_00fe5ad8 + 0x2d) = 1;
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  cVar1 = *(char *)(DAT_00fe5ac8[1] + 0x2d);
  piVar12 = (int *)DAT_00fe5ac8[1];
  local_28 = DAT_00fe5ac8;
  while (piVar14 = piVar12, cVar1 == '\0') {
    if (piVar14[3] < 0x294) {
      piVar12 = (int *)piVar14[2];
      piVar14 = local_28;
    }
    else {
      piVar12 = (int *)*piVar14;
    }
    cVar1 = *(char *)((int)piVar12 + 0x2d);
    local_28 = piVar14;
  }
  if ((local_28 == DAT_00fe5ac8) || (0x294 < local_28[3])) {
    local_24 = DAT_00fe5ac8;
    ppiVar13 = &local_24;
  }
  else {
    ppiVar13 = &local_28;
  }
  if (*ppiVar13 == DAT_00fe5ac8) {
    pcVar6 = (code *)swi(3);
    (*pcVar6)();
    return;
  }
  FUN_00757710();
  if ((DAT_00fe5ae4 & 1) != 0) {
LAB_006bbe80:
    iVar10 = local_14;
    cVar1 = *(char *)(DAT_00fe5ac8[1] + 0x2d);
    piVar12 = (int *)DAT_00fe5ac8[1];
    local_28 = DAT_00fe5ac8;
    while (piVar14 = piVar12, cVar1 == '\0') {
      if (piVar14[3] < 0x295) {
        piVar12 = (int *)piVar14[2];
        piVar14 = local_28;
      }
      else {
        piVar12 = (int *)*piVar14;
      }
      cVar1 = *(char *)((int)piVar12 + 0x2d);
      local_28 = piVar14;
    }
    if ((local_28 == DAT_00fe5ac8) || (0x295 < local_28[3])) {
      local_1c[0] = DAT_00fe5ac8;
      ppiVar13 = local_1c;
    }
    else {
      ppiVar13 = &local_28;
    }
    if (*ppiVar13 == DAT_00fe5ac8) {
      pcVar6 = (code *)swi(3);
      (*pcVar6)();
      return;
    }
    FUN_00757710();
    piVar12 = *(int **)(iVar10 + 0x90);
    puVar4 = (undefined4 *)piVar12[0x19];
    for (puVar5 = (undefined4 *)*puVar4; puVar5 != puVar4; puVar5 = (undefined4 *)*puVar5) {
      iVar10 = puVar5[2];
      if ((*(int *)(iVar10 + 0x60) != 0) && ((*(int **)(iVar10 + 0x1c))[2] != 6)) {
        (**(code **)(**(int **)(iVar10 + 0x1c) + 0x30))(iVar10);
      }
    }
    (**(code **)(*piVar12 + 0x128))();
    piVar12 = *(int **)(local_14 + 0xbc);
    puVar4 = (undefined4 *)piVar12[0x19];
    for (puVar5 = (undefined4 *)*puVar4; puVar5 != puVar4; puVar5 = (undefined4 *)*puVar5) {
      iVar10 = puVar5[2];
      if ((*(int *)(iVar10 + 0x60) != 0) && ((*(int **)(iVar10 + 0x1c))[2] != 6)) {
        (**(code **)(**(int **)(iVar10 + 0x1c) + 0x30))(iVar10);
      }
    }
    (**(code **)(*piVar12 + 0x128))();
    ExceptionList = local_10;
    return;
  }
  DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
  local_8 = 8;
  _DAT_00fe5acc = 0;
  piVar12 = (int *)FUN_00891268(0x30);
  if (piVar12 == (int *)0x0) {
    local_20 = (char *)0x0;
    std::exception::exception((exception *)local_58,&local_20);
    pppuVar15 = local_58;
    local_58[0] = std::bad_alloc::vftable;
  }
  else {
    DAT_00fe5ac8 = piVar12;
    *piVar12 = (int)piVar12;
    DAT_00fe5ac8[1] = (int)DAT_00fe5ac8;
    DAT_00fe5ac8[2] = (int)DAT_00fe5ac8;
    *(undefined1 *)(DAT_00fe5ac8 + 0xb) = 1;
    *(undefined1 *)((int)DAT_00fe5ac8 + 0x2d) = 1;
    local_8 = CONCAT31(local_8._1_3_,9);
    _DAT_00fe5adc = 0;
    iVar10 = FUN_00891268(0x30);
    if (iVar10 != 0) {
      DAT_00fe5ad8 = iVar10;
      *(int *)iVar10 = iVar10;
      *(int *)(DAT_00fe5ad8 + 4) = DAT_00fe5ad8;
      *(int *)(DAT_00fe5ad8 + 8) = DAT_00fe5ad8;
      *(undefined1 *)(DAT_00fe5ad8 + 0x2c) = 1;
      *(undefined1 *)(DAT_00fe5ad8 + 0x2d) = 1;
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 0xffffffff;
      goto LAB_006bbe80;
    }
    local_24 = (int *)0x0;
    std::exception::exception((exception *)local_4c,(char **)&local_24);
    pppuVar15 = local_4c;
    local_4c[0] = std::bad_alloc::vftable;
  }
LAB_006bb950:
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(pppuVar15,&DAT_00c857a8);
}

