
void FUN_00561db0(void)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined4 extraout_ECX;
  undefined4 uVar5;
  char *pcVar6;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093fc64;
  local_14 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffd0;
  ExceptionList = &local_14;
  if (*(char *)(in_ECX + 0x89) == '\0') {
    if (*(int *)(in_ECX + 0x28) != 0) {
      *(undefined4 *)(in_ECX + 0x28) = 0;
      iVar3 = FUN_00434250(uVar2);
      *(undefined4 *)(iVar3 + 0x14) = 1;
      if (*(int *)(in_ECX + 0x38) == 0) {
        uVar4 = FUN_006bde40((undefined4 *)(in_ECX + 0x3c));
        FUN_00436890(in_ECX + 0x74,uVar4);
        FUN_005623a0(in_ECX);
        FUN_00414680();
        FUN_004a39a0(*(undefined4 *)(in_ECX + 0x38),*(undefined4 *)(in_ECX + 0x3c));
        FUN_005620b0();
      }
      else {
        pcVar6 = "CheckConfirmMessage";
        uVar5 = 1;
        uVar4 = FUN_0049b230(1,"CheckConfirmMessage");
        FUN_004ad0a0(uVar4,uVar5,pcVar6);
        uVar4 = 0xffffffff;
        FUN_0049b230(extraout_ECX,0xffffffff);
        iVar3 = FUN_004a2b50(uVar4);
        if (iVar3 == 1) {
          FUN_00414680();
          FUN_004a39a0(*(undefined4 *)(in_ECX + 0x38),*(undefined4 *)(in_ECX + 0x3c));
        }
      }
      if ((DAT_00fdf3d4 & 1) == 0) {
        DAT_00fdf3d4 = DAT_00fdf3d4 | 1;
        local_c = 4;
        FUN_006f4380();
        _atexit((_func_4879 *)&LAB_00bce6d0);
        local_c = 0xffffffff;
      }
      FUN_004ad0a0(&DAT_00fdf3c8,0,"f_removeAllCoroutines");
      if ((DAT_00faadd4 & 1) == 0) {
        DAT_00faadd4 = DAT_00faadd4 | 1;
        local_c = 5;
        FUN_00587480();
        _atexit((_func_4879 *)&LAB_00bcccc0);
        local_c = 0xffffffff;
      }
      FUN_00589a20(*(undefined4 *)(in_ECX + 0x84),*(undefined4 *)(in_ECX + 0x84));
      uVar1 = *(undefined1 *)(in_ECX + 0x88);
      iVar3 = FUN_00404ba0();
      *(undefined1 *)(iVar3 + 0x68c4) = uVar1;
    }
    *(undefined4 *)(in_ECX + 0x38) = 0;
    *(undefined4 *)(in_ECX + 0x3c) = 0;
    ExceptionList = local_14;
    return;
  }
  if (*(int *)(in_ECX + 0x28) != 0) {
    *(undefined4 *)(in_ECX + 0x28) = 0;
    iVar3 = FUN_00434250(uVar2);
    *(undefined4 *)(iVar3 + 0x14) = 1;
    if ((DAT_00fdf3d4 & 1) == 0) {
      DAT_00fdf3d4 = DAT_00fdf3d4 | 1;
      local_c = 0;
      FUN_006f4380();
      _atexit((_func_4879 *)&LAB_00bce6d0);
      local_c = 0xffffffff;
    }
    FUN_004ad0a0(&DAT_00fdf3c8,0,"f_removeAllCoroutines");
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 1;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_c = 0xffffffff;
    }
    FUN_00589a20(*(undefined4 *)(in_ECX + 0x84),*(undefined4 *)(in_ECX + 0x84));
    uVar1 = *(undefined1 *)(in_ECX + 0x88);
    iVar3 = FUN_00404ba0();
    *(undefined1 *)(iVar3 + 0x68c4) = uVar1;
  }
  if ((DAT_00fc0f64 & 1) == 0) {
    DAT_00fc0f64 = DAT_00fc0f64 | 1;
    local_c = 2;
    FUN_0047dce0();
    _atexit(FUN_00bcdaf0);
    local_c = 0xffffffff;
  }
  iVar3 = FUN_0047e640(&DAT_00fc0f68,*(undefined4 *)(in_ECX + 0x38),*(undefined4 *)(in_ECX + 0x3c));
  *(int *)(in_ECX + 0x3c) = iVar3;
  if (iVar3 == 0) {
    if ((DAT_00fc0fc0 & 1) == 0) {
      DAT_00fc0fc0 = DAT_00fc0fc0 | 1;
      local_c = 3;
      FUN_006d8e50();
      _atexit((_func_4879 *)&LAB_00bcdbb0);
      local_c = 0xffffffff;
    }
    FUN_006d9430(*(undefined4 *)(in_ECX + 0x34));
    *(undefined4 *)(in_ECX + 0x38) = 0;
    *(undefined4 *)(in_ECX + 0x3c) = 0;
    ExceptionList = local_14;
    return;
  }
  FUN_00565720(*(undefined4 *)(in_ECX + 0x38),iVar3);
  ExceptionList = local_14;
  return;
}

