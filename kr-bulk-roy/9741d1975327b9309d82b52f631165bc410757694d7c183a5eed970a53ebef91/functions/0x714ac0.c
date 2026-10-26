
undefined1 FUN_00714ac0(void)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 uVar4;
  int *unaff_ESI;
  undefined4 local_8;
  
  if (unaff_ESI == (int *)0x0) {
    return 0;
  }
  uVar4 = 0;
  uVar1 = (**(code **)(*unaff_ESI + 0x2c))();
  if (2 < uVar1) {
    uVar2 = (**(code **)(*unaff_ESI + 0x30))();
    (**(code **)(*unaff_ESI + 0x34))(0,0);
    local_8 = (uint)local_8._3_1_ << 0x18;
    iVar3 = (**(code **)(*unaff_ESI + 0x10))(&local_8,3,1);
    if ((((iVar3 != 0) && (DAT_00f886ac == (char)local_8)) && (DAT_00f886ad == local_8._1_1_)) &&
       (DAT_00f886ae == local_8._2_1_)) {
      uVar4 = 1;
    }
    (**(code **)(*unaff_ESI + 0x34))(uVar2,0);
  }
  return uVar4;
}

