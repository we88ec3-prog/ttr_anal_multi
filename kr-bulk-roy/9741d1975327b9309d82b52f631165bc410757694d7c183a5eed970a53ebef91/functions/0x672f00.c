
void FUN_00672f00(int *param_1)

{
  char cVar1;
  code *pcVar2;
  undefined1 uVar3;
  int iVar4;
  int *piVar5;
  byte *pbVar6;
  char *pcVar7;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  int *in_ECX;
  uint uVar11;
  int unaff_ESI;
  char *pcVar12;
  int unaff_EDI;
  undefined4 local_64;
  int *local_60;
  int *local_5c;
  byte *local_58;
  uint local_54;
  undefined4 local_44;
  uint local_40;
  uint local_38 [4];
  uint local_28;
  uint local_24;
  void *pvStack_20;
  uint local_1c;
  undefined4 uStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00946110;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_64;
  ExceptionList = &local_14;
  if (in_ECX == (int *)0x0) {
    in_ECX = (int *)param_1[0x36];
  }
  local_5c = in_ECX;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffff90);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  if (in_ECX < (int *)0xa) {
    local_58 = (byte *)(-(uint)(*(int *)(DAT_00f94304 + 0x5c + (int)in_ECX * 0x210) != 0) &
                       DAT_00f94304 + (int)in_ECX * 0x210);
  }
  else {
    local_58 = (byte *)0x0;
  }
  if ((DAT_00fdf3d4 & 1) == 0) {
    DAT_00fdf3d4 = DAT_00fdf3d4 | 1;
    local_c = 1;
    FUN_006f4380();
    _atexit((_func_4879 *)&LAB_00bce6d0);
  }
  local_c = 0xffffffff;
  FUN_006f5680();
  if ((*(undefined **)(DAT_00fdf3c8 + 8) == &DAT_00c0bfd8) ||
     (*(int *)(*(undefined **)(DAT_00fdf3c8 + 8) + -8) != 5)) {
    FID_conflict__wprintf("Error UseTable \'%s\'\n","g_CharExplain");
    goto LAB_00673151;
  }
  FUN_006f4f40("GetExplain",1,&DAT_00c0d6dc,local_5c);
  iVar4 = DAT_00fdf3c8;
  iVar8 = *(int *)(DAT_00fdf3c8 + 8);
  local_60 = (int *)(DAT_00fdf3c8 + 8);
  if (*(int *)(iVar8 + -8) == 4) {
LAB_0067307d:
    pcVar12 = (char *)(*(int *)(iVar8 + -0x10) + 0x10);
    if (pcVar12 != (char *)0x0) {
      local_24 = 0xf;
      local_28 = 0;
      local_38[0] = local_38[0] & 0xffffff00;
      pcVar7 = pcVar12;
      do {
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      FUN_00402a70(pcVar12,(int)pcVar7 - (*(int *)(iVar8 + -0x10) + 0x11));
      local_c = 2;
      FUN_004028b0(local_38);
      local_c = CONCAT31(local_c._1_3_,3);
      FUN_00757710();
      if (7 < local_40) {
        FUN_0089120c(local_54);
      }
      local_c = 0xffffffff;
      local_40 = 7;
      local_44 = 0;
      local_54 = local_54 & 0xffff0000;
      if (0xf < local_24) {
        FUN_0089120c(local_38[0]);
      }
      goto LAB_00673151;
    }
  }
  else {
    iVar8 = FUN_006fb5d0();
    if (iVar8 != 0) {
      if (*(uint *)(*(int *)(iVar4 + 0x10) + 0x40) <= *(uint *)(*(int *)(iVar4 + 0x10) + 0x44)) {
        FUN_006fb3a0();
      }
      iVar8 = *local_60;
      goto LAB_0067307d;
    }
  }
  FUN_00757710();
LAB_00673151:
  *(int *)(DAT_00fdf3c8 + 8) = *(int *)(DAT_00fdf3c8 + 8) + -0x10;
  if (local_58 == (byte *)0x0) {
    FUN_00673790(param_1);
    if ((DAT_00f94394 & 1) == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_c = 8;
      FUN_005c3de0();
      _atexit((_func_4879 *)&LAB_00bccc30);
      local_c = 0xffffffff;
    }
    iVar8 = FUN_005c7190();
    piVar5 = local_5c;
    if (iVar8 != 0) {
      local_60 = local_5c;
      FUN_0082ef00(&local_60);
    }
    FUN_00745060();
    if ((DAT_00f94394 & 1) == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_c = 9;
      FUN_005c3de0();
      _atexit((_func_4879 *)&LAB_00bccc30);
      local_c = 0xffffffff;
    }
    iVar8 = FUN_005c7190();
    if (iVar8 != 0) {
      local_60 = piVar5;
      FUN_0082ef00(&local_60);
    }
    FUN_00745060();
    uVar9 = FUN_004ed610();
    local_c = 10;
    FUN_00757800(uVar9);
    local_c = 0xffffffff;
    if (7 < local_40) {
      FUN_0089120c(local_54);
    }
    (**(code **)(*(int *)param_1[0x34] + 0x94))(0);
    (**(code **)(*(int *)param_1[0x35] + 0x94))(1);
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_14 = (void *)0xb;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_14 = (void *)0xffffffff;
    }
    FUN_005740f0(&stack0xffffff98);
    if (unaff_ESI == DAT_00fe5ac8) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    FUN_00757710();
    (**(code **)(*(int *)param_1[0x38] + 200))();
    (**(code **)(*param_1 + 200))();
  }
  else {
    uVar10 = DAT_00f94394 & 1;
    param_1[0x36] = (int)local_5c;
    if (uVar10 == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_c = 4;
      FUN_005c3de0();
      _atexit((_func_4879 *)&LAB_00bccc30);
      local_c = 0xffffffff;
    }
    iVar8 = FUN_005c7190();
    if (iVar8 != 0) {
      local_60 = local_5c;
      FUN_0082ef00(&local_60);
    }
    FUN_00745060();
    (**(code **)(*(int *)param_1[0x32] + 200))();
    uVar9 = FUN_00483f00((&PTR_DAT_00d6a1c4)[(int)local_5c]);
    local_c = 5;
    FUN_00757800(uVar9);
    local_c = 0xffffffff;
    if (7 < local_40) {
      FUN_0089120c(local_54);
    }
    if ((DAT_00f94394 & 1) == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_c = 6;
      FUN_005c3de0();
      _atexit((_func_4879 *)&LAB_00bccc30);
      local_c = 0xffffffff;
    }
    iVar8 = FUN_005c7190();
    if (iVar8 != 0) {
      local_60 = local_5c;
      FUN_0082ef00(&local_60);
    }
    FUN_00745060();
    (**(code **)(*(int *)param_1[0x33] + 200))();
    pbVar6 = local_58;
    FUN_007597b0(0);
    FUN_00757f20();
    FUN_007597b0(0);
    FUN_00757f20();
    FUN_007597b0(0);
    FUN_00757f20();
    FUN_007597b0(0);
    FUN_00757f20();
    FUN_007597b0(0);
    FUN_00757f20();
    FUN_007597b0(0);
    FUN_00757f20();
    FUN_007597b0(0);
    FUN_00757f20();
    uVar11 = 0;
    uVar10 = *(int *)(DAT_00fe1df4 + 0xc) - *(int *)(DAT_00fe1df4 + 8) >> 3;
    if (uVar10 != 0) {
      local_58 = *(byte **)(DAT_00fe1df4 + 8);
      do {
        if (((int *)(uint)*local_58 == local_5c) && (*(int *)(pbVar6 + 8) < (int)(uint)local_58[1]))
        {
          uVar3 = 1;
          goto LAB_0067346c;
        }
        uVar11 = uVar11 + 1;
        local_58 = local_58 + 8;
      } while (uVar11 < uVar10);
    }
    uVar3 = 0;
LAB_0067346c:
    (**(code **)(*(int *)param_1[0x30] + 0x90))(uVar3);
    (**(code **)(*(int *)param_1[0x34] + 0x94))(1);
    (**(code **)(*(int *)param_1[0x35] + 0x94))(0);
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      uStack_18 = 7;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      uStack_18 = 0xffffffff;
    }
    FUN_005740f0(&stack0xffffff94);
    if (unaff_EDI == DAT_00fe5ac8) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    FUN_00757710();
    (**(code **)(*(int *)param_1[0x38] + 200))();
    (**(code **)(*param_1 + 200))();
  }
  ExceptionList = pvStack_20;
  __security_check_cookie(local_28 ^ (uint)&stack0xffffff90);
  return;
}

