
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00565720(int param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 **ppuVar5;
  undefined4 uVar6;
  undefined4 *****pppppuVar7;
  int iVar8;
  undefined4 *puVar9;
  int unaff_ESI;
  undefined1 auStack_48 [4];
  undefined4 *local_44;
  undefined4 local_40;
  undefined4 *local_3c;
  undefined4 ****local_38 [4];
  undefined4 local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c._0_1_ = 0xff;
  local_c._1_3_ = 0xffffff;
  puStack_10 = &LAB_0093fbe8;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_48;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffffb0;
  ExceptionList = &local_14;
  *(undefined1 *)(unaff_ESI + 0x89) = 1;
  if (*(int *)(unaff_ESI + 0x28) == 0) {
    *(int *)(unaff_ESI + 0x38) = param_1;
    *(int *)(unaff_ESI + 0x3c) = param_2;
    *(undefined4 *)(unaff_ESI + 0x28) = 1;
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 0;
      FUN_00587480(uVar3);
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_c = 1;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
    }
    uVar2 = DAT_00f94390 & 1;
    local_44 = DAT_00f95bbc;
    local_40 = DAT_00f95bc0;
    *(undefined4 **)(unaff_ESI + 0x84) = DAT_00f95bbc;
    if (uVar2 == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 2;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    uVar2 = DAT_00faadd4 & 1;
    *(undefined1 *)(unaff_ESI + 0x88) = DAT_00f942a4;
    if (uVar2 == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 3;
      FUN_00587480(uVar3);
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_c._0_1_ = 0xff;
    local_c._1_3_ = 0xffffff;
    FUN_0058aad0(0xf4358);
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 4;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c._0_1_ = 0xff;
      local_c._1_3_ = 0xffffff;
    }
    DAT_00f942a4 = 1;
    FUN_00402a70(&DAT_00bf2375,0);
    puVar9 = (undefined4 *)(*(undefined4 **)(unaff_ESI + 0xc))[1];
    cVar1 = *(char *)((int)puVar9 + 0x31);
    local_3c = *(undefined4 **)(unaff_ESI + 0xc);
    while (cVar1 == '\0') {
      if (((int)puVar9[3] < param_1) || (((int)puVar9[3] <= param_1 && ((int)puVar9[4] < param_2))))
      {
        puVar4 = (undefined4 *)puVar9[2];
        puVar9 = local_3c;
      }
      else {
        puVar4 = (undefined4 *)*puVar9;
      }
      local_3c = puVar9;
      puVar9 = puVar4;
      cVar1 = *(char *)((int)puVar4 + 0x31);
    }
    puVar9 = *(undefined4 **)(unaff_ESI + 0xc);
    if (((local_3c == puVar9) || (param_1 < (int)local_3c[3])) ||
       ((param_1 <= (int)local_3c[3] && (param_2 < (int)local_3c[4])))) {
      local_44 = puVar9;
      ppuVar5 = &local_44;
    }
    else {
      ppuVar5 = &local_3c;
    }
    puVar4 = *ppuVar5;
    if (puVar4 != puVar9) {
      local_24 = 0xf;
      local_28 = 0;
      local_38[0] = (undefined4 ****)((uint)local_38[0] & 0xffffff00);
      FUN_00402a70("Event/Sequences/",0x10);
      local_c._0_1_ = 5;
      local_c._1_3_ = 0;
      FUN_00401ed0(puVar4 + 5,0,0xffffffff);
      FUN_00401fc0(&DAT_00c106e4,4);
      pppppuVar7 = (undefined4 *****)local_38[0];
      if (local_24 < 0x10) {
        pppppuVar7 = local_38;
      }
      if ((DAT_00fe1ee8 & 1) == 0) {
        DAT_00fe1ee8 = DAT_00fe1ee8 | 1;
        local_c._0_1_ = 6;
        FUN_0055c610();
        _atexit((_func_4879 *)&LAB_00bcf290);
        local_c._0_1_ = 5;
      }
      uVar6 = FUN_0055d6a0(&DAT_00fe1eec,pppppuVar7);
      *(undefined4 *)(unaff_ESI + 0x70) = uVar6;
      pppppuVar7 = (undefined4 *****)local_38[0];
      if (local_24 < 0x10) {
        pppppuVar7 = local_38;
      }
      FUN_006f4a50(pppppuVar7);
      iVar8 = FUN_00434250();
      uVar3 = DAT_00fc0f60 & 1;
      *(undefined4 *)(iVar8 + 0x14) = 0;
      if (uVar3 == 0) {
        DAT_00fc0f60 = DAT_00fc0f60 | 1;
        local_c._0_1_ = 7;
        FUN_0079cf40();
        _atexit((_func_4879 *)&LAB_00bcdb80);
        local_c._0_1_ = 5;
      }
      FUN_0079d9c0(&DAT_00fc0e90,2);
      if ((DAT_00fd94d8 & 1) == 0) {
        DAT_00fd94d8 = DAT_00fd94d8 | 1;
        local_c._0_1_ = 8;
        FUN_007b5430();
        _atexit((_func_4879 *)&LAB_00bce660);
      }
      _DAT_00fd94b0 = 2;
      if (0xf < local_24) {
        FUN_0089120c(local_38[0]);
      }
    }
  }
  else {
    FUN_006edb60(&DAT_00c106ac,param_1,param_2);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_48);
  return;
}

