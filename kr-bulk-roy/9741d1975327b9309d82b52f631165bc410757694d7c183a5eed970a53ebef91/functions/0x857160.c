
int FUN_00857160(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 in_ECX;
  int iVar3;
  int iVar4;
  int iStack00000004;
  undefined4 local_8;
  
  iVar3 = 0;
  iStack00000004 = 0;
  local_8 = in_ECX;
  do {
    iVar4 = 0;
    do {
      iVar1 = FUN_00857520(iVar3);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 8) != 0)) {
        puVar2 = (undefined4 *)FUN_00857520(iVar3);
        if (puVar2 != (undefined4 *)0x0) {
          local_8 = *puVar2;
        }
        switch(local_8) {
        case 0:
        case 4:
        case 5:
        case 6:
          iVar1 = 4;
          break;
        case 1:
        case 7:
          iVar1 = 8;
          break;
        case 2:
          iVar1 = 0xc;
          break;
        case 3:
          iVar1 = 0x10;
          break;
        default:
          iVar1 = 0;
        }
        iStack00000004 = iStack00000004 + iVar1;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0xf);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0xd);
  return iStack00000004;
}

