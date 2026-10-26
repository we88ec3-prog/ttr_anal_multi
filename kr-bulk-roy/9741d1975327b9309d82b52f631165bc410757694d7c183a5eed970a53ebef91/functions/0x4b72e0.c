
undefined4 FUN_004b72e0(char *param_1,uint param_2)

{
  byte bVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  char *pcVar9;
  uint uVar10;
  undefined **local_20 [3];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar6 = DAT_00fb7618;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00924edc;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_2 < 3) {
    local_14 = 0;
  }
  else {
    local_14 = (param_2 - 3) / 0x52;
  }
  FUN_00434840(DAT_00fb7618 + 0x5c,&param_2,*(undefined4 *)(DAT_00fb7618 + 0x5c),
               *(undefined4 *)(DAT_00fb7618 + 0x60));
  param_2 = 0;
  if (local_14 != 0) {
    do {
      pcVar9 = param_1 + param_2 * 0x52 + 3;
      if (param_2 == 0) {
        puVar8 = (undefined4 *)(iVar6 + 8);
        for (iVar7 = 0x14; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar8 = *(undefined4 *)pcVar9;
          pcVar9 = pcVar9 + 4;
          puVar8 = puVar8 + 1;
        }
        *(undefined2 *)puVar8 = *(undefined2 *)pcVar9;
      }
      else {
        pcVar2 = *(char **)(iVar6 + 0x60);
        if ((pcVar9 < pcVar2) && (pcVar3 = *(char **)(iVar6 + 0x5c), pcVar3 <= pcVar9)) {
          if (pcVar2 == *(char **)(iVar6 + 100)) {
            FUN_00434890(uVar4);
          }
          if (*(undefined4 **)(iVar6 + 0x60) != (undefined4 *)0x0) {
            puVar8 = (undefined4 *)
                     ((((int)pcVar9 - (int)pcVar3) / 0x52) * 0x52 + *(int *)(iVar6 + 0x5c));
            puVar5 = *(undefined4 **)(iVar6 + 0x60);
            for (iVar7 = 0x14; iVar7 != 0; iVar7 = iVar7 + -1) {
              *puVar5 = *puVar8;
              puVar8 = puVar8 + 1;
              puVar5 = puVar5 + 1;
            }
            *(undefined2 *)puVar5 = *(undefined2 *)puVar8;
          }
        }
        else {
          if (pcVar2 == *(char **)(iVar6 + 100)) {
            FUN_00434890(uVar4);
          }
          if (*(undefined4 **)(iVar6 + 0x60) != (undefined4 *)0x0) {
            puVar8 = *(undefined4 **)(iVar6 + 0x60);
            for (iVar7 = 0x14; iVar7 != 0; iVar7 = iVar7 + -1) {
              *puVar8 = *(undefined4 *)pcVar9;
              pcVar9 = pcVar9 + 4;
              puVar8 = puVar8 + 1;
            }
            *(undefined2 *)puVar8 = *(undefined2 *)pcVar9;
          }
        }
        *(int *)(iVar6 + 0x60) = *(int *)(iVar6 + 0x60) + 0x52;
      }
      param_2 = param_2 + 1;
      iVar6 = DAT_00fb7618;
    } while (param_2 < local_14);
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  puVar5 = (undefined4 *)FUN_00891268(0x18);
  puVar8 = (undefined4 *)0x0;
  if (puVar5 != (undefined4 *)0x0) {
    bVar1 = param_1[2];
    puVar5[3] = 0;
    puVar5[1] = 0xffffffff;
    puVar5[2] = 0xffffffff;
    puVar5[4] = 0xf42cf;
    *puVar5 = FoxUI::FXUIEventI1::vftable;
    puVar5[5] = (uint)bVar1;
    puVar8 = puVar5;
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
  uVar10 = DAT_00f95c78 + DAT_00f95c7c;
  uVar4 = uVar10 >> 2;
  if (DAT_00f95c74 <= uVar4) {
    uVar4 = uVar4 - DAT_00f95c74;
  }
  if (*(int *)(DAT_00f95c70 + uVar4 * 4) == 0) {
    iVar6 = FUN_00891268(0x10);
    if (iVar6 == 0) {
      param_1 = (char *)0x0;
      std::exception::exception((exception *)local_20,&param_1);
      local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_20,&DAT_00c857a8);
    }
    *(int *)(DAT_00f95c70 + uVar4 * 4) = iVar6;
  }
  puVar5 = (undefined4 *)(*(int *)(DAT_00f95c70 + uVar4 * 4) + (uVar10 & 3) * 4);
  if (puVar5 != (undefined4 *)0x0) {
    *puVar5 = puVar8;
  }
  DAT_00f95c7c = DAT_00f95c7c + 1;
  ExceptionList = local_10;
  return 0;
}

