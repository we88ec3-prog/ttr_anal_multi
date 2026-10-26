
void FUN_006195a0(int param_1)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint uStack_38;
  int iStack_34;
  int iStack_30;
  uint uStack_2c;
  char *pcStack_28;
  undefined **appuStack_24 [4];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093df68;
  local_14 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffb8;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(uVar2);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_c = 0xffffffff;
  if (DAT_00fba7a4 != (int *)0x0) {
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 1;
      FUN_004dec90(uVar2);
      _atexit((_func_4879 *)&LAB_00bcce30);
    }
    local_c = 0xffffffff;
    iVar3 = (**(code **)(*DAT_00fba7a4 + 0x20))();
    if (iVar3 != 0) {
      FUN_0040f060();
      iVar3 = (**(code **)(*DAT_00fba7a4 + 0x20))();
      *(undefined1 *)(param_1 + 0xfd) = *(undefined1 *)(iVar3 + 0x88);
    }
  }
  iVar3 = *(int *)(*(int *)(param_1 + 0xf8) + 0x24c);
  if ((iVar3 != 0) && (iVar3 = *(int *)(iVar3 + 0xcc), iVar3 != 0)) {
    FUN_006438f0(iVar3);
  }
  FUN_00757710();
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 2;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  if ((((*(byte *)(param_1 + 0xfd) < 10) &&
       (iVar3 = (uint)*(byte *)(param_1 + 0xfd) * 0x210 + DAT_00f94304, *(int *)(iVar3 + 0x5c) != 0)
       ) && (iVar3 != 0)) && (iVar3 + 500 != 0)) {
    uStack_2c = *(int *)(iVar3 + 0x1fc) - *(int *)(iVar3 + 0x1f8);
    uStack_38 = 0;
    if (uStack_2c != 0) {
      do {
        iVar6 = *(int *)(iVar3 + 0x1f8);
        if ((DAT_00fab230 & 1) == 0) {
          DAT_00fab230 = DAT_00fab230 | 1;
          local_c = 3;
          DAT_00fab23c = 0;
          iVar4 = FUN_00891268(0x50);
          if (iVar4 == 0) {
            pcStack_28 = (char *)0x0;
            std::exception::exception((exception *)appuStack_24,&pcStack_28);
            appuStack_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
            __CxxThrowException_8(appuStack_24,&DAT_00c857a8);
          }
          DAT_00fab238 = iVar4;
          *(int *)iVar4 = iVar4;
          *(int *)(DAT_00fab238 + 4) = DAT_00fab238;
          *(int *)(DAT_00fab238 + 8) = DAT_00fab238;
          *(undefined1 *)(DAT_00fab238 + 0x4c) = 1;
          *(undefined1 *)(DAT_00fab238 + 0x4d) = 1;
          _atexit(FUN_00bcce40);
          local_c = 0xffffffff;
        }
        iStack_34 = (uint)*(byte *)(param_1 + 0xfd) * 10000 + (uint)*(byte *)(iVar6 + uStack_38);
        FUN_00529250(&iStack_34);
        iVar6 = iStack_30;
        if ((iStack_30 != DAT_00fab238) && (iStack_30 != -0x10)) {
          iVar4 = *(int *)(*(int *)(param_1 + 0xf8) + 0x24c);
          if (iVar4 == 0) {
LAB_00619853:
            piVar5 = (int *)0x0;
          }
          else {
            iVar4 = *(int *)(iVar4 + 0xcc);
            if (iVar4 == 0) {
              piVar5 = (int *)0x0;
            }
            else {
              piVar5 = (int *)FUN_00412c70(*(undefined4 *)(iVar4 + 0xe4));
            }
            FUN_00757800(iVar6 + 0x14);
            if (piVar5 == (int *)0x0) goto LAB_00619853;
            iVar6 = (**(code **)(*piVar5 + 4))();
            if (iVar6 != 0x4b4) {
              MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
              goto LAB_00619853;
            }
          }
          uVar1 = *(undefined1 *)(param_1 + 0xfd);
          *(undefined1 *)((int)piVar5 + 0x249) =
               *(undefined1 *)(uStack_38 + *(int *)(iVar3 + 0x1f8));
          *(undefined1 *)(piVar5 + 0x92) = uVar1;
          if (*(char *)((uint)(*(char *)(iVar3 + 0x1f6) != '\0') + iVar3 + 500) ==
              *(char *)(uStack_38 + *(int *)(iVar3 + 0x1f8))) {
            FUN_0075c960();
            *(undefined1 *)(param_1 + 0xfc) = *(undefined1 *)((int)piVar5 + 0x249);
          }
        }
        uStack_38 = uStack_38 + 1;
      } while (uStack_38 < uStack_2c);
    }
  }
  FUN_00749d00();
  iVar3 = *(int *)(*(int *)(param_1 + 0xf8) + 0x24c);
  if (iVar3 != 0) {
    FUN_00749920(iVar3);
  }
  FUN_00749920(*(undefined4 *)(param_1 + 0xf8));
  (**(code **)(**(int **)(param_1 + 0xf8) + 200))();
  ExceptionList = local_14;
  return;
}

