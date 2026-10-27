
void FUN_0068f9c0(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00942b4c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    local_8 = 0;
    FUN_00539c20(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccfb0);
  }
  local_8 = 0xffffffff;
  if (DAT_00fb7258 == 0) {
    piVar1 = (int *)FUN_00891268(0x18);
    if (piVar1 == (int *)0x0) {
      piVar1 = (int *)0x0;
    }
    else {
      piVar1[1] = -1;
      piVar1[2] = -1;
      piVar1[3] = 0;
      piVar1[4] = 0xf42e1;
      *piVar1 = (int)FoxUI::FXUIEventB1::vftable;
      *(undefined1 *)(piVar1 + 5) = 1;
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_8 = 1;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_8 = 0xffffffff;
    }
    piVar3 = DAT_00f95bd4;
    if (DAT_00f95bd4 == (int *)0x0) goto LAB_0068fb11;
  }
  else {
    if (*(int *)(param_1 + 0x5a4) == 1) {
      piVar1 = (int *)FUN_00891268(0x18);
      if (piVar1 == (int *)0x0) goto LAB_0068fa59;
      piVar1[1] = -1;
      piVar1[2] = -1;
      piVar1[3] = 0;
      piVar1[4] = 0xf4390;
      *piVar1 = (int)FoxUI::FXUIEventI1::vftable;
      piVar1[5] = 0;
    }
    else {
      if (*(int *)(param_1 + 0x5a4) != 2) {
        ExceptionList = local_10;
        return;
      }
      piVar1 = (int *)FUN_00891268(0x14);
      if (piVar1 == (int *)0x0) {
LAB_0068fa59:
        piVar1 = (int *)0x0;
      }
      else {
        *piVar1 = (int)FoxUI::FXUIEvent::vftable;
        piVar1[1] = -1;
        piVar1[2] = -1;
        piVar1[3] = 0;
        piVar1[4] = 0xf4396;
      }
    }
    iVar2 = FUN_00404aa0();
    if (*(int *)(iVar2 + 0x13c4) == 0) goto LAB_0068fb11;
    piVar3 = *(int **)(iVar2 + 0x13c4);
  }
  (**(code **)(*piVar3 + 0x15c))(piVar1);
LAB_0068fb11:
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x10))(1);
  }
  ExceptionList = local_10;
  return;
}

