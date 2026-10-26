
void FUN_0074a200(void)

{
  int iVar1;
  undefined4 in_EAX;
  int iVar2;
  int *unaff_EDI;
  
  iVar1 = *unaff_EDI;
  iVar2 = FUN_0074d700(iVar1,*(undefined4 *)(iVar1 + 4),in_EAX);
  if (unaff_EDI[1] == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  unaff_EDI[1] = unaff_EDI[1] + 1;
  *(int *)(iVar1 + 4) = iVar2;
  **(int **)(iVar2 + 4) = iVar2;
  return;
}

