
void FUN_005d22b0(void)

{
  uint uVar1;
  int in_EAX;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)(in_EAX + 0xc0);
  iVar3 = 4;
  do {
    (**(code **)(*(int *)*piVar2 + 0x90))(0);
    uVar1 = *(uint *)(*piVar2 + 0x28);
    if ((uVar1 & 8) != 0) {
      *(uint *)(*piVar2 + 0x28) = uVar1 ^ 8;
    }
    piVar2 = piVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

