
void FUN_007d68d0(int param_1)

{
  char cVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  undefined4 uVar10;
  char *pcVar11;
  LPCSTR ****lpText;
  char *pcVar12;
  undefined4 ***unaff_ESI;
  undefined4 ****ppppuVar13;
  undefined4 ***unaff_EDI;
  undefined4 *puVar14;
  undefined4 *puStack_bc;
  undefined4 ****ppppuStack_b8;
  undefined4 *puStack_b4;
  char *pcStack_b0;
  undefined **ppuStack_ac;
  undefined1 *puStack_a8;
  undefined4 uStack_a4;
  int iStack_a0;
  int local_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 ****appppuStack_8c [4];
  undefined4 uStack_7c;
  uint uStack_78;
  undefined4 ****ppppuStack_74;
  undefined4 uStack_70;
  undefined4 uStack_64;
  uint uStack_60;
  uint uStack_5c;
  LPCSTR ***appppCStack_54 [4];
  int iStack_44;
  uint uStack_40;
  undefined1 auStack_3c [28];
  undefined1 uStack_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c._0_1_ = 0xff;
  local_c._1_3_ = 0xffffff;
  puStack_10 = &LAB_00937b67;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&puStack_bc;
  ExceptionList = &local_14;
  local_9c = param_1;
  if (*(int *)(param_1 + 0x7c) != 0) goto LAB_007d722c;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_c = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xffffff38);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_c._0_1_ = 0xff;
  local_c._1_3_ = 0xffffff;
  piVar6 = (int *)(**(code **)(*DAT_00fb76b4 + 0xc))();
  if (piVar6[0x37] - piVar6[0x36] >> 2 == 0) {
    iVar9 = 0;
  }
  else {
    iVar9 = *(int *)piVar6[0x36];
  }
  if (*(int **)(iVar9 + 0x74) == (int *)0x0) {
LAB_007d69b8:
    iVar9 = 0;
  }
  else {
    iVar7 = (**(code **)(**(int **)(iVar9 + 0x74) + 0x24))();
    if (iVar7 == 0) {
      iVar9 = *(int *)(iVar9 + 0x74);
    }
    else {
      iVar7 = (**(code **)(**(int **)(iVar9 + 0x74) + 0x38))();
      if (iVar7 < 1) goto LAB_007d69b8;
      iVar9 = (**(code **)(**(int **)(iVar9 + 0x74) + 0x28))(0);
    }
  }
  ppppuStack_b8 = (undefined4 *****)0x1;
  FUN_008438c0(&ppppuStack_b8);
  if (puStack_b4 == *(undefined4 **)(iVar9 + 0x174)) {
    iVar9 = 0;
  }
  else {
    iVar9 = puStack_b4[4];
  }
  *(undefined4 *)(iVar9 + 0x24) = 0;
  pcVar8 = (char *)(**(code **)(*piVar6 + 0xc))();
  pcStack_b0 = pcVar8;
  (**(code **)*piVar6)(1);
  if (*(int *)(pcVar8 + 0xdc) - *(int *)(pcVar8 + 0xd8) >> 2 == 0) {
    iVar9 = 0;
  }
  else {
    iVar9 = **(int **)(pcVar8 + 0xd8);
  }
  if (*(int **)(iVar9 + 0x74) == (int *)0x0) {
LAB_007d6a5d:
    iVar7 = 0;
  }
  else {
    iVar7 = (**(code **)(**(int **)(iVar9 + 0x74) + 0x24))();
    if (iVar7 == 0) {
      iVar7 = *(int *)(iVar9 + 0x74);
    }
    else {
      iVar7 = (**(code **)(**(int **)(iVar9 + 0x74) + 0x38))();
      if (iVar7 < 1) goto LAB_007d6a5d;
      iVar7 = (**(code **)(**(int **)(iVar9 + 0x74) + 0x28))(0);
    }
  }
  puStack_bc = (undefined4 *)0x1;
  FUN_008438c0(&puStack_bc);
  iVar5 = iStack_a0;
  if ((undefined4 *****)ppppuStack_b8 == *(undefined4 ******)(iVar7 + 0x174)) {
    ppppuVar13 = (undefined4 ****)0x0;
  }
  else {
    ppppuVar13 = (undefined4 ****)ppppuStack_b8[4];
  }
  puVar14 = (undefined4 *)(iStack_a0 + 0x1c);
  uStack_60 = 0xf;
  uStack_64 = 0;
  ppppuStack_74 = (undefined4 ****)((uint)ppppuStack_74 & 0xffffff00);
  FUN_00403040(puVar14,0,0xffffffff);
  puStack_10 = (undefined1 *)0x1;
  puStack_a8 = auStack_3c;
  ppuStack_ac = `long___cdecl_Graphics::GetImageInfoFromFile(char_const*,_D3DXIMAGE_INFO*)'::__l2::
                GetImageInfoFromFileBox::vftable;
  iVar7 = FUN_00737d40();
  if (iVar7 == 0) {
    if (uStack_60 < 0x10) {
      ppppuStack_b8 = &ppppuStack_74;
    }
    else {
      ppppuStack_b8 = ppppuStack_74;
    }
    puStack_bc = puVar14;
    if (0xf < *(uint *)(iVar5 + 0x30)) {
      puStack_bc = (undefined4 *)*puVar14;
    }
    if ((DAT_00fe1ac0 & 1) == 0) {
      DAT_00fe1ac0 = DAT_00fe1ac0 | 1;
      puStack_10._0_1_ = 2;
      FUN_007bb970();
      _atexit((_func_4879 *)&LAB_00bceac0);
      puStack_10 = (undefined1 *)CONCAT31(puStack_10._1_3_,1);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fe1b08);
    (*DAT_00fe1ae8)(puStack_bc,ppppuStack_b8);
    SetEvent(DAT_00fe1b2c);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fe1b08);
    if (*(int *)(puStack_a8 + 0x54) == 0) {
      ppppuVar13[0x17] = (undefined4 ***)0x3f800000;
      ppppuVar13[0x18] = (undefined4 ***)0x3f800000;
      ppppuVar13[0x15] = (undefined4 ***)0x0;
      ppppuVar13[0x16] = (undefined4 ***)0x0;
      FUN_00434740();
      ppppuStack_b8 = (undefined4 ****)FUN_006dd910();
      if (0xf < *(uint *)(iVar5 + 0x30)) {
        puVar14 = (undefined4 *)*puVar14;
      }
      FUN_00434740(puVar14);
      FUN_0079be00(puVar14);
      ppppuVar13[0x2e] = unaff_EDI;
      if (*(int **)(iVar9 + 0x74) == (int *)0x0) {
LAB_007d6d64:
        iVar9 = 0;
      }
      else {
        iVar7 = (**(code **)(**(int **)(iVar9 + 0x74) + 0x24))();
        if (iVar7 == 0) {
          iVar9 = *(int *)(iVar9 + 0x74);
        }
        else {
          iVar7 = (**(code **)(**(int **)(iVar9 + 0x74) + 0x38))();
          if (iVar7 < 1) goto LAB_007d6d64;
          iVar9 = (**(code **)(**(int **)(iVar9 + 0x74) + 0x28))(0);
        }
      }
      pcVar8 = "1s_alphablend";
    }
    else {
      iVar7 = *(int *)(puStack_a8 + 0x58);
      fVar2 = (float)iStack_44;
      puStack_b4 = (undefined4 *)(*(int *)(puStack_a8 + 0x60) - iVar7);
      pcStack_b0 = (char *)(*(int *)(puStack_a8 + 100) - *(int *)(puStack_a8 + 0x5c));
      if (iStack_44 < 0) {
        fVar2 = fVar2 + 4.2949673e+09;
      }
      fVar3 = (float)(int)puStack_b4;
      fVar4 = (float)(int)uStack_40;
      if ((int)uStack_40 < 0) {
        fVar4 = fVar4 + 4.2949673e+09;
      }
      unaff_ESI = (undefined4 ***)((float)(int)pcStack_b0 / fVar4);
      ppppuStack_b8 = (undefined4 ****)((float)*(int *)(puStack_a8 + 0x5c) / fVar4);
      ppppuVar13[0x17] = (undefined4 ***)(fVar3 / fVar2);
      ppppuVar13[0x18] = unaff_ESI;
      ppppuVar13[0x15] = (undefined4 ***)((float)iVar7 / fVar2);
      ppppuVar13[0x16] = ppppuStack_b8;
      FUN_00434740();
      ppppuStack_b8 = (undefined4 ****)FUN_006dd910();
      if (0xf < *(uint *)(iVar5 + 0x30)) {
        puVar14 = (undefined4 *)*puVar14;
      }
      FUN_00434740(puVar14);
      FUN_0079be00(puVar14);
      ppppuVar13[0x2e] = (undefined4 ***)(fVar3 / fVar2);
      if (*(int **)(iVar9 + 0x74) == (int *)0x0) {
LAB_007d6ce7:
        iVar9 = 0;
        pcVar8 = "offset_alphablendmap";
      }
      else {
        iVar7 = (**(code **)(**(int **)(iVar9 + 0x74) + 0x24))();
        if (iVar7 == 0) {
          iVar9 = *(int *)(iVar9 + 0x74);
          pcVar8 = "offset_alphablendmap";
        }
        else {
          iVar7 = (**(code **)(**(int **)(iVar9 + 0x74) + 0x38))();
          if (iVar7 < 1) goto LAB_007d6ce7;
          iVar9 = (**(code **)(**(int **)(iVar9 + 0x74) + 0x28))(0);
          pcVar8 = "offset_alphablendmap";
        }
      }
    }
    puVar14 = (undefined4 *)(*(code *)(*ppppuStack_b8)[0x28])(&stack0xffffff38,pcVar8);
    *(undefined4 *)(iVar9 + 0x164) = *puVar14;
    iVar9 = FUN_00891268(0xe8);
    uStack_20 = 3;
    if (iVar9 == 0) {
      uVar10 = 0;
    }
    else {
      uVar10 = FUN_0077ebb0();
    }
    pcVar8 = pcStack_b0;
    uStack_20 = 1;
    *(undefined4 *)(pcStack_b0 + 0x68) = uVar10;
    FUN_00402a70("BB_instance",0xb);
    (**(code **)(**(int **)(pcVar8 + 0x68) + 0x40))(unaff_ESI);
    pcVar12 = pcVar8;
    if (0xf < *(uint *)(pcVar8 + 0x14)) {
      pcVar12 = *(char **)pcVar8;
    }
    uStack_78 = 0xf;
    uStack_7c = 0;
    appppuStack_8c[0] = (undefined4 ****)((uint)appppuStack_8c[0] & 0xffffff00);
    pcVar11 = pcVar12;
    do {
      cVar1 = *pcVar11;
      pcVar11 = pcVar11 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(pcVar12,(int)pcVar11 - (int)(pcVar12 + 1));
    local_c._0_1_ = 4;
    FUN_00401fc0(&DAT_00c07bfc,4);
    puStack_bc = (undefined4 *)FUN_00891268(0xb4);
    local_c._0_1_ = 5;
    if (puStack_bc == (undefined4 *)0x0) {
      uVar10 = 0;
    }
    else if (*(uint *)(pcVar8 + 0x14) < 0x10) {
      uVar10 = FUN_007f1650(*(undefined4 *)(pcVar8 + 0x68));
    }
    else {
      uVar10 = FUN_007f1650(*(undefined4 *)(pcVar8 + 0x68));
    }
    if ((DAT_00fe1770 & 1) == 0) {
      DAT_00fe1770 = DAT_00fe1770 | 1;
      local_c._0_1_ = 6;
      FUN_007b7da0();
      _atexit((_func_4879 *)&LAB_00bce790);
    }
    local_c._0_1_ = 4;
    FUN_007dc660(uVar10);
    puStack_bc = (undefined4 *)FUN_00891268(0xb4);
    local_c._0_1_ = 7;
    if (puStack_bc == (undefined4 *)0x0) {
      uVar10 = 0;
    }
    else {
      uVar10 = FUN_007f15b0(0);
    }
    if ((DAT_00fe1770 & 1) == 0) {
      DAT_00fe1770 = DAT_00fe1770 | 1;
      local_c._0_1_ = 8;
      FUN_007b7da0();
      _atexit((_func_4879 *)&LAB_00bce790);
    }
    local_c = CONCAT31(local_c._1_3_,4);
    FUN_007dc660(uVar10);
    iVar9 = FUN_00891268(0x8c);
    if (iVar9 == 0) {
      pcStack_b0 = (char *)0x0;
    }
    else {
      pcStack_b0 = (char *)FUN_007dcee0();
    }
    puStack_bc = (undefined4 *)FUN_00891268(0x68);
    local_c._0_1_ = 9;
    if (puStack_bc == (undefined4 *)0x0) {
      puStack_bc = (undefined4 *)0x0;
    }
    else {
      puStack_a8 = (undefined1 *)0x0;
      uStack_a4 = 0;
      iStack_a0 = 0;
      pcVar12 = pcVar8;
      if (0xf < *(uint *)(pcVar8 + 0x14)) {
        pcVar12 = *(char **)pcVar8;
      }
      puStack_bc = (undefined4 *)
                   FUN_007d6790(pcVar12,0,*(undefined4 *)(pcVar8 + 0x78),
                                *(undefined4 *)(pcVar8 + 0x6c),*(undefined4 *)(pcVar8 + 0x70),
                                *(undefined4 *)(pcVar8 + 0x74),0,0,0,1,0,0x3f800000);
    }
    pcVar12 = pcStack_b0;
    local_c._0_1_ = 4;
    FUN_007bb350();
    puStack_bc = (undefined4 *)FUN_00891268(0x68);
    local_c._0_1_ = 10;
    if (puStack_bc == (undefined4 *)0x0) {
      puStack_bc = (undefined4 *)0x0;
    }
    else {
      puStack_a8 = (undefined1 *)0x0;
      piVar6 = (int *)(pcVar8 + 0x38);
      uStack_a4 = 0;
      iStack_a0 = 0;
      uStack_98 = 0;
      uStack_94 = 0;
      uStack_90 = 0;
      if (0xf < *(uint *)(pcVar8 + 0x4c)) {
        piVar6 = (int *)*piVar6;
      }
      puStack_bc = (undefined4 *)FUN_007d6790(piVar6,0,0x3f800000,0,0,0,0,0,0,1,0,0x3f800000);
      pcVar12 = pcStack_b0;
    }
    local_c._0_1_ = 4;
    FUN_007bb350();
    pcVar12[0x48] = '\0';
    pcVar12[0x49] = '\0';
    pcVar12[0x4a] = -0x10;
    pcVar12[0x4b] = 'A';
    if (uStack_78 < 0x10) {
      ppppuStack_b8 = appppuStack_8c;
    }
    else {
      ppppuStack_b8 = appppuStack_8c[0];
    }
    if ((DAT_00fe1770 & 1) == 0) {
      DAT_00fe1770 = DAT_00fe1770 | 1;
      local_c._0_1_ = 0xb;
      FUN_007b7da0();
      _atexit((_func_4879 *)&LAB_00bce790);
      local_c._0_1_ = 4;
    }
    iVar9 = FUN_007b82d0(&DAT_00fe173c,pcVar12);
    if (iVar9 == 0) {
      uStack_40 = 0xf;
      appppCStack_54[0] = (LPCSTR ***)((uint)appppCStack_54[0] & 0xffffff00);
      iStack_44 = iVar9;
      FUN_00402a70("Crate Name Collision has occured : Name: ",0x29);
      local_c._0_1_ = 0xc;
      FUN_00401ed0(pcVar8,0,0xffffffff);
      FUN_00401fc0(" File: ",7);
      FUN_00401ed0(appppuStack_8c,0,0xffffffff);
      lpText = (LPCSTR ****)appppCStack_54[0];
      if (uStack_40 < 0x10) {
        lpText = appppCStack_54;
      }
      MessageBoxA((HWND)0x0,(LPCSTR)lpText,&DAT_00c50214,0);
      if (0xf < uStack_40) {
        FUN_0089120c(appppCStack_54[0]);
      }
    }
    pcVar8[0x7c] = '\x02';
    pcVar8[0x7d] = '\0';
    pcVar8[0x7e] = '\0';
    pcVar8[0x7f] = '\0';
    if (0xf < uStack_78) {
      FUN_0089120c(appppuStack_8c[0]);
    }
    uStack_78 = 0xf;
    uStack_7c = 0;
    appppuStack_8c[0] = (undefined4 ****)((uint)appppuStack_8c[0] & 0xffffff00);
  }
  else {
    (**(code **)*puStack_b4)(1);
  }
  if (0xf < uStack_5c) {
    FUN_0089120c(uStack_70);
  }
LAB_007d722c:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&puStack_bc);
  return;
}

