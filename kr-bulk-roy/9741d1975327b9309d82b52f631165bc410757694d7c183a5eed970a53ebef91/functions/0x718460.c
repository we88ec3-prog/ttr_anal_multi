
uint FUN_00718460(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int *unaff_ESI;
  
  uVar1 = (**(code **)(*unaff_ESI + 4))();
  uVar2 = (**(code **)(*unaff_ESI + 4))();
  uVar3 = (**(code **)(*unaff_ESI + 4))();
  uVar4 = (**(code **)(*unaff_ESI + 4))();
  return uVar4 & 0xff | ((uVar1 & 0xff) << 8 | uVar2 & 0xff) << 0x10 | (uVar3 & 0xff) << 8;
}

