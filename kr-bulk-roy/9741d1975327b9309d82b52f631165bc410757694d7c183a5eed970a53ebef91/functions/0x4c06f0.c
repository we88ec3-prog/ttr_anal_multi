
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004c06f0(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int iVar10;
  int in_ECX;
  undefined4 *puVar11;
  int *piVar12;
  uint local_34;
  undefined4 *local_30;
  char *pcStack_2c;
  int local_28;
  undefined **appuStack_24 [4];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00947a84;
  local_14 = ExceptionList;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xffffffc0;
  ExceptionList = &local_14;
  if (*(char *)(param_1 + 2) != '\x04') {
    local_34 = CONCAT22(local_34._2_2_,0x19);
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,&local_34,2);
    }
    ExceptionList = local_14;
    return 0x80004005;
  }
  if (param_2 - 4U < 5) {
    uVar7 = 0;
  }
  else {
    uVar7 = param_2 - 9U >> 3;
  }
  local_28 = in_ECX;
  if (uVar7 != 0) {
    puVar9 = (undefined4 *)(param_1 + 9);
    local_34 = uVar7;
    do {
      if ((DAT_00faadd4 & 1) == 0) {
        DAT_00faadd4 = DAT_00faadd4 | 1;
        local_c = 0;
        FUN_00587480(uVar6);
        _atexit((_func_4879 *)&LAB_00bcccc0);
        local_c = 0xffffffff;
      }
      puVar8 = (undefined4 *)FUN_00891268(0x1c);
      puVar11 = (undefined4 *)0x0;
      if (puVar8 != (undefined4 *)0x0) {
        uVar1 = puVar9[1];
        uVar2 = *puVar9;
        puVar8[3] = 0;
        puVar8[1] = 0xffffffff;
        puVar8[2] = 0xffffffff;
        puVar8[4] = 0xf429e;
        *puVar8 = FoxUI::FXUIEventI2::vftable;
        puVar8[5] = uVar2;
        puVar8[6] = uVar1;
        puVar11 = puVar8;
      }
      if ((DAT_00faadd0 & 1) == 0) {
        DAT_00faadd0 = DAT_00faadd0 | 1;
        local_c = 1;
        FUN_0074d990();
        _atexit((_func_4879 *)&LAB_00bccc70);
        local_c = 0xffffffff;
      }
      local_30 = puVar11;
      FUN_00804260(&local_30);
      puVar9 = puVar9 + 2;
      local_34 = local_34 - 1;
    } while (local_34 != 0);
    local_34 = 0;
  }
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 2;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    local_c = 0xffffffff;
  }
  piVar12 = (int *)*DAT_00fab13c;
  if (piVar12 != DAT_00fab13c) {
    do {
      piVar3 = (int *)piVar12[4];
      cVar5 = (char)(short)piVar3[1];
      if ((cVar5 == '\0') || (cVar5 == '\x01')) {
        (**(code **)(piVar3[0x3c] + 8))(1);
      }
      *(ushort *)((int)piVar3 + 0xe2) = *(ushort *)((int)piVar3 + 0xe2) & 0x7fff;
      (**(code **)(*DAT_00fba7a4 + 0x20))();
      piVar3[0x38] = piVar3[0x38];
      iVar10 = piVar3[0x39];
      *(char *)(piVar3 + 0x39) = (char)iVar10;
      (**(code **)(*piVar3 + 0x58))((char)iVar10);
      if (*(char *)((int)piVar12 + 0x15) == '\0') {
        piVar3 = (int *)piVar12[2];
        if (*(char *)((int)piVar3 + 0x15) == '\0') {
          cVar5 = *(char *)(*piVar3 + 0x15);
          piVar12 = piVar3;
          piVar3 = (int *)*piVar3;
          while (cVar5 == '\0') {
            cVar5 = *(char *)(*piVar3 + 0x15);
            piVar12 = piVar3;
            piVar3 = (int *)*piVar3;
          }
        }
        else {
          cVar5 = *(char *)(piVar12[1] + 0x15);
          piVar4 = (int *)piVar12[1];
          piVar3 = piVar12;
          while ((piVar12 = piVar4, cVar5 == '\0' && (piVar3 == (int *)piVar12[2]))) {
            cVar5 = *(char *)(piVar12[1] + 0x15);
            piVar4 = (int *)piVar12[1];
            piVar3 = piVar12;
          }
        }
      }
    } while (piVar12 != DAT_00fab13c);
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 3;
    FUN_00587480(uVar6);
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = 0xffffffff;
  }
  if (DAT_00faadec == 0xc) {
    FUN_0058a9a0();
  }
  else {
    _DAT_00faadf0 = 0xc;
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 4;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = 0xffffffff;
  }
  puVar9 = (undefined4 *)FUN_00891268(0x1c);
  if (puVar9 == (undefined4 *)0x0) {
    puVar9 = (undefined4 *)0x0;
  }
  else {
    cVar5 = *(char *)(param_1 + 4);
    uVar1 = *(undefined4 *)(param_1 + 5);
    puVar9[1] = 0xffffffff;
    puVar9[2] = 0xffffffff;
    puVar9[3] = 0;
    puVar9[4] = 0xf429d;
    *puVar9 = FoxUI::FXUIEventI2::vftable;
    puVar9[5] = (int)cVar5;
    puVar9[6] = uVar1;
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_c = 5;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_c = 0xffffffff;
  }
  if (((DAT_00f95c78 + DAT_00f95c7c & 3U) == 0) && (DAT_00f95c74 <= DAT_00f95c7c + 4U >> 2)) {
    FUN_00636f70(&DAT_00f95c6c);
  }
  uVar7 = DAT_00f95c78 + DAT_00f95c7c;
  uVar6 = uVar7 >> 2;
  if (DAT_00f95c74 <= uVar6) {
    uVar6 = uVar6 - DAT_00f95c74;
  }
  if (*(int *)(DAT_00f95c70 + uVar6 * 4) == 0) {
    iVar10 = FUN_00891268(0x10);
    if (iVar10 == 0) {
      pcStack_2c = (char *)0x0;
      std::exception::exception((exception *)appuStack_24,&pcStack_2c);
      appuStack_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(appuStack_24,&DAT_00c857a8);
    }
    *(int *)(DAT_00f95c70 + uVar6 * 4) = iVar10;
  }
  puVar11 = (undefined4 *)(*(int *)(DAT_00f95c70 + uVar6 * 4) + (uVar7 & 3) * 4);
  if (puVar11 != (undefined4 *)0x0) {
    *puVar11 = puVar9;
  }
  DAT_00f95c7c = DAT_00f95c7c + 1;
  FUN_004ba8c0(*(char *)(param_1 + 4) == '\x01');
  *(undefined4 *)(local_28 + 0x5eb4) = 1;
  ExceptionList = local_14;
  return 0;
}

