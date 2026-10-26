
void FUN_00748980(void)

{
  int in_EAX;
  int iVar1;
  int in_EDX;
  int *unaff_ESI;
  undefined8 uVar2;
  
  uVar2 = CONCAT44(in_EDX,in_EDX);
  if ((((*(byte *)(in_EAX + 0x28) & 2) == 0) || (*(int *)(in_EAX + 0x24) == 0)) || (in_EDX == 0)) {
    if (unaff_ESI != (int *)0x0) {
      (**(code **)(*unaff_ESI + 0x10))(1);
    }
    return;
  }
  if ((*(byte *)(in_EDX + 0x28) & 0x10) == 0) {
    if (*(int *)(in_EDX + 0x60) != 0) {
      uVar2 = FUN_00745c20();
      goto LAB_007489a9;
    }
  }
  else {
LAB_007489a9:
    in_EDX = (int)((ulonglong)uVar2 >> 0x20);
    if ((int)uVar2 != 0) {
      iVar1 = *(int *)((int)uVar2 + 0x20);
      goto LAB_007489b5;
    }
  }
  iVar1 = -1;
LAB_007489b5:
  unaff_ESI[1] = iVar1;
  unaff_ESI[2] = *(int *)(in_EDX + 0x20);
  unaff_ESI[3] = in_EDX;
  FUN_007508d0(unaff_ESI);
  return;
}

