
void FUN_00866d10(void)

{
  undefined4 *puVar1;
  int iVar2;
  int *in_EAX;
  int iVar3;
  int in_ECX;
  int local_8;
  
  puVar1 = (undefined4 *)(in_ECX + 0x184);
  local_8 = in_ECX;
  FUN_0085e020(puVar1,&local_8,*puVar1,*(undefined4 *)(in_ECX + 0x188));
  iVar3 = in_EAX[1] - *in_EAX >> 4;
  if (iVar3 != 0) {
    FUN_0085e2f0(iVar3);
    iVar3 = in_EAX[1];
    iVar2 = *in_EAX;
    FUN_0085e020(puVar1,&local_8,*puVar1,*(undefined4 *)(in_ECX + 0x188));
    FUN_00866e90(puVar1,*puVar1,iVar2,iVar3,local_8);
  }
  return;
}

