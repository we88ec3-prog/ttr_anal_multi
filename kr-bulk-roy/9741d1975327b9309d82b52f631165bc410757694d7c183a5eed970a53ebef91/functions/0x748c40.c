
void FUN_00748c40(int *****param_1)

{
  char cVar1;
  undefined2 uVar2;
  int ****ppppiVar3;
  int iVar4;
  int *****pppppiVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  int *_Str1;
  int ****ppppiVar9;
  char ******ppppppcVar10;
  undefined4 ******ppppppuVar11;
  int *****in_ECX;
  int *piVar12;
  undefined4 *puVar13;
  undefined4 uVar14;
  int *****pppppiStack_bc;
  int *****pppppiStack_b8;
  int *piStack_b4;
  int aiStack_b0 [2];
  int ****local_a8;
  int ****ppppiStack_a4;
  int ****ppppiStack_a0;
  int *****pppppiStack_9c;
  undefined4 *****apppppuStack_90 [4];
  undefined4 uStack_80;
  uint uStack_7c;
  char *****apppppcStack_74 [4];
  undefined4 uStack_64;
  uint uStack_60;
  int *****apppppiStack_58 [5];
  uint uStack_44;
  undefined4 *****apppppuStack_3c [4];
  undefined4 uStack_2c;
  uint uStack_28;
  uint uStack_20;
  uint local_1c;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00920b6b;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&pppppiStack_bc;
  ExceptionList = &local_14;
  local_a8 = (int ****)param_1;
  ppppiVar3 = (int ****)FUN_00764fb0(0,DAT_00d61f20 ^ (uint)&stack0xffffff38);
  in_ECX[8] = ppppiVar3;
  ppppiVar3 = (int ****)FUN_00764fb0(in_ECX[0x12]);
  in_ECX[0x12] = ppppiVar3;
  ppppiVar3 = (int ****)FUN_00764fb0(0);
  in_ECX[10] = ppppiVar3;
  uVar2 = FUN_00765060(*(undefined2 *)(in_ECX + 0x17));
  in_ECX[10] = (int ****)((uint)in_ECX[10] | 3);
  *(undefined2 *)(in_ECX + 0x17) = uVar2;
  (*(code *)(*in_ECX)[0x23])(0);
  if (((uint)in_ECX[10] & 0x8000) != 0) {
    in_ECX[10] = (int ****)((uint)in_ECX[10] ^ 0x8000);
  }
  if (((uint)in_ECX[10] & 0x10000) != 0) {
    in_ECX[10] = (int ****)((uint)in_ECX[10] ^ 0x10000);
  }
  if (((uint)in_ECX[10] & 0x20000) != 0) {
    in_ECX[10] = (int ****)((uint)in_ECX[10] ^ 0x20000);
  }
  FUN_00755d10(param_1);
  FUN_00755d10(param_1);
  FUN_004297b0();
  ppppppuVar11 = (undefined4 ******)apppppuStack_90[0];
  if (uStack_7c < 0x10) {
    ppppppuVar11 = apppppuStack_90;
  }
  iVar4 = FUN_0072e2e0(ppppppuVar11);
  if (0xf < uStack_7c) {
    FUN_0089120c(apppppuStack_90[0]);
  }
  uStack_7c = 0xf;
  uStack_80 = 0;
  apppppuStack_90[0] = (undefined4 *****)((uint)apppppuStack_90[0] & 0xffffff00);
  if (iVar4 != 0) {
    pppppiStack_bc = (int *****)0x0;
    FUN_00429860(&pppppiStack_bc);
    if (in_ECX[7] != (int ****)0x0) {
      (*(code *)(*in_ECX[7])[7])(1);
      in_ECX[7] = (int ****)0x0;
    }
    ppppiVar3 = (int ****)(*(code *)(*in_ECX)[0x19])(pppppiStack_bc);
    in_ECX[7] = ppppiVar3;
    FUN_00429860(&stack0xffffff40);
    pppppiVar5 = (int *****)(*(code *)(*ppppiVar3)[1])();
    if ((pppppiStack_bc != pppppiVar5) || (cVar1 = (*(code *)(*ppppiVar3)[5])(iVar4), cVar1 == '\0')
       ) goto LAB_00749437;
  }
  FUN_004297b0();
  ppppppuVar11 = (undefined4 ******)apppppuStack_90[0];
  if (uStack_7c < 0x10) {
    ppppppuVar11 = apppppuStack_90;
  }
  piStack_b4 = (int *)FUN_0072e2e0(ppppppuVar11);
  if (0xf < uStack_7c) {
    FUN_0089120c(apppppuStack_90[0]);
  }
  uStack_7c = 0xf;
  uStack_80 = 0;
  apppppuStack_90[0] = (undefined4 *****)((uint)apppppuStack_90[0] & 0xffffff00);
  while (piStack_b4 != (int *)0x0) {
    aiStack_b0[0] = 0;
    FUN_00429860(aiStack_b0);
    FUN_004297b0();
    puStack_10 = (undefined1 *)0x0;
    if (uStack_44 < 0x10) {
      pppppiStack_bc = (int *****)apppppiStack_58;
    }
    else {
      pppppiStack_bc = apppppiStack_58[0];
    }
    iVar6 = (**(code **)(*piStack_b4 + 0x14))();
    for (iVar4 = *(int *)(iVar6 + 0x94); iVar4 != iVar6 + 0x44; iVar4 = *(int *)(iVar4 + 0x50)) {
      pcVar8 = (char *)(iVar4 + 0x14);
      if (0xf < *(uint *)(iVar4 + 0x28)) {
        pcVar8 = *(char **)pcVar8;
      }
      iVar7 = __stricmp(pcVar8,(char *)pppppiStack_bc);
      if (iVar7 == 0) {
        if (iVar4 != 0) {
          puVar13 = (undefined4 *)(iVar4 + 0x30);
          if (0xf < *(uint *)(iVar4 + 0x44)) {
            puVar13 = (undefined4 *)*puVar13;
          }
          if (puVar13 != (undefined4 *)0x0) {
            pppppiStack_bc = (int *****)FUN_008917b4(puVar13);
            goto LAB_00748f04;
          }
        }
        break;
      }
    }
    pppppiStack_bc = (int *****)0xffffffff;
LAB_00748f04:
    puStack_10 = (undefined1 *)0xffffffff;
    if (0xf < uStack_44) {
      FUN_0089120c(apppppiStack_58[0]);
    }
    FUN_004297b0();
    puStack_10 = (undefined1 *)0x1;
    if (uStack_44 < 0x10) {
      pppppiStack_b8 = (int *****)apppppiStack_58;
    }
    else {
      pppppiStack_b8 = apppppiStack_58[0];
    }
    iVar6 = (**(code **)(*piStack_b4 + 0x14))();
    for (iVar4 = *(int *)(iVar6 + 0x94); iVar4 != iVar6 + 0x44; iVar4 = *(int *)(iVar4 + 0x50)) {
      pcVar8 = (char *)(iVar4 + 0x14);
      if (0xf < *(uint *)(iVar4 + 0x28)) {
        pcVar8 = *(char **)pcVar8;
      }
      iVar7 = __stricmp(pcVar8,(char *)pppppiStack_b8);
      if (iVar7 == 0) {
        if (iVar4 != 0) {
          puVar13 = (undefined4 *)(iVar4 + 0x30);
          if (0xf < *(uint *)(iVar4 + 0x44)) {
            puVar13 = (undefined4 *)*puVar13;
          }
          if (puVar13 != (undefined4 *)0x0) {
            uVar14 = FUN_008917b4(puVar13);
            goto LAB_00748fc2;
          }
        }
        break;
      }
    }
    uVar14 = 0xffffffff;
LAB_00748fc2:
    puStack_10 = (undefined1 *)0xffffffff;
    if (0xf < uStack_44) {
      FUN_0089120c(apppppiStack_58[0]);
    }
    iVar4 = aiStack_b0[0];
    if (aiStack_b0[0] != -1) {
      pppppiStack_b8 = (int *****)0x0;
      if (((in_ECX[6] != (int ****)0x0) &&
          ((*(code *)(*in_ECX[6])[0x44])(uVar14,aiStack_b0[0],&pppppiStack_b8),
          (int ******)pppppiStack_b8 != (int ******)0x0)) ||
         (pppppiStack_b8 = (int *****)(*(code *)(*in_ECX)[0x18])(iVar4),
         (int ******)pppppiStack_b8 != (int ******)0x0)) {
        piVar12 = piStack_b4;
        pppppiVar5 = pppppiStack_b8;
        pppppiStack_b8[6] = in_ECX[6];
        aiStack_b0[0] = 0;
        FUN_00429860(aiStack_b0);
        iVar4 = (*(code *)(*pppppiVar5)[1])();
        if ((aiStack_b0[0] != iVar4) ||
           (cVar1 = (*(code *)(*pppppiVar5)[5])(piVar12), pppppiVar5 = pppppiStack_b8, cVar1 == '\0'
           )) goto LAB_00749437;
        local_a8 = (int ****)pppppiStack_bc;
        FUN_0082ef00(&local_a8);
        if (ppppiStack_a4 == in_ECX[0x14]) {
          pppppiVar5[0x12] = (int ****)pppppiStack_bc;
          pppppiStack_9c = pppppiVar5;
          pppppiVar5[0x11] = (int ****)in_ECX;
          ppppiStack_a0 = (int ****)pppppiStack_bc;
          uVar14 = FUN_0057ef20();
          FUN_0082f200(in_ECX + 0x13,uVar14);
        }
      }
    }
    FUN_004297b0();
    ppppppcVar10 = (char ******)apppppcStack_74[0];
    if (uStack_60 < 0x10) {
      ppppppcVar10 = apppppcStack_74;
    }
    for (piVar12 = (int *)piStack_b4[0x10]; piVar12 != (int *)0x0; piVar12 = (int *)piVar12[0x10]) {
      _Str1 = piVar12 + 8;
      if (0xf < (uint)piVar12[0xd]) {
        _Str1 = (int *)*_Str1;
      }
      iVar4 = __stricmp((char *)_Str1,(char *)ppppppcVar10);
      if (iVar4 == 0) goto LAB_00749120;
    }
    piVar12 = (int *)0x0;
LAB_00749120:
    if (0xf < uStack_60) {
      FUN_0089120c(apppppcStack_74[0]);
    }
    uStack_60 = 0xf;
    uStack_64 = 0;
    apppppcStack_74[0] = (char *****)((uint)apppppcStack_74[0] & 0xffffff00);
    piStack_b4 = piVar12;
  }
  ppppiVar3 = in_ECX[0x19];
  ppppiVar9 = (int ****)*ppppiVar3;
  *ppppiVar3 = (int ***)ppppiVar3;
  in_ECX[0x19][1] = (int ***)in_ECX[0x19];
  in_ECX[0x1a] = (int ****)0x0;
  if (ppppiVar9 != in_ECX[0x19]) {
    do {
      ppppiVar3 = (int ****)*ppppiVar9;
      FUN_0089120c(ppppiVar9);
      ppppiVar9 = ppppiVar3;
    } while (ppppiVar3 != in_ECX[0x19]);
  }
  FUN_004297b0();
  ppppppcVar10 = (char ******)apppppcStack_74[0];
  if (uStack_60 < 0x10) {
    ppppppcVar10 = apppppcStack_74;
  }
  iVar4 = FUN_0072e2e0(ppppppcVar10);
  if (0xf < uStack_60) {
    FUN_0089120c(apppppcStack_74[0]);
  }
  uStack_60 = 0xf;
  uStack_64 = 0;
  apppppcStack_74[0] = (char *****)((uint)apppppcStack_74[0] & 0xffffff00);
  if (iVar4 != 0) {
    FUN_004297b0();
    ppppppuVar11 = (undefined4 ******)apppppuStack_90[0];
    if (uStack_7c < 0x10) {
      ppppppuVar11 = apppppuStack_90;
    }
    iVar4 = FUN_0072e2e0(ppppppuVar11);
    if (0xf < uStack_7c) {
      FUN_0089120c(apppppuStack_90[0]);
    }
    uStack_7c = 0xf;
    uStack_80 = 0;
    apppppuStack_90[0] = (undefined4 *****)((uint)apppppuStack_90[0] & 0xffffff00);
    while (iVar4 != 0) {
      pppppiStack_bc = (int *****)0xffffffff;
      FUN_00429860(&pppppiStack_bc);
      if (pppppiStack_bc != (int *****)0xffffffff) {
        ppppiStack_a4 = (int ****)pppppiStack_bc;
        FUN_0082ef00(&ppppiStack_a4);
        if (local_a8 == in_ECX[0x14]) {
          ppppiVar3 = (int ****)0x0;
        }
        else {
          ppppiVar3 = (int ****)local_a8[4];
        }
        (*(code *)(*in_ECX)[0x1c])(ppppiVar3);
      }
      FUN_004297b0();
      ppppppcVar10 = (char ******)apppppcStack_74[0];
      if (uStack_60 < 0x10) {
        ppppppcVar10 = apppppcStack_74;
      }
      iVar4 = FUN_0072e320(ppppppcVar10);
      if (0xf < uStack_60) {
        FUN_0089120c(apppppcStack_74[0]);
      }
      uStack_60 = 0xf;
      uStack_64 = 0;
      apppppcStack_74[0] = (char *****)((uint)apppppcStack_74[0] & 0xffffff00);
    }
  }
  FUN_004297b0();
  ppppppuVar11 = (undefined4 ******)apppppuStack_3c[0];
  if (uStack_28 < 0x10) {
    ppppppuVar11 = apppppuStack_3c;
  }
  iVar4 = FUN_0072e2e0(ppppppuVar11);
  if (0xf < uStack_28) {
    FUN_0089120c(apppppuStack_3c[0]);
  }
  piVar12 = (int *)0x0;
  uStack_28 = 0xf;
  uStack_2c = 0;
  apppppuStack_3c[0] = (undefined4 *****)((uint)apppppuStack_3c[0] & 0xffffff00);
  if (iVar4 != 0) {
    if (in_ECX[0xf] != (int ****)0x0) {
      if (((uint)in_ECX[10] & 0x40000) != 0) goto LAB_00749429;
      FUN_00746b80();
      FUN_00746c10();
      if (in_ECX[0xf] != (int ****)0x0) {
        (*(code *)(*in_ECX[0xf])[7])(1);
        in_ECX[0xf] = (int ****)0x0;
      }
    }
    if (((uint)in_ECX[10] & 0x40000) == 0) {
      ppppiStack_a4 = _malloc(0x15c);
      puStack_10 = (undefined1 *)0x2;
      if ((int *****)ppppiStack_a4 != (int *****)0x0) {
        piVar12 = (int *)FUN_00765430();
      }
      puStack_10 = (undefined1 *)0xffffffff;
      cVar1 = FUN_00776c60();
      if (cVar1 == '\0') {
        if (piVar12 != (int *)0x0) {
          (**(code **)(*piVar12 + 0x1c))(1);
        }
        goto LAB_00749437;
      }
      (*(code *)(*in_ECX)[0x14])(piVar12);
    }
  }
LAB_00749429:
  (*(code *)(*in_ECX)[0x45])();
LAB_00749437:
  ExceptionList = pvStack_18;
  __security_check_cookie(uStack_20 ^ (uint)&stack0xffffff40);
  return;
}

