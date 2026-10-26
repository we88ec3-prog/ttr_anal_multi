
void FUN_008d81f0(void)

{
  int iVar1;
  uint uVar2;
  uint *unaff_EBX;
  
  iVar1 = FUN_008b97e0();
  if (iVar1 != 0) {
    *unaff_EBX = 0;
    return;
  }
  uVar2 = FUN_008b9ab0();
  *unaff_EBX = uVar2 & 0xffff;
  return;
}

