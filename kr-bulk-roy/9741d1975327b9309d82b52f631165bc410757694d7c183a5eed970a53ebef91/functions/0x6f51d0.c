
void FUN_006f51d0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_EAX;
  int iVar4;
  int unaff_ESI;
  int unaff_EDI;
  int local_8;
  
  if ((unaff_EDI != unaff_ESI) &&
     (*(int *)(unaff_EDI + 8) = *(int *)(unaff_EDI + 8) + in_EAX * -0x10, 0 < in_EAX)) {
    iVar4 = 0;
    local_8 = in_EAX;
    do {
      puVar2 = *(undefined4 **)(unaff_ESI + 8);
      iVar3 = *(int *)(unaff_EDI + 8);
      *(undefined4 **)(unaff_ESI + 8) = puVar2 + 4;
      *puVar2 = *(undefined4 *)(iVar3 + iVar4);
      puVar2[1] = *(undefined4 *)(iVar3 + 4 + iVar4);
      puVar1 = (undefined4 *)(iVar3 + 8 + iVar4);
      iVar4 = iVar4 + 0x10;
      local_8 = local_8 + -1;
      puVar2[2] = *puVar1;
    } while (local_8 != 0);
  }
  return;
}

