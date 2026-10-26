
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006b3fe0(void)

{
  char cVar1;
  undefined4 *puVar2;
  code *pcVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  int **ppiVar8;
  int in_ECX;
  int iVar9;
  int *piVar10;
  undefined4 *puVar11;
  undefined **local_25c [3];
  undefined **local_250 [3];
  undefined **local_244 [3];
  undefined **local_238 [3];
  int *local_22c;
  int local_228;
  int *local_224;
  int *local_220;
  int *local_21c;
  int *local_218;
  undefined1 local_214 [512];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092c1d7;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_228 = in_ECX;
  FUN_00755e50(local_14);
  FUN_006b57d0();
  FUN_00458240(2000);
  local_22c = (int *)(in_ECX + 0x18c);
  FUN_00458240(3000);
  FUN_00615fc0(4000);
  FUN_00615fc0(5000);
  FUN_00615fc0(6000);
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 0;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_8 = 0xffffffff;
  }
  local_218 = (int *)0x0;
  FUN_0082ef00(&local_218);
  iVar4 = 0;
  puVar11 = (undefined4 *)(in_ECX + 0x168);
  do {
    iVar4 = iVar4 + 1;
    FUN_0040aeb0(L"BotCha%02d",iVar4);
    uVar5 = FUN_00763360(local_214);
    *puVar11 = uVar5;
    puVar11 = puVar11 + 1;
  } while (iVar4 < 9);
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 1;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_8 = 0xffffffff;
  }
  local_218 = (int *)&DAT_0000002c;
  FUN_0082ef00(&local_218);
  iVar4 = 0;
  puVar11 = (undefined4 *)(local_228 + 0x1a8);
  do {
    iVar4 = iVar4 + 1;
    FUN_0040aeb0(L"ChaLadder%02d",iVar4);
    uVar5 = FUN_00763360(local_214);
    iVar9 = local_228;
    *puVar11 = uVar5;
    puVar11 = puVar11 + 1;
  } while (iVar4 < 9);
  local_218 = (int *)(local_228 + 0xf8);
  if (*(int *)(*local_218 + 0xcc) != 0) {
    FUN_00408920(*(int *)(*local_218 + 0xcc),9);
  }
  iVar4 = 0;
  local_21c = (int *)(-0x120 - iVar9);
  piVar7 = (int *)(iVar9 + 0x120);
  do {
    iVar9 = *(int *)(*local_218 + 0xcc);
    if (((iVar9 == 0) || (iVar4 < 0)) ||
       (*(int *)(iVar9 + 0xac) - *(int *)(iVar9 + 0xa8) >> 2 <= iVar4)) {
      iVar9 = 0;
    }
    else {
      iVar9 = *(int *)((int)local_21c + (int)piVar7 + *(int *)(iVar9 + 0xa8));
    }
    piVar7[-9] = iVar9;
    FUN_0046b6f0(0x834);
    FUN_0043c570(0x898);
    iVar9 = *piVar7;
    FUN_007444b0(0xbf6b);
    *(undefined1 *)(iVar9 + 0xa4) = 1;
    iVar9 = *piVar7;
    if (((*(char *)(iVar9 + 0xa4) != '\0') && (*(int **)(iVar9 + 0x94) != (int *)0x0)) &&
       (iVar6 = (**(code **)(**(int **)(iVar9 + 0x94) + 4))(), iVar6 == 0xbf6b)) {
      *(undefined1 *)(*(int *)(iVar9 + 0x94) + 0x4c) = 1;
    }
    iVar4 = iVar4 + 1;
    piVar7 = piVar7 + 1;
  } while (iVar4 < 9);
  piVar7 = (int *)*local_218;
  puVar11 = (undefined4 *)piVar7[0x19];
  for (puVar2 = (undefined4 *)*puVar11; puVar2 != puVar11; puVar2 = (undefined4 *)*puVar2) {
    iVar4 = puVar2[2];
    if ((*(int *)(iVar4 + 0x60) != 0) && ((*(int **)(iVar4 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar4 + 0x1c) + 0x30))(iVar4);
    }
  }
  (**(code **)(*piVar7 + 0x128))();
  if (*(int *)(*local_22c + 0xcc) != 0) {
    FUN_00408920(*(int *)(*local_22c + 0xcc),3);
  }
  iVar4 = 0;
  local_218 = (int *)(-0x19c - local_228);
  piVar7 = (int *)(local_228 + 0x19c);
  do {
    iVar9 = *(int *)(*local_22c + 0xcc);
    if (((iVar9 == 0) || (iVar4 < 0)) ||
       (*(int *)(iVar9 + 0xac) - *(int *)(iVar9 + 0xa8) >> 2 <= iVar4)) {
      iVar9 = 0;
    }
    else {
      iVar9 = *(int *)((int)local_218 + (int)piVar7 + *(int *)(iVar9 + 0xa8));
    }
    piVar7[-3] = iVar9;
    FUN_0046b6f0(0xc1c);
    iVar9 = *piVar7;
    FUN_007444b0(0xbf6b);
    *(undefined1 *)(iVar9 + 0xa4) = 1;
    iVar9 = *piVar7;
    if (((*(char *)(iVar9 + 0xa4) != '\0') && (*(int **)(iVar9 + 0x94) != (int *)0x0)) &&
       (iVar6 = (**(code **)(**(int **)(iVar9 + 0x94) + 4))(), iVar6 == 0xbf6b)) {
      *(undefined1 *)(*(int *)(iVar9 + 0x94) + 0x4c) = 1;
    }
    iVar4 = iVar4 + 1;
    piVar7 = piVar7 + 1;
  } while (iVar4 < 3);
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 2;
    _DAT_00fe5acc = 0;
    piVar7 = (int *)FUN_00891268(0x30);
    if (piVar7 == (int *)0x0) goto LAB_006b44ce;
    DAT_00fe5ac8 = piVar7;
    *piVar7 = (int)piVar7;
    DAT_00fe5ac8[1] = (int)DAT_00fe5ac8;
    DAT_00fe5ac8[2] = (int)DAT_00fe5ac8;
    *(undefined1 *)(DAT_00fe5ac8 + 0xb) = 1;
    *(undefined1 *)((int)DAT_00fe5ac8 + 0x2d) = 1;
    local_8 = CONCAT31(local_8._1_3_,3);
    _DAT_00fe5adc = 0;
    iVar4 = FUN_00891268(0x30);
    if (iVar4 == 0) {
      local_220 = (int *)0x0;
      std::exception::exception((exception *)local_238,(char **)&local_220);
      local_238[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_238,&DAT_00c857a8);
    }
    DAT_00fe5ad8 = iVar4;
    *(int *)iVar4 = iVar4;
    *(int *)(DAT_00fe5ad8 + 4) = DAT_00fe5ad8;
    *(int *)(DAT_00fe5ad8 + 8) = DAT_00fe5ad8;
    *(undefined1 *)(DAT_00fe5ad8 + 0x2c) = 1;
    *(undefined1 *)(DAT_00fe5ad8 + 0x2d) = 1;
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  cVar1 = *(char *)(DAT_00fe5ac8[1] + 0x2d);
  piVar7 = (int *)DAT_00fe5ac8[1];
  local_218 = DAT_00fe5ac8;
  while (piVar10 = piVar7, cVar1 == '\0') {
    if (piVar10[3] < 0x232) {
      piVar7 = (int *)piVar10[2];
      piVar10 = local_218;
    }
    else {
      piVar7 = (int *)*piVar10;
    }
    cVar1 = *(char *)((int)piVar7 + 0x2d);
    local_218 = piVar10;
  }
  if ((local_218 == DAT_00fe5ac8) || (0x232 < local_218[3])) {
    local_21c = DAT_00fe5ac8;
    ppiVar8 = &local_21c;
  }
  else {
    ppiVar8 = &local_218;
  }
  if (*ppiVar8 == DAT_00fe5ac8) {
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  FUN_00757710();
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 4;
    _DAT_00fe5acc = 0;
    piVar7 = (int *)FUN_00891268(0x30);
    if (piVar7 == (int *)0x0) {
      local_220 = (int *)0x0;
      std::exception::exception((exception *)local_238,(char **)&local_220);
      local_238[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_238,&DAT_00c857a8);
    }
    DAT_00fe5ac8 = piVar7;
    *piVar7 = (int)piVar7;
    DAT_00fe5ac8[1] = (int)DAT_00fe5ac8;
    DAT_00fe5ac8[2] = (int)DAT_00fe5ac8;
    *(undefined1 *)(DAT_00fe5ac8 + 0xb) = 1;
    *(undefined1 *)((int)DAT_00fe5ac8 + 0x2d) = 1;
    local_8 = CONCAT31(local_8._1_3_,5);
    _DAT_00fe5adc = 0;
    iVar4 = FUN_00891268(0x30);
    if (iVar4 == 0) {
LAB_006b44ce:
      local_224 = (int *)0x0;
      std::exception::exception((exception *)local_244,(char **)&local_224);
      local_244[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_244,&DAT_00c857a8);
    }
    DAT_00fe5ad8 = iVar4;
    *(int *)iVar4 = iVar4;
    *(int *)(DAT_00fe5ad8 + 4) = DAT_00fe5ad8;
    *(int *)(DAT_00fe5ad8 + 8) = DAT_00fe5ad8;
    *(undefined1 *)(DAT_00fe5ad8 + 0x2c) = 1;
    *(undefined1 *)(DAT_00fe5ad8 + 0x2d) = 1;
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  cVar1 = *(char *)(DAT_00fe5ac8[1] + 0x2d);
  piVar7 = (int *)DAT_00fe5ac8[1];
  local_218 = DAT_00fe5ac8;
  while (piVar10 = piVar7, cVar1 == '\0') {
    if (piVar10[3] < 0x233) {
      piVar7 = (int *)piVar10[2];
      piVar10 = local_218;
    }
    else {
      piVar7 = (int *)*piVar10;
    }
    cVar1 = *(char *)((int)piVar7 + 0x2d);
    local_218 = piVar10;
  }
  if ((local_218 == DAT_00fe5ac8) || (0x233 < local_218[3])) {
    local_21c = DAT_00fe5ac8;
    ppiVar8 = &local_21c;
  }
  else {
    ppiVar8 = &local_218;
  }
  if (*ppiVar8 == DAT_00fe5ac8) {
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  FUN_00757710();
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 6;
    _DAT_00fe5acc = 0;
    piVar7 = (int *)FUN_00891268(0x30);
    if (piVar7 == (int *)0x0) {
      local_21c = (int *)0x0;
      std::exception::exception((exception *)local_25c,(char **)&local_21c);
      local_25c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_25c,&DAT_00c857a8);
    }
    DAT_00fe5ac8 = piVar7;
    *piVar7 = (int)piVar7;
    DAT_00fe5ac8[1] = (int)DAT_00fe5ac8;
    DAT_00fe5ac8[2] = (int)DAT_00fe5ac8;
    *(undefined1 *)(DAT_00fe5ac8 + 0xb) = 1;
    *(undefined1 *)((int)DAT_00fe5ac8 + 0x2d) = 1;
    local_8 = CONCAT31(local_8._1_3_,7);
    _DAT_00fe5adc = 0;
    iVar4 = FUN_00891268(0x30);
    if (iVar4 == 0) {
      local_218 = (int *)0x0;
      std::exception::exception((exception *)local_250,(char **)&local_218);
      local_250[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_250,&DAT_00c857a8);
    }
    DAT_00fe5ad8 = iVar4;
    *(int *)iVar4 = iVar4;
    *(int *)(DAT_00fe5ad8 + 4) = DAT_00fe5ad8;
    *(int *)(DAT_00fe5ad8 + 8) = DAT_00fe5ad8;
    *(undefined1 *)(DAT_00fe5ad8 + 0x2c) = 1;
    *(undefined1 *)(DAT_00fe5ad8 + 0x2d) = 1;
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  cVar1 = *(char *)(DAT_00fe5ac8[1] + 0x2d);
  piVar7 = (int *)DAT_00fe5ac8[1];
  local_220 = DAT_00fe5ac8;
  while (piVar10 = piVar7, cVar1 == '\0') {
    if (piVar10[3] < 0x234) {
      piVar7 = (int *)piVar10[2];
      piVar10 = local_220;
    }
    else {
      piVar7 = (int *)*piVar10;
    }
    cVar1 = *(char *)((int)piVar7 + 0x2d);
    local_220 = piVar10;
  }
  if ((local_220 == DAT_00fe5ac8) || (0x234 < local_220[3])) {
    local_224 = DAT_00fe5ac8;
    ppiVar8 = &local_224;
  }
  else {
    ppiVar8 = &local_220;
  }
  if (*ppiVar8 == DAT_00fe5ac8) {
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  FUN_00757710();
  piVar7 = (int *)*local_22c;
  puVar11 = (undefined4 *)piVar7[0x19];
  for (puVar2 = (undefined4 *)*puVar11; puVar2 != puVar11; puVar2 = (undefined4 *)*puVar2) {
    iVar4 = puVar2[2];
    if ((*(int *)(iVar4 + 0x60) != 0) && ((*(int **)(iVar4 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar4 + 0x1c) + 0x30))(iVar4);
    }
  }
  (**(code **)(*piVar7 + 0x128))();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

