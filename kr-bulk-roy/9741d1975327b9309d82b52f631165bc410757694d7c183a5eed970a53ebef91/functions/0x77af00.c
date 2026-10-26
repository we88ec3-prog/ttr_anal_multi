
void FUN_0077af00(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  piVar1 = (int *)(in_ECX + 0x14);
  if (7 < *(uint *)(in_ECX + 0x28)) {
    piVar1 = (int *)*piVar1;
  }
  iVar2 = FUN_00774c30(piVar1);
  if (iVar2 != 0) {
    piVar1 = (int *)(in_ECX + 0x30);
    if (7 < *(uint *)(in_ECX + 0x44)) {
      piVar1 = (int *)*piVar1;
    }
    FUN_00763360(piVar1);
    FUN_00776650();
  }
  return;
}

