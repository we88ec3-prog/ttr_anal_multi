
void FUN_00748900(void)

{
  int *in_EAX;
  int iVar1;
  int unaff_ESI;
  
  in_EAX[3] = unaff_ESI;
  if (*(int *)(unaff_ESI + 0x60) != 0) {
    in_EAX[1] = *(int *)(unaff_ESI + 0x20);
    in_EAX[2] = *(int *)(unaff_ESI + 0x48);
    (**(code **)(**(int **)(unaff_ESI + 0x60) + 0x148))();
  }
  if (((*(uint *)(unaff_ESI + 0x28) & 2) == 0) || (*(int *)(unaff_ESI + 0x24) == 0)) {
    (**(code **)(*in_EAX + 0x10))(1);
    return;
  }
  iVar1 = unaff_ESI;
  if ((*(uint *)(unaff_ESI + 0x28) & 0x10) == 0) {
    if (*(int *)(unaff_ESI + 0x60) != 0) {
      iVar1 = FUN_00745c20();
      goto LAB_00748947;
    }
  }
  else {
LAB_00748947:
    if (iVar1 != 0) {
      iVar1 = *(int *)(iVar1 + 0x20);
      goto LAB_00748953;
    }
  }
  iVar1 = -1;
LAB_00748953:
  in_EAX[1] = iVar1;
  in_EAX[2] = *(int *)(unaff_ESI + 0x20);
  FUN_007508d0(in_EAX);
  return;
}

