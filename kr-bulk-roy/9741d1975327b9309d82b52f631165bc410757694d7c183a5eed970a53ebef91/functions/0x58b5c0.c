
void FUN_0058b5c0(int param_1)

{
  uint uVar1;
  char cVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00929280;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = 0;
    FUN_0074d990(uVar4);
    _atexit((_func_4879 *)&LAB_00bccc70);
  }
  iVar6 = DAT_00f95bd4;
  local_8 = 0xffffffff;
  *(undefined2 *)(param_1 + 0x21) = 0;
  if (iVar6 != 0) {
    iVar5 = FUN_00761010();
    if ((iVar5 == 0) || ((*(uint *)(iVar5 + 0x28) >> 0xd & 1) == 0)) {
      *(undefined1 *)(param_1 + 0x22) = *(undefined1 *)(iVar6 + 0xb1);
      *(undefined1 *)(param_1 + 0x21) = *(undefined1 *)(iVar6 + 0xb0);
    }
    else {
      *(undefined2 *)(param_1 + 0x21) = 0x101;
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_8 = 1;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_8 = 0xffffffff;
    }
    if (((iVar5 != 0) && ((*(uint *)(iVar5 + 0x28) >> 0xd & 1) != 0)) ||
       ((DAT_00f95be0 != (int *)0x0 &&
        (cVar2 = (**(code **)(*DAT_00f95be0 + 0x84))(), cVar2 != '\0')))) {
      *(undefined1 *)(param_1 + 0x22) = 1;
    }
  }
  if ((DAT_00fb131c & 1) == 0) {
    DAT_00fb131c = DAT_00fb131c | 1;
    local_8 = 2;
    FUN_00570ec0();
    _atexit((_func_4879 *)&LAB_00bccf50);
    local_8 = 0xffffffff;
  }
  if (DAT_00fb132c != 0) {
    *(undefined2 *)(param_1 + 0x21) = 0x101;
  }
  if (*(char *)(param_1 + 0x21) == '\0') {
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_8 = 3;
      FUN_0074d990(uVar4);
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_8 = 0xffffffff;
    }
    if ((((DAT_00f94924 == 3) || (DAT_00f94924 == 1)) && (DAT_00f9490c != 3)) && (DAT_00f9490c != 1)
       ) {
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
    uVar1 = DAT_00faadd0 & 1;
    *(undefined1 *)(param_1 + 0x1c) = uVar3;
    if (uVar1 == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_8 = 4;
      FUN_0074d990(uVar4);
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_8 = 0xffffffff;
    }
    if (((DAT_00f94928 == 3) || (DAT_00f94928 == 1)) && ((DAT_00f94910 != 3 && (DAT_00f94910 != 1)))
       ) {
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
    uVar4 = DAT_00faadd0 & 1;
    *(undefined1 *)(param_1 + 0x1d) = uVar3;
    if (uVar4 == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_8 = 5;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_8 = 0xffffffff;
    }
    if (((DAT_00f9492c == 3) || (DAT_00f9492c == 1)) && ((DAT_00f94914 != 3 && (DAT_00f94914 != 1)))
       ) {
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
    uVar4 = DAT_00faadd0 & 1;
    *(undefined1 *)(param_1 + 0x1e) = uVar3;
    if (uVar4 == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_8 = 6;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_8 = 0xffffffff;
    }
    if ((DAT_00f948d8 == 0) || (DAT_00f948d4 != 0)) {
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
    }
    uVar4 = DAT_00faadd0 & 1;
    *(undefined1 *)(param_1 + 0x20) = uVar3;
    if (uVar4 == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_8 = 7;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_8 = 0xffffffff;
    }
    if ((DAT_00f95bdc == (int *)0x0) || (iVar6 = (**(code **)(*DAT_00f95bdc + 4))(), iVar6 == 53000)
       ) {
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
    }
    *(undefined1 *)(param_1 + 0x1f) = uVar3;
    ExceptionList = local_10;
    return;
  }
  *(undefined4 *)(param_1 + 0x1c) = 0x1010101;
  *(undefined1 *)(param_1 + 0x20) = 1;
  ExceptionList = local_10;
  return;
}

