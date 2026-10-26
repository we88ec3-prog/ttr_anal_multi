
void FUN_0079a3c0(void)

{
  int *piVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  int in_ECX;
  int *unaff_EDI;
  
  iVar3 = *(int *)(in_ECX + 0x98);
  if (in_EAX == 0) {
    in_EAX = (**(code **)(*unaff_EDI + 4))();
  }
  iVar2 = *(int *)(in_EAX * 0x2004 + 0x2000 + iVar3);
  iVar3 = in_EAX * 0x2004 + iVar3;
  if (iVar2 < 0x800) {
    *(int **)(iVar3 + iVar2 * 4) = unaff_EDI;
    piVar1 = (int *)(iVar3 + 0x2000);
    *piVar1 = *piVar1 + 1;
  }
  return;
}

