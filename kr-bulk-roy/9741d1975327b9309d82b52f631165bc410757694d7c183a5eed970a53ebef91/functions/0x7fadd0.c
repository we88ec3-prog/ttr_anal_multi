
int FUN_007fadd0(void)

{
  int iVar1;
  float10 fVar2;
  int local_14;
  
  FUN_007f9ec0();
  FUN_007f9ec0();
  fVar2 = (float10)FUN_007f9ec0();
  iVar1 = FUN_008fed10();
  local_14 = (int)(longlong)ROUND((float)iVar1 * (float)fVar2);
  if (local_14 == 0) {
    local_14 = 1;
  }
  return local_14;
}

