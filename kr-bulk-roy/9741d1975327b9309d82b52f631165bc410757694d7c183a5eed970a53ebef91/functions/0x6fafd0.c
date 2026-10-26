
void FUN_006fafd0(void)

{
  int iVar1;
  int *piVar2;
  int unaff_EDI;
  int local_8;
  
  piVar2 = (int *)(unaff_EDI + 0x98);
  local_8 = 9;
  do {
    iVar1 = *piVar2;
    if ((iVar1 == 0) || ((*(byte *)(iVar1 + 5) & 3) == 0)) goto switchD_006fb00e_caseD_4;
    *(byte *)(iVar1 + 5) = *(byte *)(iVar1 + 5) & 0xfc;
    switch(*(undefined1 *)(iVar1 + 4)) {
    default:
      goto switchD_006fb00e_caseD_4;
    case 5:
      *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(unaff_EDI + 0x24);
      break;
    case 6:
      *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(unaff_EDI + 0x24);
      break;
    case 7:
      *(byte *)(iVar1 + 5) = *(byte *)(iVar1 + 5) | 4;
      if ((*(int *)(iVar1 + 8) != 0) && ((*(byte *)(*(int *)(iVar1 + 8) + 5) & 3) != 0)) {
        FUN_006f9f70();
      }
      if ((*(byte *)(*(int *)(iVar1 + 0xc) + 5) & 3) != 0) {
        FUN_006f9f70();
      }
      goto switchD_006fb00e_caseD_4;
    case 8:
      *(undefined4 *)(iVar1 + 0x6c) = *(undefined4 *)(unaff_EDI + 0x24);
      break;
    case 9:
      *(undefined4 *)(iVar1 + 0x44) = *(undefined4 *)(unaff_EDI + 0x24);
      break;
    case 10:
      if ((3 < (*(int **)(iVar1 + 8))[2]) && ((*(byte *)(**(int **)(iVar1 + 8) + 5) & 3) != 0)) {
        FUN_006f9f70();
      }
      if (*(int *)(iVar1 + 8) == iVar1 + 0x10) {
        *(byte *)(iVar1 + 5) = *(byte *)(iVar1 + 5) | 4;
      }
      goto switchD_006fb00e_caseD_4;
    }
    *(int *)(unaff_EDI + 0x24) = iVar1;
switchD_006fb00e_caseD_4:
    piVar2 = piVar2 + 1;
    local_8 = local_8 + -1;
    if (local_8 == 0) {
      return;
    }
  } while( true );
}

