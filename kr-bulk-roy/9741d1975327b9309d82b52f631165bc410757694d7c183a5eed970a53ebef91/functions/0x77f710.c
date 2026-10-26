
void FUN_0077f710(void)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int *unaff_ESI;
  undefined1 local_5c [44];
  undefined1 local_30 [44];
  
  bVar1 = false;
  iVar2 = (**(code **)(*unaff_ESI + 0x3c))();
  if (iVar2 != 0) {
    piVar3 = (int *)(**(code **)(*unaff_ESI + 0x3c))();
    iVar2 = (**(code **)(*piVar3 + 0x54))();
    if (iVar2 != 0) {
      bVar1 = true;
    }
  }
  if ((unaff_ESI[0x30] != 0) && (!bVar1)) {
    unaff_ESI[0x31] = 0;
    return;
  }
  iVar2 = (**(code **)(*unaff_ESI + 0x3c))();
  if (iVar2 != 0) {
    piVar3 = (int *)(**(code **)(*unaff_ESI + 0x3c))();
    uVar4 = (**(code **)(*piVar3 + 0x24))(local_30);
    FUN_0077e910(local_5c,unaff_ESI + 0x1a,uVar4);
  }
  FUN_0077ea00();
  unaff_ESI[0x30] = 1;
  unaff_ESI[0x31] = 1;
  return;
}

