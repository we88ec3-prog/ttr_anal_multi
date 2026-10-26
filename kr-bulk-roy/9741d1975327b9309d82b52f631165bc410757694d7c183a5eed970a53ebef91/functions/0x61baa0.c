
void FUN_0061baa0(void)

{
  undefined1 uVar1;
  char cVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  undefined4 uVar9;
  int in_ECX;
  undefined4 *puVar10;
  uint uStack_38;
  int iStack_34;
  int iStack_30;
  uint uStack_2c;
  char *pcStack_28;
  undefined **appuStack_24 [4];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00946b06;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_007459c0(DAT_00d61f20 ^ (uint)&stack0xffffffb8);
  iVar5 = in_ECX;
  if ((*(byte *)(in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)(in_ECX + 0x60) != 0) {
      iVar5 = FUN_00745c20();
      goto LAB_0061baed;
    }
  }
  else {
LAB_0061baed:
    if ((((iVar5 != 0) && (*(int *)(iVar5 + 0x60) != 0)) &&
        ((*(uint *)(iVar5 + 0x28) >> 0xc & 1) == 0)) && (*(int *)(iVar5 + 0x60) != 0)) {
      FUN_0074a010(iVar5);
    }
  }
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    local_c = 0xffffffff;
  }
  if (DAT_00fba7a4 == (int *)0x0) {
LAB_0061bbac:
    *(undefined4 *)(in_ECX + 0x218) = 0;
  }
  else {
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 1;
      FUN_004dec90();
      _atexit((_func_4879 *)&LAB_00bcce30);
      local_c = 0xffffffff;
    }
    iVar5 = (**(code **)(*DAT_00fba7a4 + 0x20))();
    if (iVar5 == 0) goto LAB_0061bbac;
    FUN_0040f060();
    iVar5 = (**(code **)(*DAT_00fba7a4 + 0x20))();
    *(uint *)(in_ECX + 0x218) = (uint)*(ushort *)(iVar5 + 0x88);
  }
  iVar5 = *(int *)(*(int *)(in_ECX + 0x114) + 0x24c);
  if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0xcc), iVar5 != 0)) {
    FUN_006438f0(iVar5);
  }
  FUN_00757710();
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 2;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  if (((*(uint *)(in_ECX + 0x218) < 10) &&
      (iVar5 = *(uint *)(in_ECX + 0x218) * 0x210 + DAT_00f94304, *(int *)(iVar5 + 0x5c) != 0)) &&
     ((iVar5 != 0 && (iVar5 + 500 != 0)))) {
    uStack_2c = *(int *)(iVar5 + 0x1fc) - *(int *)(iVar5 + 0x1f8);
    uStack_38 = 0;
    if (uStack_2c != 0) {
      do {
        iVar8 = *(int *)(iVar5 + 0x1f8);
        if ((DAT_00fab230 & 1) == 0) {
          DAT_00fab230 = DAT_00fab230 | 1;
          local_c = 3;
          DAT_00fab23c = 0;
          iVar6 = FUN_00891268(0x50);
          if (iVar6 == 0) {
            pcStack_28 = (char *)0x0;
            std::exception::exception((exception *)appuStack_24,&pcStack_28);
            appuStack_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
            __CxxThrowException_8(appuStack_24,&DAT_00c857a8);
          }
          DAT_00fab238 = iVar6;
          *(int *)iVar6 = iVar6;
          *(int *)(DAT_00fab238 + 4) = DAT_00fab238;
          *(int *)(DAT_00fab238 + 8) = DAT_00fab238;
          *(undefined1 *)(DAT_00fab238 + 0x4c) = 1;
          *(undefined1 *)(DAT_00fab238 + 0x4d) = 1;
          _atexit(FUN_00bcce40);
          local_c = 0xffffffff;
        }
        iStack_34 = (uint)*(byte *)(in_ECX + 0x218) * 10000 + (uint)*(byte *)(iVar8 + uStack_38);
        FUN_00529250(&iStack_34);
        iVar8 = iStack_30;
        if ((iStack_30 != DAT_00fab238) && (iStack_30 != -0x10)) {
          iVar6 = *(int *)(*(int *)(in_ECX + 0x114) + 0x24c);
          if (iVar6 == 0) {
LAB_0061bda2:
            piVar7 = (int *)0x0;
          }
          else {
            iVar6 = *(int *)(iVar6 + 0xcc);
            if (iVar6 == 0) {
              piVar7 = (int *)0x0;
            }
            else {
              piVar7 = (int *)FUN_00412c70(*(undefined4 *)(iVar6 + 0xe4));
            }
            FUN_00757800(iVar8 + 0x14);
            if (piVar7 == (int *)0x0) goto LAB_0061bda2;
            iVar8 = (**(code **)(*piVar7 + 4))();
            if (iVar8 != 0x4b4) {
              MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
              goto LAB_0061bda2;
            }
          }
          uVar1 = *(undefined1 *)(in_ECX + 0x218);
          *(undefined1 *)((int)piVar7 + 0x249) =
               *(undefined1 *)(uStack_38 + *(int *)(iVar5 + 0x1f8));
          *(undefined1 *)(piVar7 + 0x92) = uVar1;
          if (*(char *)((uint)(*(char *)(iVar5 + 0x1f6) != '\0') + iVar5 + 500) ==
              *(char *)(uStack_38 + *(int *)(iVar5 + 0x1f8))) {
            FUN_0075cd30(*(undefined4 *)(in_ECX + 0x114));
          }
        }
        uStack_38 = uStack_38 + 1;
      } while (uStack_38 < uStack_2c);
    }
  }
  puVar10 = (undefined4 *)(in_ECX + 0x1dc);
  uStack_38 = 2;
  do {
    iVar5 = 7;
    do {
      (**(code **)(*(int *)*puVar10 + 0x90))(0);
      puVar10 = puVar10 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    uStack_38 = uStack_38 + -1;
  } while (uStack_38 != 0);
  *(undefined4 *)(in_ECX + 0x214) = 0;
  piVar7 = *(int **)(*(int *)(in_ECX + 0xf8) + 4);
  cVar2 = *(char *)((int)piVar7 + 0x15);
  while (cVar2 == '\0') {
    FUN_0073eba0(piVar7[2]);
    piVar3 = (int *)*piVar7;
    FUN_0089120c(piVar7);
    piVar7 = piVar3;
    cVar2 = *(char *)((int)piVar3 + 0x15);
  }
  *(int *)(*(int *)(in_ECX + 0xf8) + 4) = *(int *)(in_ECX + 0xf8);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0xf8) = *(undefined4 *)(in_ECX + 0xf8);
  *(int *)(*(int *)(in_ECX + 0xf8) + 8) = *(int *)(in_ECX + 0xf8);
  *(undefined4 *)(in_ECX + 0xfc) = 0;
  iVar5 = *(int *)(*(int *)(in_ECX + 0x114) + 0x24c);
  if (iVar5 != 0) {
    iVar5 = *(int *)(iVar5 + 0xcc);
    if (iVar5 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)(iVar5 + 0xdc);
    }
    if (iVar5 != 0) {
      uVar9 = *(undefined4 *)(iVar5 + 0x20);
      goto LAB_0061bedc;
    }
  }
  uVar9 = 0xffffffff;
LAB_0061bedc:
  *(undefined4 *)(in_ECX + 0x21c) = uVar9;
  FUN_00749d00();
  piVar7 = *(int **)(*(int *)(in_ECX + 0x114) + 0x24c);
  if (piVar7 != (int *)0x0) {
    puVar10 = (undefined4 *)piVar7[0x19];
    for (puVar4 = (undefined4 *)*puVar10; puVar4 != puVar10; puVar4 = (undefined4 *)*puVar4) {
      iVar5 = puVar4[2];
      if ((*(int *)(iVar5 + 0x60) != 0) && ((*(int **)(iVar5 + 0x1c))[2] != 6)) {
        (**(code **)(**(int **)(iVar5 + 0x1c) + 0x30))(iVar5);
      }
    }
    (**(code **)(*piVar7 + 0x128))();
  }
  (**(code **)(**(int **)(in_ECX + 0x114) + 200))();
  FUN_0061c660();
  if ((DAT_00fab29c & 1) == 0) {
    DAT_00fab29c = DAT_00fab29c | 1;
    local_c = 4;
    FUN_004ffe60();
    _atexit((_func_4879 *)&LAB_00bccf00);
    local_c = 0xffffffff;
  }
  FUN_00501650(4);
  ExceptionList = local_14;
  return;
}

