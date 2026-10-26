
uint * FUN_0076c4f0(uint param_1)

{
  uint *puVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091b93b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar2 = -(uint)((int)((ulonglong)param_1 * 0xe0 >> 0x20) != 0) | (uint)((ulonglong)param_1 * 0xe0)
  ;
  puVar1 = (uint *)FUN_0087dc3d(-(uint)(0xfffffffb < uVar2) | uVar2 + 4,
                                DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  if (puVar1 != (uint *)0x0) {
    *puVar1 = param_1;
    _eh_vector_constructor_iterator_(puVar1 + 1,0xe0,param_1,FUN_0076cbc0,FUN_00489220);
    ExceptionList = local_10;
    return puVar1 + 1;
  }
  ExceptionList = local_10;
  return (uint *)0x0;
}

