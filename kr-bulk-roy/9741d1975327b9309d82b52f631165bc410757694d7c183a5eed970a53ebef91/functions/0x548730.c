
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00548730(void)

{
  int iVar1;
  int *in_ECX;
  char cVar2;
  uint uVar3;
  char local_21;
  undefined2 uStack_20;
  char cStack_1e;
  undefined2 uStack_1c;
  char cStack_1a;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0093fde6;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  local_21 = '\0';
  iVar1 = (**(code **)(*in_ECX + 0x20))(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
  if (iVar1 != 0) {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      uStack_c = 0;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      uStack_c = 0xffffffff;
    }
    if ((((DAT_00f9392c == 4) || (iVar1 = FUN_00404ba0(), *(int *)(iVar1 + 0x5f4c) == 9)) ||
        (iVar1 = FUN_00404ba0(), *(int *)(iVar1 + 0x5f4c) == 6)) ||
       (iVar1 = FUN_00404ba0(), *(int *)(iVar1 + 0x5f4c) == 0x1c)) {
      if ((DAT_00fb7c14 & 1) == 0) {
        DAT_00fb7c14 = DAT_00fb7c14 | 1;
        uStack_c = 1;
        FUN_006d0750();
        _atexit((_func_4879 *)&LAB_00bcd530);
        uStack_c = 0xffffffff;
      }
      if ((DAT_00f94390 & 1) == 0) {
        DAT_00f94390 = DAT_00f94390 | 1;
        uStack_c = 2;
        FUN_004e1590();
        _atexit((_func_4879 *)&LAB_00bccc80);
        uStack_c = 0xffffffff;
      }
      if (DAT_00fb9015 == '\x01') {
        FUN_0050c640(1);
      }
      if (DAT_00fb9016 == '\x01') {
        FUN_0050c640(2);
      }
      if (DAT_00fb9017 == '\x01') {
        FUN_0050c640(3);
      }
      if (DAT_00fb9018 == '\x01') {
        FUN_0050c640(4);
      }
      if ((DAT_00fb901b == '\x01') &&
         (iVar1 = (**(code **)(*in_ECX + 0x20))(), *(int *)(*(int *)(iVar1 + 0x158) + 8) != 3)) {
        local_21 = -0x80;
      }
    }
  }
  iVar1 = (**(code **)(*in_ECX + 0x20))();
  if (iVar1 != 0) {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      uStack_c = 3;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      uStack_c = 0xffffffff;
    }
    if (((DAT_00f9392c == 4) || (iVar1 = FUN_00404ba0(), *(int *)(iVar1 + 0x5f4c) == 9)) ||
       (iVar1 = FUN_00404ba0(), *(int *)(iVar1 + 0x5f4c) == 6)) {
      cVar2 = '\0';
      uVar3 = 0x1c;
      do {
        if ((DAT_00fb7c14 & 1) == 0) {
          DAT_00fb7c14 = DAT_00fb7c14 | 1;
          uStack_c = 4;
          FUN_006d0750();
          _atexit((_func_4879 *)&LAB_00bcd530);
          uStack_c = 0xffffffff;
        }
        if ((uVar3 < 0x28) && ((&DAT_00fb9004)[uVar3] == '\x01')) {
          if ((_DAT_00fb1314 & 1) == 0) {
            _DAT_00fb1314 = _DAT_00fb1314 | 1;
            _atexit((_func_4879 *)&DAT_00bccf10);
          }
          cStack_1e = cVar2 + '\x01';
          uStack_20 = 0x68;
          if (DAT_00fba798 == 0) {
            (**(code **)(*DAT_00fba854 + 0x10))(0,&uStack_20,3);
          }
        }
        uVar3 = uVar3 + 1;
        cVar2 = cVar2 + '\x01';
      } while ((int)uVar3 < 0x26);
    }
  }
  if (local_21 == '\0') {
    ExceptionList = local_14;
    return 0;
  }
  uStack_1c = 7;
  cStack_1a = local_21;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&uStack_1c,3);
  }
  ExceptionList = local_14;
  return 1;
}

