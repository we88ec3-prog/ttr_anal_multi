
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00672570(int *param_1,int param_2)

{
  short sVar1;
  code *pcVar2;
  int iVar3;
  short *psVar4;
  undefined4 uVar5;
  wchar_t *_Src;
  short *psVar6;
  undefined2 local_74 [8];
  undefined4 local_64;
  undefined4 local_60;
  undefined1 **ppuStack_5c;
  undefined1 auStack_58 [16];
  undefined4 uStack_48;
  undefined1 *local_20;
  undefined1 *local_1c;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093cf1c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  iVar3 = *(int *)(param_2 + 0x14);
  if (iVar3 == 1) {
    iVar3 = param_1[0x3c];
    if (*(char *)(iVar3 + 0x141) != '\0') {
      FUN_006edb10();
    }
    if (*(uint *)(iVar3 + 0x11c) < 8) {
      _Src = (wchar_t *)(iVar3 + 0x108);
    }
    else {
      _Src = *(wchar_t **)(iVar3 + 0x108);
    }
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 0;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c = 0xffffffff;
    }
    uStack_48 = 0x672626;
    _wcsncpy_s(&DAT_00f938f2,0x15,_Src,0x14);
    (**(code **)(*param_1 + 0xd4))();
    ExceptionList = local_14;
    return;
  }
  if (iVar3 == -1) {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 1;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_c = 0xffffffff;
    iVar3 = FUN_005854b0();
    FUN_005740f0();
    if (local_20 == *(undefined1 **)(iVar3 + 4)) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    local_1c = auStack_58;
    ppuStack_5c = (undefined1 **)0x6726d5;
    FUN_004068f0();
    local_c = 2;
    local_20 = (undefined1 *)0x2;
    ppuStack_5c = (undefined1 **)0x6726e7;
    iVar3 = FUN_005854b0();
    ppuStack_5c = &local_20;
    local_60 = 0x6726f9;
    FUN_005740f0();
    if (*(int *)(iVar3 + 4) == 0x1ba) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    psVar6 = (short *)&DAT_000001ca;
    if (7 < _DAT_000001de) {
      psVar6 = _DAT_000001ca;
    }
    local_20 = (undefined1 *)local_74;
    local_60 = 7;
    local_64 = 0;
    local_74[0] = 0;
    psVar4 = psVar6;
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar6,(int)psVar4 - (int)(psVar6 + 1) >> 1);
  }
  else {
    if (iVar3 != -2) {
      if (iVar3 == -3) {
        FUN_004054c0();
        local_20 = auStack_58;
        local_1c = auStack_58;
        ppuStack_5c = (undefined1 **)0x1ba;
        local_60 = 0x67283a;
        FUN_005854b0();
        local_60 = 0x672841;
        FUN_00585330();
        ppuStack_5c = (undefined1 **)0x672851;
        FUN_004068f0();
        local_c = 4;
      }
      else {
        FUN_004054c0();
        local_20 = auStack_58;
        local_1c = auStack_58;
        ppuStack_5c = (undefined1 **)0x1ba;
        local_60 = 0x672879;
        FUN_005854b0();
        local_60 = 0x672880;
        FUN_00585330();
        ppuStack_5c = (undefined1 **)0x672890;
        FUN_004068f0();
        local_c = 5;
      }
      ppuStack_5c = (undefined1 **)0x2;
      local_60 = 0x67289f;
      FUN_005854b0();
      local_60 = 0x6728a6;
      uVar5 = FUN_00585330();
      local_20 = (undefined1 *)local_74;
      FUN_00402250(uVar5);
      local_c = 0xffffffff;
      FUN_0058b270(0xca);
      FUN_007613e0();
      goto LAB_006728d6;
    }
    FUN_004054c0();
    local_20 = auStack_58;
    local_1c = auStack_58;
    ppuStack_5c = (undefined1 **)0x1ba;
    local_60 = 0x6727d2;
    FUN_005854b0();
    local_60 = 0x6727d9;
    FUN_00585330();
    ppuStack_5c = (undefined1 **)0x6727e9;
    FUN_004068f0();
    ppuStack_5c = (undefined1 **)0x2;
    local_c = 3;
    local_60 = 0x6727f8;
    FUN_005854b0();
    local_60 = 0x6727ff;
    uVar5 = FUN_00585330();
    local_20 = (undefined1 *)local_74;
    FUN_00402250(uVar5);
  }
  local_c = 0xffffffff;
  FUN_0058b270(0xca);
  iVar3 = param_1[0x3c];
  if (*(char *)(iVar3 + 0x141) == '\0') {
    FUN_00757710();
  }
  else {
    FUN_006edb10();
  }
  *(undefined4 *)(iVar3 + 0x168) = 0;
  *(undefined4 *)(iVar3 + 0x160) = 0;
  *(undefined4 *)(iVar3 + 0x164) = 0;
  *(undefined4 *)(iVar3 + 0x14c) = 0;
LAB_006728d6:
  (**(code **)(*param_1 + 0x90))();
  ExceptionList = pvStack_18;
  return;
}

