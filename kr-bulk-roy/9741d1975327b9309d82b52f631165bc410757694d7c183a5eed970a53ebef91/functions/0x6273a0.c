
void FUN_006273a0(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *in_ECX;
  int *piVar3;
  char *pcStack_28;
  undefined **appuStack_24 [4];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00935f13;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (in_ECX != (int *)0x0) {
    iVar1 = (**(code **)(*in_ECX + 4))(DAT_00d61f20 ^ (uint)&stack0xffffffc8);
    if (iVar1 == 0x105bd) goto LAB_006273fa;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_ECX = (int *)0x0;
LAB_006273fa:
  if (in_ECX[5] == 0x6a7) {
    iVar1 = 3;
    piVar3 = param_1 + 0x43;
    do {
      FUN_0062af80(*piVar3);
      piVar3 = piVar3 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    FUN_0062c870(param_1[0x46]);
    if ((DAT_00fb7c14 & 1) == 0) {
      DAT_00fb7c14 = DAT_00fb7c14 | 1;
      uStack_c = 0;
      FUN_006d0750();
      _atexit((_func_4879 *)&LAB_00bcd530);
      uStack_c = 0xffffffff;
    }
    FUN_006d1b50(&DAT_00fb8830);
    if ((DAT_00fdf3ec & 1) == 0) {
      DAT_00fdf3ec = DAT_00fdf3ec | 1;
      uStack_c = 1;
      FUN_006d1da0();
      _atexit((_func_4879 *)&LAB_00bce330);
      uStack_c = 0xffffffff;
    }
    FUN_006d3b90();
    if ((DAT_00fc1724 & 1) == 0) {
      DAT_00fc1724 = DAT_00fc1724 | 1;
      uStack_c = 2;
      DAT_00fc1730 = 0;
      iVar1 = FUN_00891268(0x30);
      if (iVar1 == 0) {
        pcStack_28 = (char *)0x0;
        std::exception::exception((exception *)appuStack_24,&pcStack_28);
        appuStack_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(appuStack_24,&DAT_00c857a8);
      }
      DAT_00fc172c = iVar1;
      *(int *)iVar1 = iVar1;
      *(int *)(DAT_00fc172c + 4) = DAT_00fc172c;
      *(int *)(DAT_00fc172c + 8) = DAT_00fc172c;
      *(undefined1 *)(DAT_00fc172c + 0x2c) = 1;
      *(undefined1 *)(DAT_00fc172c + 0x2d) = 1;
      uStack_c._0_1_ = 3;
      FUN_006ccc00(&DAT_00fc173c);
      uStack_c._0_1_ = 4;
      FUN_006ccc00(&DAT_00fc17bc);
      uStack_c = CONCAT31(uStack_c._1_3_,5);
      DAT_00fc1778 = 1;
      FUN_006cd0e0();
      _atexit((_func_4879 *)&LAB_00bce3c0);
      uStack_c = 0xffffffff;
    }
    FUN_006cde10();
    piVar2 = (int *)FUN_00891268(0x14);
    piVar3 = (int *)0x0;
    if (piVar2 != (int *)0x0) {
      piVar2[3] = 0;
      *piVar2 = (int)FoxUI::FXUIEvent::vftable;
      piVar2[1] = -1;
      piVar2[2] = -1;
      piVar2[4] = 0xf4403;
      piVar3 = piVar2;
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      uStack_c = 6;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      uStack_c = 0xffffffff;
    }
    if (DAT_00f95bd4 != (int *)0x0) {
      (**(code **)(*DAT_00f95bd4 + 0x15c))(piVar3);
    }
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x10))(1);
    }
    (**(code **)(*param_1 + 0xd4))();
  }
  ExceptionList = local_14;
  return;
}

