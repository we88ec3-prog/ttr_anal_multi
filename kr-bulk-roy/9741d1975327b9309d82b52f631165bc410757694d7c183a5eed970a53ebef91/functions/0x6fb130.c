
void FUN_006fb130(void)

{
  int iVar1;
  int unaff_EDI;
  
  for (iVar1 = *(int *)(unaff_EDI + 0x8c); iVar1 != unaff_EDI + 0x78; iVar1 = *(int *)(iVar1 + 0x14)
      ) {
    if ((((*(byte *)(iVar1 + 5) & 7) == 0) && (3 < (*(int **)(iVar1 + 8))[2])) &&
       ((*(byte *)(**(int **)(iVar1 + 8) + 5) & 3) != 0)) {
      FUN_006f9f70();
    }
  }
  return;
}

