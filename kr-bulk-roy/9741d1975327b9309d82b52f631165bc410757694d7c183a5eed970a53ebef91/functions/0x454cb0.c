
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00454cb0(void)

{
  char cVar1;
  int **ppiVar2;
  undefined4 *puVar3;
  code *pcVar4;
  int iVar5;
  int *piVar6;
  char *pcVar7;
  int iVar8;
  int *piVar9;
  int **ppiVar10;
  undefined2 *puVar11;
  int in_ECX;
  int *piVar12;
  int iVar13;
  undefined4 *puVar14;
  uint uVar15;
  undefined **local_58 [3];
  undefined **local_4c [3];
  undefined **local_40 [3];
  undefined **local_34 [3];
  int *local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  char *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009319fb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = in_ECX;
  FUN_00755e50(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_00458240(1000);
  FUN_00615fc0(3000);
  FUN_00615fc0(4000);
  FUN_00458240(5000);
  FUN_0043c570(0x960);
  FUN_0043c570(0x9c4);
  FUN_0043c570(0xa28);
  FUN_0043c570(0x8fc);
  local_18 = (char *)(in_ECX + 0xfc);
  iVar13 = 6000;
  do {
    pcVar7 = local_18;
    FUN_006c09c0(iVar13);
    iVar8 = *(int *)pcVar7;
    FUN_0046b6f0(iVar13 + 100);
    iVar5 = *(int *)(iVar8 + 0x24c);
    FUN_007444b0(0xbf6b);
    *(undefined1 *)(iVar5 + 0xa4) = 1;
    iVar8 = *(int *)(iVar8 + 0x24c);
    if (((*(char *)(iVar8 + 0xa4) != '\0') && (*(int **)(iVar8 + 0x94) != (int *)0x0)) &&
       (iVar5 = (**(code **)(**(int **)(iVar8 + 0x94) + 4))(), iVar5 == 0xbf6b)) {
      *(undefined1 *)(*(int *)(iVar8 + 0x94) + 0x4c) = 1;
    }
    iVar8 = local_14;
    local_18 = (char *)((int)local_18 + 4);
    iVar13 = iVar13 + 1000;
  } while (iVar13 < 9000);
  iVar13 = *(int *)(*(int *)(local_14 + 0x118) + 0xcc);
  if (iVar13 != 0) {
    FUN_006438f0(iVar13);
  }
  local_24 = (int *)(iVar8 + 0x124);
  local_18 = (char *)0x1;
  do {
    pcVar7 = local_18;
    piVar9 = *(int **)(*(int *)(iVar8 + 0x118) + 0xcc);
    if ((piVar9 == (int *)0x0) || (piVar12 = (int *)piVar9[0x29], piVar12 == (int *)0x0)) {
LAB_00454f66:
      piVar12 = (int *)0x0;
    }
    else {
      if (piVar9[0x2e] == piVar9[0x2f]) {
        piVar6 = (int *)(**(code **)(*piVar12 + 0x28))();
        local_28 = piVar6;
      }
      else {
        piVar6 = *(int **)(piVar9[0x2f] + -4);
        local_28 = piVar6;
        (**(code **)(*piVar12 + 0x2c))(piVar6);
        if (piVar9[0x2e] != piVar9[0x2f]) {
          piVar9[0x2f] = piVar9[0x2f] + -4;
        }
      }
      piVar6[8] = (int)pcVar7;
      local_1c = piVar6;
      (**(code **)(*piVar9 + 0x70))(piVar6);
      ppiVar10 = (int **)piVar9[0x2b];
      if (&local_1c < ppiVar10) {
        ppiVar2 = (int **)piVar9[0x2a];
        if (&local_1c < ppiVar2) goto LAB_00454ef9;
        if (ppiVar10 == (int **)piVar9[0x2c]) {
          FUN_004deab0();
        }
        if ((undefined4 *)piVar9[0x2b] != (undefined4 *)0x0) {
          *(undefined4 *)piVar9[0x2b] =
               *(undefined4 *)(piVar9[0x2a] + ((int)&local_1c - (int)ppiVar2 >> 2) * 4);
        }
      }
      else {
LAB_00454ef9:
        if (ppiVar10 == (int **)piVar9[0x2c]) {
          FUN_004deab0();
        }
        if ((undefined4 *)piVar9[0x2b] != (undefined4 *)0x0) {
          *(undefined4 *)piVar9[0x2b] = piVar6;
        }
      }
      piVar12 = local_28;
      piVar9[0x2b] = piVar9[0x2b] + 4;
      pcVar7 = (char *)piVar9[0x39];
      if ((char *)piVar9[0x39] < local_18 + 1) {
        pcVar7 = local_18 + 1;
      }
      piVar9[0x39] = (int)pcVar7;
      iVar13 = (**(code **)(*local_28 + 4))();
      if (iVar13 != 0x12d) {
        MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
        goto LAB_00454f66;
      }
    }
    pcVar7 = local_18;
    piVar9 = local_24;
    *local_24 = (int)piVar12;
    (**(code **)(*piVar12 + 0x1a4))(0x3eb);
    (**(code **)(*(int *)*piVar9 + 0x198))(pcVar7);
    local_18 = pcVar7 + 1;
    local_24 = piVar9 + 1;
    iVar8 = local_14;
  } while (local_18 < (char *)0xa);
  local_28 = (int *)(local_14 + 0x11c);
  if (*(int *)(*local_28 + 0xcc) != 0) {
    FUN_00408920(*(int *)(*local_28 + 0xcc),3);
  }
  iVar13 = 0;
  piVar9 = (int *)(local_14 + 0x148);
  local_24 = (int *)(-0x148 - local_14);
  local_20 = piVar9;
  do {
    iVar8 = *(int *)(*local_28 + 0xcc);
    if (((iVar8 == 0) || (iVar13 < 0)) ||
       ((*(int *)(iVar8 + 0xac) - *(int *)(iVar8 + 0xa8) >> 2 <= iVar13 ||
        (piVar12 = *(int **)((int)local_24 + (int)piVar9 + *(int *)(iVar8 + 0xa8)),
        piVar12 == (int *)0x0)))) {
LAB_00455034:
      piVar12 = (int *)0x0;
    }
    else {
      iVar8 = (**(code **)(*piVar12 + 4))();
      if (iVar8 != 0x12d) {
        MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
        goto LAB_00455034;
      }
    }
    *piVar9 = (int)piVar12;
    (**(code **)(*piVar12 + 0x1a0))(0x138b);
    (**(code **)(*(int *)*piVar9 + 0x19c))();
    iVar13 = iVar13 + 1;
    piVar9 = piVar9 + 1;
    if (2 < iVar13) {
      if ((DAT_00fe5ae4 & 1) == 0) {
        DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
        local_8 = 0;
        _DAT_00fe5acc = 0;
        piVar9 = (int *)FUN_00891268(0x30);
        if (piVar9 == (int *)0x0) {
          local_1c = (int *)0x0;
          std::exception::exception((exception *)local_40,(char **)&local_1c);
          local_40[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
          __CxxThrowException_8(local_40,&DAT_00c857a8);
        }
        DAT_00fe5ac8 = piVar9;
        *piVar9 = (int)piVar9;
        DAT_00fe5ac8[1] = (int)DAT_00fe5ac8;
        DAT_00fe5ac8[2] = (int)DAT_00fe5ac8;
        *(undefined1 *)(DAT_00fe5ac8 + 0xb) = 1;
        *(undefined1 *)((int)DAT_00fe5ac8 + 0x2d) = 1;
        local_8 = CONCAT31(local_8._1_3_,1);
        _DAT_00fe5adc = 0;
        iVar13 = FUN_00891268(0x30);
        if (iVar13 == 0) {
          local_18 = (char *)0x0;
          std::exception::exception((exception *)local_34,&local_18);
          local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
          __CxxThrowException_8(local_34,&DAT_00c857a8);
        }
        DAT_00fe5ad8 = iVar13;
        *(int *)iVar13 = iVar13;
        *(int *)(DAT_00fe5ad8 + 4) = DAT_00fe5ad8;
        *(int *)(DAT_00fe5ad8 + 8) = DAT_00fe5ad8;
        *(undefined1 *)(DAT_00fe5ad8 + 0x2c) = 1;
        *(undefined1 *)(DAT_00fe5ad8 + 0x2d) = 1;
        _atexit((_func_4879 *)&LAB_00bcf390);
        local_8 = 0xffffffff;
      }
      cVar1 = *(char *)(DAT_00fe5ac8[1] + 0x2d);
      piVar9 = (int *)DAT_00fe5ac8[1];
      local_28 = DAT_00fe5ac8;
      while (piVar12 = piVar9, cVar1 == '\0') {
        if (piVar12[3] < 0x291) {
          piVar9 = (int *)piVar12[2];
          piVar12 = local_28;
        }
        else {
          piVar9 = (int *)*piVar12;
        }
        cVar1 = *(char *)((int)piVar9 + 0x2d);
        local_28 = piVar12;
      }
      if ((local_28 == DAT_00fe5ac8) || (0x291 < local_28[3])) {
        local_24 = DAT_00fe5ac8;
        ppiVar10 = &local_24;
      }
      else {
        ppiVar10 = &local_28;
      }
      if (*ppiVar10 == DAT_00fe5ac8) {
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      FUN_00757710();
      if ((DAT_00fe5ae4 & 1) == 0) {
        DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
        local_8 = 2;
        _DAT_00fe5acc = 0;
        piVar9 = (int *)FUN_00891268(0x30);
        if (piVar9 == (int *)0x0) {
          local_1c = (int *)0x0;
          std::exception::exception((exception *)local_34,(char **)&local_1c);
          local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
          __CxxThrowException_8(local_34,&DAT_00c857a8);
        }
        DAT_00fe5ac8 = piVar9;
        *piVar9 = (int)piVar9;
        DAT_00fe5ac8[1] = (int)DAT_00fe5ac8;
        DAT_00fe5ac8[2] = (int)DAT_00fe5ac8;
        *(undefined1 *)(DAT_00fe5ac8 + 0xb) = 1;
        *(undefined1 *)((int)DAT_00fe5ac8 + 0x2d) = 1;
        local_8 = CONCAT31(local_8._1_3_,3);
        _DAT_00fe5adc = 0;
        iVar13 = FUN_00891268(0x30);
        if (iVar13 == 0) {
          local_18 = (char *)0x0;
          std::exception::exception((exception *)local_40,&local_18);
          local_40[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
          __CxxThrowException_8(local_40,&DAT_00c857a8);
        }
        DAT_00fe5ad8 = iVar13;
        *(int *)iVar13 = iVar13;
        *(int *)(DAT_00fe5ad8 + 4) = DAT_00fe5ad8;
        *(int *)(DAT_00fe5ad8 + 8) = DAT_00fe5ad8;
        *(undefined1 *)(DAT_00fe5ad8 + 0x2c) = 1;
        *(undefined1 *)(DAT_00fe5ad8 + 0x2d) = 1;
        _atexit((_func_4879 *)&LAB_00bcf390);
        local_8 = 0xffffffff;
      }
      cVar1 = *(char *)(DAT_00fe5ac8[1] + 0x2d);
      piVar9 = (int *)DAT_00fe5ac8[1];
      local_28 = DAT_00fe5ac8;
      while (piVar12 = piVar9, cVar1 == '\0') {
        if (piVar12[3] < 0x292) {
          piVar9 = (int *)piVar12[2];
          piVar12 = local_28;
        }
        else {
          piVar9 = (int *)*piVar12;
        }
        cVar1 = *(char *)((int)piVar9 + 0x2d);
        local_28 = piVar12;
      }
      if ((local_28 == DAT_00fe5ac8) || (0x292 < local_28[3])) {
        local_24 = DAT_00fe5ac8;
        ppiVar10 = &local_24;
      }
      else {
        ppiVar10 = &local_28;
      }
      if (*ppiVar10 == DAT_00fe5ac8) {
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      FUN_00757710();
      if ((DAT_00fe5ae4 & 1) == 0) {
        DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
        local_8 = 4;
        _DAT_00fe5acc = 0;
        piVar9 = (int *)FUN_00891268(0x30);
        if (piVar9 == (int *)0x0) {
          local_20 = (int *)0x0;
          std::exception::exception((exception *)local_58,(char **)&local_20);
          local_58[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
          __CxxThrowException_8(local_58,&DAT_00c857a8);
        }
        DAT_00fe5ac8 = piVar9;
        *piVar9 = (int)piVar9;
        DAT_00fe5ac8[1] = (int)DAT_00fe5ac8;
        DAT_00fe5ac8[2] = (int)DAT_00fe5ac8;
        *(undefined1 *)(DAT_00fe5ac8 + 0xb) = 1;
        *(undefined1 *)((int)DAT_00fe5ac8 + 0x2d) = 1;
        local_8 = CONCAT31(local_8._1_3_,5);
        _DAT_00fe5adc = 0;
        iVar13 = FUN_00891268(0x30);
        if (iVar13 == 0) {
          local_24 = (int *)0x0;
          std::exception::exception((exception *)local_4c,(char **)&local_24);
          local_4c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
          __CxxThrowException_8(local_4c,&DAT_00c857a8);
        }
        DAT_00fe5ad8 = iVar13;
        *(int *)iVar13 = iVar13;
        *(int *)(DAT_00fe5ad8 + 4) = DAT_00fe5ad8;
        *(int *)(DAT_00fe5ad8 + 8) = DAT_00fe5ad8;
        *(undefined1 *)(DAT_00fe5ad8 + 0x2c) = 1;
        *(undefined1 *)(DAT_00fe5ad8 + 0x2d) = 1;
        _atexit((_func_4879 *)&LAB_00bcf390);
        local_8 = 0xffffffff;
      }
      iVar13 = local_14;
      cVar1 = *(char *)(DAT_00fe5ac8[1] + 0x2d);
      piVar9 = (int *)DAT_00fe5ac8[1];
      local_28 = DAT_00fe5ac8;
      while (piVar12 = piVar9, cVar1 == '\0') {
        if (piVar12[3] < 0x293) {
          piVar9 = (int *)piVar12[2];
          piVar12 = local_28;
        }
        else {
          piVar9 = (int *)*piVar12;
        }
        cVar1 = *(char *)((int)piVar9 + 0x2d);
        local_28 = piVar12;
      }
      if ((local_28 == DAT_00fe5ac8) || (0x293 < local_28[3])) {
        local_1c = DAT_00fe5ac8;
        ppiVar10 = &local_1c;
      }
      else {
        ppiVar10 = &local_28;
      }
      if (*ppiVar10 == DAT_00fe5ac8) {
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      FUN_00757710();
      piVar9 = *(int **)(iVar13 + 0x118);
      puVar14 = (undefined4 *)piVar9[0x19];
      for (puVar3 = (undefined4 *)*puVar14; puVar3 != puVar14; puVar3 = (undefined4 *)*puVar3) {
        iVar13 = puVar3[2];
        if ((*(int *)(iVar13 + 0x60) != 0) && ((*(int **)(iVar13 + 0x1c))[2] != 6)) {
          (**(code **)(**(int **)(iVar13 + 0x1c) + 0x30))(iVar13);
        }
      }
      (**(code **)(*piVar9 + 0x128))();
      piVar9 = *(int **)(local_14 + 0x11c);
      puVar14 = (undefined4 *)piVar9[0x19];
      for (puVar3 = (undefined4 *)*puVar14; puVar3 != puVar14; puVar3 = (undefined4 *)*puVar3) {
        iVar13 = puVar3[2];
        if ((*(int *)(iVar13 + 0x60) != 0) && ((*(int **)(iVar13 + 0x1c))[2] != 6)) {
          (**(code **)(**(int **)(iVar13 + 0x1c) + 0x30))(iVar13);
        }
      }
      (**(code **)(*piVar9 + 0x128))();
      uVar15 = 0;
      local_28 = (int *)(-0xfc - local_14);
      puVar14 = (undefined4 *)(local_14 + 0xfc);
      do {
        if (uVar15 < (uint)(*(int *)(local_14 + 0x184) - *(int *)(local_14 + 0x180) >> 2)) {
          puVar11 = (undefined2 *)(*(int *)(local_14 + 0x180) + (int)local_28 + (int)puVar14);
        }
        else {
          puVar11 = (undefined2 *)0x0;
        }
        FUN_004547a0(*puVar14,*puVar11);
        (**(code **)(*(int *)*puVar14 + 200))();
        uVar15 = uVar15 + 1;
        puVar14 = puVar14 + 1;
      } while ((int)uVar15 < 3);
      ExceptionList = local_10;
      return;
    }
  } while( true );
}

