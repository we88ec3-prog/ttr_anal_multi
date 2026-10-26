
void FUN_004c1930(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  int iVar3;
  int iVar4;
  int local_38;
  int local_34;
  undefined1 local_30 [28];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009407d2;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (*(int *)(in_ECX + 0xbd78) != 0) {
    if ((DAT_00fc0f80 & 1) == 0) {
      DAT_00fc0f80 = DAT_00fc0f80 | 1;
      local_c = 0;
      FUN_0047aeb0(DAT_00d61f20 ^ (uint)&stack0xffffffb8);
      _atexit((_func_4879 *)&LAB_00bcdb70);
    }
    local_c = 0xffffffff;
    FUN_004a8b90(&DAT_00fc0f84);
    if ((DAT_00fc0f80 & 1) == 0) {
      DAT_00fc0f80 = DAT_00fc0f80 | 1;
      local_c = 1;
      FUN_0047aeb0();
      _atexit((_func_4879 *)&LAB_00bcdb70);
      local_c = 0xffffffff;
    }
    if (DAT_00fc0fb8 == 0) {
      if ((DAT_00fc0f80 & 1) == 0) {
        DAT_00fc0f80 = DAT_00fc0f80 | 1;
        local_c = 2;
        FUN_0047aeb0();
        _atexit((_func_4879 *)&LAB_00bcdb70);
        local_c = 0xffffffff;
      }
      FUN_004ad0a0(DAT_00fc0f84,0,"t_removeAllCoroutines");
      FUN_004a9db0();
      FUN_004c2050(in_ECX);
    }
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 3;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  iVar3 = DAT_00fb1318;
  if (DAT_00f942a5 == '\0') {
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_c = 4;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_c = 0xffffffff;
    }
    FUN_0079a7a0(&DAT_00fb76a8,local_30,*(undefined4 *)(iVar3 + 0xc00c),
                 *(undefined4 *)(iVar3 + 0xc010));
    *(undefined4 *)(in_ECX + 0xbd74) = 0xffffffff;
    iVar3 = 9;
    iVar4 = 9000;
    do {
      if ((DAT_00fab22c & 1) == 0) {
        DAT_00fab22c = DAT_00fab22c | 1;
        local_c = 5;
        FUN_004dec90();
        _atexit((_func_4879 *)&LAB_00bcce30);
        local_c = 0xffffffff;
      }
      local_38 = iVar4;
      FUN_0082ef00(&local_38);
      if ((((local_34 != DAT_00fab13c) && (*(int *)(local_34 + 0x10) != 0)) &&
          (*(int *)(*(int *)(local_34 + 0x10) + 0x15c) != 0)) &&
         (iVar1 = FUN_007a8030(local_30), iVar1 != 0)) {
        *(int *)(in_ECX + 0xbd74) = iVar3;
        break;
      }
      iVar3 = iVar3 + -1;
      iVar4 = iVar4 + -1000;
    } while (-1 < iVar4);
    if (-1 < *(int *)(in_ECX + 0xbd74)) {
      if (DAT_00fba80c == 0) {
        iVar3 = FUN_00891268(0x57c);
        if (iVar3 == 0) {
          DAT_00fba80c = 0;
        }
        else {
          DAT_00fba80c = FUN_006f1370();
        }
      }
      if ((*(int *)(DAT_00fba80c + 0x20) != 0) && (*(char *)(DAT_00fba80c + 0x368) == '\x01')) {
        piVar2 = (int *)FUN_00891268(0x18);
        if (piVar2 == (int *)0x0) {
          piVar2 = (int *)0x0;
        }
        else {
          iVar3 = *(int *)(in_ECX + 0xbd74);
          piVar2[1] = -1;
          piVar2[2] = -1;
          piVar2[3] = 0;
          piVar2[4] = 0xf4246;
          *piVar2 = (int)FoxUI::FXUIEventI1::vftable;
          piVar2[5] = iVar3;
        }
        if ((DAT_00faadd0 & 1) == 0) {
          DAT_00faadd0 = DAT_00faadd0 | 1;
          local_c = 6;
          FUN_0074d990();
          _atexit((_func_4879 *)&LAB_00bccc70);
          local_c = 0xffffffff;
        }
        if (DAT_00f95bd4 != (int *)0x0) {
          (**(code **)(*DAT_00f95bd4 + 0x15c))(piVar2);
        }
        if (piVar2 != (int *)0x0) {
          (**(code **)(*piVar2 + 0x10))(1);
        }
      }
    }
  }
  FUN_004adb10();
  ExceptionList = local_14;
  return;
}

