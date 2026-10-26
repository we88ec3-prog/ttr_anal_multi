
undefined4 * FUN_00586130(byte param_1)

{
  undefined4 *in_ECX;
  
  if ((param_1 & 2) != 0) {
    _eh_vector_destructor_iterator_(in_ECX,0x104,in_ECX[-1],FUN_00585f80);
    if ((param_1 & 1) != 0) {
      FUN_00891d3d(in_ECX + -1);
    }
    return in_ECX + -1;
  }
  *in_ECX = FUI::CMsgBoxWaitTimer::vftable;
  in_ECX[0x3f] = 0;
  if ((HANDLE)in_ECX[0x40] != (HANDLE)0x0) {
    WaitForSingleObject((HANDLE)in_ECX[0x40],0xffffffff);
  }
  *in_ECX = FoxUI::FXUIWindowSimple::vftable;
  FUN_00756590();
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return in_ECX;
}

