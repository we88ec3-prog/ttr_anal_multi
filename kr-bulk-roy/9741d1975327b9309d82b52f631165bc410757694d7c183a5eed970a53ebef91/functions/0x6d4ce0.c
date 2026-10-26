
undefined1 FUN_006d4ce0(void)

{
  uint unaff_ESI;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092685c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (unaff_ESI - 0x2711 < 9999) {
    if ((DAT_00fdf3ec & 1) == 0) {
      DAT_00fdf3ec = DAT_00fdf3ec | 1;
      local_8 = 0;
      FUN_006d1da0();
      _atexit((_func_4879 *)&LAB_00bce330);
    }
    FUN_0082ef00(&stack0xffffffec);
    if (local_18 != DAT_00fdf634) {
      ExceptionList = local_10;
      return *(undefined1 *)(local_18 + 0x10);
    }
  }
  else {
    if ((DAT_00fb7c14 & 1) == 0) {
      DAT_00fb7c14 = DAT_00fb7c14 | 1;
      local_8 = 1;
      FUN_006d0750(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit((_func_4879 *)&LAB_00bcd530);
    }
    if (unaff_ESI < 0x28) {
      ExceptionList = local_10;
      return (&DAT_00fb9004)[unaff_ESI];
    }
  }
  ExceptionList = local_10;
  return 0;
}

