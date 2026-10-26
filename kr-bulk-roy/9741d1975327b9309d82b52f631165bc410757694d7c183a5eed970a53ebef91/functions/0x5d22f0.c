
void FUN_005d22f0(void)

{
  int in_EAX;
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(in_EAX + 0xc0);
  iVar2 = 4;
  do {
    (**(code **)(*(int *)*piVar1 + 0x90))(1);
    *(uint *)(*piVar1 + 0x28) = *(uint *)(*piVar1 + 0x28) | 8;
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

