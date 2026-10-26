
void FUN_00410250(void)

{
  undefined1 uVar1;
  byte bVar2;
  char cVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  int in_ECX;
  int *piStack_3c;
  int iStack_34;
  int iStack_30;
  int *piStack_2c;
  char *pcStack_28;
  undefined **appuStack_24 [4];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00946b06;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_007459c0(DAT_00d61f20 ^ (uint)&stack0xffffffb8);
  iVar5 = in_ECX;
  if ((*(byte *)(in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)(in_ECX + 0x60) != 0) {
      iVar5 = FUN_00745c20();
      goto LAB_00410299;
    }
  }
  else {
LAB_00410299:
    if ((((iVar5 != 0) && (*(int *)(iVar5 + 0x60) != 0)) &&
        ((*(uint *)(iVar5 + 0x28) >> 0xc & 1) == 0)) && (*(int *)(iVar5 + 0x60) != 0)) {
      FUN_0074a010(iVar5);
    }
  }
  (**(code **)(**(int **)(in_ECX + 0x110) + 0xd0))();
  FUN_00749a00(*(undefined4 *)(in_ECX + 0x10),*(undefined4 *)(in_ECX + 0xc));
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    uStack_c = 0;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    uStack_c = 0xffffffff;
  }
  if (DAT_00fba7a4 != (int *)0x0) {
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      uStack_c = 1;
      FUN_004dec90();
      _atexit((_func_4879 *)&LAB_00bcce30);
      uStack_c = 0xffffffff;
    }
    iVar5 = (**(code **)(*DAT_00fba7a4 + 0x20))();
    if (iVar5 != 0) {
      FUN_0040f060();
      iVar5 = (**(code **)(*DAT_00fba7a4 + 0x20))();
      *(undefined1 *)(in_ECX + 0x144) = *(undefined1 *)(iVar5 + 0x88);
      goto LAB_00410381;
    }
  }
  *(undefined1 *)(in_ECX + 0x144) = 0;
LAB_00410381:
  iVar5 = *(int *)(*(int *)(in_ECX + 0xf8) + 0x24c);
  if ((iVar5 != 0) && (iVar5 = *(int *)(iVar5 + 0xcc), iVar5 != 0)) {
    FUN_006438f0(iVar5);
  }
  FUN_00757710();
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    uStack_c = 2;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    uStack_c = 0xffffffff;
  }
  if (((*(byte *)(in_ECX + 0x144) < 10) &&
      (iVar5 = (uint)*(byte *)(in_ECX + 0x144) * 0x210 + DAT_00f94304, *(int *)(iVar5 + 0x5c) != 0))
     && ((iVar5 != 0 && (iVar5 + 500 != 0)))) {
    piStack_2c = (int *)(*(int *)(iVar5 + 0x1fc) - *(int *)(iVar5 + 0x1f8));
    piStack_3c = (int *)0x0;
    if (piStack_2c != (int *)0x0) {
      do {
        iVar8 = *(int *)(iVar5 + 0x1f8);
        if ((DAT_00fab230 & 1) == 0) {
          DAT_00fab230 = DAT_00fab230 | 1;
          uStack_c = 3;
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
          uStack_c = 0xffffffff;
        }
        iStack_34 = (uint)*(byte *)(in_ECX + 0x144) * 10000 +
                    (uint)*(byte *)(iVar8 + (int)piStack_3c);
        FUN_00529250(&iStack_34);
        iVar8 = iStack_30;
        if ((iStack_30 != DAT_00fab238) && (iStack_30 != -0x10)) {
          iVar6 = *(int *)(*(int *)(in_ECX + 0xf8) + 0x24c);
          if (iVar6 == 0) {
LAB_00410564:
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
            if (piVar7 == (int *)0x0) goto LAB_00410564;
            iVar8 = (**(code **)(*piVar7 + 4))();
            if (iVar8 != 0x4b4) {
              MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
              goto LAB_00410564;
            }
          }
          uVar1 = *(undefined1 *)(in_ECX + 0x144);
          *(undefined1 *)((int)piVar7 + 0x249) =
               *(undefined1 *)((int)piStack_3c + *(int *)(iVar5 + 0x1f8));
          *(undefined1 *)(piVar7 + 0x92) = uVar1;
          bVar2 = *(byte *)((uint)(*(char *)(iVar5 + 0x1f6) != '\0') + iVar5 + 500);
          if (bVar2 == *(byte *)((int)piStack_3c + *(int *)(iVar5 + 0x1f8))) {
            *(uint *)(in_ECX + 0x15c) = (uint)bVar2;
            FUN_0075c960();
            *(undefined1 *)(in_ECX + 0x145) = *(undefined1 *)((int)piVar7 + 0x249);
          }
        }
        piStack_3c = (int *)((int)piStack_3c + 1);
      } while (piStack_3c < piStack_2c);
    }
  }
  FUN_00749d00();
  iVar5 = *(int *)(*(int *)(in_ECX + 0xf8) + 0x24c);
  if (iVar5 != 0) {
    FUN_00749920(iVar5);
  }
  (**(code **)(**(int **)(in_ECX + 0xf8) + 200))();
  FUN_004e0fc0(in_ECX + 0x114);
  if (*(int *)(in_ECX + 0x124) != *(int *)(in_ECX + 0x128)) {
    piVar9 = (int *)FUN_00858240(*(int *)(in_ECX + 0x128),pcStack_28);
    piVar7 = *(int **)(in_ECX + 0x128);
    piVar10 = piVar9;
    piStack_2c = piVar9;
    for (; piVar9 != piVar7; piVar9 = piVar9 + 4) {
      if (*piVar9 != 0) {
        FUN_0089120c(*piVar9);
        piVar10 = piStack_2c;
      }
      *piVar9 = 0;
      piVar9[1] = 0;
      piVar9[2] = 0;
    }
    *(int **)(in_ECX + 0x128) = piVar10;
  }
  piVar7 = *(int **)(*(int *)(in_ECX + 0x138) + 4);
  cVar3 = *(char *)((int)piVar7 + 0x15);
  while (cVar3 == '\0') {
    FUN_0073eba0(piVar7[2]);
    piVar9 = (int *)*piVar7;
    FUN_0089120c(piVar7);
    piVar7 = piVar9;
    cVar3 = *(char *)((int)piVar9 + 0x15);
  }
  *(int *)(*(int *)(in_ECX + 0x138) + 4) = *(int *)(in_ECX + 0x138);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x138) = *(undefined4 *)(in_ECX + 0x138);
  *(int *)(*(int *)(in_ECX + 0x138) + 8) = *(int *)(in_ECX + 0x138);
  *(undefined4 *)(in_ECX + 0x13c) = 0;
  *(undefined4 *)(in_ECX + 0x148) = 0;
  *(undefined4 *)(in_ECX + 0x158) = 0;
  FUN_004110a0(in_ECX);
  FUN_004107f0(in_ECX);
  iVar5 = *(int *)(in_ECX + 0x110);
  uVar1 = *(undefined1 *)(in_ECX + 0x144);
  uVar4 = *(undefined1 *)(in_ECX + 0x145);
  *(undefined4 *)(iVar5 + 0x108) = *(undefined4 *)(in_ECX + 0x158);
  *(undefined1 *)(iVar5 + 0x104) = uVar4;
  *(undefined1 *)(iVar5 + 0x105) = uVar1;
  FUN_004704c0(iVar5);
  (**(code **)(**(int **)(in_ECX + 0x110) + 200))();
  if ((DAT_00fab29c & 1) == 0) {
    DAT_00fab29c = DAT_00fab29c | 1;
    uStack_c = 4;
    FUN_004ffe60();
    _atexit((_func_4879 *)&LAB_00bccf00);
    uStack_c = 0xffffffff;
  }
  FUN_00501650(0xb);
  ExceptionList = local_14;
  return;
}

