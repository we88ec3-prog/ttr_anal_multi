
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004bd820(int param_1)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  undefined4 *puVar4;
  int in_ECX;
  int iVar5;
  char *pcVar6;
  undefined4 *puVar7;
  uint uVar8;
  int *piVar9;
  undefined4 *puVar10;
  uint uVar11;
  char *local_4c;
  char *pcStack_48;
  int local_44;
  undefined **appuStack_40 [3];
  undefined4 uStack_34;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00947ad8;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (*(char *)(param_1 + 2) != '\x01') {
    local_4c = (char *)CONCAT22(local_4c._2_2_,0x19);
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,&local_4c,2);
    }
    ExceptionList = local_14;
    return 0x80004005;
  }
  local_4c = (char *)(param_1 + 4);
  local_44 = in_ECX;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffffa8);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_c = 0xffffffff;
  piVar9 = (int *)*DAT_00fab13c;
  if (piVar9 != DAT_00fab13c) {
    do {
      piVar1 = (int *)piVar9[4];
      cVar3 = (char)(short)piVar1[1];
      if ((cVar3 == '\0') || (cVar3 == '\x01')) {
        (**(code **)(piVar1[0x3c] + 8))(1);
      }
      piVar2 = DAT_00fba7a4;
      *(ushort *)((int)piVar1 + 0xe2) = *(ushort *)((int)piVar1 + 0xe2) & 0x7fff;
      (**(code **)(*piVar2 + 0x20))();
      piVar1[0x38] = piVar1[0x38];
      iVar5 = piVar1[0x39];
      *(char *)(piVar1 + 0x39) = (char)iVar5;
      (**(code **)(*piVar1 + 0x58))((char)iVar5);
      if (*(char *)((int)piVar9 + 0x15) == '\0') {
        piVar1 = (int *)piVar9[2];
        if (*(char *)((int)piVar1 + 0x15) == '\0') {
          cVar3 = *(char *)(*piVar1 + 0x15);
          piVar9 = piVar1;
          piVar1 = (int *)*piVar1;
          while (cVar3 == '\0') {
            cVar3 = *(char *)(*piVar1 + 0x15);
            piVar9 = piVar1;
            piVar1 = (int *)*piVar1;
          }
        }
        else {
          cVar3 = *(char *)(piVar9[1] + 0x15);
          piVar2 = (int *)piVar9[1];
          piVar1 = piVar9;
          while ((piVar9 = piVar2, cVar3 == '\0' && (piVar1 == (int *)piVar9[2]))) {
            cVar3 = *(char *)(piVar9[1] + 0x15);
            piVar2 = (int *)piVar9[1];
            piVar1 = piVar9;
          }
        }
      }
    } while (piVar9 != DAT_00fab13c);
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 1;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = 0xffffffff;
  }
  if (DAT_00faadec == 0xb) {
    FUN_0058a9a0();
  }
  else {
    _DAT_00faadf0 = 0xb;
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 2;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = 0xffffffff;
  }
  puVar4 = (undefined4 *)FUN_00891268(0x34);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    pcVar6 = local_4c;
    puVar7 = &uStack_34;
    for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar7 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      puVar7 = puVar7 + 1;
    }
    cVar3 = *(char *)(param_1 + 3);
    *(undefined2 *)puVar7 = *(undefined2 *)pcVar6;
    *(char *)((int)puVar7 + 2) = pcVar6[2];
    puVar4[5] = (int)cVar3;
    puVar7 = &uStack_34;
    puVar10 = puVar4 + 6;
    for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar10 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar10 = puVar10 + 1;
    }
    *(undefined2 *)puVar10 = *(undefined2 *)puVar7;
    puVar4[1] = 0xffffffff;
    puVar4[2] = 0xffffffff;
    puVar4[3] = 0;
    puVar4[4] = 0xf429c;
    *puVar4 = FUI::FXUIDuelDecisionDesc::vftable;
    *(undefined1 *)((int)puVar10 + 2) = *(undefined1 *)((int)puVar7 + 2);
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_c = 3;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_c = 0xffffffff;
  }
  if (((DAT_00f95c78 + DAT_00f95c7c & 3U) == 0) && (DAT_00f95c74 <= DAT_00f95c7c + 4U >> 2)) {
    FUN_00636f70(&DAT_00f95c6c);
  }
  uVar11 = DAT_00f95c78 + DAT_00f95c7c;
  uVar8 = uVar11 >> 2;
  if (DAT_00f95c74 <= uVar8) {
    uVar8 = uVar8 - DAT_00f95c74;
  }
  if (*(int *)(DAT_00f95c70 + uVar8 * 4) == 0) {
    iVar5 = FUN_00891268(0x10);
    if (iVar5 == 0) {
      pcStack_48 = (char *)0x0;
      std::exception::exception((exception *)appuStack_40,&pcStack_48);
      appuStack_40[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(appuStack_40,&DAT_00c857a8);
    }
    *(int *)(DAT_00f95c70 + uVar8 * 4) = iVar5;
  }
  puVar7 = (undefined4 *)(*(int *)(DAT_00f95c70 + uVar8 * 4) + (uVar11 & 3) * 4);
  if (puVar7 != (undefined4 *)0x0) {
    *puVar7 = puVar4;
  }
  DAT_00f95c7c = DAT_00f95c7c + 1;
  *(undefined4 *)(local_44 + 0xbfa8) = *(undefined4 *)(local_4c + 1);
  FUN_004ba8c0(*local_4c == '\x01');
  *(undefined4 *)(local_44 + 0x5eb4) = 1;
  ExceptionList = local_14;
  return 0;
}

