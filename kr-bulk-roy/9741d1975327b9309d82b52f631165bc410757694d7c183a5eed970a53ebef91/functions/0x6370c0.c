
undefined4 * FUN_006370c0(undefined4 *param_1)

{
  undefined4 **ppuVar1;
  undefined4 **ppuVar2;
  int *piVar3;
  int *piVar4;
  char **ppcVar5;
  char **ppcVar6;
  uint uVar7;
  int iVar8;
  uint *puVar9;
  uint uVar10;
  undefined1 uVar11;
  undefined4 *puVar12;
  undefined **local_3c [3];
  undefined **local_30 [3];
  char *local_24;
  char *local_20;
  int local_1c;
  undefined4 *local_18;
  undefined1 local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009491fe;
  local_10 = ExceptionList;
  uVar7 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = FUI::CTalkBoxNpc::vftable;
  _memset(param_1 + 3,0,0xa4);
  param_1[0x2e] = 0;
  iVar8 = FUN_00891268(0x18,uVar7);
  if (iVar8 == 0) {
    local_20 = (char *)0x0;
    std::exception::exception((exception *)local_3c,&local_20);
    local_3c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_3c,&DAT_00c857a8);
  }
  param_1[0x2d] = iVar8;
  *(int *)iVar8 = iVar8;
  *(undefined4 *)(param_1[0x2d] + 4) = param_1[0x2d];
  *(undefined4 *)(param_1[0x2d] + 8) = param_1[0x2d];
  *(undefined1 *)(param_1[0x2d] + 0x14) = 1;
  *(undefined1 *)(param_1[0x2d] + 0x15) = 1;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  local_8 = 0;
  param_1[0x34] = 0;
  iVar8 = FUN_00891268(0x24,uVar7);
  if (iVar8 == 0) {
    local_24 = (char *)0x0;
    std::exception::exception((exception *)local_30,&local_24);
    local_30[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_30,&DAT_00c857a8);
  }
  param_1[0x33] = iVar8;
  *(int *)iVar8 = iVar8;
  *(undefined4 *)(param_1[0x33] + 4) = param_1[0x33];
  *(undefined4 *)(param_1[0x33] + 8) = param_1[0x33];
  *(undefined1 *)(param_1[0x33] + 0x20) = 1;
  *(undefined1 *)(param_1[0x33] + 0x21) = 1;
  local_8 = CONCAT31(local_8._1_3_,1);
  *(undefined1 *)(param_1 + 0x5f) = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[0x31] = 3;
  param_1[0x30] = 0;
  local_20 = (char *)0x12;
  local_11 = 7;
  FUN_0063a760(param_1 + 0x32);
  FUN_00443d10();
  iVar8 = 0;
  local_18 = (undefined4 *)0x0;
  local_1c = 2;
  local_20 = (char *)0x3;
  do {
    uVar11 = (undefined1)iVar8;
    local_11 = uVar11;
    puVar9 = (uint *)FUN_0063a820(param_1 + 0x32);
    ppuVar1 = (undefined4 **)puVar9[1];
    if ((&local_18 < ppuVar1) && (ppuVar2 = (undefined4 **)*puVar9, ppuVar2 <= &local_18)) {
      if (ppuVar1 == (undefined4 **)puVar9[2]) {
        FUN_004deab0();
      }
      if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
        *(undefined4 *)puVar9[1] =
             *(undefined4 *)(*puVar9 + ((int)&local_18 - (int)ppuVar2 >> 2) * 4);
      }
    }
    else {
      if (ppuVar1 == (undefined4 **)puVar9[2]) {
        FUN_004deab0();
      }
      if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
        *(undefined4 *)puVar9[1] = 0;
      }
    }
    puVar9[1] = puVar9[1] + 4;
    local_11 = uVar11;
    puVar9 = (uint *)FUN_0063a820(param_1 + 0x32);
    piVar3 = (int *)puVar9[1];
    if (&local_1c < piVar3) {
      piVar4 = (int *)*puVar9;
      if (&local_1c < piVar4) goto LAB_00637298;
      if (piVar3 == (int *)puVar9[2]) {
        FUN_004deab0();
      }
      if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
        *(undefined4 *)puVar9[1] =
             *(undefined4 *)(*puVar9 + ((int)&local_1c - (int)piVar4 >> 2) * 4);
      }
    }
    else {
LAB_00637298:
      if (piVar3 == (int *)puVar9[2]) {
        FUN_004deab0();
      }
      if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
        *(undefined4 *)puVar9[1] = 2;
      }
    }
    puVar9[1] = puVar9[1] + 4;
    local_11 = uVar11;
    puVar9 = (uint *)FUN_0063a820(param_1 + 0x32);
    ppcVar5 = (char **)puVar9[1];
    if (&local_20 < ppcVar5) {
      ppcVar6 = (char **)*puVar9;
      if (&local_20 < ppcVar6) goto LAB_00637301;
      if (ppcVar5 == (char **)puVar9[2]) {
        FUN_004deab0();
      }
      if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
        *(undefined4 *)puVar9[1] =
             *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4);
      }
    }
    else {
LAB_00637301:
      if (ppcVar5 == (char **)puVar9[2]) {
        FUN_004deab0();
      }
      if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
        *(undefined4 *)puVar9[1] = 3;
      }
    }
    puVar9[1] = puVar9[1] + 4;
    iVar8 = iVar8 + 1;
  } while (iVar8 < 0x14);
  puVar12 = param_1 + 0x32;
  local_20 = (char *)0xc;
  local_11 = 1;
  local_18 = puVar12;
  puVar9 = (uint *)FUN_0063a760(puVar12);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (&local_20 < ppcVar6) goto LAB_00637388;
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4)
      ;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  else {
LAB_00637388:
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = 0xc;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  local_20 = (char *)0x4;
  local_11 = 1;
  puVar9 = (uint *)FUN_0063a760(puVar12);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (&local_20 < ppcVar6) goto LAB_006373fb;
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4)
      ;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  else {
LAB_006373fb:
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = 4;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  local_20 = (char *)0x19;
  local_11 = 2;
  puVar9 = (uint *)FUN_0063a760(puVar12);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (&local_20 < ppcVar6) goto LAB_00637468;
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4)
      ;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  else {
LAB_00637468:
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = 0x19;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  local_20 = (char *)0x1a;
  local_11 = 2;
  puVar9 = (uint *)FUN_0063a760(puVar12);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (&local_20 < ppcVar6) goto LAB_006374d9;
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4)
      ;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  else {
LAB_006374d9:
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = 0x1a;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  local_20 = (char *)0x1c;
  local_11 = 2;
  puVar9 = (uint *)FUN_0063a760(puVar12);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (&local_20 < ppcVar6) goto LAB_0063754a;
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4)
      ;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  else {
LAB_0063754a:
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = 0x1c;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  local_20 = (char *)0x17;
  local_11 = 5;
  puVar9 = (uint *)FUN_0063a760(puVar12);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (&local_20 < ppcVar6) goto LAB_006375bb;
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4)
      ;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  else {
LAB_006375bb:
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = 0x17;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  local_20 = (char *)0x4;
  local_11 = 6;
  puVar9 = (uint *)FUN_0063a760(puVar12);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (&local_20 < ppcVar6) goto LAB_00637628;
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4)
      ;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  else {
LAB_00637628:
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = 4;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  local_20 = (char *)0x15;
  local_11 = 6;
  puVar9 = (uint *)FUN_0063a760(puVar12);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (&local_20 < ppcVar6) goto LAB_00637695;
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4)
      ;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  else {
LAB_00637695:
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = 0x15;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  local_20 = (char *)0x16;
  local_11 = 6;
  puVar9 = (uint *)FUN_0063a760(puVar12);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (&local_20 < ppcVar6) goto LAB_00637706;
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4)
      ;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  else {
LAB_00637706:
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = 0x16;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  local_20 = (char *)0x10;
  local_11 = 7;
  puVar9 = (uint *)FUN_0063a760(puVar12);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (&local_20 < ppcVar6) goto LAB_00637777;
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4)
      ;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  else {
LAB_00637777:
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = 0x10;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  local_20 = &DAT_00000011;
  local_11 = 7;
  puVar9 = (uint *)FUN_0063a760(puVar12);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (&local_20 < ppcVar6) goto LAB_006377e8;
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4)
      ;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  else {
LAB_006377e8:
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = 0x11;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  local_20 = (char *)0x13;
  local_11 = 7;
  puVar9 = (uint *)FUN_0063a760(puVar12);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (&local_20 < ppcVar6) goto LAB_00637859;
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4)
      ;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  else {
LAB_00637859:
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = 0x13;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  local_20 = &DAT_00000014;
  local_11 = 7;
  puVar9 = (uint *)FUN_0063a760(puVar12);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (&local_20 < ppcVar6) goto LAB_006378ca;
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4)
      ;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  else {
LAB_006378ca:
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = 0x14;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  local_20 = (char *)0xd;
  local_11 = 8;
  puVar9 = (uint *)FUN_0063a760(puVar12);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (&local_20 < ppcVar6) goto LAB_0063793b;
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4)
      ;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  else {
LAB_0063793b:
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = 0xd;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  local_20 = (char *)0xe;
  local_11 = 8;
  puVar9 = (uint *)FUN_0063a760(puVar12);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (&local_20 < ppcVar6) goto LAB_006379ac;
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4)
      ;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  else {
LAB_006379ac:
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = 0xe;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  local_20 = (char *)0xf;
  local_11 = 8;
  puVar9 = (uint *)FUN_0063a760(puVar12);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (&local_20 < ppcVar6) goto LAB_00637a18;
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4)
      ;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  else {
LAB_00637a18:
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = 0xf;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  local_20 = (char *)0xb;
  local_11 = 9;
  puVar9 = (uint *)FUN_0063a760(local_18);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (&local_20 < ppcVar6) goto LAB_00637a8d;
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4)
      ;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  else {
LAB_00637a8d:
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = 0xb;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  local_20 = (char *)0x20;
  local_11 = 10;
  puVar9 = (uint *)FUN_0063a760(local_18);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (&local_20 < ppcVar6) goto LAB_00637b02;
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4)
      ;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  else {
LAB_00637b02:
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = 0x20;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  local_20 = (char *)0x1e;
  local_11 = 10;
  puVar9 = (uint *)FUN_0063a760(local_18);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (&local_20 < ppcVar6) goto LAB_00637b76;
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4)
      ;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  else {
LAB_00637b76:
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = 0x1e;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  local_20 = (char *)0x4;
  local_11 = 0xb;
  puVar9 = (uint *)FUN_0063a760(local_18);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (&local_20 < ppcVar6) goto LAB_00637be5;
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4)
      ;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  else {
LAB_00637be5:
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = 4;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  local_20 = (char *)0x23;
  local_11 = 0xb;
  puVar9 = (uint *)FUN_0063a760(local_18);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (&local_20 < ppcVar6) goto LAB_00637c54;
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4)
      ;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  else {
LAB_00637c54:
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = 0x23;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  local_20 = (char *)0x24;
  local_11 = 0xb;
  puVar9 = (uint *)FUN_0063a760(local_18);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (&local_20 < ppcVar6) goto LAB_00637cc7;
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4)
      ;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  else {
LAB_00637cc7:
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = 0x24;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  local_20 = (char *)0x27;
  local_11 = 0xb;
  puVar9 = (uint *)FUN_0063a760(local_18);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (&local_20 < ppcVar6) goto LAB_00637d39;
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4)
      ;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  else {
LAB_00637d39:
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = 0x27;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  local_20 = &DAT_0000001d;
  local_11 = 0xc;
  puVar9 = (uint *)FUN_0063a760(local_18);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (&local_20 < ppcVar6) goto LAB_00637da9;
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4)
      ;
    }
  }
  else {
LAB_00637da9:
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = 0x1d;
    }
  }
  puVar9[1] = puVar9[1] + 4;
  local_20 = (char *)0xa;
  local_11 = 0xc;
  puVar9 = (uint *)FUN_0063a760(local_18);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (&local_20 < ppcVar6) goto LAB_00637e1e;
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4)
      ;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  else {
LAB_00637e1e:
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = 10;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  local_20 = (char *)0x4;
  local_11 = 0xc;
  puVar9 = (uint *)FUN_0063a760(local_18);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (&local_20 < ppcVar6) goto LAB_00637e8f;
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4)
      ;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  else {
LAB_00637e8f:
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = 4;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  local_20 = (char *)0x4;
  local_11 = 0xd;
  puVar9 = (uint *)FUN_0063a760(local_18);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (&local_20 < ppcVar6) goto LAB_00637efb;
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4)
      ;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  else {
LAB_00637efb:
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = 4;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  local_20 = (char *)0xa;
  local_11 = 0xd;
  puVar9 = (uint *)FUN_0063a760(local_18);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (&local_20 < ppcVar6) goto LAB_00637f66;
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4)
      ;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  else {
LAB_00637f66:
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = 10;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  puVar12 = local_18;
  local_20 = (char *)0x5;
  local_11 = 0xe;
  puVar9 = (uint *)FUN_0063a760(local_18);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (&local_20 < ppcVar6) goto LAB_00637fdb;
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4)
      ;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  else {
LAB_00637fdb:
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = 5;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  local_20 = (char *)0x6;
  local_11 = 0xe;
  puVar9 = (uint *)FUN_0063a760(puVar12);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (&local_20 < ppcVar6) goto LAB_0063804c;
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4)
      ;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  else {
LAB_0063804c:
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = 6;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  local_20 = (char *)0x7;
  local_11 = 0xe;
  puVar9 = (uint *)FUN_0063a760(puVar12);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (&local_20 < ppcVar6) goto LAB_006380bd;
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4)
      ;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  else {
LAB_006380bd:
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = 7;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  local_20 = (char *)0x8;
  local_11 = 0xe;
  puVar9 = (uint *)FUN_0063a760(puVar12);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (&local_20 < ppcVar6) goto LAB_0063812e;
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4)
      ;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  else {
LAB_0063812e:
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = 8;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  local_20 = (char *)0x9;
  local_11 = 0xe;
  puVar9 = (uint *)FUN_0063a760(puVar12);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (&local_20 < ppcVar6) goto LAB_0063819f;
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4)
      ;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  else {
LAB_0063819f:
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = 9;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  local_20 = (char *)0x4;
  local_11 = 0xe;
  puVar9 = (uint *)FUN_0063a760(puVar12);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (&local_20 < ppcVar6) goto LAB_0063820c;
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4)
      ;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  else {
LAB_0063820c:
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = 4;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  local_20 = (char *)0x1f;
  local_11 = 0xf;
  puVar9 = (uint *)FUN_0063a760(puVar12);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (&local_20 < ppcVar6) goto LAB_00638274;
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4)
      ;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  else {
LAB_00638274:
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = 0x1f;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  local_20 = (char *)0x15;
  local_11 = 0xf;
  puVar9 = (uint *)FUN_0063a760(local_18);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (&local_20 < ppcVar6) goto LAB_006382e0;
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4)
      ;
    }
  }
  else {
LAB_006382e0:
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = 0x15;
    }
  }
  puVar9[1] = puVar9[1] + 4;
  local_20 = (char *)0x15;
  local_11 = 0x10;
  puVar9 = (uint *)FUN_0063a760(local_18);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (&local_20 < ppcVar6) goto LAB_0063834c;
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4)
      ;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  else {
LAB_0063834c:
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = 0x15;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  puVar12 = local_18;
  local_20 = (char *)0x16;
  local_11 = 0x10;
  puVar9 = (uint *)FUN_0063a760(local_18);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (&local_20 < ppcVar6) goto LAB_006383c2;
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4)
      ;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  else {
LAB_006383c2:
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = 0x16;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  local_20 = (char *)0x4;
  local_11 = 0x10;
  puVar9 = (uint *)FUN_0063a760(puVar12);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (&local_20 < ppcVar6) goto LAB_0063842f;
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4)
      ;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  else {
LAB_0063842f:
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = 4;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  local_20 = (char *)0x4;
  local_11 = 0x12;
  puVar9 = (uint *)FUN_0063a760(puVar12);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (&local_20 < ppcVar6) goto LAB_00638498;
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4)
      ;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  else {
LAB_00638498:
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = 4;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  local_20 = &DAT_00000025;
  local_11 = 0x12;
  puVar9 = (uint *)FUN_0063a760(puVar12);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (&local_20 < ppcVar6) goto LAB_00638505;
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4)
      ;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  else {
LAB_00638505:
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = 0x25;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  local_20 = (char *)0x26;
  local_11 = 0x12;
  puVar9 = (uint *)FUN_0063a760(puVar12);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (&local_20 < ppcVar6) goto LAB_00638576;
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4)
      ;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  else {
LAB_00638576:
    if (ppcVar5 == (char **)puVar9[2]) {
      FUN_004deab0();
    }
    if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
      *(undefined4 *)puVar9[1] = 0x26;
    }
    puVar9[1] = puVar9[1] + 4;
  }
  local_20 = &DAT_00000028;
  local_11 = 0x13;
  puVar9 = (uint *)FUN_0063a760(puVar12);
  ppcVar5 = (char **)puVar9[1];
  if (&local_20 < ppcVar5) {
    ppcVar6 = (char **)*puVar9;
    if (ppcVar6 <= &local_20) {
      if (ppcVar5 == (char **)puVar9[2]) {
        FUN_004deab0();
      }
      if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
        *(undefined4 *)puVar9[1] =
             *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4);
      }
      puVar9[1] = puVar9[1] + 4;
      goto LAB_006385fe;
    }
  }
  if (ppcVar5 == (char **)puVar9[2]) {
    FUN_004deab0();
  }
  if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
    *(undefined4 *)puVar9[1] = 0x28;
  }
  puVar9[1] = puVar9[1] + 4;
LAB_006385fe:
  local_1c = 0;
  local_20 = (char *)0x1;
  do {
    iVar8 = local_1c;
    local_11 = (undefined1)local_1c;
    puVar9 = (uint *)FUN_0063a820(param_1 + 0x32);
    ppcVar5 = (char **)puVar9[1];
    if ((&local_20 < ppcVar5) && (ppcVar6 = (char **)*puVar9, ppcVar6 <= &local_20)) {
      if (ppcVar5 == (char **)puVar9[2]) {
        uVar7 = (int)ppcVar5 - (int)ppcVar6 >> 2;
        if (0x3ffffffe < uVar7) {
LAB_0063889e:
                    /* WARNING: Subroutine does not return */
          FUN_0087db30("vector<T> too long");
        }
        uVar7 = uVar7 + 1;
        uVar10 = (int)puVar9[2] - (int)ppcVar6 >> 2;
        if (uVar10 < uVar7) {
          if (0x3fffffff - (uVar10 >> 1) < uVar10) {
            uVar10 = 0;
          }
          else {
            uVar10 = uVar10 + (uVar10 >> 1);
          }
          if (uVar10 < uVar7) {
            uVar10 = uVar7;
          }
          FUN_00797980(uVar10);
          iVar8 = local_1c;
        }
      }
      if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
        *(undefined4 *)puVar9[1] =
             *(undefined4 *)(*puVar9 + ((int)&local_20 - (int)ppcVar6 >> 2) * 4);
      }
    }
    else {
      if (ppcVar5 == (char **)puVar9[2]) {
        uVar7 = (int)((int)ppcVar5 - *puVar9) >> 2;
        if (0x3ffffffe < uVar7) goto LAB_0063889e;
        uVar7 = uVar7 + 1;
        uVar10 = (int)((int)puVar9[2] - *puVar9) >> 2;
        if (uVar10 < uVar7) {
          if (0x3fffffff - (uVar10 >> 1) < uVar10) {
            uVar10 = 0;
          }
          else {
            uVar10 = uVar10 + (uVar10 >> 1);
          }
          if (uVar10 < uVar7) {
            uVar10 = uVar7;
          }
          FUN_00797980(uVar10);
        }
      }
      if ((undefined4 *)puVar9[1] != (undefined4 *)0x0) {
        *(undefined4 *)puVar9[1] = 1;
      }
    }
    puVar9[1] = puVar9[1] + 4;
    local_1c = iVar8 + 1;
    if (0x13 < local_1c) {
      param_1[0x3a] = FUN_006392a0;
      param_1[0x45] = FUN_006392a0;
      param_1[0x49] = FUN_006392a0;
      param_1[0x36] = &LAB_00639260;
      param_1[0x37] = &LAB_00639180;
      param_1[0x38] = &LAB_006391c0;
      param_1[0x39] = &LAB_00639210;
      param_1[0x3b] = &LAB_00639370;
      param_1[0x3c] = &LAB_006393b0;
      param_1[0x3d] = &LAB_006393f0;
      param_1[0x3e] = &LAB_00639430;
      param_1[0x3f] = &LAB_00639470;
      param_1[0x40] = &LAB_006394b0;
      param_1[0x41] = &LAB_006394f0;
      param_1[0x42] = &LAB_00639530;
      param_1[0x43] = &LAB_00639570;
      param_1[0x44] = &LAB_006395b0;
      param_1[0x46] = &LAB_006395f0;
      param_1[0x47] = &LAB_00639630;
      param_1[0x48] = FUN_00639670;
      param_1[0x4a] = &LAB_006397e0;
      param_1[0x4b] = &LAB_00639840;
      param_1[0x4c] = &LAB_00639890;
      param_1[0x4d] = FUN_006398d0;
      param_1[0x4e] = &LAB_00639b50;
      param_1[0x4f] = &LAB_00639ca0;
      param_1[0x50] = &LAB_00639ce0;
      param_1[0x51] = FUN_00639d20;
      param_1[0x52] = &LAB_00639eb0;
      param_1[0x53] = &LAB_00639ef0;
      param_1[0x54] = FUN_00639f30;
      param_1[0x55] = &LAB_0063a0f0;
      param_1[0x56] = &LAB_0063a130;
      param_1[0x57] = FUN_0063a170;
      param_1[0x58] = &LAB_0063a3a0;
      param_1[0x59] = &LAB_0063a3e0;
      param_1[0x5a] = &LAB_0063a420;
      param_1[0x5b] = FUN_0063a460;
      param_1[0x5c] = &LAB_0063a6a0;
      param_1[0x5d] = &LAB_0063a720;
      param_1[0x5e] = &LAB_0063a6e0;
      ExceptionList = local_10;
      return param_1;
    }
  } while( true );
}

