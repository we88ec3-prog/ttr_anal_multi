
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_0048a010(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00908a5e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fd8fd0 & 1) == 0) {
    DAT_00fd8fd0 = DAT_00fd8fd0 | 1;
    local_8 = 0;
    _DAT_00fd8fd8 = 0x3f800000;
    _DAT_00fd8fdc = 0x3f800000;
    _eh_vector_constructor_iterator_
              (&DAT_00fd8fe8,0x3c,10,(_func_void_void_ptr *)&LAB_0041d8e0,FUN_0041d980);
    _DAT_00fd9240 = 1;
    _atexit((_func_4879 *)&LAB_00bcdf70);
  }
  ExceptionList = local_10;
  return &DAT_00fd8fd8;
}

