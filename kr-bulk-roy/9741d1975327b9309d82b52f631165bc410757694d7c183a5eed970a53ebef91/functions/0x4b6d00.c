
undefined4 FUN_004b6d00(char *param_1,uint param_2)

{
  ushort uVar1;
  ushort uVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  char *pcVar10;
  uint uVar11;
  undefined **local_20 [3];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar7 = DAT_00fc0c68;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00924edc;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_2 < 10) {
    local_14 = 0;
  }
  else {
    local_14 = (param_2 - 10) / 0x43;
  }
  FUN_00454290(DAT_00fc0c68 + 0x4c,&param_2,*(undefined4 *)(DAT_00fc0c68 + 0x4c),
               *(undefined4 *)(DAT_00fc0c68 + 0x50));
  param_2 = 0;
  if (local_14 != 0) {
    do {
      pcVar10 = param_1 + param_2 * 0x43 + 10;
      if (param_2 == 0) {
        puVar9 = (undefined4 *)(iVar7 + 8);
        for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar9 = *(undefined4 *)pcVar10;
          pcVar10 = pcVar10 + 4;
          puVar9 = puVar9 + 1;
        }
        *(undefined2 *)puVar9 = *(undefined2 *)pcVar10;
        *(char *)((int)puVar9 + 2) = pcVar10[2];
      }
      else {
        pcVar3 = *(char **)(iVar7 + 0x50);
        if ((pcVar10 < pcVar3) && (pcVar4 = *(char **)(iVar7 + 0x4c), pcVar4 <= pcVar10)) {
          if (pcVar3 == *(char **)(iVar7 + 0x54)) {
            FUN_004542e0(uVar5);
          }
          if (*(undefined4 **)(iVar7 + 0x50) != (undefined4 *)0x0) {
            puVar9 = (undefined4 *)
                     ((((int)pcVar10 - (int)pcVar4) / 0x43) * 0x43 + *(int *)(iVar7 + 0x4c));
            puVar6 = *(undefined4 **)(iVar7 + 0x50);
            for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
              *puVar6 = *puVar9;
              puVar9 = puVar9 + 1;
              puVar6 = puVar6 + 1;
            }
            *(undefined2 *)puVar6 = *(undefined2 *)puVar9;
            *(undefined1 *)((int)puVar6 + 2) = *(undefined1 *)((int)puVar9 + 2);
          }
        }
        else {
          if (pcVar3 == *(char **)(iVar7 + 0x54)) {
            FUN_004542e0(uVar5);
          }
          if (*(undefined4 **)(iVar7 + 0x50) != (undefined4 *)0x0) {
            puVar9 = *(undefined4 **)(iVar7 + 0x50);
            for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
              *puVar9 = *(undefined4 *)pcVar10;
              pcVar10 = pcVar10 + 4;
              puVar9 = puVar9 + 1;
            }
            *(undefined2 *)puVar9 = *(undefined2 *)pcVar10;
            *(char *)((int)puVar9 + 2) = pcVar10[2];
          }
        }
        *(int *)(iVar7 + 0x50) = *(int *)(iVar7 + 0x50) + 0x43;
      }
      param_2 = param_2 + 1;
      iVar7 = DAT_00fc0c68;
    } while (param_2 < local_14);
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  puVar6 = (undefined4 *)FUN_00891268(0x1c);
  puVar9 = (undefined4 *)0x0;
  if (puVar6 != (undefined4 *)0x0) {
    uVar1 = *(ushort *)(param_1 + 8);
    uVar2 = *(ushort *)(param_1 + 6);
    puVar6[3] = 0;
    puVar6[1] = 0xffffffff;
    puVar6[2] = 0xffffffff;
    puVar6[4] = 0xf42cd;
    *puVar6 = FoxUI::FXUIEventI2::vftable;
    puVar6[5] = (uint)uVar2;
    puVar6[6] = (uint)uVar1;
    puVar9 = puVar6;
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = 1;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_8 = 0xffffffff;
  }
  if (((DAT_00f95c78 + DAT_00f95c7c & 3U) == 0) && (DAT_00f95c74 <= DAT_00f95c7c + 4U >> 2)) {
    FUN_00636f70(&DAT_00f95c6c);
  }
  uVar11 = DAT_00f95c78 + DAT_00f95c7c;
  uVar5 = uVar11 >> 2;
  if (DAT_00f95c74 <= uVar5) {
    uVar5 = uVar5 - DAT_00f95c74;
  }
  if (*(int *)(DAT_00f95c70 + uVar5 * 4) == 0) {
    iVar7 = FUN_00891268(0x10);
    if (iVar7 == 0) {
      param_1 = (char *)0x0;
      std::exception::exception((exception *)local_20,&param_1);
      local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_20,&DAT_00c857a8);
    }
    *(int *)(DAT_00f95c70 + uVar5 * 4) = iVar7;
  }
  puVar6 = (undefined4 *)(*(int *)(DAT_00f95c70 + uVar5 * 4) + (uVar11 & 3) * 4);
  if (puVar6 != (undefined4 *)0x0) {
    *puVar6 = puVar9;
  }
  DAT_00f95c7c = DAT_00f95c7c + 1;
  ExceptionList = local_10;
  return 0;
}

