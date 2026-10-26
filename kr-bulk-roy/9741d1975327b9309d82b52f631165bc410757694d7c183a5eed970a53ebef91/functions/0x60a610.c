
void FUN_0060a610(int *param_1)

{
  ushort uVar1;
  code *pcVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  undefined1 *puVar8;
  wchar_t *_Src;
  uint uVar9;
  ushort *puVar10;
  int *piVar11;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093e604;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  iVar6 = param_1[0x3e];
  if (*(char *)(iVar6 + 0x141) != '\0') {
    FUN_006edb10();
  }
  puVar10 = (ushort *)(iVar6 + 0x108);
  if (7 < *(uint *)(iVar6 + 0x11c)) {
    puVar10 = *(ushort **)puVar10;
  }
  if ((DAT_00fb75c0 & 1) == 0) {
    DAT_00fb75c0 = DAT_00fb75c0 | 1;
    local_c = 0;
    FUN_0081e5f0();
    _atexit((_func_4879 *)&LAB_00bcd250);
    local_c = 0xffffffff;
  }
  if (puVar10 != (ushort *)0x0) {
    uVar1 = *puVar10;
    piVar11 = DAT_00fb7608;
    while (uVar1 != 0) {
      uVar9 = (uint)*puVar10;
      if (*puVar10 < 0x80) {
        if ((((9 < uVar9 - 0x30) && (0x19 < uVar9 - 0x41)) && (0x19 < uVar9 - 0x61)) &&
           ((uVar9 != 0x20 && (0x5d < uVar9 - 0x21)))) goto LAB_0060a832;
      }
      else {
        iVar4 = (**(code **)(*piVar11 + 8))();
        piVar11 = DAT_00fb7608;
        iVar6 = DAT_00fb7608[2];
        piVar5 = (int *)FUN_0081ed70();
        if ((*piVar5 == iVar6) && (iVar4 == 0)) goto LAB_0060a832;
      }
      puVar10 = puVar10 + 1;
      uVar1 = *puVar10;
    }
    iVar6 = FUN_0081eb80();
    if ((iVar6 == 0) && (iVar6 = FUN_0081eb80(), iVar6 == 0)) {
      if ((DAT_00f94390 & 1) == 0) {
        DAT_00f94390 = DAT_00f94390 | 1;
        local_c = 4;
        FUN_004e1590();
        _atexit((_func_4879 *)&LAB_00bccc80);
        local_c = 0xffffffff;
      }
      cVar3 = FUN_00509a00();
      if (cVar3 != '\0') {
        if ((DAT_00f8d9a4 & 1) == 0) {
          DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
          local_c = 5;
          FUN_0051c120();
          _atexit((_func_4879 *)&LAB_00bccc90);
          local_c = 0xffffffff;
        }
        FUN_008438c0();
        if ((puVar10 != DAT_00f8d91c) && (*(int *)(puVar10 + 8) != 0)) {
          if (*(int *)(*(int *)(puVar10 + 8) + 0x68) != 0) {
            FUN_00404ba0();
            iVar6 = FUN_004d9c50();
            if ((iVar6 == 0) || (*(int *)(iVar6 + 0xc) == 0)) {
              FUN_004054c0();
              FUN_00402250();
              local_c = 6;
              FUN_005854b0();
              uVar7 = FUN_00585330();
              FUN_00402250(uVar7);
              local_c = 0xffffffff;
              FUN_0058b270(0xca);
              ExceptionList = local_14;
              return;
            }
          }
          local_c = 7;
          puVar8 = (undefined1 *)FUN_00891268();
          if (puVar8 != (undefined1 *)0x0) {
            _Src = (wchar_t *)FUN_00761520();
            *puVar8 = 2;
            _wcscpy_s((wchar_t *)(puVar8 + 1),0x33,_Src);
          }
          FUN_00443d10();
          FUN_00414680();
          FUN_004a39f0();
          FUN_007612c0();
          (**(code **)(*(int *)param_1[0x3e] + 200))();
          (**(code **)(*(int *)param_1[0x3f] + 0x90))();
          iVar6 = FUN_00404ba0();
          iVar4 = 0;
          if (*(int *)(iVar6 + 0x6920) != -0x16f8) {
            iVar4 = FUN_005090e0();
          }
          param_1[0x45] = iVar4 + -1;
          if (iVar4 + -1 < 0) {
            param_1[0x45] = 0;
          }
          FUN_0060adf0();
          FUN_007838f0();
        }
        ExceptionList = local_14;
        return;
      }
      iVar6 = FUN_005854b0();
      FUN_005740f0();
      if (*(int *)(iVar6 + 4) == 0) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      iVar6 = FUN_005854b0();
      FUN_005740f0();
      if (*(int *)(iVar6 + 4) != 0) {
        FUN_00404b10();
        (**(code **)(*param_1 + 0xd4))();
        ExceptionList = local_14;
        return;
      }
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
  }
LAB_0060a832:
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_c = 1;
    FUN_00584c40();
    _atexit(FUN_00bcf370);
    local_c = 0xffffffff;
  }
  FUN_005740f0();
  if (DAT_00fe5b10 == 0) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_c = 2;
    FUN_00584c40();
    _atexit(FUN_00bcf370);
    local_c = 0xffffffff;
  }
  FUN_005740f0();
  if (DAT_00fe5b10 != 0) {
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_c = 3;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_c = 0xffffffff;
    }
    FUN_007532b0();
    ExceptionList = local_14;
    return;
  }
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}

