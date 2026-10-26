
void FUN_00609550(int *param_1)

{
  ushort uVar1;
  code *pcVar2;
  char cVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined1 *puVar6;
  undefined1 auStack_74 [20];
  undefined4 uStack_60;
  undefined1 **ppuStack_5c;
  undefined1 auStack_58 [16];
  undefined4 uStack_48;
  undefined *puStack_44;
  undefined1 *puStack_40;
  undefined1 **ppuStack_3c;
  undefined1 *local_24;
  undefined1 *local_20;
  undefined1 *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093e6ae;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    ppuStack_3c = (undefined1 **)0x6095aa;
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  puStack_40 = (undefined1 *)param_1[0x59];
  ppuStack_3c = &local_24;
  puStack_44 = (undefined *)0x6095d5;
  cVar3 = FUN_00509a00();
  if (cVar3 != '\0') {
    if ((DAT_00f8d9a4 & 1) == 0) {
      DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
      local_c = 4;
      FUN_0051c120();
      ppuStack_3c = (undefined1 **)0x60973a;
      _atexit((_func_4879 *)&LAB_00bccc90);
      local_c = 0xffffffff;
    }
    local_20 = (undefined1 *)param_1[0x59];
    ppuStack_3c = (undefined1 **)0x60975e;
    FUN_008438c0();
    if (local_24 == DAT_00f8d91c) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(local_24 + 0x10);
    }
    if (*(int *)(iVar4 + 0x68) != 0) {
      uVar1 = *(ushort *)(*(int *)(iVar4 + 0x68) + 8);
      iVar4 = FUN_00404ba0();
      iVar4 = *(int *)(iVar4 + 0x6928);
      ppuStack_3c = (undefined1 **)0x6097a2;
      local_20 = (undefined1 *)(uint)uVar1;
      FUN_004a4cc0();
      if (((local_24 == *(undefined1 **)(iVar4 + 0x14)) || (*(int *)(local_24 + 0x10) == 0)) ||
         (*(int *)(*(int *)(local_24 + 0x10) + 0xc) == 0)) {
        FUN_004054c0();
        ppuStack_3c = (undefined1 **)0x0;
        local_1c = auStack_58;
        ppuStack_5c = (undefined1 **)&DAT_00bed1fc;
        uStack_60 = 0x6097da;
        FUN_00402250();
        local_c = 5;
        local_20 = (undefined1 *)0x10b;
        ppuStack_5c = (undefined1 **)0x6097ef;
        iVar4 = FUN_005854b0();
        ppuStack_5c = &local_20;
        uStack_60 = 0x609801;
        FUN_005740f0();
        if (local_24 != *(undefined1 **)(iVar4 + 4)) {
          puVar5 = (undefined4 *)(local_24 + 0x10);
          if (7 < *(uint *)(local_24 + 0x24)) {
            puVar5 = (undefined4 *)*puVar5;
          }
          local_20 = auStack_74;
          FUN_00402250(puVar5);
          local_c = 0xffffffff;
          FUN_0058b270(0xca);
          ExceptionList = local_14;
          return;
        }
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
    }
    ppuStack_3c = (undefined1 **)param_1[0x3d];
    puStack_40 = (undefined1 *)0x609870;
    FUN_0068a1b0();
    ppuStack_3c = (undefined1 **)0x609882;
    (**(code **)(*(int *)param_1[0x40] + 0x90))();
    ppuStack_3c = (undefined1 **)0x0;
    puStack_40 = (undefined1 *)0x609890;
    (**(code **)(*param_1 + 0x16c))();
    ExceptionList = local_1c;
    return;
  }
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_c = 1;
    ppuStack_3c = (undefined1 **)0x6095fa;
    FUN_00584c40();
    ppuStack_3c = (undefined1 **)0x609604;
    _atexit(FUN_00bcf370);
    local_c = 0xffffffff;
  }
  local_24 = (undefined1 *)0x196;
  ppuStack_3c = (undefined1 **)0x609626;
  FUN_005740f0();
  if (local_20 != DAT_00fe5b10) {
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_c = 2;
      ppuStack_3c = (undefined1 **)0x60966e;
      FUN_00584c40();
      ppuStack_3c = (undefined1 **)0x609678;
      _atexit(FUN_00bcf370);
      local_c = 0xffffffff;
    }
    local_20 = (undefined1 *)0x12;
    ppuStack_3c = (undefined1 **)0x60969a;
    FUN_005740f0();
    if (local_24 != DAT_00fe5b10) {
      if (*(uint *)(local_24 + 0x24) < 8) {
        puVar6 = local_24 + 0x10;
      }
      else {
        puVar6 = *(undefined1 **)(local_24 + 0x10);
      }
      if ((DAT_00faadd0 & 1) == 0) {
        DAT_00faadd0 = DAT_00faadd0 | 1;
        local_c = 3;
        FUN_0074d990();
        ppuStack_3c = (undefined1 **)0x6096e2;
        _atexit((_func_4879 *)&LAB_00bccc70);
        local_c = 0xffffffff;
      }
      ppuStack_3c = (undefined1 **)0x0;
      puStack_44 = &DAT_00f94810;
      uStack_48 = 0x6096ff;
      puStack_40 = puVar6;
      FUN_007532b0();
      ExceptionList = local_14;
      return;
    }
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}

