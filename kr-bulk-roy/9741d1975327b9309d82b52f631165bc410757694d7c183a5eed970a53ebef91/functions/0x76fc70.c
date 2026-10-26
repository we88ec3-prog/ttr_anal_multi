
void FUN_0076fc70(void)

{
  int *piVar1;
  int *piVar2;
  int in_EAX;
  int *unaff_ESI;
  
  piVar1 = (int *)(in_EAX + 0xa0);
  FUN_0076fcd0(piVar1);
  (**(code **)(*unaff_ESI + 400))();
  (**(code **)(*unaff_ESI + 0x164))();
  (**(code **)(*unaff_ESI + 0x144))();
  piVar2 = (int *)*piVar1;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
    *piVar1 = 0;
  }
  return;
}

