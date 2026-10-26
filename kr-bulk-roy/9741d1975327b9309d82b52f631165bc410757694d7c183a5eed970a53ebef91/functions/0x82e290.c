
void FUN_0082e290(void)

{
  int iVar1;
  int iVar2;
  int in_EDX;
  int iVar3;
  int *unaff_EDI;
  
  iVar3 = unaff_EDI[1];
  if (iVar3 < unaff_EDI[3]) {
    iVar1 = unaff_EDI[2];
    do {
      iVar2 = *unaff_EDI;
      if (iVar2 < iVar1) {
        do {
          *(undefined4 *)
           (*(int *)(in_EDX + 0x20) + 4 + (*(int *)(in_EDX + 8) * iVar3 + iVar2) * 0x18) = 0;
          *(undefined4 *)(*(int *)(in_EDX + 0x20) + (*(int *)(in_EDX + 8) * iVar3 + iVar2) * 0x18) =
               0;
          iVar1 = unaff_EDI[2];
          iVar2 = iVar2 + 1;
        } while (iVar2 < iVar1);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < unaff_EDI[3]);
  }
  return;
}

