
void FUN_00749d00(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_EAX;
  int *unaff_ESI;
  
  if (unaff_ESI[5] - unaff_ESI[3] != in_EAX) {
    iVar1 = unaff_ESI[4];
    iVar2 = unaff_ESI[3];
    iVar3 = unaff_ESI[2];
    FUN_00745b80();
    unaff_ESI[2] = iVar3;
    unaff_ESI[3] = iVar2;
    unaff_ESI[4] = iVar1;
    unaff_ESI[5] = iVar2 + in_EAX;
    FUN_00746f70();
    FUN_00749920(unaff_ESI);
    if ((*(byte *)((int)unaff_ESI + 0x2a) & 1) == 0) {
      FUN_00745b80();
    }
    else {
      (**(code **)(*unaff_ESI + 0x11c))();
      (**(code **)(*unaff_ESI + 0x118))();
      (**(code **)(*unaff_ESI + 0xcc))();
    }
    if (((uint)unaff_ESI[10] >> 0xf & 1) != 0) {
      (**(code **)(*unaff_ESI + 0x120))();
      (**(code **)(*unaff_ESI + 0x124))();
    }
  }
  return;
}

