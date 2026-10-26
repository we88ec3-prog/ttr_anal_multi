
void FUN_00571ed0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (1.0 <= *(float *)(in_ECX + 0xc)) {
    uVar1 = FUN_008fed10();
    uVar2 = FUN_008fed10(uVar1);
    FUN_005719e0(*(undefined4 *)(in_ECX + 8),uVar2,uVar1);
    return;
  }
  FUN_008fed10();
  uVar1 = FUN_008fed10();
  FUN_00571b20(uVar1);
  return;
}

