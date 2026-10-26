
void FUN_00845210(void)

{
  int *piVar1;
  undefined4 *in_EAX;
  int iVar2;
  undefined4 uVar3;
  int *in_EDX;
  undefined4 *unaff_ESI;
  
  *unaff_ESI = *in_EAX;
  piVar1 = (int *)*in_EDX;
  unaff_ESI[1] = piVar1;
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 8))(0);
    if (iVar2 == 0) {
      uVar3 = (**(code **)(*(int *)unaff_ESI[1] + 0xc))();
      unaff_ESI[1] = uVar3;
    }
    *(int *)(unaff_ESI[1] + 4) = *(int *)(unaff_ESI[1] + 4) + 1;
  }
  return;
}

