
void FUN_0045f1b0(uint *param_1,char *param_2)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int in_ECX;
  uint uVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined **local_1c [3];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  uVar9 = (uint)param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092561c;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar7 = 0;
  uVar3 = *(int *)(in_ECX + 8) - *(int *)(in_ECX + 4) >> 2;
  param_1 = (uint *)((uint)param_1 & 0xffffff);
  if (uVar3 != 0) {
    do {
      piVar1 = *(int **)(*(int *)(in_ECX + 4) + uVar7 * 4);
      if (*(int *)(*piVar1 + 0x1c) == *(int *)(uVar9 + 0x1c)) {
        piVar1 = piVar1 + 1;
        *piVar1 = (int)(param_2 + *piVar1);
        param_1 = (uint *)CONCAT13(1,param_1._0_3_);
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < uVar3);
    if (param_1._3_1_ != '\0') goto LAB_0045f290;
  }
  puVar4 = (uint *)FUN_00891268(8,uVar2);
  if (puVar4 == (uint *)0x0) {
    puVar4 = (uint *)0x0;
  }
  else {
    *puVar4 = 0;
    puVar4[1] = 0;
  }
  *puVar4 = uVar9;
  puVar4[1] = (uint)param_2;
  puVar8 = *(undefined4 **)(in_ECX + 8);
  param_1 = puVar4;
  if (&param_1 < puVar8) {
    puVar5 = *(undefined4 **)(in_ECX + 4);
    if (&param_1 < puVar5) goto LAB_0045f276;
    if (puVar8 == *(undefined4 **)(in_ECX + 0xc)) {
      FUN_004deab0();
    }
    if (*(undefined4 **)(in_ECX + 8) != (undefined4 *)0x0) {
      **(undefined4 **)(in_ECX + 8) =
           *(undefined4 *)(*(int *)(in_ECX + 4) + ((int)&param_1 - (int)puVar5 >> 2) * 4);
    }
  }
  else {
LAB_0045f276:
    if (puVar8 == *(undefined4 **)(in_ECX + 0xc)) {
      FUN_004deab0();
    }
    if (*(undefined4 **)(in_ECX + 8) != (undefined4 *)0x0) {
      **(undefined4 **)(in_ECX + 8) = puVar4;
    }
  }
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + 4;
LAB_0045f290:
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  puVar5 = (undefined4 *)FUN_00891268(0x14,uVar2);
  puVar8 = (undefined4 *)0x0;
  if (puVar5 != (undefined4 *)0x0) {
    puVar5[3] = 0;
    *puVar5 = FoxUI::FXUIEvent::vftable;
    puVar5[1] = 0xffffffff;
    puVar5[2] = 0xffffffff;
    puVar5[4] = 0xf4427;
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
  uVar2 = DAT_00f95c78 + DAT_00f95c7c;
  uVar9 = uVar2 >> 2;
  if (DAT_00f95c74 <= uVar9) {
    uVar9 = uVar9 - DAT_00f95c74;
  }
  if (*(int *)(DAT_00f95c70 + uVar9 * 4) == 0) {
    iVar6 = FUN_00891268(0x10);
    if (iVar6 == 0) {
      param_2 = (char *)0x0;
      std::exception::exception((exception *)local_1c,&param_2);
      local_1c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_1c,&DAT_00c857a8);
    }
    *(int *)(DAT_00f95c70 + uVar9 * 4) = iVar6;
  }
  puVar5 = (undefined4 *)(*(int *)(DAT_00f95c70 + uVar9 * 4) + (uVar2 & 3) * 4);
  if (puVar5 != (undefined4 *)0x0) {
    *puVar5 = puVar8;
  }
  DAT_00f95c7c = DAT_00f95c7c + 1;
  ExceptionList = local_10;
  return;
}

